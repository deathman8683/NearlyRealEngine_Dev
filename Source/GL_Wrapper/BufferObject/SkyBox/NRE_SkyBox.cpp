
    #include "NRE_SkyBox.hpp"

    namespace NRE {
        namespace GL {

            GLenum SkyBox::TYPE = GL_UNSIGNED_BYTE;

            SkyBox::SkyBox() {
            }

            SkyBox::SkyBox(std::string const& path, std::string const& ext) : TextureBuffer::TextureBuffer(true),
                                                                              xNeg(path + "_Near." + ext),
                                                                              yNeg(path + "_Left." + ext),
                                                                              zNeg(path + "_Bottom." + ext),
                                                                              xPos(path + "_Far." + ext),
                                                                              yPos(path + "_Right." + ext),
                                                                              zPos(path + "_Top." + ext),
                                                                              buffer(true), vao(true) {
                allocateAndFill(true);
                fillBuffer();
            }

            SkyBox::SkyBox(SkyBox const& sb) : TextureBuffer::TextureBuffer(sb), BufferObject::BufferObject(sb), xNeg(sb.getXNeg()), yNeg(sb.getYNeg()), zNeg(sb.getZNeg()), xPos(sb.getXPos()), yPos(sb.getYPos()), zPos(sb.getZPos()), buffer(true), vao(true) {
                fillBuffer();
            }

            SkyBox::~SkyBox() {
                free();
            }

            SDL::Surface const& SkyBox::getXNeg() const {
                return xNeg;
            }

            SDL::Surface const& SkyBox::getYNeg() const {
                return yNeg;
            }

            SDL::Surface const& SkyBox::getZNeg() const {
                return zNeg;
            }

            SDL::Surface const& SkyBox::getXPos() const {
                return xPos;
            }

            SDL::Surface const& SkyBox::getYPos() const {
                return yPos;
            }

            SDL::Surface const& SkyBox::getZPos() const {
                return zPos;
            }

            IBO const& SkyBox::getBuffer() const {
                return buffer;
            }

            VAO const& SkyBox::getVAO() const {
                return vao;
            }

            GLenum const SkyBox::getType() const {
                return TYPE;
            }

            void SkyBox::setXNeg(SDL::Surface const& t) {
                xNeg = t;
            }

            void SkyBox::setYNeg(SDL::Surface const& t) {
                yNeg = t;
            }

            void SkyBox::setZNeg(SDL::Surface const& t) {
                zNeg = t;
            }

            void SkyBox::setXPos(SDL::Surface const& t) {
                xPos = t;
            }

            void SkyBox::setYPos(SDL::Surface const& t) {
                yPos = t;
            }

            void SkyBox::setZPos(SDL::Surface const& t) {
                zPos = t;
            }

            void SkyBox::setBuffer(IBO const& buf) {
                buffer = buf;
            }

            void SkyBox::setVAO(VAO const& vao) {
                this->vao = vao;
            }

            void SkyBox::bind() const {
                TextureBuffer::bind(GL_TEXTURE_CUBE_MAP);
            }

            void SkyBox::unbind() const {
                TextureBuffer::unbind(GL_TEXTURE_CUBE_MAP);
            }

            void SkyBox::allocate(bool const& callFilter) {
                bind();
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, getXNeg().getGLInternalFormat(), getXNeg().getW(), getXNeg().getH(), getXNeg().getGLFormat(), false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, getYNeg().getGLInternalFormat(), getYNeg().getW(), getYNeg().getH(), getYNeg().getGLFormat(), false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, getZNeg().getGLInternalFormat(), getZNeg().getW(), getZNeg().getH(), getZNeg().getGLFormat(), false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, getXPos().getGLInternalFormat(), getXPos().getW(), getXPos().getH(), getXPos().getGLFormat(), false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, getYPos().getGLInternalFormat(), getYPos().getW(), getYPos().getH(), getYPos().getGLFormat(), false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, getZPos().getGLInternalFormat(), getZPos().getW(), getZPos().getH(), getZPos().getGLFormat(), callFilter);
                unbind();
                setAllocated(true);
            }

            void SkyBox::update(std::vector<GLint> const& xOffset, std::vector<GLint> const& yOffset, std::vector<GLsizei> const& w, std::vector<GLsizei> const& h, std::vector<GLenum> const& format, std::vector<GLvoid*> const& data) const {
                bind();
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, xOffset[0], yOffset[0], w[0], h[0], format[0], data[0]);
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, xOffset[1], yOffset[1], w[1], h[1], format[1], data[1]);
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, xOffset[2], yOffset[2], w[2], h[2], format[2], data[2]);
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, xOffset[3], yOffset[3], w[3], h[3], format[3], data[3]);
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, xOffset[4], yOffset[4], w[4], h[4], format[4], data[4]);
                    TextureBuffer::update(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, xOffset[5], yOffset[5], w[5], h[5], format[5], data[5]);
                unbind();
            }

            void SkyBox::allocateAndFill(bool const& callFilter) {
                bind();
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, getXNeg().getGLInternalFormat(), getXNeg().getW(), getXNeg().getH(), getXNeg().getGLFormat(), getXNeg().getPixels(), false);
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, getYNeg().getGLInternalFormat(), getYNeg().getW(), getYNeg().getH(), getYNeg().getGLFormat(), getYNeg().getPixels(), false);
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, getZNeg().getGLInternalFormat(), getZNeg().getW(), getZNeg().getH(), getZNeg().getGLFormat(), getZNeg().getPixels(), false);
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, getXPos().getGLInternalFormat(), getXPos().getW(), getXPos().getH(), getXPos().getGLFormat(), getXPos().getPixels(), false);
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, getYPos().getGLInternalFormat(), getYPos().getW(), getYPos().getH(), getYPos().getGLFormat(), getYPos().getPixels(), false);
                    TextureBuffer::allocateAndFill(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, getZPos().getGLInternalFormat(), getZPos().getW(), getZPos().getH(), getZPos().getGLFormat(), getZPos().getPixels(), callFilter);
                unbind();
                setAllocated(true);
                free();
            }

            void SkyBox::applyFilter() const {
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
            }

            void SkyBox::access() const {
                TextureBuffer::access(GL_TEXTURE_CUBE_MAP);
            }

            void SkyBox::free() {
                xNeg.free();
                yNeg.free();
                zNeg.free();
                xPos.free();
                yPos.free();
                zPos.free();
            }

            void SkyBox::fillBuffer() {
                GLint vData[24] = {
                    -1, -1, -1,
                    -1, -1, 1,
                    -1, 1, -1,
                    -1, 1, 1,
                    1, 1, 1,
                    1, 1, -1,
                    1, -1, 1,
                    1, -1, -1
                };

                GLuint iData[36] = {
                    2, 1, 0, 1, 2, 3,
                    4, 5, 6, 7, 6, 5,
                    0, 1, 7, 6, 7, 1,
                    5, 3, 2, 3, 5, 4,
                    3, 6, 1, 6, 3, 4,
                    0, 7, 2, 5, 2, 7
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);

                buffer.allocateAndFill(sizeof(GLint), 24, 36, GL_STATIC_DRAW, data, iData);
                vao.access(buffer, GL_INT, true);
            }

            void SkyBox::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Maths::Point3D<NREfloat> const& eye) {
                MVP.translate(Maths::Vector3D<NREfloat>(eye));
                glUseProgram(shader.getProgramID());
                    getVAO().bind();
                        bind();

                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "MVP"), 1, GL_TRUE, MVP.value());

                        glDepthMask(GL_FALSE);
                        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                        glDepthMask(GL_TRUE);

                        unbind();
                    getVAO().unbind();
                glUseProgram(0);
                MVP.translate(Maths::Vector3D<NREfloat>(-eye));
            }

        };
    };
