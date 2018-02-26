
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"

    #define GLM_ENABLE_EXPERIMENTAL

    #include <glm/glm.hpp>
    #include <glm/gtx/transform.hpp>
    #include <glm/gtx/string_cast.hpp>
    #include <glm/gtc/type_ptr.hpp>

    using namespace NRE;
    using namespace glm;

    #define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", Maths::Vector3D<NREfloat>(-3, -3, -3), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0));
        GL::VBO vbo(true);
        GL::VAO vao(true);

        NREfloat vertices[] = {-1.0, -1.0, -1.0,  -1.0, 1.0, -1.0,  1.0, 1.0, -1.0,
                                1.0, 1.0, -1.0,  1.0, -1.0, -1.0, -1.0, -1.0, -1.0};
        NREfloat couleurs[] = {1.0, 0.0, 0.0,  0.0, 1.0, 0.0,  0.0, 0.0, 1.0,
                               0.0, 0.0, 1.0,  1.0, 1.0, 0.0,  1.0, 0.0, 0.0};
        GLbyte normal[] = {1, 0, 0,  1, 0, 0, 1, 0, 0,
                           1, 0, 0,  1, 0, 0, 1, 0, 0};

        camera.Keyboard::swap(SDL_SCANCODE_LSHIFT, SDL_SCANCODE_SPACE);

        vbo.allocateAndFill(sizeof(NREfloat), 6, GL_STATIC_DRAW, vertices, couleurs, normal);
        vao.access(vbo, GL_FLOAT);

        Renderer::Shader shaderCouleur("Shaders/couleur3D.vert", "Shaders/couleur3D.frag", true);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;
        mat4 m2(1.0);


        projection.projection(70.0, 800.0 / 600.0, 0.1, 100.0);

        while(!camera.getQuit())
        {
            camera.calculateVector();
            camera.update();

            glClear(GL_COLOR_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);

            glUseProgram(shaderCouleur.getProgramID());

                vao.bind();

                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                    glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                    glDrawArrays(GL_TRIANGLES, 0, 6);

                vao.unbind();

            glUseProgram(0);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
