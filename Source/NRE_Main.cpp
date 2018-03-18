
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100), Maths::Vector2D<NREfloat>(0, 0), true);

        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
        Renderer::Shader deferredShader("Shaders/DeferredShading.vert", "Shaders/DeferredShading.frag", true);
        Renderer::Shader deferredRendering("Shaders/DeferredRendering.vert", "Shaders/DeferredRendering.frag", true);
        std::vector<Light::Light*> engineLighting;
        Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(1, 1, 1), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0, 0.06, 0);
        engineLighting.push_back(&engineLight1);

        Maths::Matrix4x4<NREfloat> projection, modelview;

        Time::Clock engineClock;

        GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

        camera.computeProjectionMatrix(projection);

        Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(800.0, 600.0));
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while(!camera.getQuit())
        {
            engineClock.updateTimestep(1000.0 / 60.0);

            camera.update();

            engineDeferredRenderer.startFBO();
                modelview.setIdentity();
                camera.setView(modelview);

                engineSkybox.render(skyBoxShader, modelview, projection, camera.getEye());
                engineSkybox.bind();
                    engineWorld.render(deferredShader, modelview, projection, camera);
                engineSkybox.unbind();
            engineDeferredRenderer.endFBO();

            engineDeferredRenderer.render(deferredRendering, camera, engineLighting);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
