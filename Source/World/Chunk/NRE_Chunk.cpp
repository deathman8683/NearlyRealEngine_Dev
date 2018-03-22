
    #include "NRE_Chunk.hpp"

    namespace NRE {
        namespace World {

            GLuint Chunk::SIZE_X = 16;
            GLuint Chunk::SIZE_Y = 16;
            GLuint Chunk::SIZE_Z = 128;
            Maths::Vector3D<GLuint> Chunk::SIZE = Maths::Vector3D<GLuint>(SIZE_X, SIZE_Y, SIZE_Z);

            Chunk::Chunk() : voxel(0) {
            }

            Chunk::Chunk(bool const& generateID) : Chunk(Maths::Point2D<GLint>(0, 0), generateID) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID) : voxel(0), coord(coord), buffer(generateID), vao(generateID), bounding(Maths::Point3D<GLint>(coord.getX() * SIZE_X, coord.getY() * SIZE_Y, 0) + SIZE / 2, Maths::Vector3D<GLint>(SIZE / 2)), active(true) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
                buffer.push_back(new GL::ColorBuffer(generateID));
                buffer.push_back(new GL::NormalBuffer(generateID));
                vao.access(getBuffer(), GL_INT);
            }

            Chunk::Chunk(Chunk const& c) : voxel(0), buffer(true), vao(true), bounding(c.getBounding()), active(c.isActive()) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
                memcpy(voxel, c.getVoxels(), sizeof(Voxel));
                buffer.push_back(new GL::ColorBuffer(true));
                buffer.push_back(new GL::NormalBuffer(true));
                vao.access(getBuffer(), GL_INT);
            }

            Chunk::~Chunk() {
                save();
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

            bool const& Chunk::isActive() const {
                return active;
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

            void Chunk::setActive(bool const& state) {
                active = state;
            }

            void Chunk::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Camera::FixedCamera const& camera) {
                NREfloat eye[3] = {camera.getEye().getX(), camera.getEye().getY(), camera.getEye().getZ()};

                setActive(camera.AABBCollision(getBounding()));

                if (isActive()) {
                    glUseProgram(shader.getID());
                        vao.bind();

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "MVP"), 1, GL_TRUE, MVP.value());
                            glUniform3fv(glGetUniformLocation(shader.getID(), "cameraV"), 1, eye);

                            glDrawElements(GL_TRIANGLES, getBuffer().getNb(), GL_UNSIGNED_INT, 0);

                        vao.unbind();
                    glUseProgram(0);
                }
            }

            void Chunk::save() {
                std::ofstream chunkFile;
                std::ostringstream xStr, yStr;
                std::string chunkName;
                xStr << getCoord().getX();
                yStr << getCoord().getY();
                chunkName = "Data/Chunk/c." + xStr.str() + "." + yStr.str() + ".dat";
                chunkFile.open(chunkName, std::ios::out);
                if (chunkFile.is_open()) {
                    GLuint x = 0, y = 0, z = 0;
                    GLuint currentType = getVoxel(x, y, z).getType(), currentLineSize = 0;
                    while (z != SIZE_Z) {
                        if (currentType == static_cast <GLuint> (getVoxel(x, y, z).getType())) {
                            currentLineSize = currentLineSize + 1;
                        } else {
                            chunkFile << currentLineSize << " " << currentType << '\n';
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

                    chunkFile << currentLineSize << " " << currentType;
                    chunkFile.close();
                }
            }

            void Chunk::load(World * w) {
                std::ifstream chunkFile;
                std::ostringstream xStr, yStr;
                std::string chunkName;
                xStr << getCoord().getX();
                yStr << getCoord().getY();
                chunkName = "Data/Chunk/c." + xStr.str() + "." + yStr.str() + ".dat";
                chunkFile.open(chunkName, std::ios::in);
                if (chunkFile.is_open()) {
                    GLuint x = 0, y = 0, z = 0;
                    GLuint voxNumber = 0, voxType = 0;
                    std::string line;
                    while (!chunkFile.eof()) {
                        std::getline(chunkFile, line);
                        std::istringstream parser(line);
                        parser >> voxNumber >> voxType;

                        loadVoxels(x, y, z, voxNumber, voxType);
                    }
                } else {
                    createProceduralTerrain(w);
                    chunkFile.open(chunkName, std::ios::trunc | std::ios::out);
                    chunkFile.close();
                }
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

            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) {
                return Array::get1DIndexFrom3D(x, y, z, Chunk::SIZE);
            }

        };
    };
