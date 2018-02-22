
    #include <iostream>

    #include "GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "Support/Scene/NRE_Scene.hpp"
    #include "SDL_Wrapper/Event/NRE_Event.hpp"
    #include "Camera/Input/NRE_Input.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        SDL::Event event;
        GL::VBO buffer(true);
        GL::VAO vao(true);
        Input::Input in;

        while (!in.getQuit()) {
            in.update();
        }


        return 0;
    }
