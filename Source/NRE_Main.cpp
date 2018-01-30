
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/Point/NRE_Point2D.hpp"
    #include "Maths/Vector/NRE_Vector2D.hpp"

    int main(int argc, char **argv) {
        NRE::Maths::Point2D<NREfloat> tmp(10, 0);
        NRE::Maths::Point2D<NREfloat> res(10, 0);
        std::cout << tmp.distance(res) << std::endl;
        std::cout << res.distance(tmp) << std::endl;
        std::cout << (tmp == res) << std::endl;
    }
