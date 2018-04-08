
    #include "NRE_Chunk.hpp"

    namespace NRE {
        namespace World {

            GLuint Chunk::SIZE_X = 16;
            GLuint Chunk::SIZE_Y = 16;
            GLuint Chunk::SIZE_Z = 128;
            Maths::Vector3D<GLuint> Chunk::SIZE = Maths::Vector3D<GLuint>(SIZE_X, SIZE_Y, SIZE_Z);
            GLuint Chunk::SECTOR_SIZE = 4096;
            GLuint Chunk::LOOKUP_SIZE = 1024;

            Chunk::Chunk() : voxel(0) {
            }

            Chunk::Chunk(bool const& generateID) : Chunk(Maths::Point2D<GLint>(0), 1, generateID) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, GLuint const& loD, bool const& generateID) : voxel(0), coord(coord), buffer(generateID), vao(generateID), bounding(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2, Maths::Vector3D<GLint>(SIZE / 2)), loD(loD),
                                                                                                          active(true), loaded(false), constructed(false), loading(false), constructing(false), modified(false) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
                buffer.push_back(new GL::MaterialBuffer(generateID));
                buffer.push_back(new GL::NormalBuffer(generateID));
                vao.access(getBuffer(), GL_INT);
            }

            Chunk::Chunk(Chunk const& c) : voxel(0), buffer(true), vao(true), bounding(c.getBounding()), loD(c.getLoD()),
                                           active(c.isActive()), loaded(c.isLoaded()), constructed(c.isConstructed()), loading(c.isLoading()), constructing(c.isConstructing()), modified(c.isModfied()) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
                memcpy(voxel, c.getVoxels(), sizeof(Voxel));
                buffer.push_back(new GL::MaterialBuffer(true));
                buffer.push_back(new GL::NormalBuffer(true));
                vao.access(getBuffer(), GL_INT);
            }

            Chunk::~Chunk() {
                delete[] voxel;
            }

            Voxel* const& Chunk::getVoxels() const {
                return voxel;
            }

            Voxel const& Chunk::getVoxel(Maths::Point3D<GLuint> const& p) const {
                return getVoxel(p.getX(), p.getY(), p.getZ());
            }

            Voxel const& Chunk::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return voxel[getVoxelIndex(x, y, z)];
            }

            Voxel const& Chunk::getVoxel(GLuint const& index) const {
                return voxel[index];
            }

            Maths::Point2D<GLint> const& Chunk::getCoord() const {
                return coord;
            }

            GL::IBO const& Chunk::getBuffer() const {
                return buffer;
            }

            GL::VAO const& Chunk::getVAO() const {
                return vao;
            }

            Physics::AABB<GLint> const& Chunk::getBounding() const {
                return bounding;
            }

            GLuint const& Chunk::getLoD() const {
                return loD;
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

            void Chunk::setVoxels(Voxel* const& vox) {
                voxel = vox;
            }

            void Chunk::setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox) {
                setVoxel(p.getX(), p.getY(), p.getZ(), vox);
            }

            void Chunk::setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox) {
                voxel[getVoxelIndex(x, y, z)] = vox;
            }

            void Chunk::setVoxel(GLuint const& index, Voxel const& vox) {
                voxel[index] = vox;
            }

            void Chunk::setCoord(Maths::Point2D<GLint> const& p) {
                coord = p;
            }

            void Chunk::setBuffer(GL::IBO const& buffer) {
                this->buffer = buffer;
            }

            void Chunk::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void Chunk::setBounding(Physics::AABB<GLint> const& box) {
                bounding = box;
            }

            void Chunk::setLoD(GLuint const& value) {
                loD = value;
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

            void Chunk::renderAlone(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Camera::FixedCamera* const& camera) {
                if (camera != 0) {
                    setActive(camera->AABBCollision(getBounding()));
                } else {
                    setActive(true);
                }

                if (isActive()) {
                    glUseProgram(shader.getID());
                        vao.bind();

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "modelview"), 1, GL_TRUE, modelview.value());
                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "projection"), 1, GL_TRUE, projection.value());
                            if (camera != 0) {
                                glUniform3fv(glGetUniformLocation(shader.getID(), "cameraV"), 1, camera->getEye().value());
                            }

                            glDrawElements(GL_TRIANGLES, getBuffer().getNb(), GL_UNSIGNED_INT, 0);

                        vao.unbind();
                    glUseProgram(0);
                }
            }

            void Chunk::render() {
                vao.bind();
                    glDrawElements(GL_TRIANGLES, getBuffer().getNb(), GL_UNSIGNED_INT, 0);
                vao.unbind();
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

                    GLuint voxNumber, voxType, x = 0, y = 0, z = 0;
                    while (dataSize > 0) {
                        data.read(reinterpret_cast<char*> (&voxNumber), 2);
                        data.read(reinterpret_cast<char*> (&voxType), 1);
                        dataSize = dataSize - 3;

                        loadVoxels(x, y, z, voxNumber, voxType);
                    }
                }
                setLoaded(true);
                setLoading(false);
            }

            void Chunk::loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type) {
                GLuint index, n = nb;
                while (n != 0) {
                    index = getVoxelIndex(x, y, z);
                    voxel[index].setType(type);
                    x = x + 1;
                    if (x == SIZE_X) {
                        x = 0;
                        y = y + 1;
                        if (y == SIZE_Y) {
                            y = 0;
                            z = z + 1;
                        }
                    }
                    n = n - 1;
                }
            }

            void Chunk::reload() {
                setLoaded(false);
                setLoading(false);
                setConstructed(false);
                setConstructing(false);
                buffer.reload();
                vao.access(getBuffer(), GL_INT);
                bounding.setCenter(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2);
            }

            void Chunk::writeCompressedData(std::stringstream &data) {
                GLuint x = 0, y = 0, z = 0;
                GLuint currentType = getVoxel(x, y, z).getType(), currentLineSize = 0;
                while (z != SIZE_Z) {
                    if (currentType == static_cast <GLuint> (getVoxel(x, y, z).getType())) {
                        currentLineSize = currentLineSize + 1;
                    } else {
                        data.write(reinterpret_cast<char*> (&currentLineSize), 2);
                        data.write(reinterpret_cast<char*> (&currentType), 1);
                        currentType = getVoxel(x, y, z).getType();
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

            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) {
                return Array::get1DIndexFrom3D(x, y, z, Chunk::SIZE);
            }

        };
    };
