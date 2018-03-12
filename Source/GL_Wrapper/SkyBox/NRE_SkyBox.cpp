
    #include "NRE_SkyBox.hpp"

    namespace NRE {
        namespace GL {

            SkyBox::SkyBox() : id(0) {
            }

            SkyBox::SkyBox(std::string const& path, std::string const& ext) : id(0), xNeg(path + "_Near." + ext),
                                                                                     yNeg(path + "_Left." + ext),
                                                                                     zNeg(path + "_Bottom." + ext),
                                                                                     xPos(path + "_Far." + ext),
                                                                                     yPos(path + "_Right." + ext),
                                                                                     zPos(path + "_Top." + ext),
                                                                                     vertex(true), index(true), vao(true) {
                generateID();
                load();
                free();
            }

            SkyBox::SkyBox(SkyBox const& sb) : id(sb.getID()), xNeg(sb.getXNeg()), yNeg(sb.getYNeg()), zNeg(sb.getZNeg()), xPos(sb.getXPos()), yPos(sb.getYPos()), zPos(sb.getZPos()), vertex(true), index(true), vao(true) {
                fillBuffer();
            }

            SkyBox::~SkyBox() {
                deleteID();
            }

            GLuint const& SkyBox::getID() const {
                return id;
            }

            NRE::Buffer::VertexBuffer const& SkyBox::getVertexBuffer() const {
                return vertex;
            }

            NRE::Buffer::IndexBuffer const& SkyBox::getIndexBuffer() const {
                return index;
            }

            VAO const& SkyBox::getVAO() const {
                return vao;
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

            void SkyBox::setID(GLuint const& id) {
                this->id = id;
            }

            void SkyBox::setVertexBuffer(NRE::Buffer::VertexBuffer const& buf) {
                vertex = buf;
            }

            void SkyBox::setIndexBuffer(NRE::Buffer::IndexBuffer const& buf) {
                index = buf;
            }

            void SkyBox::setVAO(VAO const& vao) {
                this->vao = vao;
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

            void SkyBox::generateID() {
                glGenTextures(1, &id);
            }

            void SkyBox::deleteID() {
                glDeleteTextures(1 ,&id);
            }

            void SkyBox::reload() {
                deleteID();
                generateID();
            }

            void SkyBox::bind() const {
                glBindTexture(GL_TEXTURE_CUBE_MAP, getID());
            }

            void SkyBox::unbind() const {
                glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
            }

            void SkyBox::load() {
                bind();
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, getXNeg().getGLInternalFormat(), getXNeg().getW(), getXNeg().getH(), 0, getXNeg().getGLFormat(), GL_UNSIGNED_BYTE, getXNeg().getPixels());
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, getYNeg().getGLInternalFormat(), getYNeg().getW(), getYNeg().getH(), 0, getYNeg().getGLFormat(), GL_UNSIGNED_BYTE, getYNeg().getPixels());
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, getZNeg().getGLInternalFormat(), getZNeg().getW(), getZNeg().getH(), 0, getZNeg().getGLFormat(), GL_UNSIGNED_BYTE, getZNeg().getPixels());
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, getXPos().getGLInternalFormat(), getXPos().getW(), getXPos().getH(), 0, getXPos().getGLFormat(), GL_UNSIGNED_BYTE, getXPos().getPixels());
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, getYPos().getGLInternalFormat(), getYPos().getW(), getYPos().getH(), 0, getYPos().getGLFormat(), GL_UNSIGNED_BYTE, getYPos().getPixels());
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, getZPos().getGLInternalFormat(), getZPos().getW(), getZPos().getH(), 0, getZPos().getGLFormat(), GL_UNSIGNED_BYTE, getZPos().getPixels());
                    applyFilter();
                    fillBuffer();
                unbind();
            }

            void SkyBox::applyFilter() {
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
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

                vertex.allocateAndFill(sizeof(GLint) * 24 * 3, GL_STATIC_DRAW, vData);
                index.allocateAndFill(NRE::Buffer::IndexBuffer::SIZE * 36, GL_STATIC_DRAW, iData);

                vao.bind();
                    getVertexBuffer().bind();
                        glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 0, 0);
                        glEnableVertexAttribArray(0);
                    getIndexBuffer().bind();
                vao.unbind();
            }

            void SkyBox::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Maths::Point3D<NREfloat> const& eye) {
                modelview.translate(Maths::Vector3D<NREfloat>(eye));
                glUseProgram(shader.getProgramID());
                    getVAO().bind();
                        bind();

                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                        glDepthMask(GL_FALSE);
                        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                        glDepthMask(GL_TRUE);

                        unbind();
                    getVAO().unbind();
                glUseProgram(0);
                modelview.translate(Maths::Vector3D<NREfloat>(-eye));
            }

        };
    };
