
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
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
            Renderer::Shader deferredRendering("Shaders/DeferredRendering.vert", "Shaders/DeferredRendering.frag", true);

            std::vector<Light::Light*> engineLighting;
            Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 250, 300, 0),         Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0.0, 0.1, 0.0);
            Light::Light engineLight2(Maths::Point4D<NREfloat>(29.7,  28.0, 30.0, 1.0), Maths::Vector3D<NREfloat>(1.0, 0.0, 0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight3(Maths::Point4D<NREfloat>(71.6,  41.7, 30.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight4(Maths::Point4D<NREfloat>(60.5, -44.8, 30.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight5(Maths::Point4D<NREfloat>(50.0, -4.8,  30.0, 1.0), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            engineLighting.push_back(&engineLight1);
            engineLighting.push_back(&engineLight2);
            engineLighting.push_back(&engineLight3);
            engineLighting.push_back(&engineLight4);
            engineLighting.push_back(&engineLight5);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, MVP, lightModelview;

            Time::Clock engineClock;

            GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

            camera.computeProjectionMatrix(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            double angle = 0.0;
            double nbFrames = 0;

            while(!camera.getQuit())
            {
                engineClock.updateActualTime();
                nbFrames = nbFrames + 1;

                if (engineClock.getActualTime() - engineClock.getLastTime() >= 1000.0) {
                    std::cout << 1000.0 / nbFrames << "ms / frame" << std::endl;
                    nbFrames = 0;
                    engineClock.setLastTime(engineClock.getLastTime() + 1000.0);
                }

                camera.update();

                angle += 0.002;
                if (angle >= 360) {
                    angle = 0.0;
                }

                shadowView.setEye(Maths::Point3D<NREfloat>(8, sin(angle) * 256, cos(angle) * 256));
                engineLight1.setPosition(Maths::Point4D<NREfloat>(shadowView.getEye(), 0.0));
                shadowView.computeAngle();
                shadowView.computeVector();

                modelview.setIdentity();
                lightModelview.setIdentity();
                camera.setView(modelview);
                shadowView.setView(lightModelview);

                MVP = projection * modelview;

                engineDeferredRenderer.startGBufferPass();
                    auto it = camera.Keyboard::getKeyMap().find(SDL_SCANCODE_E);
                    engineSkybox.render(skyBoxShader, MVP, camera.getEye());

                    if (it->second.isActive()) {
                        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    }
                    engineWorld.render(gBufferPass, modelview, projection, &camera);
                    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                engineDeferredRenderer.endGBufferPass();

                engineDeferredRenderer.startShadowPass();
                    engineWorld.render(shadowPass, lightModelview, projection);
                engineDeferredRenderer.endShadowPass();

                invProjection = projection;
                invProjection.inverse();
                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.SSAOPass(ssaoPass, projection, invProjection);

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

                engineDeferredRenderer.render(deferredRendering, invModelview, invProjection, lightModelview, camera, engineLighting, engineSkybox);

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
