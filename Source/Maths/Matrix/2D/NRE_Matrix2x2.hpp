
    /**
     * @file NRE_Matrix2x2.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix2x2
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

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
                    Vector2D<T> data[2];   /**< Matrix's lines, row major order */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Matrix2x2();
                        /**
                         * Construct a matrix with passed values
                         * @param a first matrix component
                         * @param b second matrix component
                         * @param c third matrix component
                         * @param d fourth matrix component
                         */
                        Matrix2x2(T const& a, T const& b,
                                  T const& c, T const& d);
                        /**
                         * Construct a matrix witn a unique value for all component
                         * @param value new value for all component
                         */
                        Matrix2x2(T const& value);
                        /**
                         * Construct a matrix with their lines passed in parameters with vector
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         */
                        Matrix2x2(Vector2D<T> const& l1, Vector2D<T> const& l2);
                        /**
                         * Construct a matrix with their lines passed in parameters with point
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         */
                        Matrix2x2(Point2D<T> const& l1, Point2D<T> const& l2);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the matrix to copy the content
                         */
                        Matrix2x2(Matrix2x2 const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the matrix to move
                         */
                        Matrix2x2(Matrix2x2 && m);

                    //## Convertor ##//
                        /**
                         * Convert a K-type matrix into a T-type matrix
                         * @param m the K-type matrix to convert
                         */
                        template <class K>
                        Matrix2x2(Matrix2x2<K> const& m);

                    //## Deconstructor ##//
                        /**
                         * Matrix2x2 Deconstructor
                         */
                        ~Matrix2x2();

                    //## Getter ##//
                        /**
                         * First line getter
                         * @return the matrix's first line vector
                         */
                        Vector2D<T> const& getL1() const;
                        /**
                         * Second line getter
                         * @return the matrix's second line vector
                         */
                        Vector2D<T> const& getL2() const;
                        /**
                         * First column getter
                         * @return the matrix's first column vector
                         */
                        Vector2D<T> getC1() const;
                        /**
                         * Second column getter
                         * @return the matrix's second column vector
                         */
                        Vector2D<T> getC2() const;
                        /**
                         * Compute the matrix's determinant
                         * @return the computed matrix's determinant
                         */
                        NREfloat const getDeterminant() const;

                    //## Setter ##//
                        /**
                         * First line setter
                         * @param l1 the new first line vector
                         */
                        template <class K>
                        void setL1(Vector2D<K> const& l1);
                        /**
                         * Second line setter
                         * @param l2 the new second line vector
                         */
                        template <class K>
                        void setL2(Vector2D<K> const& l2);
                        /**
                         * First column setter
                         * @param c1 the new first column vector
                         */
                        template <class K>
                        void setC1(Vector2D<K> const& c1);
                        /**
                         * Second column setter
                         * @param c2 the new second column vector
                         */
                        template <class K>
                        void setC2(Vector2D<K> const& c2);
                        /**
                         * Set the matrix to the identity matrix
                         */
                        void setIdentity();

                    //## Methods ##//
                        /**
                         * Transpose the matrix
                         */
                        void transpose();
                        /**
                         * Inverse the matrix, if not possible the matrix become the identity one
                         */
                        void inverse();
                        /**
                         * Perfom a translation transformation on this
                         * @param u the translation vector
                         */
                        void translate(T const& u);
                        /**
                         * Perform a scale transformation on this
                         * @param u the scaling vector
                         */
                        void scale(T const& u);
                        /**
                         * Return a pointer to the start of the matrix's data
                         * @return the matrix's data's pointer
                         */
                        const T* const value() const;

                    //## Access Operator ##//
                        /**
                         * Return a reference on the index's line of the matrix, don't check the index range
                         * @param  index the matrix's line index
                         * @return a reference on the index's line of the matrix
                         */
                        Vector2D<T>& operator[](unsigned int const& index);
                        /**
                         * Return a const-reference on the index's line of the matrix, don't check the index range
                         * @param  index the matrix's line index
                         * @return a const-reference on the index's line of the matrix
                         */
                        const Vector2D<T>& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the matrix to copy into this
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator=(Matrix2x2<T> const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the matrix to move into this
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator=(Matrix2x2<T> && m);

                    //## Shortcut Operator ##//
                        /**
                         * Add all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix2x2<T>& operator+=(Matrix2x2<T> const& m);
                        /**
                         * Subtract all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix2x2<T>& operator-=(Matrix2x2<T> const& m);
                        /**
                         * Multiply all component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator*=(T const& k);
                        /**
                         * Multiply this with m
                         * @param m the matrix to multiply with this
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator*=(Matrix2x2<T> const& m);
                        /**
                         * Divide all component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator/=(T const& k);
                        /**
                         * Divide this with m, by multiply this with m's inverse
                         * @param m the matrix to divide with this
                         * @return the reference of himself
                         */
                        Matrix2x2<T>& operator/=(Matrix2x2<T> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the matrix resulting in the addition of this and m
                         * @param m the matrix to add with this
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator+(Matrix2x2<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the subtraction of this and m
                         * @param m the matrix to subtract with this
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator-(Matrix2x2<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator*(T const& k) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this and m
                         * @param m the matrix to multiply with this
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator*(Matrix2x2<T> const& m) const;
                        /**
                         * Compute the vector resulting in the transformation of u by this
                         * @param u the vector to transform
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator*(Vector2D<T> const& u) const;
                        /**
                         * Compute the matrix resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator/(T const& k) const;
                        /**
                         * Compute the matrix resulting in the division of this and m
                         * @param m the matrix to divide with this
                         * @return the newly computed matrix
                         */
                        Matrix2x2<T> operator/(Matrix2x2<T> const& m) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator==(Matrix2x2<T> const& m) const;
                        /**
                         * Difference test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator!=(Matrix2x2<T> const& m) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for 2x2 matrix
             * @param stream the out stream to add the matrix m
             * @param m the matrix to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Matrix2x2<T> const& m) {
                 stream << "[" << m[0][0] << " " << m[0][1] << "]" << '\n';
                 stream << "[" << m[1][0] << " " << m[1][1] << "]";
                 return stream;
             }

        };
    };

    #include "NRE_Matrix2x2.tpp"
