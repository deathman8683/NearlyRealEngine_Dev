
    #include "NRE_SkyBox.hpp"

    #include <stb_image.h>

    namespace NRE {
        namespace GL {

            GLenum SkyBox::TYPE = GL_FLOAT;
            GLuint SkyBox::SIZE = 1024;

            SkyBox::SkyBox() {
            }

            SkyBox::SkyBox(std::string const& path) : TextureBuffer::TextureBuffer(true), capture(SIZE, SIZE), cubeMap(0), buffer(true), vao(true) {
                allocate(true);
                cubeMap = new Texture2D();

                cubeMap->setType(GL_FLOAT);
                cubeMap->setGLInternalFormat(GL_RGB16F);
                cubeMap->setGLFormat(GL_RGB);
                stbi_set_flip_vertically_on_load(true);
                int w, h, nrComponents;
                float *data = stbi_loadf(path.c_str(), &w, &h, &nrComponents, 0);
                cubeMap->setGLW(w);
                cubeMap->setGLH(h);
                cubeMap->bind();
                    cubeMap->TextureBuffer::allocateAndFill(GL_TEXTURE_2D, 0, cubeMap->getGLInternalFormat(), cubeMap->getGLW(), cubeMap->getGLH(), cubeMap->getGLFormat(), data, true);
                cubeMap->unbind();
                cubeMap->setAllocated(true);

                std::vector<GLenum> format, type;
                std::vector<GLint> internalFormat;
                format.push_back(GL_RGBA);
                type.push_back(GL_FLOAT);
                internalFormat.push_back(GL_RGBA16F);
                capture.allocateColorBuffer(1, format, internalFormat, type);
                capture.allocateRenderBuffer();
                capture.bind();
                if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
                    std::cout << "ERROR" << std::endl;
                }
                capture.unbind();
                fillBuffer();
            }

            SkyBox::SkyBox(SkyBox const& sb) : TextureBuffer::TextureBuffer(sb), BufferObject::BufferObject(sb), cubeMap(sb.getCubeMap()), buffer(true), vao(true) {
            }

            SkyBox::~SkyBox() {
                delete cubeMap;
            }

            FBO const& SkyBox::getCapture() const {
                return capture;
            }

            Texture2D* const& SkyBox::getCubeMap() const {
                return cubeMap;
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

            void SkyBox::setCapture(FBO const& buf) {
                capture = buf;
            }

            void SkyBox::setCubeMap(Texture2D* const& t) {
                cubeMap = t;
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
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, false);
                    TextureBuffer::allocate(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGBA16F, SIZE, SIZE, GL_RGBA, callFilter);
                unbind();
                setAllocated(true);
            }

            void SkyBox::applyFilter() const {
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
            }

            void SkyBox::access() const {
                TextureBuffer::access(GL_TEXTURE_CUBE_MAP);
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

            void SkyBox::captureCubeMap(Renderer::Shader const& shader) {
                Maths::Matrix4x4<NREfloat> projection;
                projection.projection(90.0, 1.0, 0.1, 10.0);

                Maths::Matrix4x4<NREfloat> modelviews[6];
                modelviews[1].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(1.0,  0.0,  0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0));
                modelviews[2].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(-1.0, 0.0,  0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0));
                modelviews[3].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(0.0,  1.0,  0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0));
                modelviews[4].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(0.0, -1.0,  0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0));
                modelviews[5].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(0.0,  0.0,  1.0), Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));
                modelviews[6].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(0.0,  0.0, -1.0), Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                glUseProgram(shader.getID());
                    glUniform1i(glGetUniformLocation(shader.getID(), "skyBox"), 0);
                    glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "projection"), 1, GL_TRUE, projection.value());
                    cubeMap->bind();

                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "modelviews"), 1, GL_TRUE, modelviews[i].value());
                            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_NEGATIVE_X + i, getID(), 0);

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                glUseProgram(0);
            }

            void SkyBox::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Maths::Point3D<NREfloat> const& eye) {
                MVP.translate(Maths::Vector3D<NREfloat>(eye));
                glUseProgram(shader.getID());
                    getVAO().bind();
                        bind();

                        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "MVP"), 1, GL_TRUE, MVP.value());
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
