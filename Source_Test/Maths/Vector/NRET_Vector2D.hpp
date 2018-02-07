
    /**
     * @file NRET_Vector2D.hpp
     * @brief Test of Engine's Maths's Object : Vector2D
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
    void testConstructorPoint();
    void testCopyConstructor();
    void testConvertorType();
    void testConvertorPoint();
    void testGetX();
    void testGetY();
    void testSetX();
    void testSetY();
    void testSetCoord();
    void testNorm();
    void testNormSquared();
    void testNormalize();
    void testRotate();
    void testOperatorShortAdd();
    void testOperatorShortSub();
    void testOperatorShortMult();
    void testOperatorShortDiv();
    void testOperatorShortScalar();
    void testOperatorAdd();
    void testOperatorSub();
    void testOperatorNegate();
    void testOperatorMult();
    void testOperatorDiv();
    void testOperatorEqual();
    void testOperatorNotEqual();
    void testOperatorInferior();
    void testOperatorSuperior();
    void testOperatorScalar();
    void testOStream();

    void mainTest() {
        testConstructorAtomic();
        testConstructorPoint();
        testCopyConstructor();
        testConvertorType();
        testConvertorPoint();
        testGetX();
        testGetY();
        testSetX();
        testSetY();
        testSetCoord();
        testNorm();
        testNormSquared();
        testNormalize();
        testRotate();
        testOperatorShortAdd();
        testOperatorShortSub();
        testOperatorShortMult();
        testOperatorShortDiv();
        testOperatorShortScalar();
        testOperatorAdd();
        testOperatorSub();
        testOperatorNegate();
        testOperatorMult();
        testOperatorDiv();
        testOperatorEqual();
        testOperatorNotEqual();
        testOperatorInferior();
        testOperatorSuperior();
        testOperatorScalar();
        testOStream();
    }

    void testConstructorAtomic() {
        Vector2D<int> tmp(1, 2);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConstructorPoint() {
        Point2D<int> p(1, 2);
        Point2D<float> q(2, 3);
        Vector2D<int> tmp(p, q);

        assert(tmp.getX() == 1 && tmp.getY() == 1);
    }

    void testCopyConstructor() {
        Vector2D<int> u(1, 2), tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConvertorType() {
        Vector2D<float> u(1.4, 2.4);
        Vector2D<int> tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConvertorPoint() {
        Point2D<float> p(1.4, 2.4);
        Vector2D<int> tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testGetX() {
        Vector2D<int> tmp(1, 2);

        assert(tmp.getX() == 1);
    }

    void testGetY() {
        Vector2D<int> tmp(1, 2);

        assert(tmp.getY() == 2);
    }

    void testSetX() {
        Vector2D<int> tmp(1, 2);
        tmp.setX(3.4);

        assert(tmp.getX() == 3);
    }

    void testSetY() {
        Vector2D<int> tmp(1, 2);
        tmp.setY(4.4);

        assert(tmp.getY() == 4);
    }

    void testSetCoord() {
        Vector2D<int> tmp(1, 2);
        tmp.setCoord(3.4, 4.4);

        assert(tmp.getX() == 3 && tmp.getY() == 4);
    }

    void testNorm() {
        Vector2D<int> tmp(0, 10);

        assert(tmp.norm() == 10.0);
    }

    void testNormSquared() {
        Vector2D<int> tmp(0, 10);

        assert(tmp.normSquared() == 100.0);
    }

    void testNormalize() {
        Vector2D<float> tmp(0, 10);
        tmp.normalize();

        assert(tmp.getX() == 0 && tmp.getY() == 1.0);
    }

    void testRotate() {
        Vector2D<float> tmp(5, 10);
        tmp.rotate(90);

        assert(almostEqual(tmp.getX(), -10) && almostEqual(tmp.getY(), 5));
    }

    void testOperatorShortAdd() {
        Vector2D<int> tmp(1, 2);
        Vector2D<float> u(1.4, 2.4);
        tmp += u;

        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorShortSub() {
        Vector2D<int> tmp(2, 3);
        Vector2D<float> u(1.4, 2.4);
        tmp -= u;

        assert(tmp.getX() == 0 && tmp.getY() == 0);
    }

    void testOperatorShortMult() {
        Vector2D<int> tmp(1, 2);
        float k = 2.2;
        tmp *= k;

        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorShortDiv() {
        Vector2D<int> tmp(2, 4);
        float k = 1.2;
        tmp /= k;

        assert(tmp.getX() == 1 && tmp.getY() == 3);
    }

    void testOperatorShortScalar() {
        Vector2D<int> tmp(2, 4);
        Vector2D<float> u(2.4, 4.4);
        
        assert(almostEqual((tmp |= u), 22.4));
    }

    void testOperatorAdd() {
        Vector2D<int> u(1, 2);
        Vector2D<float> v(1.4, 2.4);
        Vector2D<int> tmp = u + v;

        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorSub() {
        Vector2D<int> u(2, 3);
        Vector2D<float> v(1.4, 2.4);
        Vector2D<int> tmp = u - v;

        assert(tmp.getX() == 0 && tmp.getY() == 0);
    }

    void testOperatorNegate() {
        Vector2D<int> tmp(-1, -2);
        tmp = -tmp;

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testOperatorMult() {
        Vector2D<int> u(1, 2);
        float k = 2.2;
        Vector2D<int> tmp = u * k;

        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorDiv() {
        Vector2D<int> u(2, 4);
        float k = 1.2;
        Vector2D<int> tmp = u / k;

        assert(tmp.getX() == 1 && tmp.getY() == 3);
    }

    void testOperatorEqual() {
        Vector2D<int> u(1, 2), v(1, 2);

        assert(u == v);
    }

    void testOperatorNotEqual() {
        Vector2D<int> u(1, 2), v(3, 4);

        assert(u != v);
    }

    void testOperatorInferior() {
        Vector2D<int> u(1, 2), v(3, 4);

        assert(u < v);
    }

    void testOperatorSuperior() {
        Vector2D<int> u(1, 2), v(3, 4);

        assert(v > u);
    }

    void testOperatorScalar() {
        Vector2D<int> u(2, 4);
        Vector2D<float> v(2.4, 4.4);
        assert(almostEqual((u | v), 22.4));
    }

    void testOStream() {
        std::ostringstream stream; Vector2D<int> tmp(1, 2);
        stream << tmp;
        assert(stream.str() == "(1,2)");
    }
