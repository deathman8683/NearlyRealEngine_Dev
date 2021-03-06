
    #include "NRE_DeferredRenderer.hpp"

    namespace NRE {
        namespace Renderer {

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : Object2D::Object2D(GL_INT, GL_STATIC_DRAW, Maths::Point2D<GLint>(-1, -1), Maths::Vector2D<GLint>(2, 2)), gBuffer(size.getW(), size.getH()) {

                ShadersManager::sendKernel(ssao);

                std::vector<GLenum> format, type;
                std::vector<GLint> internalFormat;
                format.push_back(GL_RGBA);
                format.push_back(GL_RGBA);
                type.push_back(GL_FLOAT);
                type.push_back(GL_FLOAT);
                internalFormat.push_back(GL_RGBA16F);
                internalFormat.push_back(GL_RGBA16F);

                gBuffer.allocateColorBuffer(2, format, internalFormat, type);
                gBuffer.setDepthBuffer(new GL::Texture2D(gBuffer.getSize().getW(), gBuffer.getSize().getH(), GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT32F, GL_FLOAT));
                gBuffer.attachDepthBuffer(GL_DEPTH_ATTACHMENT);

                gBuffer.checkIntegrity();
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer && def) : Object2D::Object2D(std::move(def)), gBuffer(std::move(def.gBuffer)), ssao(std::move(def.ssao)) {
            }

            DeferredRenderer::~DeferredRenderer() {
            }

            void DeferredRenderer::render(Maths::Matrix4x4<NREfloat> const& invModelview, Maths::Matrix4x4<NREfloat> const& rotation, Camera::FixedCamera const& camera, EnvironmentMap const& skyBox) {

                SSAOPass();

                const PBRShader* shader = static_cast <const PBRShader*> (ShadersManager::getShader("PBR"));

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                shader->bind();
                    glActiveTexture(GL_TEXTURE0);
                        gBuffer.getDepthBuffer()->bind();
                    glActiveTexture(GL_TEXTURE1);
                        gBuffer.getColorBuffer(0)->bind();
                    glActiveTexture(GL_TEXTURE2);
                        gBuffer.getColorBuffer(1)->bind();
                    glActiveTexture(GL_TEXTURE3);
                        skyBox.getIrradianceMap().bind();
                    glActiveTexture(GL_TEXTURE4);
                        skyBox.getPrefilterMap().bind();
                    glActiveTexture(GL_TEXTURE5);
                        skyBox.getBRDFLUT().bind();
                    glActiveTexture(GL_TEXTURE6);
                        MaterialsManager::getMaterialsAlbedo().bind();
                    glActiveTexture(GL_TEXTURE7);
                        MaterialsManager::getMaterialsRoughness().bind();
                    glActiveTexture(GL_TEXTURE8);
                        MaterialsManager::getMaterialsMetallic().bind();

                    shader->sendLigths();
                    shader->sendCamera(camera);
                    shader->sendInvModelview(invModelview);
                    shader->sendRotation(rotation);

                    draw();


                    glActiveTexture(GL_TEXTURE8);
                    MaterialsManager::getMaterialsMetallic().unbind();
                    glActiveTexture(GL_TEXTURE7);
                    MaterialsManager::getMaterialsRoughness().unbind();
                    glActiveTexture(GL_TEXTURE6);
                    MaterialsManager::getMaterialsAlbedo().unbind();
                    glActiveTexture(GL_TEXTURE5);
                        skyBox.getBRDFLUT().unbind();
                    glActiveTexture(GL_TEXTURE4);
                        skyBox.getPrefilterMap().unbind();
                    glActiveTexture(GL_TEXTURE3);
                        skyBox.getIrradianceMap().unbind();
                    glActiveTexture(GL_TEXTURE2);
                        gBuffer.getColorBuffer(1)->unbind();
                    glActiveTexture(GL_TEXTURE1);
                        gBuffer.getColorBuffer(0)->unbind();
                    glActiveTexture(GL_TEXTURE0);
                        gBuffer.getDepthBuffer()->unbind();
                shader->unbind();
            }

            void DeferredRenderer::startGBufferPass() {
                gBuffer.bind();
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
                    glDrawBuffers(3, buffers);

                    MaterialsManager::getMaterialsNormal().bind();
            }

            void DeferredRenderer::endGBufferPass() {
                    MaterialsManager::getMaterialsNormal().unbind();
                gBuffer.unbind();
            }

            void DeferredRenderer::SSAOPass() {

                const Shader* shader = ShadersManager::getShader("SSAO");

                gBuffer.bind();
                    glDepthMask(false);
                    glColorMask(false, false, false, true);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0};
                    glDrawBuffers(1, buffers);

                    shader->bind();
                        glActiveTexture(GL_TEXTURE0);
                            gBuffer.getDepthBuffer()->bind();
                        glActiveTexture(GL_TEXTURE1);
                            gBuffer.getColorBuffer(1)->bind();
                        glActiveTexture(GL_TEXTURE2);
                            ssao.getNoise()->bind();

                        draw();

                        glActiveTexture(GL_TEXTURE2);
                            ssao.getNoise()->unbind();
                        glActiveTexture(GL_TEXTURE1);
                            gBuffer.getColorBuffer(1)->unbind();
                        glActiveTexture(GL_TEXTURE0);
                            gBuffer.getDepthBuffer()->unbind();
                    shader->unbind();
                    glColorMask(true, true, true, true);
                    glDepthMask(true);
                gBuffer.unbind();
            }

            DeferredRenderer& DeferredRenderer::operator=(DeferredRenderer && def) {
                gBuffer = std::move(def.gBuffer);
                ssao = std::move(def.ssao);
                return *this;
            }

        };
    };
