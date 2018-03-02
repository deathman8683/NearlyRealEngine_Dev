
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "World/Voxel/Type/NRE_VoxelType.hpp"
    #include "Renderer/Color/NRE_Color.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", Maths::Vector3D<NREfloat>(-3, -3, -3), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0), 0.01);
        GL::IBO ibo(true);
        GL::VAO vao(true);

        Color::RGB test0;
        Color::RGBA test1;
        Color::HSL test2;
        Color::HSLA test3;

        GLint* vertices;
        GLfloat* couleurs;
        GLbyte* normal;
        GLuint* index;

        Voxel::Stone test;
        World::Voxel *blockTest = &test;

        size_t iCpt = blockTest->getVertices(vertices, couleurs, normal, index);

        ibo.allocateAndFill(sizeof(GLint), 36, iCpt, GL_STATIC_DRAW, vertices, couleurs, normal, index);
        vao.access(ibo, GL_INT);

        Renderer::Shader shaderCouleur("Shaders/couleur3D.vert", "Shaders/couleur3D.frag", true);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;

        projection.projection(70.0, 800.0 / 600.0, 0.1, 100.0);

        while(!camera.getQuit())
        {
            camera.update();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);

            glUseProgram(shaderCouleur.getProgramID());

                vao.bind();

                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                    glDrawElements(GL_TRIANGLES, iCpt, GL_UNSIGNED_INT, 0);

                vao.unbind();

                for (int i = 0; i < 10; i = i + 1) {
                    modelview.translate(Maths::Vector3D<NREfloat>(0.05, 0.05, 1));
                    modelview.scale(Maths::Vector3D<NREfloat>(0.9, 0.9, 0.9));

                    vao.bind();

                        glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                        glDrawElements(GL_TRIANGLES, iCpt, GL_UNSIGNED_INT, 0);

                    vao.unbind();
                }

            glUseProgram(0);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
