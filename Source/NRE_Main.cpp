
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
    #include "GL_Wrapper/BufferObject/FBO/NRE_FBO.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", 70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100), Maths::Vector2D<NREfloat>(0, 0), true);
        Camera::FixedCamera cameraFBO(70.0, 800.0 / 600.0, Maths::Vector2D<NREfloat>(0.1, 1000.0), Maths::Vector3D<NREfloat>(56, -64, 64), Maths::Vector3D<NREfloat>(56, -63, 64), Maths::Vector2D<NREfloat>(-15, 97), true);

        World::World engineWorld(Maths::Vector2D<GLuint>(5, 5));
        engineWorld.constructChunksMesh();

        Renderer::Shader lightShader("Shaders/PhongReflection.vert", "Shaders/PhongReflection.frag", true);
        Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
        Renderer::Shader textureShader("Shaders/Texture.vert", "Shaders/Texture.frag", true);
        std::vector<Light::Light*> engineLighting;
        //Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(0.03, 0.08, 0.25), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0, 0.06, 0);
        Light::Light engineLight1(Maths::Point4D<NREfloat>(0, 0, 80, 0), Maths::Vector3D<NREfloat>(1, 1, 1), Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), 0, 0.06, 0);
        engineLighting.push_back(&engineLight1);

        Maths::Matrix4x4<NREfloat> projection, modelview;
        Maths::Matrix4x4<NREfloat> projectionFBO, modelviewFBO;

        Time::Clock engineClock;

        GL::SkyBox engineSkybox("Data/SkyBox/Warm", "png");

        camera.computeProjectionMatrix(projection);
        cameraFBO.computeProjectionMatrix(projectionFBO);

        GL::FBO fbo(800, 600);
        std::vector<GLvoid*> data;
        GLint vertices[] = {0, 0, 100, 0, 100, 100, 0, 100, 200,
                            0, 100, 200, 0, 0, 200, 0, 0, 100};

        GLshort uv[] = {0, 0, 1, 0, 1, 1,
                        1, 1, 0, 1, 0, 0};

        data.push_back(vertices);
        data.push_back(uv);

        GL::VBO buf(true);

        buf.push_back(new GL::UVBuffer(true));

        buf.allocateAndFill(sizeof(GLint), 6, GL_STREAM_DRAW, data);
        GL::VAO vao(true);
        vao.access(buf, GL_INT, true);

        while(!camera.getQuit())
        {
            engineClock.updateTimestep(1000.0 / 60.0);

            fbo.bind();
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                cameraFBO.computeVector();
                modelviewFBO.setIdentity();
                cameraFBO.setView(modelviewFBO);

                engineSkybox.render(skyBoxShader, modelviewFBO, projectionFBO, cameraFBO.getEye());
                engineSkybox.bind();
                    engineWorld.render(lightShader, modelviewFBO, projectionFBO, cameraFBO, engineLighting);
                engineSkybox.unbind();
            fbo.unbind();

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                camera.update();
                modelview.setIdentity();
                camera.setView(modelview);


                /*engineSkybox.render(skyBoxShader, modelview, projection, camera.getEye());
                engineSkybox.bind();
                    engineWorld.render(lightShader, modelview, projection, camera, engineLighting);
                engineSkybox.unbind();*/
                glUseProgram(textureShader.getProgramID());
                    vao.bind();
                        fbo.getColorBuffer(0)->bind();

                            glUniformMatrix4fv(glGetUniformLocation(textureShader.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                            glUniformMatrix4fv(glGetUniformLocation(textureShader.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                            glDrawArrays(GL_TRIANGLES, 0, 6);

                        fbo.getColorBuffer(0)->unbind();
                    vao.unbind();
                glUseProgram(0);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
