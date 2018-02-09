
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

    class TestPoint2D {
        public:
            static void main() {
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

        private:
            static void testConstructorAtomic() {
                Point2D<int> tmp(1, 2);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConstructorAdd() {
                Point2D<int> p(1, 2); Vector2D<float> u(1.4, 2.4);
                Point2D<int> tmp(p, u);

                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testCopyConstructor() {
                Point2D<int> p(1, 2), tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConvertorType() {
                Point2D<float> p(1.4, 2.4); Point2D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConvertorVector() {
                Vector2D<float> u(1.4, 2.4); Point2D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testGetX() {
                Point2D<int> tmp(1, 2);

                assert(tmp.getX() == 1);
            }

            static void testGetY() {
                Point2D<int> tmp(1, 2);

                assert(tmp.getY() == 2);
            }

            static void testSetX() {
                Point2D<int> tmp(1, 2);
                tmp.setX(3.4);

                assert(tmp.getX() == 3);
            }

            static void testSetY() {
                Point2D<int> tmp(1, 2);
                tmp.setY(3.4);

                assert(tmp.getY() == 3);
            }

            static void testSetCoord() {
                Point2D<int> tmp(1, 2);
                tmp.setCoord(3.4, 4.4);

                assert(tmp.getX() == 3 && tmp.getY() == 4);
            }

            static void testDistanceOrigin() {
                Point2D<int> tmp(0, 10);

                assert(tmp.distance() == 10.0);
            }

            static void testDistancePoint() {
                Point2D<int> p(10, 10), tmp(10, 20);

                assert(tmp.distance(p) == 10.0);
            }

            static void testDistanceSquaredOrigin() {
                Point2D<int> tmp(0, 10);

                assert(tmp.distanceSquared() == 100.0);
            }

            static void testDistanceSquaredPoint() {
                Point2D<int> p(10, 10), tmp(10, 20);

                assert(tmp.distanceSquared(p) == 100.0);
            }

            static void testOperatorShortAdd() {
                Point2D<int> tmp(1, 2);
                Vector2D<float> u(1.4, 2.4);

                tmp += u;
                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorShortSub() {
                Point2D<int> tmp(2, 3);
                Vector2D<float> u(1.4, 2.4);

                tmp -= u;
                assert(tmp.getX() == 0 && tmp.getY() == 0);
            }

            static void testOperatorAdd() {
                Point2D<int> p(1, 2);
                Vector2D<float> u(1.4, 2.4);

                Point2D<int> tmp = p + u;
                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorSub() {
                Point2D<int> p(2, 3);
                Vector2D<float> u(1.4, 2.4);

                Point2D<int> tmp = p - u;
                assert(tmp.getX() == 0 && tmp.getY() == 0);
            }

            static void testOperatorSubPoint() {
                Point2D<int> p(2, 3);
                Point2D<float> q(3.4, 4.4);

                Vector2D<int> tmp = p - q;
                assert(tmp.getX() == 1 && tmp.getY() == 1);
            }

            static void testOperatorNegate() {
                Point2D<int> tmp(2, 3);

                tmp = -tmp;
                assert(tmp.getX() == -2 && tmp.getY() == -3);
            }

            static void testOperatorEqual() {
                Point2D<int> p(1, 2), q(1, 2);
                assert(p == q);
            }

            static void testOperatorNotEqual() {
                Point2D<int> p(1, 2), q(2, 3);
                assert(p != q);
            }

            static void testOperatorInferior() {
                Point2D<int> p(1, 2), q(2, 3);
                assert(p < q);
            }

            static void testOperatorSuperior() {
                Point2D<int> p(1, 2), q(2, 3);
                assert(q > p);
            }

            static void testOStream() {
                std::ostringstream stream; Point2D<int> tmp(1, 2);
                stream << tmp;
                assert(stream.str() == "(1,2)");
            }

    };
