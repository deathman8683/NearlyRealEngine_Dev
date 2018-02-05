
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    int main(int argc, char **argv) {
        Vector2D<int> mother;
        Vector3D<int> daughter(mother, 0);
        Point3D<int> tmp(daughter);
        std::cout << mother << std::endl;
        std::cout << daughter << std::endl;
        std::cout << tmp << std::endl;
    }
