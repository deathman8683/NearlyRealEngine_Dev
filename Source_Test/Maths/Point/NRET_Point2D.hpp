
    /**
     * @file NRET_Point2D.hpp
     * @brief Test of Engine's Maths's Object : Point2D
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
    void testConstructorAdd();
    void testCopyConstructor();
    void testConvertorType();
    void testConvertorVector();
    void testGetX();
    void testGetY();
    void testSetX();
    void testSetY();
    void testSetCoord();
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
        testConstructorAdd();
        testCopyConstructor();
        testConvertorType();
        testConvertorVector();
        testGetX();
        testGetY();
        testSetX();
        testSetY();
        testSetCoord();
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
        Point2D<int> tmp(1, 2);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConstructorAdd() {
        Point2D<int> p(1, 2); Vector2D<float> u(1.4, 2.4);
        Point2D<int> tmp(p, u);

        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testCopyConstructor() {
        Point2D<int> p(1, 2), tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConvertorType() {
        Point2D<float> p(1.4, 2.4); Point2D<int> tmp(p);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testConvertorVector() {
        Vector2D<float> u(1.4, 2.4); Point2D<int> tmp(u);

        assert(tmp.getX() == 1 && tmp.getY() == 2);
    }

    void testGetX() {
        Point2D<int> tmp(1, 2);

        assert(tmp.getX() == 1);
    }

    void testGetY() {
        Point2D<int> tmp(1, 2);

        assert(tmp.getY() == 2);
    }

    void testSetX() {
        Point2D<int> tmp(1, 2);
        tmp.setX(3.4);

        assert(tmp.getX() == 3);
    }

    void testSetY() {
        Point2D<int> tmp(1, 2);
        tmp.setY(3.4);

        assert(tmp.getY() == 3);
    }

    void testSetCoord() {
        Point2D<int> tmp(1, 2);
        tmp.setCoord(3.4, 4.4);

        assert(tmp.getX() == 3 && tmp.getY() == 4);
    }

    void testDistanceOrigin() {
        Point2D<int> tmp(0, 10);

        assert(tmp.distance() == 10.0);
    }

    void testDistancePoint() {
        Point2D<int> p(10, 10), tmp(10, 20);

        assert(tmp.distance(p) == 10.0);
    }

    void testDistanceSquaredOrigin() {
        Point2D<int> tmp(0, 10);

        assert(tmp.distanceSquared() == 100.0);
    }

    void testDistanceSquaredPoint() {
        Point2D<int> p(10, 10), tmp(10, 20);

        assert(tmp.distanceSquared(p) == 100.0);
    }

    void testOperatorShortAdd() {
        Point2D<int> tmp(1, 2);
        Vector2D<float> u(1.4, 2.4);

        tmp += u;
        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorShortSub() {
        Point2D<int> tmp(2, 3);
        Vector2D<float> u(1.4, 2.4);

        tmp -= u;
        assert(tmp.getX() == 0 && tmp.getY() == 0);
    }

    void testOperatorAdd() {
        Point2D<int> p(1, 2);
        Vector2D<float> u(1.4, 2.4);

        Point2D<int> tmp = p + u;
        assert(tmp.getX() == 2 && tmp.getY() == 4);
    }

    void testOperatorSub() {
        Point2D<int> p(2, 3);
        Vector2D<float> u(1.4, 2.4);

        Point2D<int> tmp = p - u;
        assert(tmp.getX() == 0 && tmp.getY() == 0);
    }

    void testOperatorSubPoint() {
        Point2D<int> p(2, 3);
        Point2D<float> q(3.4, 4.4);

        Vector2D<int> tmp = p - q;
        assert(tmp.getX() == 1 && tmp.getY() == 1);
    }

    void testOperatorNegate() {
        Point2D<int> tmp(2, 3);

        tmp = -tmp;
        assert(tmp.getX() == -2 && tmp.getY() == -3);
    }

    void testOperatorEqual() {
        Point2D<int> p(1, 2), q(1, 2);
        assert(p == q);
    }

    void testOperatorNotEqual() {
        Point2D<int> p(1, 2), q(2, 3);
        assert(p != q);
    }

    void testOperatorInferior() {
        Point2D<int> p(1, 2), q(2, 3);
        assert(p < q);
    }

    void testOperatorSuperior() {
        Point2D<int> p(1, 2), q(2, 3);
        assert(q > p);
    }

    void testOStream() {
        std::ostringstream stream; Point2D<int> tmp(1, 2);
        stream << tmp;
        assert(stream.str() == "(1,2)");
    }
