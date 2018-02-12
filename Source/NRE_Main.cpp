
    #include <iostream>

    #include "Support/Scene/NRE_Scene.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"
    #define GLM_ENABLE_EXPERIMENTAL
    #include <glm/glm.hpp>
    #include <glm/gtx/transform.hpp>
    #include <glm/gtx/string_cast.hpp>
    #include <glm/gtc/type_ptr.hpp>

    using namespace NRE;
    using namespace glm;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NearlyRealEngine - Dev version", Maths::Vector2D<int>(800, 600));

        bool terminer(false);

        float vertices[] = {-0.5, -0.5, -1.0, 0.0, 0.5, -1.0, 0.5, -0.5, -1.0};
        float couleurs[] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};

        Renderer::Shader shaderCouleur("Shaders/couleur3D.vert", "Shaders/couleur3D.frag", true);

        Maths::Matrix4x4<float> projection, modelview;

        projection.projection(70.0, (double)(800 / 600), 1.0, 100.0);

        while (!terminer)
        {
            SDL_Event event;
            SDL_WaitEvent(&event);

            if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
                terminer = true;
            }

            glClear(GL_COLOR_BUFFER_BIT);

            modelview.setIdentity();

            glUseProgram(shaderCouleur.getProgramID());

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
                glEnableVertexAttribArray(0);

                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
                glEnableVertexAttribArray(1);

                //modelview.translate(Maths::Vector3D<float>(0.4, 0, 0));

                glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "modelview"), 1, GL_FALSE, modelview.value());
                glUniformMatrix4fv(glGetUniformLocation(shaderCouleur.getProgramID(), "projection"), 1, GL_FALSE, projection.value());

                glDrawArrays(GL_TRIANGLES, 0, 3);

                glDisableVertexAttribArray(1);
                glDisableVertexAttribArray(0);

            glUseProgram(0);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        return 0;
    }
