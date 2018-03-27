
    /**
     * @file NRE_Matrix3x3.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix3x3
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

            template<class> class Point3D;
            template<class> class Vector3D;

            /**
             * @class Matrix3x3
             * @brief Maths's Object : 3x3 Generic Matrix
             */
            template <class T>
            class Matrix3x3 {
                private:
                    Vector3D<T> data[3];   /**< Matrix's data */

                public:
                    //## Constructor ##//
                         /**
                          * @brief Constructor
                          * Default constructor, iniatlize a 3x3 identity matrix
                          */
                        Matrix3x3();
                          /**
                           * @brief Constructor
                           * Initialize the matrix's value with 9 generic-type parameters
                           * @param a : K, the l1-c1 value
                           * @param b : L, the l1-c2 value
                           * @param c : M, the l1-c3 value
                           * @param d : N, the l2-c1 value
                           * @param e : O, the l2-c2 value
                           * @param f : P, the l2-c3 value
                           * @param g : Q, the l3-c1 value
                           * @param h : R, the l3-c2 value
                           * @param i : S, the l3-c3 value
                           */
                        template <class K, class L, class M,
                                  class N, class O, class P,
                                  class Q, class R, class S>
                        Matrix3x3(K const& a, L const& b, M const& c,
                                  N const& d, O const& e, P const& f,
                                  Q const& g, R const& h, S const& i);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with three 3D generic-type vector as line
                         * @param l1 : Vector3D<K>, the matrix's first line
                         * @param l2 : Vector3D<L>, the matrix's second line
                         * @param l3 : Vector3D<M>, the matrix's third line
                         */
                        template <class K, class L, class M>
                        Matrix3x3(Vector3D<K> const& l1, Vector3D<L> const& l2, Vector3D<M> const& l3);
                        /**
                         * @brief Constructor
                         * Initialize the matrix's value with three 3D generic-type point as line
                         * @param l1 : Point3D<K>, the matrix's first line
                         * @param l2 : Point3D<L>, the matrix's second line
                         * @param l3 : Point3D<M>, the matrix's third line
                         */
                        template <class K, class L, class M>
                        Matrix3x3(Point3D<K> const& l1, Point3D<L> const& l2, Point3D<M> const& l3);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of m
                         * @param m : Matrix3x3<T>, the matrix to copy
                         */
                        Matrix3x3(Matrix3x3 const& m);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 3x3 generic-type matrix into a 3x3 T matrix
                         * @param m : Matrix3x3<K>, the matrix to convert
                         */
                        template <class K>
                        Matrix3x3(Matrix3x3<K> const& m);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 3x3 matrix
                         */
                        ~Matrix3x3();

                    //## Getter ##//
                        /**
                         * @brief First line getter
                         * Return the matrix's first line as a 3D vector
                         * @return Vector3D<T>, the matrix's first line
                         */
                        Vector3D<T> const& getL1() const;
                        /**
                         * @brief Second line getter
                         * Return the matrix's second line as a 3D vector
                         * @return Vector3D<T>, the matrix's second line
                         */
                        Vector3D<T> const& getL2() const;
                        /**
                         * @brief Third line getter
                         * Return the matrix's third line as a 3D vector
                         * @return Vector3D<T>, the matrix's third line
                         */
                        Vector3D<T> const& getL3() const;
                        /**
                         * @brief First column getter
                         * Return the matrix's first column as a 3D vector
                         * @return Vector3D<T>, the matrix's first column
                         */
                        Vector3D<T> getC1() const;
                        /**
                         * @brief Second column getter
                         * Return the matrix's second column as a 3D vector
                         * @return Vector3D<T>, the matrix's second column
                         */
                        Vector3D<T> getC2() const;
                        /**
                         * @brief Third column getter
                         * Return the matrix's third column as a 3D vector
                         * @return Vector3D<T>, the matrix's third column
                         */
                        Vector3D<T> getC3() const;
                        /**
                         * @brief Determinant getter
                         * Compute the matrix's determinant
                         * @return NREfloat, the computed determinant
                         */
                        NREfloat getDeterminant() const;

                    //## Setter ##//
                        /**
                         * @brief First line setter
                         * Set the matrix's first line with a 3D generic-type vector
                         * @param l1 : Vector3D<K>, the vector use as first line
                         */
                        template <class K>
                        void setL1(Vector3D<K> const& l1);
                        /**
                         * @brief Second line setter
                         * Set the matrix's second line with a 3D generic-type vector
                         * @param l2 : Vector3D<K>, the vector use as second line
                         */
                        template <class K>
                        void setL2(Vector3D<K> const& l2);
                        /**
                         * @brief Third line setter
                         * Set the matrix's third line with a 3D generic-type vector
                         * @param l3 : Vector3D<K>, the vector use as third line
                         */
                        template <class K>
                        void setL3(Vector3D<K> const& l3);
                        /**
                         * @brief First column setter
                         * Set the matrix's first column with a 3D generic-type vector
                         * @param c1 : Vector3D<K>, the vector use as first column
                         */
                        template <class K>
                        void setC1(Vector3D<K> const& c1);
                        /**
                         * @brief Second column setter
                         * Set the matrix's second column with a 3D generic-type vector
                         * @param c2 : Vector3D<K>, the vector use as second column
                         */
                        template <class K>
                        void setC2(Vector3D<K> const& c2);
                        /**
                         * @brief Third column setter
                         * Set the matrix's third column with a 3D generic-type vector
                         * @param c3 : Vector3D<K>, the vector use as third column
                         */
                        template <class K>
                        void setC3(Vector3D<K> const& c3);
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
                         * Apply a translation to the matrix with a 2D generic-type vector
                         * @param u : Vector2D<K>, the translation vector
                         */
                        template <class K>
                        void translate(Vector2D<K> const& u);
                        /**
                         * @brief Scale the matrix
                         * Apply a scale transformation to the matrix with a 2D generic-type vector
                         * @param u : Vector2D<K>, the scale vector
                         */
                        template <class K>
                        void scale(Vector2D<K> const& u);
                        const T* const value() const;

                    //## Access Operator ##//
                        /**
                         * @brief Write Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        Vector3D<T>& operator[](unsigned int const& index);
                        /**
                         * @brief Read Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        const Vector3D<T>& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * @brief Assignment Operator =
                         * Copy a generic-type matrix into this
                         * @param m : Matrix3x3<K>, the matrix to copy
                         */
                        template <class K>
                        Matrix3x3<T>& operator=(Matrix3x3<K> const& m);

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the addition between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to add into this
                         * @return Matrix3x3<T>, this after the addition
                         */
                        template <class K>
                        Matrix3x3<T>& operator+=(Matrix3x3<K> const& m);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the substraction between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to substract into this
                         * @return Matrix3x3<T>, this after the substraction
                         */
                        template <class K>
                        Matrix3x3<T>& operator-=(Matrix3x3<K> const& m);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix3x3<T>, this after the multiplication by k
                         */
                        template <class K>
                        Matrix3x3<T>& operator*=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to multiply into this
                         * @return Matrix3x3<T>, this after the multiplication by m
                         */
                        template <class K>
                        Matrix3x3<T>& operator*=(Matrix3x3<K> const& m);
                        /**
                         * @brief Shortcut Operator /=
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix3x3<T>, this after the division by k
                         */
                        template <class K>
                        Matrix3x3<T>& operator/=(K const& k);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication between this and the inverse of a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to inverse and multiplicate into this
                         * @return Matrix3x3<T>, this after the multiplication by 1/m
                         */
                        template <class K>
                        Matrix3x3<T>& operator/=(Matrix3x3<K> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the addition between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to add to this
                         * @return Matrix3x3<T>, a new matrix with this added to m
                         */
                        template <class K>
                        Matrix3x3<T> operator+(Matrix3x3<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the substract between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to substract to this
                         * @return Matrix3x3<T>, a new matrix with this substracted to m
                         */
                        template <class K>
                        Matrix3x3<T> operator-(Matrix3x3<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a generic-type factor
                         * @param k : K, the multiplication factor
                         * @return Matrix3x3<T>, a new matrix result of the multiplication of this and k
                         */
                        template <class K>
                        Matrix3x3<T> operator*(K const& k) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to multiply to this
                         * @return Matrix3x3<T>, a new matrix with this multiplied to m
                         */
                        template <class K>
                        Matrix3x3<T> operator*(Matrix3x3<K> const& m) const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the transformation of a 3D generic-type vector by this
                         * @param u : Vector3D<K>, the vector to transform by this
                         * @return Vector3D<K>, the transformed vector
                         */
                        template <class K>
                        Vector3D<K> operator*(Vector3D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the division between this and a generic-type factor
                         * @param k : K, the division factor
                         * @return Matrix3x3<T>, a new matrix result of the division of this and k
                         */
                        template <class K>
                        Matrix3x3<T> operator/(K const& k) const;
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the multiplication between this and the inverse of a 3x3 generic-type matrix
                         * @param m : Matrix3x3<K>, the matrix to inverse and multiply to this
                         * @return Matrix3x3<T>, a new matrix with this multiplied to 1/m
                         */
                        template <class K>
                        Matrix3x3<T> operator/(Matrix3x3<K> const& m) const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 3x3 generic-type matrix are equal, based on vector == comparison
                         * @param m : Matrix3x3<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Matrix3x3<K> const& m) const;
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 3x3 generic-type matrix aren't equal, based on the negation of the == test
                         * @param m : Matrix3x3<K>, the matrix to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Matrix3x3<K> const& m) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * @brief Shift Operator <<
             * Add m to an out stream with : [a, b c]\n[d e f]\n[g h i]
             * @param stream : std::ostream, the out stream to add m
             * @param m : Matrix3x3<T>, the matrix to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Matrix3x3<T> const& m) {
                 stream << "[" << m[0][0] << " " << m[0][1] << " " << m[0][2] << "]" << std::endl;
                 stream << "[" << m[1][0] << " " << m[1][1] << " " << m[1][2] << "]" << std::endl;
                 stream << "[" << m[2][0] << " " << m[2][1] << " " << m[2][2] << "]";
                 return stream;
             }

        };
    };

    #include "NRE_Matrix3x3.tpp"
