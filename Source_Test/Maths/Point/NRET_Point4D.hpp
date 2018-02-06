
    /**
     * @file NRET_Point4D.hpp
     * @brief Test of Engine's Maths's Object : Point4D
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
    void testConstructorBase();
    void testConstructorAdd();
    void testCopyConstructor();
    void testConvertorType();
    void testConvertorVector();

    void mainTest() {
        testConstructorAtomic();
        testConstructorBase();
        testConstructorAdd();
        testCopyConstructor();
        testConvertorType();
        testConvertorVector();
    }

    void testConstructorAtomic() {
        Point4D<int> tmp(1, 2, 3, 4);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
    }

    void testConstructorBase() {
        Point3D<int> b(1, 2, 3);
        Point4D<int> tmp(b, 4);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
    }

    void testConstructorAdd() {
        Point4D<int> p(1, 2, 3, 4);
        Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
        Point4D<int> tmp(p, u);

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
    }

    void testCopyConstructor() {
        Point4D<int> p(1, 2, 3, 4), tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
    }

    void testConvertorType() {
        Point4D<float> p(1.4, 2.4, 3.4, 4.4);
        Point4D<int> tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
    }

    void testConvertorVector() {
        Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
        Point4D<int> tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
    }
