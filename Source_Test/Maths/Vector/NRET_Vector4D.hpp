
    /**
     * @file NRET_Vector4D.hpp
     * @brief Test of Engine's Maths's Object : Vector4D
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestVector4D {
        public:
            static void main() {
                testConstructorAtomic();
                testConstructorBase();
                testConstructorPoint();
                testCopyConstructor();
                testConvertorType();
                testConvertorPoint();
                testGetW();
                testSetW();
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
                Vector4D<int> tmp(1, 2, 3, 4);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConstructorBase() {
                Vector3D<int> u(1, 2, 3);
                Vector4D<int> tmp(u, 4);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConstructorPoint() {
                Point4D<int> p(1, 2, 3, 4), q(2, 3, 4, 5);
                Vector4D<int> tmp(p, q);

                assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1 && tmp.getW() == 1);
            }

            static void testCopyConstructor() {
                Vector4D<int> u(1, 2, 3, 4), tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConvertorType() {
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                Vector4D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConvertorPoint() {
                Point4D<float> p(1.4, 2.4, 3.4, 4.4);
                Vector4D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testGetW() {
                Vector4D<int> tmp(1, 2, 3, 4);

                assert(tmp.getW() == 4);
            }

            static void testSetW() {
                Vector4D<int> tmp(1, 2, 3, 4);
                tmp.setW(5.4);

                assert(tmp.getW() == 5);
            }

            static void testSetCoordAtomic() {
                Vector4D<int> tmp(1, 2, 3, 4);
                tmp.setCoord(5.4, 6.4, 7.4, 8.4);

                assert(tmp.getX() == 5 && tmp.getY() == 6 && tmp.getZ() == 7 && tmp.getW() == 8);
            }

            static void testSetCoordBase() {
                Vector4D<int> tmp(1, 2, 3, 4);
                Vector3D<float> u(5.4, 6.4, 7.4);
                tmp.setCoord(u, 8.4);

                assert(tmp.getX() == 5 && tmp.getY() == 6 && tmp.getZ() == 7 && tmp.getW() == 8);
            }

            static void testNorm() {
                Vector4D<int> tmp(0, 0, 0, 10);

                assert(tmp.norm() == 10.0);
            }

            static void testNormSquared() {
                Vector4D<int> tmp(0, 0, 0, 10);

                assert(tmp.normSquared() == 100.0);
            }

            static void testNormalize() {
                Vector4D<float> tmp(0, 0, 0, 10);
                tmp.normalize();

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0 && tmp.getW() == 1.0);
            }

            static void testOperatorShortAdd() {
                Vector4D<int> tmp(1, 2, 3, 4);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                tmp += u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testOperatorShortSub() {
                Vector4D<int> tmp(2, 3, 4, 5);
                Vector4D<float> u (1.4, 2.4, 3.4, 4.4);
                tmp -= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0 && tmp.getW() == 0);
            }

            static void testOperatorShortMult() {
                Vector4D<int> tmp(1, 2, 3, 4);
                float k = 2.2;
                tmp *= k;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testOperatorShortDiv() {
                Vector4D<int> tmp(2, 3, 4, 5);
                float k = 1.2;
                tmp /= k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testOperatorShortScalar() {
                Vector4D<int> tmp(2, 4, 6, 8);
                Vector4D<float> u(2.4, 4.4, 6.6, 8.4);

                assert(almostEqual((tmp |= u), 129.2));
            }

            static void testOperatorAdd() {
                Vector4D<int> u(1, 2, 3, 4);
                Vector4D<float> v(1.4, 2.4, 3.4, 4.4);
                Vector4D<int> tmp = u + v;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testOperatorSub() {
                Vector4D<int> u(2, 3, 4, 5);
                Vector4D<float> v (1.4, 2.4, 3.4, 4.4);
                Vector4D<int> tmp = u - v;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0 && tmp.getW() == 0);
            }

            static void testOperatorNegate() {
                Vector4D<int> tmp(-1, -2, -3, -4);
                tmp = -tmp;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testOperatorMult() {
                Vector4D<int> u(1, 2, 3, 4);
                float k = 1.2;
                Vector4D<int> tmp = u * k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testOperatorDiv() {
                Vector4D<int> u(2, 3, 4, 5);
                float k = 1.2;
                Vector4D<int> tmp = u / k;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testOperatorEqual() {
                Vector4D<int> u(1, 2, 3, 4), v(1, 2, 3, 4);

                assert(u == v);
            }

            static void testOperatorNotEqual() {
                Vector4D<int> u(1, 2, 3, 4), v(5, 6, 7, 8);

                assert(u != v);
            }

            static void testOperatorInferior() {
                Vector4D<int> u(1, 2, 3, 4), v(5, 6, 7, 8);

                assert(u < v);
            }

            static void testOperatorSuperior() {
                Vector4D<int> u(1, 2, 3, 4), v(5, 6, 7, 8);

                assert(v > u);
            }

            static void testOperatorScalar() {
                Vector4D<int> u(2, 4, 6, 8);
                Vector4D<float> v(2.4, 4.4, 6.6, 8.4);

                assert(almostEqual((u | v), 129.2));
            }

            static void testOStream() {
                std::ostringstream stream; Vector4D<int> tmp(1, 2, 3, 4);
                stream << tmp;
                assert(stream.str() == "(1,2,3,4)");
            }
    };
