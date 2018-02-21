
    #include <iostream>

    #include "GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "Support/Scene/NRE_Scene.hpp"
    #include "SDL_Wrapper/Event/NRE_Event.hpp"
    #include "Camera/Input/Keyboard/NRE_Keyboard.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        /*Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        SDL::Event event;
        GL::VBO buffer(true);
        GL::VAO vao(true);

        bool again = true;

        while (again) {
            while (event.poll()) {
                switch(event.getType()) {
                    case (SDL_QUIT) : {
                        again = false;
                        break;
                    }
                    case (SDL_KEYDOWN) : {
                        std::cout << event.getKeyScancode() << std::endl;
                        break;
                    }
                    default : {
                    }
                }
            }
        }*/

        Input::Keyboard kb;
        kb.swap(15, 16);
        std::cout << kb << std::endl;

        return 0;
    }
