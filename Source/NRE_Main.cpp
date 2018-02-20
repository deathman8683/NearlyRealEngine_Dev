
    #include <iostream>

    #include "GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "Support/Scene/NRE_Scene.hpp"


    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        GL::VBO buffer(true);
        GL::VAO vao(true);

        std::cout << buffer << std::endl;
        std::cout << vao << std::endl;

        //while(1) {}

        return 0;
    }
