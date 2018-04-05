
    #include "NRE_SkyBox.hpp"

    #define STB_IMAGE_IMPLEMENTATION

    #include <stb_image.h>

    namespace NRE {
        namespace GL {

            GLenum SkyBox::TYPE = GL_FLOAT;
            GLuint SkyBox::SIZE = 128;

            SkyBox::SkyBox() {
            }

            SkyBox::SkyBox(std::string const& path) : CubeMap::CubeMap(true), cubeMap(0), irradianceMap(0), buffer(true), vao(true) {
                glGenTextures(1, &irradianceMap);
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
                    cubeMap->TextureBuffer::allocateAndFill(0, cubeMap->getGLInternalFormat(), cubeMap->getGLW(), cubeMap->getGLH(), cubeMap->getGLFormat(), data, true);
                cubeMap->unbind();
                cubeMap->setAllocated(true);

                stbi_image_free(data);
                fillBuffer();
            }

            SkyBox::SkyBox(SkyBox const& sb) : CubeMap::CubeMap(sb), BufferObject::BufferObject(sb), cubeMap(sb.getCubeMap()), buffer(true), vao(true) {
            }

            SkyBox::~SkyBox() {
                delete cubeMap;
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

            GLenum const SkyBox::getTarget() const {
                return GL_TEXTURE_CUBE_MAP;
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

            void SkyBox::allocate(bool const& callFilter) {
                CubeMap::allocate(0, GL_RGB16F, SIZE, SIZE, GL_RGB, callFilter);
                glBindTexture(GL_TEXTURE_CUBE_MAP, irradianceMap);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB16F, 32, 32, 0, GL_RGB, GL_FLOAT, 0);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
                setAllocated(true);
            }

            void SkyBox::applyFilter() const {
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
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
                    2, 0, 7, 7, 5, 2,
                    1, 0, 2, 2, 3, 1,
                    7, 6, 4, 4, 5, 7,
                    1, 3, 4, 4, 6, 1,
                    2, 5, 4, 4, 3, 2,
                    0, 1, 7, 7, 1, 6,
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);

                buffer.allocateAndFill(sizeof(GLint), 24, 36, GL_STATIC_DRAW, data, iData);
                vao.access(buffer, GL_INT, true);
            }

            void SkyBox::captureCubeMap(Renderer::Shader const& captureShader, Renderer::Shader const& irradianceShader) {
                FBO capture(SIZE, SIZE);
                RenderBuffer* tmp = new RenderBuffer(GL_DEPTH_COMPONENT24, capture.getSize().getW(), capture.getSize().getH(), true);
                capture.setDepthBuffer(tmp);
                capture.attachDepthBuffer(GL_DEPTH_ATTACHMENT);

                Maths::Matrix4x4<NREfloat> projection;
                projection.projection(70.0, 1.0, 0.1, 10.0);

                Maths::Matrix4x4<NREfloat> modelviews[6];
                modelviews[0].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>( 1.0,  0.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[1].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>(-1.0,  0.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[2].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>( 0.0,  0.0,  -1.0), Maths::Vector3D<NREfloat>(0.0,  1.0,  0.0));
                modelviews[3].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>( 0.0,  0.0,  1.0), Maths::Vector3D<NREfloat>(0.0, -1.0,  0.0));
                modelviews[4].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>( 0.0,  1.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[5].lookAt(Maths::Point3D<NREfloat>(0.0, 0.0, 0.0), Maths::Point3D<NREfloat>( 0.0, -1.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));

                glUseProgram(captureShader.getID());
                    glUniform1i(glGetUniformLocation(captureShader.getID(), "skyBox"), 0);
                    glUniformMatrix4fv(glGetUniformLocation(captureShader.getID(), "projection"), 1, GL_TRUE, projection.value());
                    cubeMap->bind();

                    glViewport(0, 0, SIZE, SIZE);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(captureShader.getID(), "modelview"), 1, GL_TRUE, modelviews[i].value());
                            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, getID(), 0);

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                glUseProgram(0);

                capture.bind();
                    tmp->allocate(GL_DEPTH_COMPONENT24, 32, 32);
                capture.unbind();

                glUseProgram(irradianceShader.getID());
                    glUniform1i(glGetUniformLocation(irradianceShader.getID(), "skyBox"), 0);
                    glUniformMatrix4fv(glGetUniformLocation(irradianceShader.getID(), "projection"), 1, GL_TRUE, projection.value());
                    bind();

                    glViewport(0, 0, 32, 32);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(irradianceShader.getID(), "modelview"), 1, GL_TRUE, modelviews[i].value());
                            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, irradianceMap, 0);

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                glUseProgram(0);
            }

            void SkyBox::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview) {
                Maths::Matrix4x4<NREfloat> MVP = projection * Maths::Matrix4x4<NREfloat>(Maths::Matrix3x3<NREfloat>(modelview));
                glDepthFunc(GL_LEQUAL);
                glUseProgram(shader.getID());
                    getVAO().bind();
                            bind();

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "MVP"), 1, GL_TRUE, MVP.value());
                            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

                            unbind();
                    getVAO().unbind();
               glUseProgram(0);
               glDepthFunc(GL_LESS);
            }

        };
    };
