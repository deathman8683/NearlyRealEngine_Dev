
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "GL_Wrapper/SkyBox/NRE_SkyBox.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector3D<NREfloat>(1, 1, 1), Maths::Vector2D<NREfloat>(0, 0), 1);

        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader lightShader("Shaders/PhongReflection.vert", "Shaders/PhongReflection.frag", true);
        Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
        std::vector<Light::Light*> engineLighting;
        //Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(0.03, 0.08, 0.25), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0, 0.06, 360);
        Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(1, 1, 1), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0, 0.06, 360);
        Light::Light engineLight2(Maths::Point4D<NREfloat>(64, -55, 45, 1), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.05, 0.01, 360);
        engineLighting.push_back(&engineLight1);
        engineLighting.push_back(&engineLight2);

        Maths::Matrix4x4<NREfloat> projection, modelview;

        Time::Clock engineClock;

        GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

        camera.computeProjectionMatrix(projection);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        while(!camera.getQuit())
        {
            engineClock.updateTimestep(1000.0 / 60.0);

            camera.update();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);


            engineSkybox.render(skyBoxShader, modelview, projection, camera.getEye());
            engineWorld.render(lightShader, modelview, projection, camera, engineLighting);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
