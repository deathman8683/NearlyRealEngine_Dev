
    /**
     * @file NRET_Matrix3x3.hpp
     * @brief Test of Engine's Maths's Object : Matrix3x3
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestMatrix3x3 {
        public:
            static void main() {
                testConstructorAtomic();
                testConstructorVector();
                testConstructorPoint();
                testCopyConstructor();
                testConvertor();
                testGetL1();
                testGetL2();
                testGetL3();
                testGetC1();
                testGetC2();
                testGetC3();
                testGetDeterminant();
                testSetL1();
                testSetL2();
                testSetL3();
                testSetC1();
                testSetC2();
                testSetC3();
                testSetIdentity();
                testTranspose();
                testInverse();
                testTranslate();
                testScale();
                testOperatorAccessRead();
                testOperatorAccessWrite();
                testOperatorAssign();
                testOperatorShortAdd();
                testOperatorShortSub();
                testOperatorShortMult();
                testOperatorShortMultMatrix();
                testOperatorShortDiv();
                testOperatorShortDivMatrix();
                testOperatorAdd();
                testOperatorSub();
                testOperatorMult();
                testOperatorMultMatrix();
                testOperatorDiv();
                testOperatorDivMatrix();
                testOperatorEqual();
                testOperatorNotEqual();
                testOStream();
            }

        private:
            static void testConstructorAtomic() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testConstructorVector() {
                Vector3D<float> l1(1.4, 2.4, 3.4), l2(4.4, 5.4, 6.4), l3(7.4, 8.4, 9.4);
                Matrix3x3<int> tmp(l1, l2, l3);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testConstructorPoint() {
                Point3D<float> l1(1.4, 2.4, 3.4), l2(4.4, 5.4, 6.4), l3(7.4, 8.4, 9.4);
                Matrix3x3<int> tmp(l1, l2, l3);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testCopyConstructor() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9), tmp(m);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testConvertor() {
                Matrix3x3<float> m(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4);
                Matrix3x3<int> tmp(m);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testGetL1() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3));
            }

            static void testGetL2() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getL2() == Vector3D<int>(4, 5, 6));
            }

            static void testGetL3() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testGetC1() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getC1() == Vector3D<int>(1, 4, 7));
            }

            static void testGetC2() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getC2() == Vector3D<int>(2, 5, 8));
            }

            static void testGetC3() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp.getC3() == Vector3D<int>(3, 6, 9));
            }

            static void testGetDeterminant() {
                Matrix3x3<int> tmp(2, 3, 4, 5, 6, 7, 1, 2, 1);

                assert(tmp.getDeterminant() == 6.0);
            }

            static void testSetL1() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setL1(u);

                assert(tmp.getL1() == Vector3D<int>(10, 11, 12) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testSetL2() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setL2(u);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(10, 11, 12) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testSetL3() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setL3(u);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(10, 11, 12));
            }

            static void testSetC1() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setC1(u);

                assert(tmp.getL1() == Vector3D<int>(10, 2, 3) && tmp.getL2() == Vector3D<int>(11, 5, 6) && tmp.getL3() == Vector3D<int>(12, 8, 9));
            }

            static void testSetC2() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setC2(u);

                assert(tmp.getL1() == Vector3D<int>(1, 10, 3) && tmp.getL2() == Vector3D<int>(4, 11, 6) && tmp.getL3() == Vector3D<int>(7, 12, 9));
            }

            static void testSetC3() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector3D<float> u(10.4, 11.4, 12.4);
                tmp.setC3(u);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 10) && tmp.getL2() == Vector3D<int>(4, 5, 11) && tmp.getL3() == Vector3D<int>(7, 8, 12));
            }

            static void testSetIdentity() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                tmp.setIdentity();

                assert(tmp.getL1() == Vector3D<int>(1, 0, 0) && tmp.getL2() == Vector3D<int>(0, 1, 0) && tmp.getL3() == Vector3D<int>(0, 0, 1));
            }

            static void testTranspose() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                tmp.transpose();

                assert(tmp.getL1() == Vector3D<int>(1, 4, 7) && tmp.getL2() == Vector3D<int>(2, 5, 8) && tmp.getL3() == Vector3D<int>(3, 6, 9));
            }

            static void testInverse() {
                Matrix3x3<float> tmp(2, 3, 4, 5, 6, 7, 1, 2, 1);
                tmp.inverse();

                assert(tmp.getL1() == Vector3D<float>(-4.0 / 3.0, 5.0 / 6.0, -1.0 / 2.0) && tmp.getL2() == Vector3D<float>(1.0 / 3.0, -1.0 / 3.0,  1.0) && tmp.getL3() == Vector3D<float>(2.0 / 3.0, -1.0 / 6.0, -1.0 / 2.0));
            }

            static void testTranslate() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector2D<float> u(1.4, 2.4);
                tmp.translate(u);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 4) && tmp.getL2() == Vector3D<int>(4, 5, 8) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testScale() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Vector2D<float> u(1.4, 2.4);
                tmp.scale(u);

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 12, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testOperatorAccessRead() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(tmp[0][0] == tmp.getL1().getX());
            }

            static void testOperatorAccessWrite() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                tmp[0][0] = 10.4;

                assert(tmp.getL1() == Vector3D<int>(10, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testOperatorAssign() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9), m(10, 11, 12, 13, 14, 15, 16, 17, 18);
                tmp = m;

                assert(tmp.getL1() == Vector3D<int>(10, 11, 12) && tmp.getL2() == Vector3D<int>(13, 14, 15) && tmp.getL3() == Vector3D<int>(16, 17, 18));
            }

            static void testOperatorShortAdd() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Matrix3x3<float> m(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4);
                tmp += m;

                assert(tmp.getL1() == Vector3D<int>(2, 4, 6) && tmp.getL2() == Vector3D<int>(8, 10, 12) && tmp.getL3() == Vector3D<int>(14, 16, 18));
            }

            static void testOperatorShortSub() {
                Matrix3x3<int> tmp(2, 3, 4, 5, 6, 7, 8, 9, 10);
                Matrix3x3<float> m(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4);
                tmp -= m;

                assert(tmp.getL1() == Vector3D<int>(0, 0, 0) && tmp.getL2() == Vector3D<int>(0, 0, 0) && tmp.getL3() == Vector3D<int>(0, 0, 0));
            }

            static void testOperatorShortMult() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                float k = 2.2;
                tmp *= k;

                assert(tmp.getL1() == Vector3D<int>(2, 4, 6) && tmp.getL2() == Vector3D<int>(8, 11, 13) && tmp.getL3() == Vector3D<int>(15, 17, 19));
            }

            static void testOperatorShortMultMatrix() {
                Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9), m(2, 3, 4, 5, 6, 7, 8, 9, 10);
                tmp *= m;

                assert(tmp.getL1() == Vector3D<int>(36, 42, 48) && tmp.getL2() == Vector3D<int>(81, 96, 111) && tmp.getL3() == Vector3D<int>(126, 150, 174));
            }

            static void testOperatorShortDiv() {
                Matrix3x3<int> tmp(2, 3, 4, 5, 6, 7, 8, 9, 10);
                float k = 1.1;
                tmp /= k;

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testOperatorShortDivMatrix() {
                Matrix3x3<float> tmp(2, 3, 4, 5, 6, 7, 1, 2, 1), m(2, 3, 4, 5, 6, 7, 1, 2, 1);
                tmp /= m;

                assert(tmp.getL1() == Vector3D<float>(1, 0, 0) && tmp.getL2() == Vector3D<float>(0, 1, 0) && tmp.getL3() == Vector3D<float>(0, 0, 1));
            }

            static void testOperatorAdd() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9);
                Matrix3x3<float> n(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4);
                Matrix3x3<int> tmp = m + n;

                assert(tmp.getL1() == Vector3D<int>(2, 4, 6) && tmp.getL2() == Vector3D<int>(8, 10, 12) && tmp.getL3() == Vector3D<int>(14, 16, 18));
            }

            static void testOperatorSub() {
                Matrix3x3<int> m(2, 3, 4, 5, 6, 7, 8, 9, 10);
                Matrix3x3<float> n(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4);
                Matrix3x3<int> tmp = m - n;

                assert(tmp.getL1() == Vector3D<int>(0, 0, 0) && tmp.getL2() == Vector3D<int>(0, 0, 0) && tmp.getL3() == Vector3D<int>(0, 0, 0));
            }

            static void testOperatorMult() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9);
                float k = 2.2;
                Matrix3x3<int> tmp = m * k;

                assert(tmp.getL1() == Vector3D<int>(2, 4, 6) && tmp.getL2() == Vector3D<int>(8, 11, 13) && tmp.getL3() == Vector3D<int>(15, 17, 19));
            }

            static void testOperatorMultMatrix() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9), n(2, 3, 4, 5, 6, 7, 8, 9, 10);
                Matrix3x3<int> tmp = m * n;

                assert(tmp.getL1() == Vector3D<int>(36, 42, 48) && tmp.getL2() == Vector3D<int>(81, 96, 111) && tmp.getL3() == Vector3D<int>(126, 150, 174));
            }

            static void testOperatorDiv() {
                Matrix3x3<int> m(2, 3, 4, 5, 6, 7, 8, 9, 10);
                float k = 1.1;
                Matrix3x3<int> tmp = m / k;

                assert(tmp.getL1() == Vector3D<int>(1, 2, 3) && tmp.getL2() == Vector3D<int>(4, 5, 6) && tmp.getL3() == Vector3D<int>(7, 8, 9));
            }

            static void testOperatorDivMatrix() {
                Matrix3x3<float> m(2, 3, 4, 5, 6, 7, 1, 2, 1), n(2, 3, 4, 5, 6, 7, 1, 2, 1);
                Matrix3x3<float> tmp = m / n;

                assert(tmp.getL1() == Vector3D<float>(1, 0, 0) && tmp.getL2() == Vector3D<float>(0, 1, 0) && tmp.getL3() == Vector3D<float>(0, 0, 1));
            }

            static void testOperatorEqual() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9), n(1, 2, 3, 4, 5, 6, 7, 8, 9);

                assert(m == n);
            }

            static void testOperatorNotEqual() {
                Matrix3x3<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9), n(1, 2, 3, 4, 7, 8, 9, 4, 5);

                assert(m != n);
            }

            static void testOStream() {
                std::ostringstream stream; Matrix3x3<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9);
                stream << tmp;
                assert(stream.str() == "[1 2 3]\n[4 5 6]\n[7 8 9]");
            }
    };
