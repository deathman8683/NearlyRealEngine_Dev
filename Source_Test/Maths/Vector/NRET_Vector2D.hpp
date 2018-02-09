
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

    class TestVector2D {
        public:
            static void main() {
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

        private:
            static void testConstructorAtomic() {
                Vector2D<int> tmp(1, 2);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConstructorPoint() {
                Point2D<int> p(1, 2);
                Point2D<float> q(2, 3);
                Vector2D<int> tmp(p, q);

                assert(tmp.getX() == 1 && tmp.getY() == 1);
            }

            static void testCopyConstructor() {
                Vector2D<int> u(1, 2), tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConvertorType() {
                Vector2D<float> u(1.4, 2.4);
                Vector2D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testConvertorPoint() {
                Point2D<float> p(1.4, 2.4);
                Vector2D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testGetX() {
                Vector2D<int> tmp(1, 2);

                assert(tmp.getX() == 1);
            }

            static void testGetY() {
                Vector2D<int> tmp(1, 2);

                assert(tmp.getY() == 2);
            }

            static void testSetX() {
                Vector2D<int> tmp(1, 2);
                tmp.setX(3.4);

                assert(tmp.getX() == 3);
            }

            static void testSetY() {
                Vector2D<int> tmp(1, 2);
                tmp.setY(4.4);

                assert(tmp.getY() == 4);
            }

            static void testSetCoord() {
                Vector2D<int> tmp(1, 2);
                tmp.setCoord(3.4, 4.4);

                assert(tmp.getX() == 3 && tmp.getY() == 4);
            }

            static void testNorm() {
                Vector2D<int> tmp(0, 10);

                assert(tmp.norm() == 10.0);
            }

            static void testNormSquared() {
                Vector2D<int> tmp(0, 10);

                assert(tmp.normSquared() == 100.0);
            }

            static void testNormalize() {
                Vector2D<float> tmp(0, 10);
                tmp.normalize();

                assert(tmp.getX() == 0 && tmp.getY() == 1.0);
            }

            static void testRotate() {
                Vector2D<float> tmp(5, 10);
                tmp.rotate(90);

                assert(almostEqual(tmp.getX(), -10) && almostEqual(tmp.getY(), 5));
            }

            static void testOperatorShortAdd() {
                Vector2D<int> tmp(1, 2);
                Vector2D<float> u(1.4, 2.4);
                tmp += u;

                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorShortSub() {
                Vector2D<int> tmp(2, 3);
                Vector2D<float> u(1.4, 2.4);
                tmp -= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0);
            }

            static void testOperatorShortMult() {
                Vector2D<int> tmp(1, 2);
                float k = 2.2;
                tmp *= k;

                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorShortDiv() {
                Vector2D<int> tmp(2, 4);
                float k = 1.2;
                tmp /= k;

                assert(tmp.getX() == 1 && tmp.getY() == 3);
            }

            static void testOperatorShortScalar() {
                Vector2D<int> tmp(2, 4);
                Vector2D<float> u(2.4, 4.4);

                assert(almostEqual((tmp |= u), 22.4));
            }

            static void testOperatorAdd() {
                Vector2D<int> u(1, 2);
                Vector2D<float> v(1.4, 2.4);
                Vector2D<int> tmp = u + v;

                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorSub() {
                Vector2D<int> u(2, 3);
                Vector2D<float> v(1.4, 2.4);
                Vector2D<int> tmp = u - v;

                assert(tmp.getX() == 0 && tmp.getY() == 0);
            }

            static void testOperatorNegate() {
                Vector2D<int> tmp(-1, -2);
                tmp = -tmp;

                assert(tmp.getX() == 1 && tmp.getY() == 2);
            }

            static void testOperatorMult() {
                Vector2D<int> u(1, 2);
                float k = 2.2;
                Vector2D<int> tmp = u * k;

                assert(tmp.getX() == 2 && tmp.getY() == 4);
            }

            static void testOperatorDiv() {
                Vector2D<int> u(2, 4);
                float k = 1.2;
                Vector2D<int> tmp = u / k;

                assert(tmp.getX() == 1 && tmp.getY() == 3);
            }

            static void testOperatorEqual() {
                Vector2D<int> u(1, 2), v(1, 2);

                assert(u == v);
            }

            static void testOperatorNotEqual() {
                Vector2D<int> u(1, 2), v(3, 4);

                assert(u != v);
            }

            static void testOperatorInferior() {
                Vector2D<int> u(1, 2), v(3, 4);

                assert(u < v);
            }

            static void testOperatorSuperior() {
                Vector2D<int> u(1, 2), v(3, 4);

                assert(v > u);
            }

            static void testOperatorScalar() {
                Vector2D<int> u(2, 4);
                Vector2D<float> v(2.4, 4.4);
                assert(almostEqual((u | v), 22.4));
            }

            static void testOStream() {
                std::ostringstream stream; Vector2D<int> tmp(1, 2);
                stream << tmp;
                assert(stream.str() == "(1,2)");
            }
    };
