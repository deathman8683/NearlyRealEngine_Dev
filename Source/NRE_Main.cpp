
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/Input/NRE_Input.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"

    using namespace NRE;

    #define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Input::Input in("kBinder.cfg", "mBinder.cfg");
        GL::VBO vbo(true);
        GL::VAO vao(true);

        NREfloat vertices[] = {-1.0, -1.0, -1.0,  -1.0, 1.0, -1.0,  1.0, 1.0, -1.0,
                                1.0, 1.0, -1.0,  1.0, -1.0, -1.0, -1.0, -1.0, -1.0};
        NREfloat couleurs[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0,
                               0.0, 0.0, 1.0,  1.0, 1.0, 0.0,  1.0, 0.0, 0.0};
        GLbyte normal[] = {1, 0, 0,  1, 0, 0, 1, 0, 0,
                           1, 0, 0,  1, 0, 0, 1, 0, 0};

        vbo.allocateAndFill(sizeof(NREfloat), 6, GL_STATIC_DRAW, vertices, couleurs, normal);
        vao.access(vbo, GL_FLOAT);

        Renderer::Shader shaderCouleur("Shaders/couleur3D.vert", "Shaders/couleur3D.frag", true);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;

        projection.projection(70.0, 800.0 / 600.0, 0.1, 100.0);

        while(!in.getQuit())
        {
            in.update(NULL);

            glClear(GL_COLOR_BUFFER_BIT);

            modelview.setIdentity();

            glUseProgram(shaderCouleur.getProgramID());

                vao.bind();

                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "modelview"), 1, GL_FALSE, modelview.value());
                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "projection"), 1, GL_FALSE, projection.value());

                    glDrawArrays(GL_TRIANGLES, 0, 6);

                vao.unbind();

            glUseProgram(0);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        in.Keyboard::save("kBinder.cfg");
        in.Mouse::save("mBinder.cfg");

        return 0;
    }
