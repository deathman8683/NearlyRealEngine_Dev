
    /**
     * @file NRET_Vector3D.hpp
     * @brief Test of Engine's Maths's Object : Vector3D
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestVector3D {
        public:
            static void main() {
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

        private:
            static void testConstructorAtomic() {
                Vector3D<int> tmp(1, 2, 3);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConstructorBase() {
                Vector2D<float> u(1.4, 2.4);
                Vector3D<int> tmp(u, 3);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConstructorPoint() {
                Point3D<int> p(1, 2, 3), q(2, 3, 4);
                Vector3D<int> tmp(p, q);

                assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1);
            }

            static void testCopyConstructor() {
                Vector3D<int> u(1, 2, 3), tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConvertorType() {
                Vector3D<float> u(1.4, 2.4, 3.4);
                Vector3D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConvertorPoint() {
                Point3D<float> p(1.4, 2.4, 3.4);
                Vector3D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testGetZ() {
                Vector3D<int> tmp(1, 2, 3);

                assert(tmp.getZ() == 3);
            }

            static void testSetZ() {
                Vector3D<int> tmp(1, 2, 3);
                tmp.setZ(4.4);

                assert(tmp.getZ() == 4);
            }

            static void testSetCoordAtomic() {
                Vector3D<int> tmp(1, 2, 3);
                tmp.setCoord(4.4, 5.4, 6.4);

                assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
            }

            static void testSetCoordBase() {
                Vector2D<float> u(4.4, 5.4);
                Vector3D<int> tmp(1, 2, 3);
                tmp.setCoord(u, 6.4);

                assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
            }

            static void testNorm() {
                Vector3D<int> tmp(0, 0, 10);

                assert(tmp.norm() == 10.0);
            }

            static void testNormSquared() {
                Vector3D<int> tmp(0, 0, 10);

                assert(tmp.normSquared() == 100.0);
            }

            static void testNormalize() {
                Vector3D<float> tmp(0, 0, 10);
                tmp.normalize();

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1.0);
            }

            static void testOperatorShortAdd() {
                Vector3D<int> tmp(1, 2, 3);
                Vector3D<float> u(1.4, 2.4, 3.4);
                tmp += u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testOperatorShortSub() {
                Vector3D<int> tmp(2, 3, 4);
                Vector3D<float> u (1.4, 2.4, 3.4);
                tmp -= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
            }

            static void testOperatorShortMult() {
                Vector3D<int> tmp(1, 2, 3);
                float k = 2.2;
                tmp *= k;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testOperatorShortDiv() {
                Vector3D<int> tmp(2, 3, 4);
                float k = 1.2;
                tmp /= k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testOperatorShortScalar() {
                Vector3D<int> tmp(2, 4, 6);
                Vector3D<float> u(2.4, 4.4, 6.6);

                assert(almostEqual((tmp |= u), 62.0));
            }

            static void testOperatorShortVectorial() {
                Vector3D<int> tmp(1, 0, 0);
                Vector3D<int> u(0, 1, 0);
                tmp ^= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1);
            }

            static void testOperatorAdd() {
                Vector3D<int> u(1, 2, 3);
                Vector3D<float> v(1.4, 2.4, 3.4);
                Vector3D<int> tmp = u + v;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testOperatorSub() {
                Vector3D<int> u(2, 3, 4);
                Vector3D<float> v (1.4, 2.4, 3.4);
                Vector3D<int> tmp = u - v;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
            }

            static void testOperatorNegate() {
                Vector3D<int> tmp(-1, -2, -3);
                tmp = -tmp;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testOperatorMult() {
                Vector3D<int> u(1, 2, 3);
                float k = 1.2;
                Vector3D<int> tmp = u * k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testOperatorDiv() {
                Vector3D<int> u(2, 3, 4);
                float k = 1.2;
                Vector3D<int> tmp = u / k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testOperatorEqual() {
                Vector3D<int> u(1, 2, 3), v(1, 2, 3);

                assert(u == v);
            }

            static void testOperatorNotEqual() {
                Vector3D<int> u(1, 2, 3), v(4, 5, 6);

                assert(u != v);
            }

            static void testOperatorInferior() {
                Vector3D<int> u(1, 2, 3), v(4, 5, 6);

                assert(u < v);
            }

            static void testOperatorSuperior() {
                Vector3D<int> u(1, 2, 3), v(4, 5, 6);

                assert(v > u);
            }

            static void testOperatorScalar() {
                Vector3D<int> u(2, 4, 6);
                Vector3D<float> v(2.4, 4.4, 6.6);

                assert(almostEqual((u | v), 62.0));
            }

            static void testOperatorVectorial() {
                Vector3D<int> u(1, 0, 0);
                Vector3D<int> v(0, 1, 0);
                Vector3D<int> tmp = u ^ v;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 1);
            }

            static void testOStream() {
                std::ostringstream stream; Vector3D<int> tmp(1, 2, 3);
                stream << tmp;
                assert(stream.str() == "(1,2,3)");
            }
    };
