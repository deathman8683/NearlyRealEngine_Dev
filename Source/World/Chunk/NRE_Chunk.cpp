
    #include "NRE_Chunk.hpp"

    namespace NRE {
        namespace World {

            GLuint Chunk::SIZE_X = 16;
            GLuint Chunk::SIZE_Y = 16;
            GLuint Chunk::SIZE_Z = 128;
            Maths::Vector3D<GLuint> Chunk::SIZE = Maths::Vector3D<GLuint>(SIZE_X, SIZE_Y, SIZE_Z);
            GLuint Chunk::SECTOR_SIZE = 4096;
            GLuint Chunk::LOOKUP_SIZE = 1024;

            Chunk::Chunk() {
            }

            Chunk::Chunk(bool const& generateID) : Chunk(Maths::Point2D<GLint>(0), generateID) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID) : Object3D(SIZE), coord(coord), bounding(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2, Maths::Vector3D<GLint>(SIZE / 2)),
                                                                                       active(true), loaded(false), constructed(false), loading(false), constructing(false), modified(false) {
            }

            Chunk::Chunk(Chunk && c) : Object3D(std::move(c)), coord(std::move(c.coord)), bounding(std::move(c.bounding)),
                                       active(std::move(c.active)), loaded(std::move(c.loaded)), constructed(std::move(c.constructed)), loading(std::move(c.loading)), constructing(std::move(c.constructing)), modified(std::move(c.modified)) {
            }

            Chunk::~Chunk() {
            }

            Maths::Point2D<GLint> const& Chunk::getCoord() const {
                return coord;
            }

            Physics::AABB<GLint> const& Chunk::getBounding() const {
                return bounding;
            }

            bool const& Chunk::isActive() const {
                return active;
            }

            bool const& Chunk::isLoaded() const {
                return loaded;
            }

            bool const& Chunk::isConstructed() const {
                return constructed;
            }

            bool const& Chunk::isLoading() const {
                return loading;
            }

            bool const& Chunk::isConstructing() const {
                return constructing;
            }

            bool const& Chunk::isModfied() const {
                return modified;
            }

            void Chunk::setCoord(Maths::Point2D<GLint> const& p) {
                coord = p;
            }

            void Chunk::setBounding(Physics::AABB<GLint> const& box) {
                bounding = box;
            }

            void Chunk::setActive(bool const& state) {
                active = state;
            }

            void Chunk::setLoaded(bool const& state) {
                loaded = state;
            }

            void Chunk::setConstructed(bool const& state) {
                constructed = state;
            }

            void Chunk::setLoading(bool const& state) {
                loading = state;
            }

            void Chunk::setConstructing(bool const& state) {
                constructing = state;
            }

            void Chunk::setModified(bool const& state) {
                modified = state;
            }

            void Chunk::save(std::fstream &chunkFile) {
                GLuint xOff, yOff;
                if (getCoord().getX() < 0) {
                    xOff = (-(getCoord().getX() + 1) % 16) * 16;
                } else {
                    xOff = (getCoord().getX() % 16) * 16;
                }
                if (getCoord().getY() < 0) {
                    yOff = (-(getCoord().getY() + 1) % 16);
                } else {
                    yOff = (getCoord().getY() % 16);
                }
                size_t fileOffset = 4 * (xOff + yOff);
                chunkFile.seekg(fileOffset, chunkFile.beg);
                GLuint offset = 0, size = 0;
                chunkFile.read(reinterpret_cast<char*> (&offset), 3);
                chunkFile.read(reinterpret_cast<char*> (&size), 1);

                if (offset == 0 && size == 0) {
                    std::stringstream data;
                    writeCompressedData(data);
                    GLuint dataSize = data.tellp();
                    chunkFile.seekg(0, chunkFile.end);
                    GLuint endOffset = chunkFile.tellp();
                    chunkFile.write(reinterpret_cast<char*> (&dataSize), 4);
                    dataSize = dataSize + 4;
                    chunkFile << data.rdbuf();
                    size_t paddingSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE) * SECTOR_SIZE - dataSize;
                    if (paddingSize > 0) {
                        char padding[paddingSize] = {0};
                        chunkFile.write(padding, paddingSize);
                    }

                    chunkFile.seekg(fileOffset, chunkFile.beg);
                    GLuint chunkSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE);
                    GLuint chunkOffset = std::ceil((static_cast <NREfloat> (endOffset - LOOKUP_SIZE)) / SECTOR_SIZE);
                    chunkFile.write(reinterpret_cast<char*> (&chunkOffset), 3);
                    chunkFile.write(reinterpret_cast<char*> (&chunkSize), 1);
                } else {
                    if (isModfied()) {
                        std::stringstream data;
                        writeCompressedData(data);
                        GLuint dataSize = data.tellp();
                        chunkFile.seekg(offset * SECTOR_SIZE + LOOKUP_SIZE, chunkFile.beg);
                        chunkFile.write(reinterpret_cast<char*> (&dataSize), 4);
                        chunkFile << data.rdbuf();

                        chunkFile.seekg(fileOffset + 3, chunkFile.beg);
                        GLuint chunkSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE);
                        chunkFile.write(reinterpret_cast<char*> (&chunkSize), 1);
                    }
                }
            }

            void Chunk::load(std::fstream &chunkFile, World* w) {
                GLuint xOff, yOff;
                if (getCoord().getX() < 0) {
                    xOff = (-(getCoord().getX() + 1) % 16) * 16;
                } else {
                    xOff = (getCoord().getX() % 16) * 16;
                }
                if (getCoord().getY() < 0) {
                    yOff = (-(getCoord().getY() + 1) % 16);
                } else {
                    yOff = (getCoord().getY() % 16);
                }
                size_t fileOffset = 4 * (xOff + yOff);
                chunkFile.seekg(fileOffset, chunkFile.beg);
                GLuint offset = 0, size = 0;
                chunkFile.read(reinterpret_cast<char*> (&offset), 3);
                chunkFile.read(reinterpret_cast<char*> (&size), 1);

                if (offset == 0 && size == 0) {
                    createProceduralTerrain(w);
                } else {
                    chunkFile.seekg(offset * SECTOR_SIZE + LOOKUP_SIZE, chunkFile.beg);
                    GLuint dataSize = 0;
                    chunkFile.read(reinterpret_cast<char*> (&dataSize), 4);

                    std::vector<char> buffer(dataSize);
                    chunkFile.read(&buffer[0], dataSize);
                    std::stringstream data;
                    data.rdbuf()->pubsetbuf(&buffer[0], dataSize);

                    GLuint voxNumber, x = 0, y = 0, z = 0;
                    GLubyte voxType;
                    while (dataSize > 0) {
                        data.read(reinterpret_cast<char*> (&voxNumber), 2);
                        data.read(reinterpret_cast<char*> (&voxType), 1);
                        dataSize = dataSize - 3;

                        model.loadVoxels(x, y, z, voxNumber, voxType);
                    }
                }
                setLoaded(true);
                setLoading(false);
            }

            void Chunk::checkActiveState(Camera::FixedCamera* camera) {
                if (camera != 0) {
                    setActive(camera->AABBCollision(getBounding()));
                } else {
                    setActive(true);
                }
            }

            void Chunk::reload() {
                setLoaded(false);
                setLoading(false);
                setConstructed(false);
                setConstructing(false);
                buffer->reload();
                vao.access(*buffer, GL_INT);
                bounding.setCenter(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2);
            }

            void Chunk::writeCompressedData(std::stringstream &data) {
                GLuint x = 0, y = 0, z = 0;
                GLuint currentType = model.getVoxel(x, y, z).getType(), currentLineSize = 0;
                while (z != SIZE_Z) {
                    if (currentType == static_cast <GLuint> (model.getVoxel(x, y, z).getType())) {
                        currentLineSize = currentLineSize + 1;
                    } else {
                        data.write(reinterpret_cast<char*> (&currentLineSize), 2);
                        data.write(reinterpret_cast<char*> (&currentType), 1);
                        currentType = model.getVoxel(x, y, z).getType();
                        currentLineSize = 1;
                    }

                    x = x + 1;
                    if (x == SIZE_X) {
                        x = 0;
                        y = y + 1;
                        if (y == SIZE_Y) {
                            y = 0;
                            z = z + 1;
                        }
                    }
                }
                data.write(reinterpret_cast<char*> (&currentLineSize), 2);
                data.write(reinterpret_cast<char*> (&currentType), 1);
            }

            Chunk& Chunk::operator=(Chunk && c) {
                model = std::move(c.model);
                coord = std::move(c.coord);
                buffer = std::move(c.buffer);
                vao = std::move(c.vao);
                bounding = std::move(c.bounding);
                active = std::move(c.active);
                loaded = std::move(c.loaded);
                constructed = std::move(c.constructed);
                loading = std::move(c.loading);
                constructing = std::move(c.constructing);
                modified = std::move(c.modified);
                return *this;
            }

        };
    };
