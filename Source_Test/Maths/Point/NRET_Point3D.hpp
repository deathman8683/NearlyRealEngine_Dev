
    /**
     * @file NRET_Point3D.hpp
     * @brief Test of Engine's Maths's Object : Point3D
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
    void testGetZ();
    void testSetZ();
    void testSetCoordAtomic();
    void testSetCoordBase();
    void testDistanceOrigin();
    void testDistancePoint();
    void testDistanceSquaredOrigin();
    void testDistanceSquaredPoint();
    void testOperatorShortAdd();
    void testOperatorShortSub();
    void testOperatorAdd();
    void testOperatorSub();
    void testOperatorSubPoint();
    void testOperatorNegate();
    void testOperatorEqual();
    void testOperatorNotEqual();
    void testOperatorInferior();
    void testOperatorSuperior();
    void testOStream();

    void mainTest() {
        testConstructorAtomic();
        testConstructorBase();
        testConstructorAdd();
        testCopyConstructor();
        testConvertorType();
        testConvertorVector();
        testGetZ();
        testSetZ();
        testSetCoordAtomic();
        testSetCoordBase();
        testDistanceOrigin();
        testDistancePoint();
        testDistanceSquaredOrigin();
        testDistanceSquaredPoint();
        testOperatorShortAdd();
        testOperatorShortSub();
        testOperatorAdd();
        testOperatorSub();
        testOperatorSubPoint();
        testOperatorNegate();
        testOperatorEqual();
        testOperatorNotEqual();
        testOperatorInferior();
        testOperatorSuperior();
        testOStream();
    }

    void testConstructorAtomic() {
        Point3D<int> tmp(1, 2, 3);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConstructorBase() {
        Point2D<int> b(1, 2);
        Point3D<int> tmp(b, 3);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConstructorAdd() {
        Point3D<int> p(1, 2, 3);
        Vector3D<float> u(1.4, 2.4, 3.4);
        Point3D<int> tmp(p, u);

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testCopyConstructor() {
        Point3D<int> p(1, 2, 3), tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConvertorType() {
        Point3D<float> p(1.4, 2.4, 3.4);
        Point3D<int> tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testConvertorVector() {
        Vector3D<float> u(1.4, 2.4, 3.4);
        Point3D<int> tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testGetZ() {
        Point3D<int> tmp(1, 2, 3);

        assert(tmp.getZ() == 3);
    }

    void testSetZ() {
        Point3D<int> tmp(1, 2, 3);
        tmp.setZ(4.4);

        assert(tmp.getZ() == 4);
    }

    void testSetCoordAtomic() {
        Point3D<int> tmp(1, 2, 3);
        tmp.setCoord(4.4, 5.4, 6.4);

        assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
    }

    void testSetCoordBase() {
        Point2D<float> b(4.4, 5.4);
        Point3D<int> tmp(1, 2, 3);
        tmp.setCoord(b, 6.4);

        assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
    }

    void testDistanceOrigin() {
        Point3D<int> tmp(0, 0, 10);

        assert(tmp.distance() == 10.0);
    }

    void testDistancePoint() {
        Point3D<int> p(10, 10, 10), tmp(10, 10, 20);


        assert(tmp.distance(p) == 10.0);
    }

    void testDistanceSquaredOrigin() {
        Point3D<int> tmp(0, 0, 10);

        assert(tmp.distanceSquared() == 100.0);
    }

    void testDistanceSquaredPoint() {
        Point3D<int> p(10, 10, 10), tmp(10, 10, 20);

        assert(tmp.distanceSquared(p) == 100.0);
    }

    void testOperatorShortAdd() {
        Point3D<int> tmp(1, 2, 3);
        Vector3D<float> u(1.4, 2.4, 3.4);
        tmp += u;

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testOperatorShortSub() {
        Point3D<int> tmp(2, 3, 4);
        Vector3D<float> u(1.4, 2.4, 3.4);
        tmp -= u;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
    }

    void testOperatorAdd() {
        Point3D<int> p(1, 2, 3);
        Vector3D<float> u(1.4, 2.4, 3.4);
        Point3D<int> tmp = p + u;

        assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
    }

    void testOperatorSub() {
        Point3D<int> p(2, 3, 4);
        Vector3D<float> u(1.4, 2.4, 3.4);
        Point3D<int> tmp = p - u;

        assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
    }

    void testOperatorSubPoint() {
        Point3D<int> p(1, 2, 3);
        Point3D<float> q(2.4, 3.4, 4.4);

        Vector3D<int> tmp = p - q;

        assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1);
    }

    void testOperatorNegate() {
        Point3D<int> tmp(-1, -2, -3);
        tmp = -tmp;

        assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
    }

    void testOperatorEqual() {
        Point3D<int> p(1, 2, 3), q(1, 2, 3);

        assert(p == q);
    }

    void testOperatorNotEqual() {
        Point3D<int> p(1, 2, 3), q(4, 5, 6);

        assert(p != q);
    }

    void testOperatorInferior() {
        Point3D<int> p(1, 2, 3), q(4, 5, 6);

        assert(p < q);
    }

    void testOperatorSuperior() {
        Point3D<int> p(1, 2, 3), q(4, 5, 6);

        assert(q > p);
    }

    void testOStream() {
        std::ostringstream stream; Point3D<int> tmp(1, 2, 3);
        stream << tmp;
        assert(stream.str() == "(1,2,3)");
    }
