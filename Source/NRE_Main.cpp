
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    int main(int argc, char **argv) {
        Point4D<int> l1(1, 2, 3, 4), l2, l3;
        std::cout << l1 << std::endl;
        l2.setCoord(1, 1, 1, 1);
        l3.setCoord(1, 2, 3, 4);
        l1 = l2;
        std::cout << l1 << std::endl;
        std::cout << l3 << std::endl;

        Point3D<int> c1;
        c1.setCoord(1, 2, 3);
        std::cout << c1 << std::endl;
    }
