
    /**
     * @file NRET_Point3D.hpp
     * @brief Test of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestPoint3D {
        public:
            static void main() {
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

        private:
            static void testConstructorAtomic() {
                Point3D<int> tmp(1, 2, 3);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConstructorBase() {
                Point2D<int> b(1, 2);
                Point3D<int> tmp(b, 3);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConstructorAdd() {
                Point3D<int> p(1, 2, 3);
                Vector3D<float> u(1.4, 2.4, 3.4);
                Point3D<int> tmp(p, u);

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testCopyConstructor() {
                Point3D<int> p(1, 2, 3), tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConvertorType() {
                Point3D<float> p(1.4, 2.4, 3.4);
                Point3D<int> tmp(p);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testConvertorVector() {
                Vector3D<float> u(1.4, 2.4, 3.4);
                Point3D<int> tmp(u);

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testGetZ() {
                Point3D<int> tmp(1, 2, 3);

                assert(tmp.getZ() == 3);
            }

            static void testSetZ() {
                Point3D<int> tmp(1, 2, 3);
                tmp.setZ(4.4);

                assert(tmp.getZ() == 4);
            }

            static void testSetCoordAtomic() {
                Point3D<int> tmp(1, 2, 3);
                tmp.setCoord(4.4, 5.4, 6.4);

                assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
            }

            static void testSetCoordBase() {
                Point2D<float> b(4.4, 5.4);
                Point3D<int> tmp(1, 2, 3);
                tmp.setCoord(b, 6.4);

                assert(tmp.getX() == 4 && tmp.getY() == 5 && tmp.getZ() == 6);
            }

            static void testDistanceOrigin() {
                Point3D<int> tmp(0, 0, 10);

                assert(tmp.distance() == 10.0);
            }

            static void testDistancePoint() {
                Point3D<int> p(10, 10, 10), tmp(10, 10, 20);


                assert(tmp.distance(p) == 10.0);
            }

            static void testDistanceSquaredOrigin() {
                Point3D<int> tmp(0, 0, 10);

                assert(tmp.distanceSquared() == 100.0);
            }

            static void testDistanceSquaredPoint() {
                Point3D<int> p(10, 10, 10), tmp(10, 10, 20);

                assert(tmp.distanceSquared(p) == 100.0);
            }

            static void testOperatorShortAdd() {
                Point3D<int> tmp(1, 2, 3);
                Vector3D<float> u(1.4, 2.4, 3.4);
                tmp += u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testOperatorShortSub() {
                Point3D<int> tmp(2, 3, 4);
                Vector3D<float> u(1.4, 2.4, 3.4);
                tmp -= u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
            }

            static void testOperatorAdd() {
                Point3D<int> p(1, 2, 3);
                Vector3D<float> u(1.4, 2.4, 3.4);
                Point3D<int> tmp = p + u;

                assert(tmp.getX() == 2 && tmp.getY() == 4 && tmp.getZ() == 6);
            }

            static void testOperatorSub() {
                Point3D<int> p(2, 3, 4);
                Vector3D<float> u(1.4, 2.4, 3.4);
                Point3D<int> tmp = p - u;

                assert(tmp.getX() == 0 && tmp.getY() == 0 && tmp.getZ() == 0);
            }

            static void testOperatorSubPoint() {
                Point3D<int> p(1, 2, 3);
                Point3D<float> q(2.4, 3.4, 4.4);

                Vector3D<int> tmp = p - q;

                assert(tmp.getX() == 1 && tmp.getY() == 1 && tmp.getZ() == 1);
            }

            static void testOperatorNegate() {
                Point3D<int> tmp(-1, -2, -3);
                tmp = -tmp;

                assert(tmp.getX() == 1 && tmp.getY() == 2 && tmp.getZ() == 3);
            }

            static void testOperatorEqual() {
                Point3D<int> p(1, 2, 3), q(1, 2, 3);

                assert(p == q);
            }

            static void testOperatorNotEqual() {
                Point3D<int> p(1, 2, 3), q(4, 5, 6);

                assert(p != q);
            }

            static void testOperatorInferior() {
                Point3D<int> p(1, 2, 3), q(4, 5, 6);

                assert(p < q);
            }

            static void testOperatorSuperior() {
                Point3D<int> p(1, 2, 3), q(4, 5, 6);

                assert(q > p);
            }

            static void testOStream() {
                std::ostringstream stream; Point3D<int> tmp(1, 2, 3);
                stream << tmp;
                assert(stream.str() == "(1,2,3)");
            }

    };
