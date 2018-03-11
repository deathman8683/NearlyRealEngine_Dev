
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(1, 1000.0), Maths::Vector3D<NREfloat>(-2, -2, -2), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0), 0.1);

        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader lightShader("Shaders/PhongReflection.vert", "Shaders/PhongReflection.frag", true);
        Renderer::Shader colorShader("Shaders/color3D.vert", "Shaders/color3D.frag", true);
        std::vector<Light::Light*> engineLighting;
        Light::Light engineLight1(Maths::Point3D<NREfloat>(0, 0, 80), Maths::Vector3D<NREfloat>(1.0, 0.0, 0.0), 0.01, 0);
        Light::Light engineLight2(Maths::Point3D<NREfloat>(0, 0, 80), Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0), 0.01, 0);
        Light::Light engineLight3(Maths::Point3D<NREfloat>(0, 0, 80), Maths::Vector3D<NREfloat>(0.0, 0.0, 1.0), 0.01, 0);
        Light::Light engineLight4(Maths::Point3D<NREfloat>(64, -55, 45), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), 0.01, 0);
        engineLighting.push_back(&engineLight1);
        engineLighting.push_back(&engineLight2);
        engineLighting.push_back(&engineLight3);
        engineLighting.push_back(&engineLight4);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;

        double angle = 0;

        camera.computeProjectionMatrix(projection);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        while(!camera.getQuit())
        {
            angle = (angle + 0.3);
            if (angle > 360) {
                angle = 0;
            }
            camera.update();


            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);

            Maths::Point3D<NREfloat> eye1 = engineLight1.getPosition();
            eye1.setX(std::sin(toRad(angle)) * 50);
            eye1.setY(std::cos(toRad(angle)) * 50);

            Maths::Point3D<NREfloat> eye2 = engineLight2.getPosition();
            eye2.setX(std::sin(toRad((angle + 120))) * 50);
            eye2.setY(std::cos(toRad((angle + 120))) * 50);

            Maths::Point3D<NREfloat> eye3 = engineLight3.getPosition();
            eye3.setX(std::sin(toRad((angle + 240))) * 50);
            eye3.setY(std::cos(toRad((angle + 240))) * 50);


            engineLight1.setPosition(eye1);
            engineLight2.setPosition(eye2);
            engineLight3.setPosition(eye3);

            //engineLight4.setPosition(camera.getEye());

            engineWorld.render(lightShader, modelview, projection, camera, engineLighting);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
