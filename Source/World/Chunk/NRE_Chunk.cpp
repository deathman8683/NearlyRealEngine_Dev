
    #include "NRE_Chunk.hpp"
    #include "../NRE_World.hpp"

    namespace NRE {
        namespace World {

            GLuint Chunk::SIZE_X = 16;
            GLuint Chunk::SIZE_Y = 16;
            GLuint Chunk::SIZE_Z = 128;
            Maths::Vector3D<GLuint> Chunk::SIZE = Maths::Vector3D<GLuint>(SIZE_X, SIZE_Y, SIZE_Z);
            GLuint Chunk::SECTOR_SIZE = 4096;
            GLuint Chunk::LOOKUP_SIZE = 1024;

            Chunk::Chunk() : Chunk(Maths::Point2D<GLint>(0)) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord) : coord(coord), bounding(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2, Maths::Vector3D<GLint>(SIZE / 2)),
                                                                                       active(true), loaded(false), constructed(false), loading(false), constructing(false), modified(false) {
                push_back(SIZE);
            }

            Chunk::Chunk(Chunk && c) : VoxelObject(std::move(c)), coord(std::move(c.coord)), bounding(std::move(c.bounding)),
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

            void Chunk::setType(Maths::Point3D<GLuint> const& p, GLubyte const& type) {
                voxelSets[0].setType(p, type);
                reload();
            }

            void Chunk::save(IO::BinaryIOFile &chunkFile) {
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
                chunkFile.InputStream::seekBegin(fileOffset);

                GLuint offset = 0, size = 0;
                chunkFile.readBinary(offset, 3);
                chunkFile.readBinary(size, 1);

                if (offset == 0 && size == 0) {
                    std::stringstream data;
                    voxelSets[0].writeCompressedData(data);
                    GLuint dataSize = data.tellp();
                    chunkFile.OutputStream::seekEnd();
                    GLuint endOffset = chunkFile.OutputStream::getPosition();
                    chunkFile.writeBinary(dataSize, 4);
                    dataSize = dataSize + 4;
                    chunkFile.write(data.rdbuf());
                    size_t paddingSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE) * SECTOR_SIZE - dataSize;
                    if (paddingSize > 0) {
                        char* padding = new char[paddingSize]{0};
                        chunkFile.writeBinary(padding[0], paddingSize);
                        delete padding;
                    }

                    chunkFile.OutputStream::seekBegin(fileOffset);
                    GLuint chunkSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE);
                    GLuint chunkOffset = std::ceil((static_cast <NREfloat> (endOffset - LOOKUP_SIZE)) / SECTOR_SIZE);
                    chunkFile.writeBinary(chunkOffset, 3);
                    chunkFile.writeBinary(chunkSize, 1);
                } else {
                    if (isModfied()) {
                        std::stringstream data;
                        voxelSets[0].writeCompressedData(data);
                        GLuint dataSize = data.tellp();
                        chunkFile.OutputStream::seekBegin(offset * SECTOR_SIZE + LOOKUP_SIZE);
                        chunkFile.writeBinary(dataSize, 4);
                        chunkFile.write(data.rdbuf());

                        chunkFile.OutputStream::seekBegin(fileOffset + 3);
                        GLuint chunkSize = std::ceil((static_cast <NREfloat> (dataSize)) / SECTOR_SIZE);
                        chunkFile.writeBinary(chunkSize, 1);
                    }
                }
            }

            void Chunk::load(IO::BinaryIOFile &chunkFile, World* w) {
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
                chunkFile.InputStream::seekBegin(fileOffset);

                GLuint offset = 0, size = 0;
                chunkFile.readBinary(offset, 3);
                chunkFile.readBinary(size, 1);

                if (offset == 0 && size == 0) {
                    createProceduralTerrain(w);
                } else {
                    chunkFile.InputStream::seekBegin(offset * SECTOR_SIZE + LOOKUP_SIZE);
                    GLuint dataSize = 0;
                    chunkFile.readBinary(dataSize, 4);

                    std::vector<char> buffer(dataSize);
                    chunkFile.readBinary(buffer[0], dataSize);
                    std::stringstream data;
                    data.rdbuf()->pubsetbuf(&buffer[0], dataSize);

                    GLuint voxNumber, x = 0, y = 0, z = 0;
                    GLubyte voxType;
                    while (dataSize > 0) {
                        data.read(reinterpret_cast<char*> (&voxNumber), 2);
                        data.read(reinterpret_cast<char*> (&voxType), 1);
                        dataSize = dataSize - 3;

                        loadVoxels(0, x, y, z, voxNumber, voxType);
                    }
                }
                setLoaded(true);
                setLoading(false);
            }

            void Chunk::createProceduralTerrain(World* w) {
                voxelSets[0].createProceduralTerrain(w->getSoilGenerator(), w->getMoistureGenerator(), getCoord());
            }

            void Chunk::checkActiveState(Camera::FixedCamera* camera) {
                if (camera != 0) {
                    setActive(camera->AABBCollision(getBounding()));
                } else {
                    setActive(true);
                }
            }

            void Chunk::reload() {
                setConstructed(false);
                setConstructing(false);
                Object::reload();
                bounding.setCenter(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2);
            }

            Chunk& Chunk::operator=(Chunk && c) {
                VoxelObject::operator=(std::move(c));
                coord = std::move(c.coord);
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
