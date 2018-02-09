
    /**
     * @file NRET_Point4D.hpp
     * @brief Test of Engine's Maths's Object : Point4D
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestPoint4D {
        public:
            static void main() {
                testConstructorAtomic();
                testConstructorBase();
                testConstructorAdd();
                testCopyConstructor();
                testConvertorType();
                testConvertorVector();
                testGetW();
                testSetW();
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

        private:
            static void testConstructorAtomic() {
                Point4D<int> tmp(1, 2, 3, 4);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConstructorBase() {
                Point3D<int> b(1, 2, 3);
                Point4D<int> tmp(b, 4);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConstructorAdd() {
                Point4D<int> p(1, 2, 3, 4);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                Point4D<int> tmp(p, u);

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testCopyConstructor() {
                Point4D<int> p(1, 2, 3, 4), tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConvertorType() {
                Point4D<float> p(1.4, 2.4, 3.4, 4.4);
                Point4D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testConvertorVector() {
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                Point4D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testGetW() {
                Point4D<int> tmp(1, 2, 3, 4);

                assert(tmp.getW() == 4);
            }

            static void testSetW() {
                Point4D<int> tmp(1, 2, 3, 4);
                tmp.setW(5.4);

                assert(tmp.getW() == 5);
            }

            static void testSetCoordAtomic() {
                Point4D<int> tmp(1, 2, 3, 4);
                tmp.setCoord(5.4, 6.4, 7.4, 8.4);

                assert(tmp.getX() == 5 && tmp.getY() == 6 && tmp.getZ() == 7 && tmp.getW() == 8);
            }

            static void testSetCoordBase() {
                Point4D<int> tmp(1, 2, 3, 4);
                Point3D<float> b(5.4, 6.4, 7.4);
                tmp.setCoord(b, 8.4);

                assert(tmp.getX() == 5 && tmp.getY() == 6 && tmp.getZ() == 7 && tmp.getW() == 8);
            }

            static void testDistanceOrigin() {
                Point4D<int> tmp(0, 0, 0, 10);

                assert(tmp.distance() == 10.0);
            }

            static void testDistancePoint() {
                Point4D<int> p(10, 10, 10, 10), tmp(10, 10, 10, 20);

                assert(tmp.distance(p) == 10.0);
            }

            static void testDistanceSquaredOrigin() {
                Point4D<int> tmp(0, 0, 0, 10);

                assert(tmp.distanceSquared() == 100.0);
            }

            static void testDistanceSquaredPoint() {
                Point4D<int> p(10, 10, 10, 10), tmp(10, 10, 10, 20);

                assert(tmp.distanceSquared(p) == 100.0);
            }

            static void testOperatorShortAdd() {
                Point4D<int> tmp(1, 2, 3, 4);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                tmp += u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testOperatorShortSub() {
                Point4D<int> tmp(2, 3, 4, 5);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                tmp -= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0 && tmp.getW() == 0);
            }

            static void testOperatorAdd() {
                Point4D<int> p(1, 2, 3, 4);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                Point4D<int> tmp = p + u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6 && tmp.getW() == 8);
            }

            static void testOperatorSub() {
                Point4D<int> p(2, 3, 4, 5);
                Vector4D<float> u(1.4, 2.4, 3.4, 4.4);
                Point4D<int> tmp = p - u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0 && tmp.getW() == 0);
            }

            static void testOperatorSubPoint() {
                Point4D<int> p(1, 2, 3, 4);
                Point4D<float> q(2.4, 3.4, 4.4, 5.4);
                Vector4D<int> tmp = p - q;

                assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1 && tmp.getW() == 1);
            }

            static void testOperatorNegate() {
                Point4D<int> tmp(-1, -2, -3, -4);
                tmp = -tmp;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3 && tmp.getW() == 4);
            }

            static void testOperatorEqual() {
                Point4D<int> p(1, 2, 3, 4), q(1, 2, 3, 4);

                assert(p == q);
            }

            static void testOperatorNotEqual() {
                Point4D<int> p(1, 2, 3, 4), q(5, 6, 7, 8);

                assert(p != q);
            }

            static void testOperatorInferior() {
                Point4D<int> p(1, 2, 3, 4), q(5, 6, 7, 8);

                assert(p < q);
            }

            static void testOperatorSuperior() {
                Point4D<int> p(1, 2, 3, 4), q(5, 6, 7, 8);

                assert(q > p);
            }

            static void testOStream() {
                std::ostringstream stream; Point4D<int> tmp(1, 2, 3, 4);
                stream << tmp;
                assert(stream.str() == "(1,2,3,4)");
            }
    };
