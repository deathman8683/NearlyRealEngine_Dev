
    /**
     * @file NRE_Matrix3x3.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix3x3
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

            template<class> class Point3D;
            template<class> class Vector3D;
            template<class> class Quaternion;
            template<class> class Matrix4x4;

            /**
             * @class Matrix3x3
             * @brief Maths's Object : 3x3 Generic Matrix
             */
            template <class T>
            class Matrix3x3 {
                private:
                    Vector3D<T> data[3];   /**< Matrix's lines, row major order */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Matrix3x3();
                        /**
                         * Construct a matrix with passed values
                         * @param a first matrix component
                         * @param b second matrix component
                         * @param c third matrix component
                         * @param d fourth matrix component
                         * @param e fifth matrix component
                         * @param f sixth matrix component
                         * @param g seventh matrix component
                         * @param h eigth matrix component
                         * @param i nineth matrix component
                         */
                        Matrix3x3(T const& a, T const& b, T const& c,
                                  T const& d, T const& e, T const& f,
                                  T const& g, T const& h, T const& i);
                        /**
                         * Construct a matrix witn a unique value for all component
                         * @param value new value for all component
                         */
                        Matrix3x3(T const& value);
                        /**
                         * Construct a matrix with their lines passed in parameters with vector
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         * @param l3 the new value for the third line
                         */
                        Matrix3x3(Vector3D<T> const& l1, Vector3D<T> const& l2, Vector3D<T> const& l3);
                        /**
                         * Construct a matrix with their lines passed in parameters with point
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         * @param l3 the new value for the third line
                         */
                        Matrix3x3(Point3D<T> const& l1, Point3D<T> const& l2, Point3D<T> const& l3);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the matrix to copy the content
                         */
                        Matrix3x3(Matrix3x3 const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the matrix to move
                         */
                        Matrix3x3(Matrix3x3 && m);

                    //## Convertor ##//
                        /**
                         * Convert a K-type matrix into a T-type matrix
                         * @param m the K-type matrix to convert
                         */
                        template <class K>
                        Matrix3x3(Matrix3x3<K> const& m);
                        /**
                         * Convert a K-type 4x4 matrix into a T-type 3x3 matrix
                         * @param m the K-type 4x4 matrix to convert
                         */
                        template <class K>
                        Matrix3x3(Matrix4x4<K> const& m);
                        /**
                         * Convert a K-type Quaternion into a T-type 3x3 matrix
                         * @param q the K-type Quaternion to convert
                         */
                        template <class K>
                        Matrix3x3(Quaternion<K> const& q);

                    //## Deconstructor ##//
                        /**
                         * Matrix3x3 Deconstructor
                         */
                        ~Matrix3x3();

                    //## Getter ##//
                        /**
                         * First line getter
                         * @return the matrix's first line vector
                         */
                        Vector3D<T> const& getL1() const;
                        /**
                         * Second line getter
                         * @return the matrix's second line vector
                         */
                        Vector3D<T> const& getL2() const;
                        /**
                         * Third line getter
                         * @return the matrix's third line vector
                         */
                        Vector3D<T> const& getL3() const;
                        /**
                         * First column getter
                         * @return the matrix's first column vector
                         */
                        Vector3D<T> getC1() const;
                        /**
                         * Second column getter
                         * @return the matrix's second column vector
                         */
                        Vector3D<T> getC2() const;
                        /**
                         * Third column getter
                         * @return the matrix's third column vector
                         */
                        Vector3D<T> getC3() const;
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
                        void setL1(Vector3D<T> const& l1);
                        /**
                         * Second line setter
                         * @param l2 the new second line vector
                         */
                        void setL2(Vector3D<T> const& l2);
                        /**
                         * Third line setter
                         * @param l3 the new third line vector
                         */
                        void setL3(Vector3D<T> const& l3);
                        /**
                         * First column setter
                         * @param c1 the new first column vector
                         */
                        void setC1(Vector3D<T> const& c1);
                        /**
                         * Second column setter
                         * @param c2 the new second column vector
                         */
                        void setC2(Vector3D<T> const& c2);
                        /**
                         * Third column setter
                         * @param c3 the new third column vector
                         */
                        void setC3(Vector3D<T> const& c3);
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
                        void translate(Vector2D<T> const& u);
                        /**
                         * Perform a scale transformation on this
                         * @param u the scaling vector
                         */
                        void scale(Vector2D<T> const& u);
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
                        Vector3D<T>& operator[](unsigned int const& index);
                        /**
                         * Return a const-reference on the index's line of the matrix, don't check the index range
                         * @param  index the matrix's line index
                         * @return a const-reference on the index's line of the matrix
                         */
                        const Vector3D<T>& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the matrix to copy into this
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator=(Matrix3x3<T> const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the matrix to move into this
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator=(Matrix3x3<T> && m);

                    //## Shortcut Operator ##//
                        /**
                         * Add all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix3x3<T>& operator+=(Matrix3x3<T> const& m);
                        /**
                         * Subtract all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix3x3<T>& operator-=(Matrix3x3<T> const& m);
                        /**
                         * Multiply all component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator*=(T const& k);
                        /**
                         * Multiply this with m
                         * @param m the matrix to multiply with this
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator*=(Matrix3x3<T> const& m);
                        /**
                         * Divide all component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator/=(T const& k);
                        /**
                         * Divide this with m, by multiply this with m's inverse
                         * @param m the matrix to divide with this
                         * @return the reference of himself
                         */
                        Matrix3x3<T>& operator/=(Matrix3x3<T> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the matrix resulting in the addition of this and m
                         * @param m the matrix to add with this
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator+(Matrix3x3<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the subtraction of this and m
                         * @param m the matrix to subtract with this
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator-(Matrix3x3<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator*(T const& k) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this and m
                         * @param m the matrix to multiply with this
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator*(Matrix3x3<T> const& m) const;
                        /**
                         * Compute the vector resulting in the transformation of u by this
                         * @param u the vector to transform
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator*(Vector3D<T> const& u) const;
                        /**
                         * Compute the matrix resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator/(T const& k) const;
                        /**
                         * Compute the matrix resulting in the division of this and m
                         * @param m the matrix to divide with this
                         * @return the newly computed matrix
                         */
                        Matrix3x3<T> operator/(Matrix3x3<T> const& m) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator==(Matrix3x3<T> const& m) const;
                        /**
                         * Difference test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator!=(Matrix3x3<T> const& m) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for 3x3 matrix
             * @param stream the out stream to add the matrix m
             * @param m the matrix to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Matrix3x3<T> const& m) {
                 stream << "[" << m[0][0] << " " << m[0][1] << " " << m[0][2] << "]" << '\n';
                 stream << "[" << m[1][0] << " " << m[1][1] << " " << m[1][2] << "]" << '\n';
                 stream << "[" << m[2][0] << " " << m[2][1] << " " << m[2][2] << "]";
                 return stream;
             }

        };
    };

    #include "NRE_Matrix3x3.tpp"
