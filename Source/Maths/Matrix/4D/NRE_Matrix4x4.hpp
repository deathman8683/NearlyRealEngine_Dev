
    /**
     * @file NRE_Matrix4x4.hpp
     * @brief Declaration of Engine's Maths's Object : Matrix4x4
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

            template<class> class Point4D;
            template<class> class Vector4D;

            /**
             * @class Matrix4x4
             * @brief Maths's Object : 4x4 Generic Matrix
             */
            template <class T>
            class Matrix4x4 {
                private:
                    Vector4D<T> data[4];   /**< Matrix's lines, row major order */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Matrix4x4();
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
                         * @param j tenth matrix component
                         * @param k eleventh matrix component
                         * @param l twelfth matrix component
                         * @param m thirteenth matrix component
                         * @param n fourteenth matrix component
                         * @param o fifteenth matrix component
                         * @param p sixteenth matrix component
                         */
                        Matrix4x4(T const& a, T const& b, T const& c, T const& d,
                                  T const& e, T const& f, T const& g, T const& h,
                                  T const& i, T const& j, T const& k, T const& l,
                                  T const& m, T const& n, T const& o, T const& p);
                        /**
                         * Construct a matrix witn a unique value for all component
                         * @param value new value for all component
                         */
                        Matrix4x4(T const& value);
                        /**
                         * Construct a matrix with their lines passed in parameters with vector
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         * @param l3 the new value for the third line
                         * @param l4 the new value for the fourth line
                         */
                        Matrix4x4(Vector4D<T> const& l1, Vector4D<T> const& l2, Vector4D<T> const& l3, Vector4D<T> const& l4);
                        /**
                         * Construct a matrix with their lines passed in parameters with point
                         * @param l1 the new value for the first line
                         * @param l2 the new value for the second line
                         * @param l3 the new value for the third line
                         * @param l4 the new value for the fourth line
                         */
                        Matrix4x4(Point4D<T> const& l1, Point4D<T> const& l2, Point4D<T> const& l3, Point4D<T> const& l4);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the matrix to copy the content
                         */
                        Matrix4x4(Matrix4x4 const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the matrix to move
                         */
                        Matrix4x4(Matrix4x4 && m);

                    //## Convertor ##//
                        /**
                         * Convert a K-type matrix into a T-type matrix
                         * @param m the K-type matrix to convert
                         */
                        template <class K>
                        Matrix4x4(Matrix4x4<K> const& m);
                        /**
                         * Convert a K-type 3x3 matrix into a T-type 4x4 matrix
                         * @param m the K-type 3x3 matrix to convert
                         */
                        template <class K>
                        Matrix4x4(Matrix3x3<K> const& m);

                    //## Deconstructor ##//
                        /**
                         * Matrix3x3 Deconstructor
                         */
                        ~Matrix4x4();

                    //## Getter ##//
                        /**
                         * First line getter
                         * @return the matrix's first line vector
                         */
                        Vector4D<T> const& getL1() const;
                        /**
                         * Second line getter
                         * @return the matrix's second line vector
                         */
                        Vector4D<T> const& getL2() const;
                        /**
                         * Third line getter
                         * @return the matrix's third line vector
                         */
                        Vector4D<T> const& getL3() const;
                        /**
                         * Fourth line getter
                         * @return the matrix's fourth line vector
                         */
                        Vector4D<T> const& getL4() const;
                        /**
                         * First column getter
                         * @return the matrix's first column vector
                         */
                        Vector4D<T> getC1() const;
                        /**
                         * Second column getter
                         * @return the matrix's second column vector
                         */
                        Vector4D<T> getC2() const;
                        /**
                         * Third column getter
                         * @return the matrix's third column vector
                         */
                        Vector4D<T> getC3() const;
                        /**
                         * Fourth column getter
                         * @return the matrix's fourth column vector
                         */
                        Vector4D<T> getC4() const;
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
                        void setL1(Vector4D<T> const& l1);
                        /**
                         * Second line setter
                         * @param l2 the new second line vector
                         */
                        void setL2(Vector4D<T> const& l2);
                        /**
                         * Third line setter
                         * @param l3 the new third line vector
                         */
                        void setL3(Vector4D<T> const& l3);
                        /**
                         * Fourth line setter
                         * @param l4 the new fourth line vector
                         */
                        void setL4(Vector4D<T> const& l4);
                        /**
                         * First column setter
                         * @param c1 the new first column vector
                         */
                        void setC1(Vector4D<T> const& c1);
                        /**
                         * Second column setter
                         * @param c2 the new second column vector
                         */
                        void setC2(Vector4D<T> const& c2);
                        /**
                         * Third column setter
                         * @param c3 the new third column vector
                         */
                        void setC3(Vector4D<T> const& c3);
                        /**
                         * Fourth column setter
                         * @param c4 the new fourth column vector
                         */
                        void setC4(Vector4D<T> const& c4);
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
                        void translate(Vector3D<T> const& u);
                        /**
                         * Perform a scale transformation on this
                         * @param u the scaling vector
                         */
                        void scale(Vector3D<T> const& u);
                        /**
                         * Perform a rotation transformation on this
                         * @param angle the rotation angle
                         * @param axis the axis vector to apply the rotation on
                         */
                        void rotate(T const& angle, Vector3D<T> const& axis);
                        /**
                         * Perform a perspective projection on this
                         * @param fov   the projection's fov
                         * @param ratio the projection's ratio
                         * @param zNear the projection's near plane distance
                         * @param zFar  the projection's far plane distance
                         */
                        void projection(T const& fov, T const& ratio, T const& zNear, T const& zFar);
                        /**
                         * Perform an orthogonal projection on this
                         * @param left   coordinate for the vertical clipping plane
                         * @param right  coordinate for the vertical clipping plane
                         * @param bottom coordinate for the horizontal clipping plane
                         * @param top    coordinate for the horizontal clipping plane
                         * @param zNear  the projection's near plane distance
                         * @param zFar   the projection's far plane distance
                         */
                        void ortho(T const& left, T const& right, T const& bottom, T const& top, T const& zNear, T const& zFar);
                        /**
                         * Perform a viewing transformation on this
                         * @param eye    the camera's eye
                         * @param center the point fixed by the camera
                         * @param up     the camera's up vector
                         */
                        void lookAt(Point3D<T> const& eye, Point3D<T> const& center, Vector3D<T> const& up);
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
                        Vector4D<T>& operator[](unsigned int const& index);
                        /**
                         * Return a const-reference on the index's line of the matrix, don't check the index range
                         * @param  index the matrix's line index
                         * @return a const-reference on the index's line of the matrix
                         */
                        const Vector4D<T>& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the matrix to copy into this
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator=(Matrix4x4<T> const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the matrix to move into this
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator=(Matrix4x4<T> && m);

                    //## Shortcut Operator ##//
                        /**
                         * Add all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix4x4<T>& operator+=(Matrix4x4<T> const& m);
                        /**
                         * Subtract all m's component with this' ones
                         * @param m the matrix to add into this
                         * @return the reference on himself
                         */
                        Matrix4x4<T>& operator-=(Matrix4x4<T> const& m);
                        /**
                         * Multiply all component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator*=(T const& k);
                        /**
                         * Multiply this with m
                         * @param m the matrix to multiply with this
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator*=(Matrix4x4<T> const& m);
                        /**
                         * Divide all component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator/=(T const& k);
                        /**
                         * Divide this with m, by multiply this with m's inverse
                         * @param m the matrix to divide with this
                         * @return the reference of himself
                         */
                        Matrix4x4<T>& operator/=(Matrix4x4<T> const& m);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the matrix resulting in the addition of this and m
                         * @param m the matrix to add with this
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator+(Matrix4x4<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the subtraction of this and m
                         * @param m the matrix to subtract with this
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator-(Matrix4x4<T> const& m) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator*(T const& k) const;
                        /**
                         * Compute the matrix resulting in the multiplication of this and m
                         * @param m the matrix to multiply with this
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator*(Matrix4x4<T> const& m) const;
                        /**
                         * Compute the vector resulting in the transformation of u by this
                         * @param u the vector to transform
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator*(Vector4D<T> const& u) const;
                        /**
                         * Compute the matrix resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator/(T const& k) const;
                        /**
                         * Compute the matrix resulting in the division of this and m
                         * @param m the matrix to divide with this
                         * @return the newly computed matrix
                         */
                        Matrix4x4<T> operator/(Matrix4x4<T> const& m) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator==(Matrix4x4<T> const& m) const;
                        /**
                         * Difference test between this and m
                         * @param m the matrix to test with this
                         */
                        bool operator!=(Matrix4x4<T> const& m) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for 4x4 matrix
             * @param stream the out stream to add the matrix m
             * @param m the matrix to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Matrix4x4<T> const& m) {
                 stream << "[" << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << "]" << '\n';
                 stream << "[" << m[1][0] << " " << m[1][1] << " " << m[1][2] << " " << m[1][3] << "]" << '\n';
                 stream << "[" << m[2][0] << " " << m[2][1] << " " << m[2][2] << " " << m[2][3] << "]" << '\n';
                 stream << "[" << m[3][0] << " " << m[3][1] << " " << m[3][2] << " " << m[3][3] << "]";
                 return stream;
             }

        };
    };

    #include "NRE_Matrix4x4.tpp"
