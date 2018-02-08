
    /**
     * @file NRET_Matrix4x4.hpp
     * @brief Test of Engine's Maths's Object : Matrix4x4
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include <cassert>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    void testConstructorAtomic();

    void mainTest() {
        testConstructorAtomic();
    }

    void testConstructorAtomic() {
        Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

        assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
               tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
    }

    void testConstructorVector() {
        Vector4D<float> l1(1.4, 2.4, 3.4, 4.4), l2(5.4, 6.4, 7.4, 8.4), l3(9.4, 10.4, 11.4, 12.4), l4(13.4, 14.4, 15.4, 16.4);
        Matrix4x4<int> tmp(l1, l2, l3, l4);

        assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
               tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
    }

    void testConstructorPoint() {
        Point4D<float> l1(1.4, 2.4, 3.4, 4.4), l2(5.4, 6.4, 7.4, 8.4), l3(9.4, 10.4, 11.4, 12.4), l4(13.4, 14.4, 15.4, 16.4);
        Matrix4x4<int> tmp(l1, l2, l3, l4);

        assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
               tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
    }

    void testCopyConstructor() {
        Matrix4x4<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16), tmp(m);

        assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
               tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
    }

    void testConvertor() {
        Matrix4x4<float> m(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4, 10.4, 11.4, 12.4, 13.4, 14.4, 15.4, 16.4),
        Matrix4x4<int> tmp(m);

        assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
               tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
    }
