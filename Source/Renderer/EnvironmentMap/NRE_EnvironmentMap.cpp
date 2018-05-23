
    #include "NRE_EnvironmentMap.hpp"

    #include <stb_image.h>

    namespace NRE {
        namespace Renderer {

            GLuint EnvironmentMap::SIZE = 1024;

            EnvironmentMap::EnvironmentMap(std::string const& path) : brdfLUT(SIZE, SIZE, GL_RG, GL_RG16F, GL_FLOAT), buffer(true), vao(true) {
                fillBuffer();
                allocate();
                capture(path);
            }

            EnvironmentMap::EnvironmentMap(EnvironmentMap && map) : map(std::move(map.map)), irradianceMap(std::move(map.irradianceMap)), prefilterMap(std::move(map.prefilterMap)), brdfLUT(std::move(map.brdfLUT)), buffer(std::move(map.buffer)), vao(std::move(map.vao)) {
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

            GL::Texture2D const& EnvironmentMap::getBRDFLUT() const {
                return brdfLUT;
            }

            GL::IBO const& EnvironmentMap::getBuffer() const {
                return buffer;
            }

            GL::VAO const& EnvironmentMap::getVAO() const {
                return vao;
            }

            void EnvironmentMap::allocate() {
                map.allocate(SIZE, SIZE, true);
                irradianceMap.allocate(32, 32, true);
                prefilterMap.allocate(256, 256, false);
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
                data.push_back(iData);

                buffer.allocateAndFill(sizeof(GLint), 24, 36, GL_STATIC_DRAW, data);
                vao.access(buffer, GL_INT, true);
            }

            void EnvironmentMap::capture(std::string const& path) {

                const CaptureShader*    captureShader    = static_cast <const CaptureShader*>    (ShadersManager::getShader("Capture"));
                const IrradianceShader* irradianceShader = static_cast <const IrradianceShader*> (ShadersManager::getShader("Irradiance"));
                const PrefilterShader*  prefilterShader  = static_cast <const PrefilterShader*>  (ShadersManager::getShader("Prefilter"));
                const BRDFShader*       brdfShader       = static_cast <const BRDFShader*>       (ShadersManager::getShader("BRDF"));


                int w, h, nrComponents;
                stbi_set_flip_vertically_on_load(true);
                float *data = stbi_loadf(path.c_str(), &w, &h, &nrComponents, 0);

                GL::Texture2D cubeMap(w, h, GL_RGB, GL_RGB16F, GL_FLOAT);
                cubeMap.update(0, 0, data);

                stbi_image_free(data);

                GL::FBO capture(SIZE, SIZE);
                GL::RenderBuffer* tmp = new GL::RenderBuffer(GL_DEPTH_COMPONENT24, capture.getSize().getW(), capture.getSize().getH(), true);
                capture.setDepthBuffer(tmp);
                capture.attachDepthBuffer(GL_DEPTH_ATTACHMENT);

                Maths::Matrix4x4<NREfloat> modelviews[6];
                modelviews[0].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>( 1.0,  0.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[1].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>(-1.0,  0.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[2].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>( 0.0,  0.0,  -1.0), Maths::Vector3D<NREfloat>(0.0,  1.0,  0.0));
                modelviews[3].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>( 0.0,  0.0,  1.0), Maths::Vector3D<NREfloat>(0.0, -1.0,  0.0));
                modelviews[4].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>( 0.0,  1.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));
                modelviews[5].lookAt(Maths::Point3D<NREfloat>(0.0), Maths::Point3D<NREfloat>( 0.0, -1.0,  0.0), Maths::Vector3D<NREfloat>(0.0,  0.0,  1.0));

                captureShader->bind();
                    cubeMap.bind();

                    glViewport(0, 0, SIZE, SIZE);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            captureShader->sendModelview(modelviews[i]);
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, map.getID());

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                captureShader->unbind();

                capture.bind();
                    tmp->allocate(GL_DEPTH_COMPONENT24, 32, 32);
                capture.unbind();

                irradianceShader->bind();
                    map.bind();

                    glViewport(0, 0, 32, 32);
                    capture.bind();
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            irradianceShader->sendModelview(modelviews[i]);
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, irradianceMap.getID());

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    capture.unbind();
                irradianceShader->unbind();

                modelviews[0].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));
                modelviews[1].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));
                modelviews[2].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));
                modelviews[3].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));
                modelviews[4].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));
                modelviews[5].rotate(90.0, Maths::Vector3D<NREfloat>(-1.0, 0.0, 0.0));

                prefilterShader->bind();
                    map.bind();

                    capture.bind();
                    GLuint maxMipLevels = 5;
                    for (GLuint mip = 0; mip < maxMipLevels; mip = mip + 1) {
                        GLuint mipWidth = 256 * std::pow(0.5, mip);
                        GLuint mipHeight = 256 * std::pow(0.5, mip);
                        tmp->allocate(GL_DEPTH_COMPONENT24, mipWidth, mipHeight);

                        glViewport(0, 0, mipWidth, mipHeight);

                        float roughness = (float)mip / (float)(maxMipLevels - 1);
                        prefilterShader->sendRoughness(roughness);
                        for (GLuint i = 0; i < 6; i = i + 1) {
                            prefilterShader->sendModelview(modelviews[i]);
                            capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, prefilterMap.getID(), mip);

                            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                            getVAO().bind();
                                glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
                            getVAO().unbind();
                        }
                    }
                    capture.unbind();
                prefilterShader->unbind();

                capture.bind();
                    tmp->allocate(GL_DEPTH_COMPONENT24, SIZE, SIZE);
                    capture.attachBuffer(GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, brdfLUT.getID());

                    glViewport(0, 0, SIZE, SIZE);
                    brdfShader->bind();
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                        renderQuad();
                    brdfShader->unbind();
                capture.unbind();
            }

            void EnvironmentMap::render(Maths::Matrix4x4<NREfloat> const& projection, Maths::Matrix4x4<NREfloat> const& modelview) const {

                const SkyBoxShader* shader = static_cast <const SkyBoxShader*> (ShadersManager::getShader("SkyBox"));

                Maths::Matrix4x4<NREfloat> MVP = projection * Maths::Matrix4x4<NREfloat>(Maths::Matrix3x3<NREfloat>(modelview));
                glDepthFunc(GL_LEQUAL);
                shader->bind();
                    getVAO().bind();
                            map.bind();

                            shader->sendMVP(MVP);
                            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

                            map.unbind();
                    getVAO().unbind();
                shader->unbind();
               glDepthFunc(GL_LESS);
            }

            void EnvironmentMap::renderQuad() {
                GLint vData[12] = {
                    -1, 1, 0,
                    -1, -1, 0,
                    1, 1, 0,
                    1, -1, 0
                };

                GLfloat uvData[8] = {
                    0, 1,
                    0, 0,
                    1, 1,
                    1, 0
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);
                data.push_back(uvData);

                GL::VBO quadVBO(true);
                quadVBO.push_back(new GL::UVBuffer(true));

                quadVBO.allocateAndFill(sizeof(GLint), 12, GL_STATIC_DRAW, data);

                GL::VAO quadVAO(true);
                quadVAO.access(quadVBO, GL_INT, true);
                quadVAO.bind();
                    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                quadVAO.unbind();
            }

            EnvironmentMap& EnvironmentMap::operator=(EnvironmentMap && map) {
                this->map = std::move(map.map);
                irradianceMap = std::move(map.irradianceMap);
                prefilterMap = std::move(map.prefilterMap);
                brdfLUT = std::move(map.brdfLUT);
                buffer = std::move(map.buffer);
                vao = std::move(map.vao);
                return *this;
            }

        };
    };
