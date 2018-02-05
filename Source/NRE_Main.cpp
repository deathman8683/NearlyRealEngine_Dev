
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    int main(int argc, char **argv) {
        Matrix2x2<int> m1, m2;
        std::cout << m1 << std::endl;
        std::cout << m2 << std::endl;
        std::cout << m1 + m2 << std::endl;

        Matrix3x3<int> n1, n2;
        std::cout << n1 << std::endl;
        std::cout << n2 << std::endl;
        std::cout << n1 + n2 << std::endl;

        Point3D<int> l1, l2, l3;
        Matrix3x3<int> n3(l1, l2, l3);
        std::cout << n3 << std::endl;
    }
