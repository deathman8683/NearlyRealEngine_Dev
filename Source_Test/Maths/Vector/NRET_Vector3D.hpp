
    /**
     * @file NRET_Vector3D.hpp
     * @brief Test of Engine's Maths's Object : Vector3D
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
    void testConstructorPoint();
    void testCopyConstructor();
    void testConvertorType();
    void testConvertorPoint();
    void testGetZ();
    void testSetZ();
    void testSetCoordAtomic();
    void testSetCoordBase();
    void testNorm();
    void testNormSquared();
    void testNormalize();
    void testOperatorShortAdd();
    void testOperatorShortSub();
    void testOperatorShortMult();
    void testOperatorShortDiv();
    void testOperatorShortScalar();
    void testOperatorShortVectorial();
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
    void testOperatorVectorial();
    void testOStream();

    void mainTest() {
        testConstructorAtomic();
        testConstructorBase();
        testConstructorPoint();
        testCopyConstructor();
        testConvertorType();
        testConvertorPoint();
        testGetZ();
        testSetZ();
        testSetCoordAtomic();
        testSetCoordBase();
        testNorm();
        testNormSquared();
        testNormalize();
        testOperatorShortAdd();
        testOperatorShortSub();
        testOperatorShortMult();
        testOperatorShortDiv();
        testOperatorShortScalar();
        testOperatorShortVectorial();
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
        testOperatorVectorial();
        testOStream();
    }

    void testConstructorAtomic() {
        Vector3D<int> tmp(1, 2, 3);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConstructorBase() {
        Vector2D<float> u(1.4, 2.4);
        Vector3D<int> tmp(u, 3);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConstructorPoint() {
        Point3D<int> p(1, 2, 3), q(2, 3, 4);
        Vector3D<int> tmp(p, q);

        assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1);
    }

    void testCopyConstructor() {
        Vector3D<int> u(1, 2, 3), tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConvertorType() {
        Vector3D<float> u(1.4, 2.4, 3.4);
        Vector3D<int> tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConvertorPoint() {
        Point3D<float> p(1.4, 2.4, 3.4);
        Vector3D<int> tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testGetZ() {
        Vector3D<int> tmp(1, 2, 3);

        assert(tmp.getZ() == 3);
    }

    void testSetZ() {
        Vector3D<int> tmp(1, 2, 3);
        tmp.setZ(4.4);

        assert(tmp.getZ() == 4);
    }

    void testSetCoordAtomic() {
        Vector3D<int> tmp(1, 2, 3);
        tmp.setCoord(4.4, 5.4, 6.4);

        assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
    }

    void testSetCoordBase() {
        Vector2D<float> u(4.4, 5.4);
        Vector3D<int> tmp(1, 2, 3);
        tmp.setCoord(u, 6.4);

        assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
    }

    void testNorm() {
        Vector3D<int> tmp(0, 0, 10);

        assert(tmp.norm() == 10.0);
    }

    void testNormSquared() {
        Vector3D<int> tmp(0, 0, 10);

        assert(tmp.normSquared() == 100.0);
    }

    void testNormalize() {
        Vector3D<float> tmp(0, 0, 10);
        tmp.normalize();

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1.0);
    }

    void testOperatorShortAdd() {
        Vector3D<int> tmp(1, 2, 3);
        Vector3D<float> u(1.4, 2.4, 3.4);
        tmp += u;

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testOperatorShortSub() {
        Vector3D<int> tmp(2, 3, 4);
        Vector3D<float> u (1.4, 2.4, 3.4);
        tmp -= u;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
    }

    void testOperatorShortMult() {
        Vector3D<int> tmp(1, 2, 3);
        float k = 2.2;
        tmp *= k;

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testOperatorShortDiv() {
        Vector3D<int> tmp(2, 3, 4);
        float k = 1.2;
        tmp /= k;

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testOperatorShortScalar() {
        Vector3D<int> tmp(2, 4, 6);
        Vector3D<float> u(2.4, 4.4, 6.6);

        assert(almostEqual((tmp |= u), 62.0));
    }

    void testOperatorShortVectorial() {
        Vector3D<int> tmp(1, 0, 0);
        Vector3D<int> u(0, 1, 0);
        tmp ^= u;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1);
    }

    void testOperatorAdd() {
        Vector3D<int> u(1, 2, 3);
        Vector3D<float> v(1.4, 2.4, 3.4);
        Vector3D<int> tmp = u + v;

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testOperatorSub() {
        Vector3D<int> u(2, 3, 4);
        Vector3D<float> v (1.4, 2.4, 3.4);
        Vector3D<int> tmp = u - v;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
    }

    void testOperatorNegate() {
        Vector3D<int> tmp(-1, -2, -3);
        tmp = -tmp;

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testOperatorMult() {
        Vector3D<int> u(1, 2, 3);
        float k = 1.2;
        Vector3D<int> tmp = u * k;

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testOperatorDiv() {
        Vector3D<int> u(2, 3, 4);
        float k = 1.2;
        Vector3D<int> tmp = u / k;

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testOperatorEqual() {
        Vector3D<int> u(1, 2, 3), v(1, 2, 3);

        assert(u == v);
    }

    void testOperatorNotEqual() {
        Vector3D<int> u(1, 2, 3), v(4, 5, 6);

        assert(u != v);
    }

    void testOperatorInferior() {
        Vector3D<int> u(1, 2, 3), v(4, 5, 6);

        assert(u < v);
    }

    void testOperatorSuperior() {
        Vector3D<int> u(1, 2, 3), v(4, 5, 6);

        assert(v > u);
    }

    void testOperatorScalar() {
        Vector3D<int> u(2, 4, 6);
        Vector3D<float> v(2.4, 4.4, 6.6);

        assert(almostEqual((u | v), 62.0));
    }

    void testOperatorVectorial() {
        Vector3D<int> u(1, 0, 0);
        Vector3D<int> v(0, 1, 0);
        Vector3D<int> tmp = u ^ v;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1);
    }

    void testOStream() {
        std::ostringstream stream; Vector3D<int> tmp(1, 2, 3);
        stream << tmp;
        assert(stream.str() == "(1,2,3)");
    }
