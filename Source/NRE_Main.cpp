
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(1, 100), Maths::Vector3D<NREfloat>(-2, -2, -2), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0), 0.1);

        World::World engineWorld(Maths::Vector2D<GLuint>(0, 0));
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

        GL::IBO frustum(true);
        GL::VAO frustumVao(true);

        GLfloat* vData;
        GLfloat *cData;
        GLbyte* nData;
        GLuint* iData;

        double angle = 0;
        int test = 0;
        size_t iCpt;

        camera.computeProjectionMatrix(projection);

        while(!camera.getQuit())
        {
            angle = (angle + 0.3);
            if (angle > 360) {
                angle = 0;
            }
            test++;
            camera.update();
            //if (test == 5000) {
                frustum.reload();
                iCpt = camera.getVertices(vData, cData, nData, iData);
                frustum.allocateAndFill(sizeof(GLfloat), 20, iCpt, GL_STATIC_DRAW, vData, cData, nData, iData);
                frustumVao.access(frustum, GL_FLOAT);
            //}


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

            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            engineWorld.render(lightShader, modelview, projection, camera, engineLighting);

            //if (test >= 5000) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glUseProgram(colorShader.getProgramID());
                    frustumVao.bind();
                        glUniformMatrix4fv(glGetUniformLocation(colorShader.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(colorShader.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                        glDrawElements(GL_LINES, iCpt, GL_UNSIGNED_INT, 0);
                    frustumVao.unbind();
                glUseProgram(0);
            //}

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        delete[] vData;
        delete[] cData;
        delete[] nData;
        delete[] iData;

        return 0;
    }
