
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        try {
            Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(1280, 720));
            Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100));
            Camera::FixedCamera shadowView(70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(8, 256, 256), Maths::Vector3D<NREfloat>(8, 8, 64));

            World::World engineWorld(Maths::Vector2D<GLuint>(5, 5), Maths::Vector2D<GLint>(0, 0));

            Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
            Renderer::Shader gBufferPass("Shaders/GBufferPass.vert", "Shaders/GBufferPass.frag", true);
            Renderer::Shader ssaoPass("Shaders/SSAOPass.vert", "Shaders/SSAOPass.frag", true);
            Renderer::Shader shadowPass("Shaders/ShadowPass.vert", "Shaders/ShadowPass.frag", true);
            Renderer::Shader pbrShader("Shaders/PBRShader.vert", "Shaders/PBRShader.frag", true);
            Renderer::Shader captureShader("Shaders/CaptureShader.vert", "Shaders/CaptureShader.frag", true);
            Renderer::Shader irradianceShader("Shaders/IrradianceShader.vert", "Shaders/IrradianceShader.frag", true);
            Renderer::Shader prefilterShader("Shaders/PrefilterShader.vert", "Shaders/PrefilterShader.frag", true);
            Renderer::Shader brdfShader("Shaders/BRDFShader.vert", "Shaders/BRDFShader.frag", true);

            std::vector<Light::Light*> engineLight;
            //Light::DirectionnalLight engineLight1(Maths::Point3D<NREfloat>(0, 250, 300),Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.1);
            Light::PointLight engineLight2(Maths::Point3D<NREfloat>(29.7,  28.0, 29.0), Maths::Vector3D<NREfloat>(400.0, 0.0, 0.0));
            Light::PointLight engineLight3(Maths::Point3D<NREfloat>(71.6,  41.7, 29.0), Maths::Vector3D<NREfloat>(0.0, 400.0, 0.0));
            Light::PointLight engineLight4(Maths::Point3D<NREfloat>(60.5, -44.8, 29.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 400.0));
            Light::PointLight engineLight5(Maths::Point3D<NREfloat>(50.0, -4.8,  29.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            //engineLight.push_back(&engineLight1);
            engineLight.push_back(&engineLight2);
            engineLight.push_back(&engineLight3);
            engineLight.push_back(&engineLight4);
            engineLight.push_back(&engineLight5);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, lightModelview, rotation;

            Time::Clock engineClock;

            Renderer::EnvironmentMap engineSkybox("Data/SkyBox/Sky.hdr", captureShader, irradianceShader, prefilterShader, brdfShader);

            camera.computeProjectionMatrix(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            int angle = 0;
            double skyboxAngle = 0;

            glViewport(0, 0, 1280.0, 720.0);

            while(!camera.getQuit())
            {
                engineClock.updateTimestep(1000.0 / 60.0);

                camera.update();

                angle += 1;
                angle %= 360;
                skyboxAngle += 0.01;
                if (skyboxAngle >= 360) {
                    skyboxAngle = 0.0;
                }
                rotation.setIdentity();

                Color::HSL color(angle, 1.0, 0.5);
                Color::RGB colorRGB(color);
                Maths::Vector3D<NREfloat> tmpColor((static_cast <NREfloat> (colorRGB.getR() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getG() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getB() / 255.0)) * 4000.0);
                engineLight5.setIntensities(tmpColor);

                rotation.rotate(skyboxAngle, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));
                rotation.rotate(skyboxAngle, Maths::Vector3D<NREfloat>(1.0, 0.0, 0.0));

                /*shadowView.setEye(Maths::Point3D<NREfloat>(8 + engineWorld.getShift().getX() * 16, sin(angle) * 256 + engineWorld.getShift().getY() * 16, cos(angle) * 256));
                shadowView.setCenter(Maths::Point3D<NREfloat>(8 + engineWorld.getShift().getX() * 16, 8 + engineWorld.getShift().getY() * 16, 64));
                engineLight1.setPosition(Maths::Point4D<NREfloat>(shadowView.getEye(), 0.0));
                shadowView.computeAngle();
                shadowView.computeVector();*/

                modelview.setIdentity();
                lightModelview.setIdentity();
                camera.setView(modelview);
                shadowView.setView(lightModelview);

                engineDeferredRenderer.startGBufferPass();
                    auto it = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_E);

                    if (it->second.isActive()) {
                        tmpColor.setG(tmpColor.getR());
                        tmpColor.setB(tmpColor.getR());
                       engineLight5.setIntensities(tmpColor);
                    }
                    engineWorld.render(gBufferPass, modelview, projection, &camera);
                    Maths::Matrix4x4<NREfloat> tmp(modelview);
                    modelview = modelview * rotation;
                    engineSkybox.render(skyBoxShader, projection, modelview);
                    modelview = tmp;
                engineDeferredRenderer.endGBufferPass();

                /*engineDeferredRenderer.startShadowPass();
                    engineWorld.render(shadowPass, lightModelview, projection);
                engineDeferredRenderer.endShadowPass();*/

                invProjection = projection;
                invProjection.inverse();
                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.SSAOPass(ssaoPass, projection, invProjection);

                auto it0 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_L);
                if (it0->second.isActive()) {
                    engineWorld.flushConstructionStack();
                    for (auto c : engineWorld.getChunkMap()) {
                        c.second->setLoD(c.second->getLoD() * 2);
                        c.second->reload();
                    }
                }
                auto it1 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_O);
                if (it1->second.isActive()) {
                    engineWorld.flushConstructionStack();
                    for (auto c : engineWorld.getChunkMap()) {
                        c.second->setLoD(c.second->getLoD() / 2);
                        c.second->reload();
                    }
                }

                auto it2 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_F);
                if (it2->second.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(1, 0));
                }
                auto it3 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_G);
                if (it3->second.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(0, -1));
                }
                auto it4 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_H);
                if (it4->second.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(-1, 0));
                }
                auto it5 = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_T);
                if (it5->second.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(0, 1));
                }

                engineDeferredRenderer.render(pbrShader, invModelview, invProjection, lightModelview, rotation, camera, engineLight, engineSkybox);

                engineWorld.update();

                SDL_GL_SwapWindow(engineScene.getWindow().getItem());
            }

            camera.Keyboard::save("kBinder.cfg");
            camera.Mouse::save("mBinder.cfg");
        }
        catch (Exception::ExceptionHandler const& e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }

        World::VoxelTypes::free();

        return 0;
    }
