
    #include "NRE_DeferredRenderer.hpp"

    namespace NRE {
        namespace Renderer {

            DeferredRenderer::DeferredRenderer() {
            }

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : gBuffer(size.getW(), size.getH()), buffer(true), vao(true) {
                std::vector<GLenum> format, type;
                std::vector<GLint> internalFormat;
                format.push_back(GL_RGBA);
                format.push_back(GL_RGBA);
                format.push_back(GL_RGBA);
                format.push_back(GL_RGBA);
                type.push_back(GL_UNSIGNED_BYTE);
                type.push_back(GL_FLOAT);
                type.push_back(GL_UNSIGNED_BYTE);
                type.push_back(GL_UNSIGNED_BYTE);
                internalFormat.push_back(GL_RGBA);
                internalFormat.push_back(GL_RGBA32F);
                internalFormat.push_back(GL_RGBA);
                internalFormat.push_back(GL_RGBA);
                gBuffer.allocateColorBuffer(4, format, internalFormat, type);
                gBuffer.allocateRenderBuffer();

                if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
                    std::cout << "ERROR" << std::endl;
                }

                buffer.push_back(new GL::UVBuffer(true));
                fillBuffer();
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer const& renderer) : gBuffer(renderer.getFrameBuffer()), ssao(renderer.getSSAO()), buffer(renderer.getBuffer()), vao(renderer.getVAO()) {
            }

            DeferredRenderer::~DeferredRenderer() {
            }

            GL::FBO const& DeferredRenderer::getFrameBuffer() const {
                return gBuffer;
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

            void DeferredRenderer::setSSAO(SSAO const& ssao) {
                this->ssao = ssao;
            }

            void DeferredRenderer::setBuffer(GL::VBO const& buffer) {
                this->buffer = buffer;
            }

            void DeferredRenderer::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void DeferredRenderer::render(Renderer::Shader const& shader, bool const& type, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light, GL::SkyBox const& skyBox) {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                glUseProgram(shader.getID());
                    vao.bind();
                        glActiveTexture(GL_TEXTURE0);
                        getFrameBuffer().getColorBuffer(0)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texDiffuse"), 0);

                        glActiveTexture(GL_TEXTURE1);
                        getFrameBuffer().getColorBuffer(1)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texPosition"), 1);

                        glActiveTexture(GL_TEXTURE2);
                        getFrameBuffer().getColorBuffer(2)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texNormal"), 2);

                        glActiveTexture(GL_TEXTURE3);
                        getFrameBuffer().getColorBuffer(3)->bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texSSAO"), 3);

                        glActiveTexture(GL_TEXTURE4);
                        skyBox.bind();
                            glUniform1i(glGetUniformLocation(shader.getID(), "texSkyBox"), 4);

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

                        glUniform3fv(glGetUniformLocation(shader.getID(), "cameraV"), 1, camera.getEye().value());
                        glUniform1i(glGetUniformLocation(shader.getID(), "numLights"), light.size());

                        float t = type;

                        glUniform1f(glGetUniformLocation(shader.getID(), "type"), t);

                        glDrawArrays(GL_TRIANGLES, 0, 6);

                        glActiveTexture(GL_TEXTURE4);
                            skyBox.unbind();
                        glActiveTexture(GL_TEXTURE3);
                            getFrameBuffer().getColorBuffer(3)->unbind();
                        glActiveTexture(GL_TEXTURE2);
                            getFrameBuffer().getColorBuffer(2)->unbind();
                        glActiveTexture(GL_TEXTURE1);
                            getFrameBuffer().getColorBuffer(1)->unbind();
                        glActiveTexture(GL_TEXTURE0);
                            getFrameBuffer().getColorBuffer(0)->unbind();
                    vao.unbind();
                glUseProgram(0);
            }

            void DeferredRenderer::startGBufferPass() {
                getFrameBuffer().bind();
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
                    glDrawBuffers(3, buffers);
            }

            void DeferredRenderer::endGBufferPass() {
                getFrameBuffer().unbind();
            }

            void DeferredRenderer::SSAOPass(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP) {
                getFrameBuffer().bind();

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT3};
                    glDrawBuffers(1, buffers);

                    glUseProgram(shader.getID());
                        vao.bind();

                            glActiveTexture(GL_TEXTURE0);
                            getFrameBuffer().getColorBuffer(1)->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texPosition"), 0);
                            glActiveTexture(GL_TEXTURE1);
                            getFrameBuffer().getColorBuffer(2)->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texNormal"), 1);
                            glActiveTexture(GL_TEXTURE2);
                            getSSAO().getNoise()->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texNoise"), 2);

                            glUniformMatrix4fv(glGetUniformLocation(shader.getID(), "MVP"), 1, GL_TRUE, MVP.value());
                            glUniform3fv(glGetUniformLocation(shader.getID(), "gKernel"), 128, ssao.getKernel()[0].value());
                            glUniform1f(glGetUniformLocation(shader.getID(), "gSampleRad"), 0.08);

                            glDrawArrays(GL_TRIANGLES, 0, 6);

                            glActiveTexture(GL_TEXTURE2);
                                getSSAO().getNoise()->unbind();
                            glActiveTexture(GL_TEXTURE2);
                                getFrameBuffer().getColorBuffer(2)->unbind();
                            glActiveTexture(GL_TEXTURE0);
                                getFrameBuffer().getColorBuffer(1)->unbind();
                        vao.unbind();
                    glUseProgram(0);
                getFrameBuffer().unbind();
            }

            void DeferredRenderer::BlurPass(Renderer::Shader const& shader) {
                getFrameBuffer().bind();

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT3};
                    glDrawBuffers(1, buffers);

                    glUseProgram(shader.getID());
                        vao.bind();

                            glActiveTexture(GL_TEXTURE3);
                            getFrameBuffer().getColorBuffer(3)->bind();
                                glUniform1i(glGetUniformLocation(shader.getID(), "texSSAO"), 3);

                            glDrawArrays(GL_TRIANGLES, 0, 6);

                            glActiveTexture(GL_TEXTURE3);
                                getFrameBuffer().getColorBuffer(3)->unbind();
                        vao.unbind();
                    glUseProgram(0);
                getFrameBuffer().unbind();
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
