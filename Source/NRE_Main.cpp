
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
        Camera::FixedCamera cameraFBO(70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(392.886, 286.034, 625.038), Maths::Vector3D<NREfloat>(392.886, 286.052, 624.038), Maths::Vector2D<NREfloat>(-89, 90.0999), true);
        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader lightShader("Shaders/PhongReflection.vert", "Shaders/PhongReflection.frag", true);
        Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
        Renderer::Shader textureShader("Shaders/Texture.vert", "Shaders/Texture.frag", true);
        Renderer::Shader deferredShader("Shaders/DeferredShading.vert", "Shaders/DeferredShading.frag", true);
        Renderer::Shader deferredRendering("Shaders/DeferredRendering.vert", "Shaders/DeferredRendering.frag", true);
        std::vector<Light::Light*> engineLighting;
        //Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(0.03, 0.08, 0.25), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0, 0.06, 0);
        Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(1, 1, 1), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0, 0.06, 0);
        engineLighting.push_back(&engineLight1);

        Maths::Matrix4x4<NREfloat> projection, modelview;
        Maths::Matrix4x4<NREfloat> projectionFBO, modelviewFBO;

        Time::Clock engineClock;

        GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

        camera.computeProjectionMatrix(projectionFBO);
        projection.ortho(0.0, 800.0, 0.0, 600.0, 0.1, 2.0);

        Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(800.0, 600.0));
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while(!camera.getQuit())
        {
            engineClock.updateTimestep(1000.0 / 60.0);

            camera.update();
            cameraFBO.computeVector();

            engineDeferredRenderer.getFrameBuffer().bind();
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                modelviewFBO.setIdentity();
                camera.setView(modelviewFBO);

                engineSkybox.render(skyBoxShader, modelviewFBO, projectionFBO, camera.getEye());
                engineSkybox.bind();
                    engineWorld.render(deferredShader, modelviewFBO, projectionFBO, camera, engineLighting);
                engineSkybox.unbind();
            engineDeferredRenderer.getFrameBuffer().unbind();

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                modelviewFBO.setIdentity();
                //cameraFBO.setView(modelviewFBO);
                modelview.translate(Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0));
                /*engineSkybox.render(skyBoxShader, modelview, projection, camera.getEye());
                engineSkybox.bind();
                    engineWorld.render(deferredShader, modelview, projection, camera, engineLighting);
                engineSkybox.unbind();*/

                engineDeferredRenderer.setProjection(projection);
                engineDeferredRenderer.setModelview(modelview);
                engineDeferredRenderer.render(textureShader);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
