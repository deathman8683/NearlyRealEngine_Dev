
    #include <iostream>

    #include "Support/Scene/NRE_Scene.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NearlyRealEngine - Dev version", Maths::Vector2D<int>(800, 600));

        return 0;
    }
