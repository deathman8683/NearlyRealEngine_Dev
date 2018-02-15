
    #include <iostream>

    #include "GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        GL::VBO* tmp = new GL::VBO();

        std::cout << "Deconstruction" << std::endl;

        delete tmp;

        return 0;
    }
