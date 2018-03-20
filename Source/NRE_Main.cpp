
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        try {
            Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
            Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100), Maths::Vector2D<NREfloat>(0, 0), true);

            World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
            engineWorld.constructChunksMesh();

            Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
            Renderer::Shader gBufferPass("Shaders/GBufferPass.vert", "Shaders/GBufferPass.frag", true);
            Renderer::Shader deferredRendering("Shaders/DeferredRendering.vert", "Shaders/DeferredRendering.frag", true);

            std::vector<Light::Light*> engineLighting;
            Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(.01, .03, .25), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0.0, 0.0, 0.0);
            Light::Light engineLight2(Maths::Point4D<NREfloat>(55.0, -62.0, 21.0, 1.0), Maths::Vector3D<NREfloat>(1.0, .0, .0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight3(Maths::Point4D<NREfloat>(61.0, -29.0, 21.0, 1.0), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight4(Maths::Point4D<NREfloat>(55.0, 0.0, 21.0, 1.0), Maths::Vector3D<NREfloat>(.0, 1.0, .0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            Light::Light engineLight5(Maths::Point4D<NREfloat>(44.0, -38.0, 21.0, 1.0), Maths::Vector3D<NREfloat>(.0, .0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.001, 0.0, 360.0);
            engineLighting.push_back(&engineLight1);
            engineLighting.push_back(&engineLight2);
            engineLighting.push_back(&engineLight3);
            engineLighting.push_back(&engineLight4);
            engineLighting.push_back(&engineLight5);

            Maths::Matrix4x4<NREfloat> projection, modelview, MVP;

            Time::Clock engineClock;

            GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

            camera.computeProjectionMatrix(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(800.0, 600.0));

            while(!camera.getQuit())
            {
                engineClock.updateTimestep(1000.0 / 60.0);

                camera.update();

                modelview.setIdentity();
                camera.setView(modelview);

                MVP = projection * modelview;

                engineDeferredRenderer.beginRendering();
                    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                    engineSkybox.render(skyBoxShader, MVP, camera.getEye());
                    engineWorld.render(gBufferPass, MVP, camera);
                    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                engineDeferredRenderer.endRendering();

                engineSkybox.bind();
                    engineDeferredRenderer.render(deferredRendering, camera, engineLighting);
                engineSkybox.unbind();

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

        return 0;
    }
