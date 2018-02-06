
    #include <iostream>

    #include "Generic/NRE_Type.hpp"
    #include "Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    int main(int argc, char **argv) {
        Matrix4x4<NREfloat> tmp;
        std::cout << tmp << std::endl;
        tmp.rotate(90, Vector3D<NREfloat>(0, 0, 1));
        std::cout << tmp << std::endl;
        tmp.setIdentity();
        tmp.projection(90, 16/9, 0.1, 100);
        std::cout << tmp << std::endl;
        tmp.setIdentity();
        tmp.lookAt(Point3D<NREfloat>(0, 0, 0), Point3D<NREfloat>(10, 0, 0), Vector3D<NREfloat>(0, 0, 1));
        std::cout << tmp << std::endl;
    }
