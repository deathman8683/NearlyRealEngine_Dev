
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(1, 1000.0), Maths::Vector3D<NREfloat>(-2, -2, -2), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0), 1);

        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader lightShader("Shaders/PhongReflection.vert", "Shaders/PhongReflection.frag", true);
        std::vector<Light::Light*> engineLighting;
        Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 1), Maths::Vector3D<NREfloat>(2.0, 0.0, 0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.1, 0, 30.0);
        Light::Light engineLight2(Maths::Point4D<NREfloat>(0, 0, 80, 1), Maths::Vector3D<NREfloat>(0.0, 2.0, 0.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.1, 0, 30.0);
        Light::Light engineLight3(Maths::Point4D<NREfloat>(0, 0, 80, 1), Maths::Vector3D<NREfloat>(0.0, 0.0, 2.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.1, 0, 30.0);
        Light::Light engineLight4(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0, 0.06, 360);
        Light::Light engineLight5(Maths::Point4D<NREfloat>(64, -55, 45, 1), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.05, 0.01, 360);
        engineLighting.push_back(&engineLight1);
        engineLighting.push_back(&engineLight2);
        engineLighting.push_back(&engineLight3);
        engineLighting.push_back(&engineLight4);
        engineLighting.push_back(&engineLight5);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;

        Time::Clock engineClock;

        int angle = 0;

        camera.computeProjectionMatrix(projection);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        while(!camera.getQuit())
        {
            engineClock.updateTimestep(1000.0 / 60.0);

            angle = (angle + 1) % 360;
            camera.update();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);

            Maths::Point4D<NREfloat> eye1 = engineLight1.getPosition();
            eye1.setX(std::sin(toRad(angle)) * 50);
            eye1.setY(std::cos(toRad(angle)) * 50);

            Maths::Point4D<NREfloat> eye2 = engineLight2.getPosition();
            eye2.setX(std::sin(toRad((angle + 120))) * 50);
            eye2.setY(std::cos(toRad((angle + 120))) * 50);

            Maths::Point4D<NREfloat> eye3 = engineLight3.getPosition();
            eye3.setX(std::sin(toRad((angle + 240))) * 50);
            eye3.setY(std::cos(toRad((angle + 240))) * 50);

            engineLight1.setPosition(eye1);
            engineLight2.setPosition(eye2);
            engineLight3.setPosition(eye3);

            //engineLight4.setConeDirection(camera.getEye());
            //engineLight4.setPosition(Maths::Point4D<NREfloat>(camera.getEye(), 1.0));

            engineWorld.render(lightShader, modelview, projection, camera, engineLighting);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
