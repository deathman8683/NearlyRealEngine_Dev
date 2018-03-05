
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

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID) : voxel(0), buffer(generateID), vao(generateID) {
                voxel = new Voxel*[SIZE_X * SIZE_Y * SIZE_Z];
                for (GLuint i = 0; i < SIZE_X * SIZE_Y * SIZE_Z; i = i + 1) {
                    voxel[i] = new NRE::Voxel::Grass;
                }

                vao.access(getBuffer(), GL_INT);
            }

            Chunk::Chunk(Chunk const& c) : voxel(0), buffer(true), vao(true) {
                voxel = new Voxel*[SIZE_X * SIZE_Y * SIZE_Z];
                memcpy(voxel, c.getVoxels(), sizeof(Voxel));

                vao.access(getBuffer(), GL_INT);
            }

            Chunk::~Chunk() {
                save();
                for (GLuint i = 0; i < SIZE_X * SIZE_Y * SIZE_Z; i = i + 1) {
                    delete voxel[i];
                }
                delete[] voxel;
            }

            Voxel** const& Chunk::getVoxels() const {
                return voxel;
            }

            Voxel* const& Chunk::getVoxel(Maths::Point3D<GLuint> const& p) const {
                return getVoxel(p.getX(), p.getY(), p.getZ());
            }

            Voxel* const& Chunk::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return voxel[getVoxelIndex(x, y, z)];
            }

            Voxel* const& Chunk::getVoxel(GLuint const& index) const {
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

            void Chunk::setVoxels(Voxel** const& vox) {
                voxel = vox;
            }

            void Chunk::setVoxel(Maths::Point3D<GLuint> const& p, Voxel* const& vox) {
                setVoxel(p.getX(), p.getY(), p.getZ(), vox);
            }

            void Chunk::setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel* const& vox) {
                voxel[getVoxelIndex(x, y, z)] = vox;
            }

            void Chunk::setVoxel(GLuint const& index, Voxel* const& vox) {
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

            void Chunk::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection) {
                glUseProgram(shader.getProgramID());
                    vao.bind();

                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                        glDrawElements(GL_TRIANGLES, getBuffer().getNb(), GL_UNSIGNED_INT, 0);

                    vao.unbind();
                glUseProgram(0);
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
                    GLuint currentType = getVoxel(x, y, z)->getType(), currentLineSize = 0;
                    while (z != SIZE_Z) {
                        if (currentType == static_cast <GLuint> (getVoxel(x, y, z)->getType())) {
                            currentLineSize = currentLineSize + 1;
                        } else {
                            chunkFile << currentLineSize << "_" << currentType << "-" << getVoxel(x, y, z)->getType();
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

                    chunkFile << currentLineSize << "_" << currentType << "-";
                    chunkFile.close();
                }
            }



            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) {
                return Array::get1DIndexFrom3D(x, y, z, Chunk::SIZE);
            }

        };
    };
