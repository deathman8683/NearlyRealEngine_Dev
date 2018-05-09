
    #include "NRE_DeferredRenderer.hpp"

    namespace NRE {
        namespace Renderer {

            DeferredRenderer::DeferredRenderer() {
            }

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : Object2D::Object2D(GL_STATIC_DRAW, Maths::Point2D<GLint>(-1, -1), Maths::Vector2D<GLint>(2, 2)), gBuffer(size.getW(), size.getH()) {
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

                gBuffer.checkIntegrity();
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer && def) : Object2D::Object2D(std::move(def)), gBuffer(std::move(def.gBuffer)), ssao(std::move(def.ssao)) {
            }

            DeferredRenderer::~DeferredRenderer() {
            }

            void DeferredRenderer::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &invModelview, Maths::Matrix4x4<NREfloat> &invProjection, Maths::Matrix4x4<NREfloat> &rotation, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light, EnvironmentMap const& skyBox) {

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                shader.bind();
                    glActiveTexture(GL_TEXTURE0);
                        gBuffer.getDepthBuffer()->bind();
                            shader.use1I("texDepth", 0);
                    glActiveTexture(GL_TEXTURE1);
                        gBuffer.getColorBuffer(0)->bind();
                            shader.use1I("texDiffuse", 1);
                    glActiveTexture(GL_TEXTURE2);
                        gBuffer.getColorBuffer(1)->bind();
                            shader.use1I("texNormal", 2);
                    glActiveTexture(GL_TEXTURE4);
                        skyBox.getIrradianceMap().bind();
                            shader.use1I("irradianceMap", 4);
                    glActiveTexture(GL_TEXTURE5);
                        skyBox.getPrefilterMap().bind();
                            shader.use1I("prefilterMap", 5);
                    glActiveTexture(GL_TEXTURE6);
                        skyBox.getBRDFLUT().bind();
                            shader.use1I("brdfLUT", 6);

                    for (unsigned int i = 0; i < light.size(); i = i + 1) {
                        std::ostringstream index;
                        index << i;
                        shader.use4FV("lights[" + index.str() + "].position", 1, light.at(i)->getPosition().value());
                        shader.use3FV("lights[" + index.str() + "].intensities", 1, light.at(i)->getIntensities().value());
                        shader.use3FV("lights[" + index.str() + "].direction", 1, light.at(i)->getDirection().value());
                        shader.use1FV("lights[" + index.str() + "].angle", 1, light.at(i)->getAngleValue());
                    }


                    for (unsigned int i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                        std::ostringstream index;
                        index << i;
                        shader.use3FV("materials[" + index.str() + "].albedo", 1, World::VoxelTypes::getMaterial(i).getAlbedo().value());
                        shader.use1FV("materials[" + index.str() + "].metallic", 1, World::VoxelTypes::getMaterial(i).getMetallicValue());
                        shader.use1FV("materials[" + index.str() + "].roughness", 1, World::VoxelTypes::getMaterial(i).getRoughnessValue());
                    }

                    shader.use3FV("cameraV", 1, camera.getEye().value());
                    shader.useMat4("invModelview", 1, &invModelview);
                    shader.useMat4("invProjection", 1, &invProjection);
                    shader.useMat4("rotation", 1, &rotation);
                    shader.use1I("numLights", light.size());

                    draw();

                    glActiveTexture(GL_TEXTURE6);
                        skyBox.getBRDFLUT().unbind();
                    glActiveTexture(GL_TEXTURE5);
                        skyBox.getPrefilterMap().unbind();
                    glActiveTexture(GL_TEXTURE4);
                        skyBox.getIrradianceMap().unbind();
                    glActiveTexture(GL_TEXTURE2);
                        gBuffer.getColorBuffer(1)->unbind();
                    glActiveTexture(GL_TEXTURE1);
                        gBuffer.getColorBuffer(0)->unbind();
                    glActiveTexture(GL_TEXTURE0);
                        gBuffer.getDepthBuffer()->unbind();
                shader.unbind();
            }

            void DeferredRenderer::startGBufferPass() {
                gBuffer.bind();
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};
                    glDrawBuffers(2, buffers);
            }

            void DeferredRenderer::endGBufferPass() {
                gBuffer.unbind();
            }

            void DeferredRenderer::SSAOPass(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &invProjection) {
                gBuffer.bind();
                    glDepthMask(false);
                    glColorMask(false, false, false, true);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0};
                    glDrawBuffers(1, buffers);

                    shader.bind();
                        glActiveTexture(GL_TEXTURE0);
                            gBuffer.getDepthBuffer()->bind();
                                shader.use1I("texDepth", 0);
                        glActiveTexture(GL_TEXTURE1);
                            gBuffer.getColorBuffer(1)->bind();
                                shader.use1I("texNormal", 1);
                        glActiveTexture(GL_TEXTURE2);
                            ssao.getNoise()->bind();
                                shader.use1I("texNoise", 2);;

                        shader.useMat4("projection", 1, &projection);
                        shader.useMat4("invProjection", 1, &invProjection);
                        shader.use3FV("gKernel", SSAO::KERNEL_SIZE, ssao.getKernel()[0].value());
                        shader.use1F("gSampleRad", 0.5);

                        draw();

                        glActiveTexture(GL_TEXTURE2);
                            ssao.getNoise()->unbind();
                        glActiveTexture(GL_TEXTURE1);
                            gBuffer.getColorBuffer(1)->unbind();
                        glActiveTexture(GL_TEXTURE0);
                            gBuffer.getDepthBuffer()->unbind();
                    shader.unbind();
                    glColorMask(true, true, true, true);
                    glDepthMask(true);
                gBuffer.unbind();
            }

            DeferredRenderer& DeferredRenderer::operator=(DeferredRenderer && def) {
                gBuffer = std::move(def.gBuffer);
                ssao = std::move(def.ssao);
                buffer = std::move(def.buffer);
                vao = std::move(def.vao);
                return *this;
            }

        };
    };
