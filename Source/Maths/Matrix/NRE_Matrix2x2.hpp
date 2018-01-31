
    /**
     * @file NRE_Matrix2x2.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix2x2
     * @author Louis ABEL
     * @version 1.0
     */

     #pragma once

    #include "../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Maths
         * @brief Engine's Mathematicals Module
         */
        namespace Maths {

            template<class> class Point2D;
            template<class> class Vector2D;

            /**
             * @class Matrix2x2
             * @brief Maths's Objects : 2x2 Generic Matrix
             */
             template <class T>
            class Matrix2x2 {
                private:
                    T data[2][2];   /**< Matrix's data */

                public:
                    //## Constructor ##//
                    Matrix2x2();
                    template <class K, class L, class M, class N>
                    Matrix2x2(K const& a, L const& b,
                              M const& c, N const& d);
                    template <class K, class L>
                    Matrix2x2(Vector2D<K> const& l1, Vector2D<L> const& l2);
                    template <class K, class L>
                    Matrix2x2(Point2D<K> const& l1, Point2D<L> const& l2);

                    //## Copy-Constructor ##//
                    Matrix2x2(Matrix2x2 const& m);

                    //## Convertor ##//
                    template <class K>
                    Matrix2x2(Matrix2x2<K> const& m);

                    //## Deconstructor ##//
                    ~Matrix2x2();

                    //## Getter ##//
                    Vector2D<T> getL1() const;
                    Vector2D<T> getL2() const;
                    Vector2D<T> getC1() const;
                    Vector2D<T> getC2() const;
                    NREfloat getDeterminant() const;

                    //## Setter ##//
                    template <class K>
                    void setL1(Vector2D<K> const& l1);
                    template <class K>
                    void setL2(Vector2D<K> const& l2);
                    template <class K>
                    void setC1(Vector2D<K> const& c1);
                    template <class K>
                    void setC2(Vector2D<K> const& c2);
                    void setIdentity();

                    //## Methods ##//
                    void transpose();
                    void inverse();
                    template <class K>
                    void translate(K const& u);
                    template <class K>
                    void scale(K const& u);

                    //## Access Operator ##//
                    T* operator[](unsigned int const& index);
                    const T* operator[](unsigned int const& index) const;

                    template <class K>
                    Matrix2x2<T>& operator=(Matrix2x2<K> const& m);

                    //## Shortcut Operator ##//
                    template <class K>
                    Matrix2x2<T>& operator+=(Matrix2x2<K> const& m);
                    template <class K>
                    Matrix2x2<T>& operator-=(Matrix2x2<K> const& m);
                    template <class K>
                    Matrix2x2<T>& operator*=(K const& k);
                    template <class K>
                    Matrix2x2<T>& operator*=(Matrix2x2<K> const& m);
                    template <class K>
                    Matrix2x2<T>& operator/=(K const& k);
                    template <class K>
                    Matrix2x2<T>& operator/=(Matrix2x2<K> const& m);

                    //## Arithmetic Operator ##//
                    template <class K>
                    Matrix2x2<T> operator+(Matrix2x2<K> const& m);
                    template <class K>
                    Matrix2x2<T> operator-(Matrix2x2<K> const& m);
                    template <class K>
                    Matrix2x2<T> operator*(K const& k);
                    template <class K>
                    Matrix2x2<T> operator*(Matrix2x2<K> const& m);
                    template <class K>
                    Vector2D<K> operator*(Vector2D<K> const& u);
                    template <class K>
                    Matrix2x2<T> operator/(K const& k);
                    template <class K>
                    Matrix2x2<T> operator/(Matrix2x2<K> const& m);

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Matrix2x2<T> const& m);

        };
    };

    #include "NRE_Matrix2x2.tpp"
