
    #include "NRE_DeferredRenderer.hpp"

    namespace NRE {
        namespace Renderer {

            DeferredRenderer::DeferredRenderer() {
            }

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : gBuffer(size.getW(), size.getH()), shadowMap(size.getW(), size.getH()), buffer(true), vao(true) {
                std::vector<GLenum> format, type;
                std::vector<GLint> internalFormat;
                format.push_back(GL_RGBA);
                format.push_back(GL_RGBA);
                type.push_back(GL_UNSIGNED_BYTE);
                type.push_back(GL_FLOAT);
                internalFormat.push_back(GL_RGBA);
                internalFormat.push_back(GL_RGBA16F);
                gBuffer.allocateColorBuffer(2, format, internalFormat, type);
                gBuffer.setDepthBuffer(new GL::Texture2D(gBuffer.getSize().getW(), gBuffer.getSize().getH(), GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT32F, GL_FLOAT));
                gBuffer.attachDepthBuffer(GL_DEPTH_ATTACHMENT);

                shadowMap.setDepthBuffer(new GL::RenderBuffer(GL_DEPTH_COMPONENT32F, shadowMap.getSize().getW(), shadowMap.getSize().getH(), true));
                shadowMap.attachDepthBuffer(GL_DEPTH_ATTACHMENT);
                shadowMap.getDepthBuffer()->clampToBorder(Maths::Vector4D<NREfloat>(1.0, 1.0, 1.0, 1.0));

                gBuffer.bind();
                if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
                    std::cout << "ERROR 1" << std::endl;
                }
                gBuffer.unbind();
                shadowMap.bind();
                if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
                    std::cout << "ERROR 2" << std::endl;
                }
                shadowMap.unbind();

                buffer.push_back(new GL::UVBuffer(true));
                fillBuffer();
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer const& renderer) : gBuffer(renderer.getFrameBuffer()), shadowMap(renderer.getShadowMap()), ssao(renderer.getSSAO()), buffer(renderer.getBuffer()), vao(renderer.getVAO()) {
            }

            DeferredRenderer::~DeferredRenderer() {
            }

            GL::FBO const& DeferredRenderer::getFrameBuffer() const {
                return gBuffer;
            }

            GL::FBO const& DeferredRenderer::getShadowMap() const {
                return shadowMap;
            }

            SSAO const& DeferredRenderer::getSSAO() const {
                return ssao;
            }

            GL::VBO const& DeferredRenderer::getBuffer() const {
                return buffer;
            }

            GL::VAO const& DeferredRenderer::getVAO() const {
                return vao;
            }

            void DeferredRenderer::setFrameBuffer(GL::FBO const& buffer) {
                gBuffer = buffer;
            }

            void DeferredRenderer::setShadowMap(GL::FBO const& buffer) {
                shadowMap = buffer;
            }

            void DeferredRenderer::setSSAO(SSAO const& ssao) {
                this->ssao = ssao;
            }

            void DeferredRenderer::setBuffer(GL::VBO const& buffer) {
                this->buffer = buffer;
            }

            void DeferredRenderer::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void DeferredRenderer::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &invModelview, Maths::Matrix4x4<NREfloat> &invProjection, Maths::Matrix4x4<NREfloat> &lightModelview, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light, GL::SkyBox const& skyBox) {

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                glUseProgram(shader.getID());
                    vao.bind();

                        glActiveTexture(GL_TEXTURE0);
                        getFrameBuffer().getDepthBuffer()->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texDepth"), 0);
                        glActiveTexture(GL_TEXTURE1);
                        getFrameBuffer().getColorBuffer(0)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texDiffuse"), 1);
                        glActiveTexture(GL_TEXTURE2);
                        getFrameBuffer().getColorBuffer(1)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texNormal"), 2);
                        glActiveTexture(GL_TEXTURE3);
                        getShadowMap().getDepthBuffer()->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texShadow"), 3);
                        glActiveTexture(GL_TEXTURE4);
                            glBindTexture(GL_TEXTURE_CUBE_MAP, skyBox.irradianceMap);
                            glUniform1i(glGetUniformLocation(shader.getID(), "irradianceMap"), 4);

                        for (unsigned int i = 0; i < light.size(); i = i + 1) {
                            std::ostringstream index;
                            index << i;
                            glUniform4fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].position").c_str()), 1, light.at(i)->getPosition().value());
                            glUniform3fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].intensities").c_str()), 1, light.at(i)->getIntensities().value());
                            glUniform3fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].coneDirection").c_str()), 1, light.at(i)->getConeDirection().value());
                            glUniform1fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].attenuation").c_str()), 1, light.at(i)->getAttenuationValue());
                            glUniform1fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].ambientCoefficient").c_str()), 1, light.at(i)->getAmbientCoeffValue());
                            glUniform1fv(glGetUniformLocation(shader.getID(), ("lights[" + index.str() + "].coneAngle").c_str()), 1, light.at(i)->getConeAngleValue());
                        }


                        for (unsigned int i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                            std::ostringstream index;
                            index << i;
                            glUniform3fv(glGetUniformLocation(shader.getID(), ("materials[" + index.str() + "].albedo").c_str()), 1, World::VoxelTypes::getMaterial(i).getAlbedo().value());
                            glUniform1fv(glGetUniformLocation(shader.getID(), ("materials[" + index.str() + "].metallic").c_str()), 1, World::VoxelTypes::getMaterial(i).getMetallicValue());
                            glUniform1fv(glGetUniformLocation(shader.getID(), ("materials[" + index.str() + "].roughness").c_str()), 1, World::VoxelTypes::getMaterial(i).getRoughnessValue());
                        }

                        glUniform3fv(glGetUniformLocation(shader.getID(), "cameraV"), 1, camera.getEye().value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "invModelview"), 1, GL_TRUE, invModelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "invProjection"), 1, GL_TRUE, invProjection.value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "lightModelview"), 1, GL_TRUE, lightModelview.value());
                        glUniform1i(glGetUniformLocation(shader.getID(), "numLights"), light.size());

                        glDrawArrays(GL_TRIANGLES, 0, 6);

                        glActiveTexture(GL_TEXTURE4);
                            glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
                        glActiveTexture(GL_TEXTURE3);
                            getShadowMap().getDepthBuffer()->unbind();
                        glActiveTexture(GL_TEXTURE2);
                            getFrameBuffer().getColorBuffer(1)->unbind();
                        glActiveTexture(GL_TEXTURE1);
                            getFrameBuffer().getColorBuffer(0)->unbind();
                        glActiveTexture(GL_TEXTURE0);
                            getFrameBuffer().getDepthBuffer()->unbind();
                    vao.unbind();
                glUseProgram(0);
            }

            void DeferredRenderer::startGBufferPass() {
                getFrameBuffer().bind();
                    glClearColor(0.0, 0.0, 0.0, 1.0);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};
                    glDrawBuffers(2, buffers);
            }

            void DeferredRenderer::endGBufferPass() {
                getFrameBuffer().unbind();
            }

            void DeferredRenderer::SSAOPass(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &invProjection) {
                getFrameBuffer().bind();
                    glDepthMask(false);
                    glColorMask(false, false, false, true);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0};
                    glDrawBuffers(1, buffers);

                    glUseProgram(shader.getID());
                        vao.bind();

                            glActiveTexture(GL_TEXTURE0);
                            getFrameBuffer().getDepthBuffer()->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texDepth"), 0);
                            glActiveTexture(GL_TEXTURE1);
                            getFrameBuffer().getColorBuffer(0)->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texDiffuse"), 1);
                            glActiveTexture(GL_TEXTURE2);
                            getFrameBuffer().getColorBuffer(1)->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texNormal"), 2);
                            glActiveTexture(GL_TEXTURE3);
                            getSSAO().getNoise()->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texNoise"), 3);

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "projection"), 1, GL_TRUE, projection.value());
                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "invProjection"), 1, GL_TRUE, invProjection.value());
                            glUniform3fv(glGetUniformLocation(shader.getID(), "gKernel"), 32, ssao.getKernel()[0].value());
                            glUniform1f(glGetUniformLocation(shader.getID(), "gSampleRad"), 0.5);

                            glDrawArrays(GL_TRIANGLES, 0, 6);

                            glActiveTexture(GL_TEXTURE3);
                                getSSAO().getNoise()->unbind();
                            glActiveTexture(GL_TEXTURE2);
                                getFrameBuffer().getColorBuffer(1)->unbind();
                            glActiveTexture(GL_TEXTURE1);
                                getFrameBuffer().getColorBuffer(0)->unbind();
                            glActiveTexture(GL_TEXTURE0);
                                getFrameBuffer().getDepthBuffer()->unbind();
                        vao.unbind();
                    glUseProgram(0);
                    glColorMask(true, true, true, true);
                    glDepthMask(true);
                getFrameBuffer().unbind();
            }

            void DeferredRenderer::startShadowPass() {
                getShadowMap().bind();
                    glClear(GL_DEPTH_BUFFER_BIT);

                    GLenum buffers[] = {GL_NONE};
                    glDrawBuffers(1, buffers);
            }

            void DeferredRenderer::endShadowPass() {
                getShadowMap().unbind();
            }

            void DeferredRenderer::fillBuffer() {
                GLint vData[] = {
                    -1, -1, 0,
                    1, -1, 0,
                    1, 1, 0,
                    1, 1, 0,
                    -1, 1, 0,
                    -1, -1, 0
                };

                GLshort uvData[] = {
                    0, 0, 1, 0, 1, 1,
                    1, 1, 0, 1, 0, 0
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);
                data.push_back(uvData);


                buffer.allocateAndFill(sizeof(GLint), 6, GL_STREAM_DRAW, data);
                vao.access(buffer, GL_INT, true);
            }

        };
    };
