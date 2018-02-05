
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    int main(int argc, char **argv) {
        Point4D<int> c1(11, 22, 33, 44), c2(1, 2, 3, 4);
        Vector4D<int> l1(c1, c2);
        std::cout << -l1 << std::endl;
    }
