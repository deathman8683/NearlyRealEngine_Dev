
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
                         /**
                          * @brief Constructor
                          * Default constructor, iniatlize a 2x2 identity matrix
                          */
                        Matrix2x2();
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with 4 generic-type parameters
                         * @param a : K, the l1-c1 value
                         * @param b : L, the l1-c2 value
                         * @param c : M, the l2-c1 value
                         * @param d : N, the l2-c2 value
                         */
                        template <class K, class L, class M, class N>
                        Matrix2x2(K const& a, L const& b,
                                  M const& c, N const& d);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with two 2D generic-type vector as line
                         * @param l1 : Vector2D<K>, the matrix's first line
                         * @param l2 : Vector2D<L>, the matrix's second line
                         */
                        template <class K, class L>
                        Matrix2x2(Vector2D<K> const& l1, Vector2D<L> const& l2);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with two 2D generic-type point as line
                         * @param l1 : Point2D<K>, the matrix's first line
                         * @param l2 : Point2D<L>, the matrix's second line
                         */
                        template <class K, class L>
                        Matrix2x2(Point2D<K> const& l1, Point2D<L> const& l2);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of m
                         * @param m : Matrix2x2<T>, the matrix to copy
                         */
                        Matrix2x2(Matrix2x2 const& m);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 2x2 generic-type matrix into a 2x2 T matrix
                         * @param m : Matrix2x2<K>, the matrix to convert
                         */
                        template <class K>
                        Matrix2x2(Matrix2x2<K> const& m);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 2x2 matrix
                         */
                        ~Matrix2x2();

                    //## Getter ##//
                        /**
                         * @brief First line getter
                         * Return the matrix's first line as a 2D vector
                         * @return Vector2D<T>, the matrix's first line
                         */
                        Vector2D<T> getL1() const;
                        /**
                         * @brief Second line getter
                         * Return the matrix's second line as a 2D vector
                         * @return Vector2D<T>, the matrix's second line
                         */
                        Vector2D<T> getL2() const;
                        /**
                         * @brief First column getter
                         * Return the matrix's first column as a 2D vector
                         * @return Vector2D<T>, the matrix's first column
                         */
                        Vector2D<T> getC1() const;
                        /**
                         * @brief Second column getter
                         * Return the matrix's second column as a 2D vector
                         * @return Vector2D<T>, the matrix's second column
                         */
                        Vector2D<T> getC2() const;
                        /**
                         * @brief Determinant getter
                         * Compute the matrix's determinant
                         * @return NREfloat, the computed determinant
                         */
                        NREfloat getDeterminant() const;

                    //## Setter ##//
                        /**
                         * @brief First line setter
                         * Set the matrix's first line with a 2D generic-type vector
                         * @param l1 : Vector2D<K>, the vector use as first line
                         */
                        template <class K>
                        void setL1(Vector2D<K> const& l1);
                        /**
                         * @brief Second line setter
                         * Set the matrix's second line with a 2D generic-type vector
                         * @param l2 : Vector2D<K>, the vector use as second line
                         */
                        template <class K>
                        void setL2(Vector2D<K> const& l2);
                        /**
                         * @brief First column setter
                         * Set the matrix's first column with a 2D generic-type vector
                         * @param c1 : Vector2D<K>, the vector use as first column
                         */
                        template <class K>
                        void setC1(Vector2D<K> const& c1);
                        /**
                         * @brief Second column setter
                         * Set the matrix's second column with a 2D generic-type vector
                         * @param c2 : Vector2D<K>, the vector use as second column
                         */
                        template <class K>
                        void setC2(Vector2D<K> const& c2);
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
                         * Apply a translation to the matrix with a generic-type factor u
                         * @param u : K, the translation factor
                         */
                        template <class K>
                        void translate(K const& u);
                        /**
                         * @brief Scale the matrix
                         * Apply a scale transformation to the matrix with a generic-type factor u
                         * @param u : K, the scale factor
                         */
                        template <class K>
                        void scale(K const& u);

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
                        T* const operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * @brief Assignment Operator =
                         * Copy a generic-type matrix into this
                         * @param m : Matrix2x2<K>, the matrix to copy
                         */
                        template <class K>
                        Matrix2x2<T>& operator=(Matrix2x2<K> const& m);

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the addition between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to add into this
                         * @return Matrix2x2<T>, this after the addition
                         */
                        template <class K>
                        Matrix2x2<T>& operator+=(Matrix2x2<K> const& m);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the substraction between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to substract into this
                         * @return Matrix2x2<T>, this after the substraction
                         */
                        template <class K>
                        Matrix2x2<T>& operator-=(Matrix2x2<K> const& m);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix2x2<T>, this after the multiplication by k
                         */
                        template <class K>
                        Matrix2x2<T>& operator*=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to multiply into this
                         * @return Matrix2x2<T>, this after the multiplication by m
                         */
                        template <class K>
                        Matrix2x2<T>& operator*=(Matrix2x2<K> const& m);
                        /**
                         * @brief Shortcut Operator /=
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix2x2<T>, this after the division by k
                         */
                        template <class K>
                        Matrix2x2<T>& operator/=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and the inverse of a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to inverse and multiplicate into this
                         * @return Matrix2x2<T>, this after the multiplication by 1/m
                         */
                        template <class K>
                        Matrix2x2<T>& operator/=(Matrix2x2<K> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the addition between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to add to this
                         * @return Matrix2x2<T>, a new matrix with this added to m
                         */
                        template <class K>
                        Matrix2x2<T> operator+(Matrix2x2<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the substract between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to substract to this
                         * @return Matrix2x2<T>, a new matrix with this substracted to m
                         */
                        template <class K>
                        Matrix2x2<T> operator-(Matrix2x2<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix2x2<T>, a new matrix result of the multiplication of this and k
                         */
                        template <class K>
                        Matrix2x2<T> operator*(K const& k) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to multiply to this
                         * @return Matrix2x2<T>, a new matrix with this multiplied to m
                         */
                        template <class K>
                        Matrix2x2<T> operator*(Matrix2x2<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the transformation of a 2D generic-type vector by this
                         * @param u : Vector2D<K>, the vector to transform by this
                         * @return Vector2D<K>, the transformed vector
                         */
                        template <class K>
                        Vector2D<K> operator*(Vector2D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix2x2<T>, a new matrix result of the division of this and k
                         */
                        template <class K>
                        Matrix2x2<T> operator/(K const& k) const;
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the multiplication between this and the inverse of a 2x2 generic-type matrix
                         * @param m : Matrix2x2<K>, the matrix to inverse and multiply to this
                         * @return Matrix2x2<T>, a new matrix with this multiplied to 1/m
                         */
                        template <class K>
                        Matrix2x2<T> operator/(Matrix2x2<K> const& m) const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 2x2 generic-type matrix are equal, based on vector == comparison
                         * @param m : Matrix2x2<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Matrix2x2<K> const& m) const;
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 2x2 generic-type matrix aren't equal, based on the negation of the == test
                         * @param m : Matrix2x2<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Matrix2x2<K> const& m) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * @brief Shift Operator <<
             * Add m to an out stream with : [a b]\n[c d]
             * @param stream : std::ostream, the out stream to add m
             * @param m : Matrix2x2<T>, the matrix to add
             * @return std::ostream, the modified out stream
             */
            template <class T>
            std::ostream& operator<<(std::ostream &stream, Matrix2x2<T> const& m);

        };
    };

    #include "NRE_Matrix2x2.tpp"
