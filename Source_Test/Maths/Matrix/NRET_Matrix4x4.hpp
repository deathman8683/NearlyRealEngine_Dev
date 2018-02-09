
    /**
     * @file NRET_Matrix4x4.hpp
     * @brief Test of Engine's Maths's Object : Matrix4x4
     * @author Louis ABEL
     * @version 1.0
     */

    #include <sstream>
    #include <iostream>
    #include <cassert>
    #include "../../../Source/Generic/NRE_Type.hpp"
    #include "../../../Source/Maths/NRE_Maths.hpp"

    using namespace NRE::Maths;

    class TestMatrix4x4 {
        public:
            static void main() {
                testConstructorAtomic();
                testConstructorAtomic();
                testConstructorVector();
                testConstructorPoint();
                testCopyConstructor();
                testConvertor();
                testGetL1();
                testGetL2();
                testGetL3();
                testGetL4();
                testGetC1();
                testGetC2();
                testGetC3();
                testGetC4();
                testGetDeterminant();
                testSetL1();
                testSetL2();
                testSetL3();
                testSetL4();
            }

        private:
            static void testConstructorAtomic() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testConstructorVector() {
                Vector4D<float> l1(1.4, 2.4, 3.4, 4.4), l2(5.4, 6.4, 7.4, 8.4), l3(9.4, 10.4, 11.4, 12.4), l4(13.4, 14.4, 15.4, 16.4);
                Matrix4x4<int> tmp(l1, l2, l3, l4);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testConstructorPoint() {
                Point4D<float> l1(1.4, 2.4, 3.4, 4.4), l2(5.4, 6.4, 7.4, 8.4), l3(9.4, 10.4, 11.4, 12.4), l4(13.4, 14.4, 15.4, 16.4);
                Matrix4x4<int> tmp(l1, l2, l3, l4);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testCopyConstructor() {
                Matrix4x4<int> m(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16), tmp(m);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testConvertor() {
                Matrix4x4<float> m(1.4, 2.4, 3.4, 4.4, 5.4, 6.4, 7.4, 8.4, 9.4, 10.4, 11.4, 12.4, 13.4, 14.4, 15.4, 16.4);
                Matrix4x4<int> tmp(m);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testGetL1() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4));
            }

            static void testGetL2() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getL2() == Vector4D<int>(5, 6, 7, 8));
            }

            static void testGetL3() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getL3() == Vector4D<int>(9, 10, 11, 12));
            }

            static void testGetL4() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testGetC1() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getC1() == Vector4D<int>(1, 5, 9, 13));
            }

            static void testGetC2() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getC2() == Vector4D<int>(2, 6, 10, 14));
            }

            static void testGetC3() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getC3() == Vector4D<int>(3, 7, 11, 15));
            }

            static void testGetC4() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);

                assert(tmp.getC4() == Vector4D<int>(4, 8, 12, 16));
            }

            static void testGetDeterminant() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 9, 0, 9, 0, 2, 1, 1, 2, 1, 2, 2, 1);

                assert(tmp.getDeterminant() == -108);
            }

            static void testSetL1() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
                tmp.setL1(Vector4D<float>(20.4, 21.4, 22.4, 23.4));


                assert(tmp.getL1() == Vector4D<int>(20, 21, 22, 23) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testSetL2() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
                tmp.setL2(Vector4D<float>(20.4, 21.4, 22.4, 23.4));


                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(20, 21, 22, 23) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testSetL3() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
                tmp.setL3(Vector4D<float>(20.4, 21.4, 22.4, 23.4));


                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(20, 21, 22, 23) && tmp.getL4() == Vector4D<int>(13, 14, 15, 16));
            }

            static void testSetL4() {
                Matrix4x4<int> tmp(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
                tmp.setL4(Vector4D<float>(20.4, 21.4, 22.4, 23.4));


                assert(tmp.getL1() == Vector4D<int>(1, 2, 3, 4) && tmp.getL2() == Vector4D<int>(5, 6, 7, 8) &&
                       tmp.getL3() == Vector4D<int>(9, 10, 11, 12) && tmp.getL4() == Vector4D<int>(20, 21, 22, 23));
            }
    };
