
    #include "NRE_EnvironmentMap.hpp"

    #include <stb_image.h>

    namespace NRE {
        namespace Renderer {

            GLuint EnvironmentMap::SIZE = 1024;

            EnvironmentMap::EnvironmentMap() {
            }

            EnvironmentMap::EnvironmentMap(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader) : buffer(true), vao(true) {
                fillBuffer();
                allocate();
                capture(path, captureShader, irradianceShader, prefilterShader);
            }

            EnvironmentMap::EnvironmentMap(EnvironmentMap const& map) : map(map.getMap()), irradianceMap(map.getIrradianceMap()), prefilterMap(map.getPrefilterMap()), buffer(true), vao(true) {
                fillBuffer();
            }

            EnvironmentMap::~EnvironmentMap() {
            }

            GL::SkyBox const& EnvironmentMap::getMap() const {
                return map;
            }

            GL::SkyBox const& EnvironmentMap::getIrradianceMap() const {
                return irradianceMap;
            }

            GL::SkyBox const& EnvironmentMap::getPrefilterMap() const {
                return prefilterMap;
            }

            GL::IBO const& EnvironmentMap::getBuffer() const {
                return buffer;
            }

            GL::VAO const& EnvironmentMap::getVAO() const {
                return vao;
            }

            void EnvironmentMap::setMap(GL::SkyBox const& map) {
                this->map = map;
            }

            void EnvironmentMap::setIrradianceMap(GL::SkyBox const& map) {
                irradianceMap = map;
            }

            void EnvironmentMap::setPrefilterMap(GL::SkyBox const& map) {
                prefilterMap = map;
            }

            void EnvironmentMap::setBuffer(GL::IBO const& buf) {
                buffer = buf;
            }

            void EnvironmentMap::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void EnvironmentMap::allocate() {
                map.allocate(SIZE, SIZE, true);
                irradianceMap.allocate(32, 32, true);
                prefilterMap.allocate(128, 128, false);
                prefilterMap.bind();
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

                    glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
                prefilterMap.unbind();
            }

            void EnvironmentMap::fillBuffer() {
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

            void EnvironmentMap::capture(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader) {
                GL::Texture2D cubeMap;

                cubeMap.setType(GL_FLOAT);
                cubeMap.setGLInternalFormat(GL_RGB16F);
                cubeMap.setGLFormat(GL_RGB);

                stbi_set_flip_vertically_on_load(true);

                int w, h, nrComponents;
                float *data = stbi_loadf(path.c_str(), &w, &h, &nrComponents, 0);
                cubeMap.setGLW(w);
                cubeMap.setGLH(h);
                cubeMap.TextureBuffer::allocateAndFill(0, cubeMap.getGLInternalFormat(), cubeMap.getGLW(), cubeMap.getGLH(), cubeMap.getGLFormat(), data, true);
                cubeMap.setAllocated(true);

                stbi_image_free(data);

                GL::FBO capture(SIZE, SIZE);
                GL::RenderBuffer* tmp = new GL::RenderBuffer(GL_DEPTH_COMPONENT24, capture.getSize().getW(), capture.getSize().getH(), true);
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
                    cubeMap.bind();

                    glViewport(0, 0, SIZE, SIZE);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(captureShader.getID(), "modelview"), 1, GL_TRUE, modelviews[i].value());
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, map.getID());

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
                    map.bind();

                    glViewport(0, 0, 32, 32);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(irradianceShader.getID(), "modelview"), 1, GL_TRUE, modelviews[i].value());
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, irradianceMap.getID());

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                glUseProgram(0);

                glUseProgram(prefilterShader.getID());
                    glUniform1i(glGetUniformLocation(prefilterShader.getID(), "skyBox"), 0);
                    glUniformMatrix4fv(glGetUniformLocation(prefilterShader.getID(), "projection"), 1, GL_TRUE, projection.value());
                    map.bind();

                    capture.bind();
                    GLuint maxMipLevels = 5;
                    for (GLuint mip = 0; mip < maxMipLevels; mip = mip + 1) {
                        GLuint mipWidth = 128 * std::pow(0.5, mip);
                        GLuint mipHeight = 128 * std::pow(0.5, mip);
                        tmp->allocate(GL_DEPTH_COMPONENT24, mipWidth, mipHeight);

                        glViewport(0, 0, mipWidth, mipHeight);

                        float roughness = (float)mip / (float)(maxMipLevels - 1);
                        glUniform1f(glGetUniformLocation(prefilterShader.getID(), "roughness"), roughness);
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            glUniformMatrix4fv(glGetUniformLocation(prefilterShader.getID(), "modelview"), 1, GL_TRUE, modelviews[i].value());
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, prefilterMap.getID(), mip);

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    }
                    capture.unbind();
                glUseProgram(0);
            }

            void EnvironmentMap::render(Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview) {
                Maths::Matrix4x4<NREfloat> MVP = projection * Maths::Matrix4x4<NREfloat>(Maths::Matrix3x3<NREfloat>(modelview));
                glDepthFunc(GL_LEQUAL);
                glUseProgram(shader.getID());
                    getVAO().bind();
                            prefilterMap.bind();

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "MVP"), 1, GL_TRUE, MVP.value());
                            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

                            prefilterMap.unbind();
                    getVAO().unbind();
               glUseProgram(0);
               glDepthFunc(GL_LESS);
            }

        };
    };
