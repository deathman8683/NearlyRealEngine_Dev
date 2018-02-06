
    /**
     * @file NRE_Matrix4x4.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix4x4
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

            template<class> class Point4D;
            template<class> class Vector4D;

            /**
             * @class Matrix4x4
             * @brief Maths's Object : 4x4 Generic Matrix
             */
            template <class T>
            class Matrix4x4 {
                private:
                    T data[4][4];   /**< Matrix's data */

                public:
                    //## Constructor ##//
                         /**
                          * @brief Constructor
                          * Default constructor, iniatlize a 4x4 identity matrix
                          */
                        Matrix4x4();
                          /**
                           * @brief Constructor
                           * Initialize the matrix's value with 16 generic-type parameters
                           * @param a : A, the l1-c1 value
                           * @param b : B, the l1-c2 value
                           * @param c : C, the l1-c3 value
                           * @param d : D, the l1-c4 value
                           * @param e : E, the l2-c1 value
                           * @param f : F, the l2-c2 value
                           * @param g : G, the l2-c1 value
                           * @param h : H, the l2-c4 value
                           * @param i : I, the l3-c1 value
                           * @param j : J, the l3-c2 value
                           * @param k : K, the l3-c3 value
                           * @param l : L, the l3-c4 value
                           * @param m : M, the l4-c1 value
                           * @param n : N, the l4-c2 value
                           * @param o : O, the l4-c3 value
                           * @param p : P, the l4-c4 value
                           */
                        template <class A, class B, class C, class D,
                                  class E, class F, class G, class H,
                                  class I, class J, class K, class L,
                                  class M, class N, class O, class P>
                        Matrix4x4(A const& a, B const& b, C const& c, D const& d,
                                  D const& e, F const& f, G const& g, H const& h,
                                  I const& i, J const& j, K const& k, L const& l,
                                  M const& m, N const& n, O const& o, P const& p);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with three 4D generic-type vector as line
                         * @param l1 : Vector4D<K>, the matrix's first line
                         * @param l2 : Vector4D<L>, the matrix's second line
                         * @param l3 : Vector4D<M>, the matrix's third line
                         * @param l4 : Vector4D<N>, the matrix's fourth line
                         */
                        template <class K, class L, class M, class N>
                        Matrix4x4(Vector4D<K> const& l1, Vector4D<L> const& l2, Vector4D<M> const& l3, Vector4D<N> const& l4);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with three 4D generic-type point as line
                         * @param l1 : Point4D<K>, the matrix's first line
                         * @param l2 : Point4D<L>, the matrix's second line
                         * @param l3 : Point4D<M>, the matrix's third line
                         * @param l4 : Point4D<N>, the matrix's fourth line
                         */
                        template <class K, class L, class M, class N>
                        Matrix4x4(Point4D<K> const& l1, Point4D<L> const& l2, Point4D<M> const& l3, Point4D<N> const& l4);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of m
                         * @param m : Matrix4x4<T>, the matrix to copy
                         */
                        Matrix4x4(Matrix4x4 const& m);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 4x4 generic-type matrix into a 4x4 T matrix
                         * @param m : Matrix4x4<K>, the matrix to convert
                         */
                        template <class K>
                        Matrix4x4(Matrix4x4<K> const& m);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 4x4 matrix
                         */
                        ~Matrix4x4();

                    //## Getter ##//
                        /**
                         * @brief First line getter
                         * Return the matrix's first line as a 4D vector
                         * @return Vector4D<T>, the matrix's first line
                         */
                        Vector4D<T> getL1() const;
                        /**
                         * @brief Second line getter
                         * Return the matrix's second line as a 4D vector
                         * @return Vector4D<T>, the matrix's second line
                         */
                        Vector4D<T> getL2() const;
                        /**
                         * @brief Third line getter
                         * Return the matrix's third line as a 4D vector
                         * @return Vector4D<T>, the matrix's third line
                         */
                        Vector4D<T> getL3() const;
                        /**
                         * @brief Fourth line getter
                         * Return the matrix's fourth line as a 4D vector
                         * @return Vector4D<T>, the matrix's fourth line
                         */
                        Vector4D<T> getL4() const;
                        /**
                         * @brief First column getter
                         * Return the matrix's first column as a 4D vector
                         * @return Vector4D<T>, the matrix's first column
                         */
                        Vector4D<T> getC1() const;
                        /**
                         * @brief Second column getter
                         * Return the matrix's second column as a 4D vector
                         * @return Vector4D<T>, the matrix's second column
                         */
                        Vector4D<T> getC2() const;
                        /**
                         * @brief Third column getter
                         * Return the matrix's third column as a 4D vector
                         * @return Vector4D<T>, the matrix's third column
                         */
                        Vector4D<T> getC3() const;
                        /**
                         * @brief Fourth column getter
                         * Return the matrix's fourth column as a 4D vector
                         * @return Vector4D<T>, the matrix's fourth column
                         */
                        Vector4D<T> getC4() const;
                        /**
                         * @brief Determinant getter
                         * Compute the matrix's determinant
                         * @return NREfloat, the computed determinant
                         */
                        NREfloat getDeterminant() const;

                    //## Setter ##//
                        /**
                         * @brief First line setter
                         * Set the matrix's first line with a 4D generic-type vector
                         * @param l1 : Vector4D<K>, the vector use as first line
                         */
                        template <class K>
                        void setL1(Vector4D<K> const& l1);
                        /**
                         * @brief Second line setter
                         * Set the matrix's second line with a 4D generic-type vector
                         * @param l2 : Vector4D<K>, the vector use as second line
                         */
                        template <class K>
                        void setL2(Vector4D<K> const& l2);
                        /**
                         * @brief Third line setter
                         * Set the matrix's third line with a 4D generic-type vector
                         * @param l3 : Vector4D<K>, the vector use as third line
                         */
                        template <class K>
                        void setL3(Vector4D<K> const& l3);
                        /**
                         * @brief Fourth line setter
                         * Set the matrix's fourth line with a 4D generic-type vector
                         * @param l4 : Vector4D<K>, the vector use as fourth line
                         */
                        template <class K>
                        void setL4(Vector4D<K> const& l4);
                        /**
                         * @brief First column setter
                         * Set the matrix's first column with a 4D generic-type vector
                         * @param c1 : Vector4D<K>, the vector use as first column
                         */
                        template <class K>
                        void setC1(Vector4D<K> const& c1);
                        /**
                         * @brief Second column setter
                         * Set the matrix's second column with a 4D generic-type vector
                         * @param c2 : Vector4D<K>, the vector use as second column
                         */
                        template <class K>
                        void setC2(Vector4D<K> const& c2);
                        /**
                         * @brief Third column setter
                         * Set the matrix's third column with a 4D generic-type vector
                         * @param c3 : Vector4D<K>, the vector use as third column
                         */
                        template <class K>
                        void setC3(Vector4D<K> const& c3);
                        /**
                         * @brief Fourth column setter
                         * Set the matrix's fourth column with a 4D generic-type vector
                         * @param c4 : Vector4D<K>, the vector use as fourth column
                         */
                        template <class K>
                        void setC4(Vector4D<K> const& c4);
                        /**
                         * @brief Identity setter
                         * Erase the matrix and transform it into the identity matrix
                         */
                        void setIdentity();

                    //## Methods ##//
                        /**
                         * @brief Transpose the matrix
                         * Transpose the current matrix
                         */
                        void transpose();
                        /**
                         * @brief Inverse the matrix
                         * Inverse the current matrix, set it to identity if the determinant is null
                         */
                        void inverse();
                        /**
                         * @brief Translate the matrix
                         * Apply a translation to the matrix with a 3D generic-type vector
                         * @param u : Vector3D<K>, the translation vector
                         */
                        template <class K>
                        void translate(Vector3D<K> const& u);
                        /**
                         * @brief Scale the matrix
                         * Apply a scale transformation to the matrix with a 3D generic-type vector
                         * @param u : Vector3D<K>, the scale vector
                         */
                        template <class K>
                        void scale(Vector3D<K> const& u);
                        template <class K, class L>
                        void rotate(K const& angle, Vector3D<L> const& axis);
                        template <class K, class L, class M, class N>
                        void projection(K const& fov, L const& ratio, M const& zNear, N const& zFar);
                        template <class K, class L, class M>
                        void lookAt(Point3D<K> const& eye, Point3D<L> const& center, Vector3D<M> const& up);
                        T* const value();

                    //## Access Operator ##//
                        /**
                         * @brief Write Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        T* operator[](unsigned int const& index);
                        /**
                         * @brief Read Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        const T* operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * @brief Assignment Operator =
                         * Copy a generic-type matrix into this
                         * @param m : Matrix4x4<K>, the matrix to copy
                         */
                        template <class K>
                        Matrix4x4<T>& operator=(Matrix4x4<K> const& m);

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the addition between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to add into this
                         * @return Matrix4x4<T>, this after the addition
                         */
                        template <class K>
                        Matrix4x4<T>& operator+=(Matrix4x4<K> const& m);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the substraction between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to substract into this
                         * @return Matrix4x4<T>, this after the substraction
                         */
                        template <class K>
                        Matrix4x4<T>& operator-=(Matrix4x4<K> const& m);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix4x4<T>, this after the multiplication by k
                         */
                        template <class K>
                        Matrix4x4<T>& operator*=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to multiply into this
                         * @return Matrix4x4<T>, this after the multiplication by m
                         */
                        template <class K>
                        Matrix4x4<T>& operator*=(Matrix4x4<K> const& m);
                        /**
                         * @brief Shortcut Operator /=
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix4x4<T>, this after the division by k
                         */
                        template <class K>
                        Matrix4x4<T>& operator/=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and the inverse of a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to inverse and multiplicate into this
                         * @return Matrix4x4<T>, this after the multiplication by 1/m
                         */
                        template <class K>
                        Matrix4x4<T>& operator/=(Matrix4x4<K> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the addition between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to add to this
                         * @return Matrix4x4<T>, a new matrix with this added to m
                         */
                        template <class K>
                        Matrix4x4<T> operator+(Matrix4x4<K> const& m);
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the substract between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to substract to this
                         * @return Matrix4x4<T>, a new matrix with this substracted to m
                         */
                        template <class K>
                        Matrix4x4<T> operator-(Matrix4x4<K> const& m);
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix4x4<T>, a new matrix result of the multiplication of this and k
                         */
                        template <class K>
                        Matrix4x4<T> operator*(K const& k);
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to multiply to this
                         * @return Matrix4x4<T>, a new matrix with this multiplied to m
                         */
                        template <class K>
                        Matrix4x4<T> operator*(Matrix4x4<K> const& m);
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the transformation of a 4D generic-type vector by this
                         * @param u : Vector4D<K>, the vector to transform by this
                         * @return Vector4D<K>, the transformed vector
                         */
                        template <class K>
                        Vector4D<K> operator*(Vector4D<K> const& u);
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix4x4<T>, a new matrix result of the division of this and k
                         */
                        template <class K>
                        Matrix4x4<T> operator/(K const& k);
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the multiplication between this and the inverse of a 4x4 generic-type matrix
                         * @param m : Matrix4x4<K>, the matrix to inverse and multiply to this
                         * @return Matrix4x4<T>, a new matrix with this multiplied to 1/m
                         */
                        template <class K>
                        Matrix4x4<T> operator/(Matrix4x4<K> const& m);

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 4x4 generic-type matrix are equal, based on vector == comparison
                         * @param m : Matrix4x4<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Matrix4x4<K> const& m);
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 4x4 generic-type matrix aren't equal, based on the negation of the == test
                         * @param m : Matrix4x4<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Matrix4x4<K> const& m);

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * @brief Shift Operator <<
             * Add m to an out stream with : [a, b c d]\n[e f g h]\n[i j k l]\n[m n o p]
             * @param stream : std::ostream, the out stream to add m
             * @param m : Matrix4x4<T>, the matrix to add
             * @return std::ostream, the modified out stream
             */
            template <class T>
            std::ostream& operator<<(std::ostream &stream, Matrix4x4<T> const& m);

        };
    };

    #include "NRE_Matrix4x4.tpp"
