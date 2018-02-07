
    /**
     * @file NRET_Matrix2x2.hpp
     * @brief Test of Engine's Maths's Object : Matrix2x2
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
    void testConstructorVector();
    void testConstructorPoint();
    void testCopyConstructor();
    void testConvertor();
    void testGetL1();
    void testGetL2();
    void testGetC1();
    void testGetC2();
    void testGetDeterminant();
    void testSetL1();
    void testSetL2();
    void testSetC1();
    void testSetC2();
    void testSetIdentity();
    void testTranspose();
    void testInverse();
    void testTranslate();
    void testScale();
    void testOperatorAccessRead();
    void testOperatorAccessWrite();
    void testOperatorAssign();
    void testOperatorShortAdd();
    void testOperatorShortSub();
    void testOperatorShortMult();
    void testOperatorMultMatrix();
    void testOperatorShortDiv();

    void mainTest() {
        testConstructorAtomic();
        testConstructorVector();
        testConstructorPoint();
        testCopyConstructor();
        testConvertor();
        testGetL1();
        testGetL2();
        testGetC1();
        testGetC2();
        testGetDeterminant();
        testSetL1();
        testSetL2();
        testSetC1();
        testSetC2();
        testSetIdentity();
        testTranspose();
        testInverse();
        testTranslate();
        testScale();
        testOperatorAccessRead();
        testOperatorAccessWrite();
        testOperatorAssign();
        testOperatorShortAdd();
        testOperatorShortSub();
        testOperatorShortMult();
        testOperatorMultMatrix();
        testOperatorShortDiv();
    }

    void testConstructorAtomic() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testConstructorVector() {
        Vector2D<float> l1(1.4, 2.4), l2(3.4, 4.4);
        Matrix2x2<int> tmp(l1, l2);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testConstructorPoint() {
        Point2D<float> l1(1.4, 2.4), l2(3.4, 4.4);
        Matrix2x2<int> tmp(l1, l2);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testCopyConstructor() {
        Matrix2x2<int> m(1, 2, 3, 4), tmp(m);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testConvertor() {
        Matrix2x2<float> m(1.4, 2.4, 3.4, 4.4);
        Matrix2x2<int> tmp(m);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testGetL1() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getL1() == Vector2D<int>(1, 2));
    }

    void testGetL2() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testGetC1() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getC1() == Vector2D<int>(1, 3));
    }

    void testGetC2() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getC2() == Vector2D<int>(2, 4));
    }

    void testGetDeterminant() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp.getDeterminant() == -2);
    }

    void testSetL1() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        Vector2D<float> u(5.4, 6.4);
        tmp.setL1(u);

        assert(tmp.getL1() == Vector2D<int>(5, 6) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testSetL2() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        Vector2D<float> u(5.4, 6.4);
        tmp.setL2(u);

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(5, 6));
    }

    void testSetC1() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        Vector2D<float> u(5.4, 6.4);
        tmp.setC1(u);

        assert(tmp.getL1() == Vector2D<int>(5, 2) && tmp.getL2() == Vector2D<int>(6, 4));
    }

    void testSetC2() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        Vector2D<float> u(5.4, 6.4);
        tmp.setC2(u);

        assert(tmp.getL1() == Vector2D<int>(1, 5) && tmp.getL2() == Vector2D<int>(3, 6));
    }

    void testSetIdentity() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        tmp.setIdentity();

        assert(tmp.getL1() == Vector2D<int>(1, 0) && tmp.getL2() == Vector2D<int>(0, 1));
    }

    void testTranspose() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        tmp.transpose();

        assert(tmp.getL1() == Vector2D<int>(1, 3) && tmp.getL2() == Vector2D<int>(2, 4));
    }

    void testInverse() {
        Matrix2x2<float> tmp(1, 2, 3, 4);
        tmp.inverse();

        assert(tmp.getL1() == Vector2D<float>(-2, 1) && tmp.getL2() == Vector2D<float>(3.0 / 2.0, -1.0 / 2.0));
    }

    void testTranslate() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        tmp.translate(8.4);

        assert(tmp.getL1() == Vector2D<int>(1, 10) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testScale() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        tmp.scale(9.4);

        assert(tmp.getL1() == Vector2D<int>(10, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testOperatorAccessRead() {
        Matrix2x2<int> tmp(1, 2, 3, 4);

        assert(tmp[0][0] == tmp.getL1().getX());
    }

    void testOperatorAccessWrite() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        tmp[0][0] = 5.4;

        assert(tmp.getL1() == Vector2D<int>(5, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testOperatorAssign() {
        Matrix2x2<float> m(1.4, 2.4, 3.4, 4.4);
        Matrix2x2<int> tmp = m;

        assert(tmp.getL1() == Vector2D<int>(1, 2) && tmp.getL2() == Vector2D<int>(3, 4));
    }

    void testOperatorShortAdd() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        Matrix2x2<float> m(1.4, 2.4, 3.4, 4.4);
        tmp += m;

        assert(tmp.getL1() == Vector2D<int>(2, 4) && tmp.getL2() == Vector2D<int>(6, 8));
    }

    void testOperatorShortSub() {
        Matrix2x2<int> tmp(2, 3, 4, 5);
        Matrix2x2<float> m(1.4, 2.4, 3.4, 4.4);
        tmp -= m;

        assert(tmp.getL1() == Vector2D<int>(0, 0) && tmp.getL2() == Vector2D<int>(0, 0));
    }

    void testOperatorShortMult() {
        Matrix2x2<int> tmp(1, 2, 3, 4);
        float k = 2.2;
        tmp *= k;

        assert(tmp.getL1() == Vector2D<int>(2, 4) && tmp.getL2() == Vector2D<int>(6, 8));
    }

    void testOperatorMultMatrix() {
        Matrix2x2<int> tmp(1, 2, 3, 4), m(2, 3, 4, 5);
        tmp *= m;
        
        assert(tmp.getL1() == Vector2D<int>(10, 13) && tmp.getL2() == Vector2D<int>(22, 29));
    }

    void testOperatorShortDiv() {
        Matrix2x2<float> tmp(1, 2, 3, 4), u(1, 2, 3, 4);
        tmp /= u;

        assert(tmp.getL1() == Vector2D<float>(1, 0) && tmp.getL2() == Vector2D<float>(0, 1));
    }
