
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/Point/NRE_Point2D.hpp"
    #include "Maths/Vector/NRE_Vector2D.hpp"
    #include "Maths/Matrix/NRE_Matrix2x2.hpp"

    int main(int argc, char **argv) {
        NRE::Maths::Point2D<int> p1, p2;
        NRE::Maths::Matrix2x2<double> tmp(p1, p2);
        NRE::Maths::Vector2D<double> c1(2, 1);
        tmp.setIdentity();
        int i = 10;
        tmp.translate(i);
        std::cout << tmp << std::endl;
        c1 = tmp * c1;
        std::cout << c1 << std::endl;
    }
