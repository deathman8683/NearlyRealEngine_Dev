
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
                    Vector4D<T> data[4];   /**< Matrix's data */

                public:
                    //## Constructor ##//
                         /**
                          * @brief Constructor
                          * Default constructor, iniatlize a 4x4 identity matrix
                          */
                        Matrix4x4();
                        Matrix4x4(T const& a, T const& b, T const& c, T const& d,
                                  T const& e, T const& f, T const& g, T const& h,
                                  T const& i, T const& j, T const& k, T const& l,
                                  T const& m, T const& n, T const& o, T const& p);
                        Matrix4x4(T const& value);
                        Matrix4x4(Vector4D<T> const& l1, Vector4D<T> const& l2, Vector4D<T> const& l3, Vector4D<T> const& l4);
                        Matrix4x4(Point4D<T> const& l1, Point4D<T> const& l2, Point4D<T> const& l3, Point4D<T> const& l4);

                    //## Copy-Constructor ##//
                        Matrix4x4(Matrix4x4 const& m);

                    //## Move-Constructor ##//
                        Matrix4x4(Matrix4x4 && m);

                    //## Convertor ##//
                        template <class K>
                        Matrix4x4(Matrix4x4<K> const& m);
                        template <class K>
                        Matrix4x4(Matrix3x3<K> const& m);

                    //## Deconstructor ##//
                        ~Matrix4x4();

                    //## Getter ##//
                        /**
                         * @brief First line getter
                         * Return the matrix's first line as a 4D vector
                         * @return Vector4D<T>, the matrix's first line
                         */
                        Vector4D<T> const& getL1() const;
                        /**
                         * @brief Second line getter
                         * Return the matrix's second line as a 4D vector
                         * @return Vector4D<T>, the matrix's second line
                         */
                        Vector4D<T> const& getL2() const;
                        /**
                         * @brief Third line getter
                         * Return the matrix's third line as a 4D vector
                         * @return Vector4D<T>, the matrix's third line
                         */
                        Vector4D<T> const& getL3() const;
                        /**
                         * @brief Fourth line getter
                         * Return the matrix's fourth line as a 4D vector
                         * @return Vector4D<T>, the matrix's fourth line
                         */
                        Vector4D<T> const& getL4() const;
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
                        NREfloat const getDeterminant() const;

                    //## Setter ##//
                        void setL1(Vector4D<T> const& l1);
                        void setL2(Vector4D<T> const& l2);
                        void setL3(Vector4D<T> const& l3);
                        void setL4(Vector4D<T> const& l4);
                        void setC1(Vector4D<T> const& c1);
                        void setC2(Vector4D<T> const& c2);
                        void setC3(Vector4D<T> const& c3);
                        void setC4(Vector4D<T> const& c4);
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
                        void translate(Vector3D<T> const& u);
                        void scale(Vector3D<T> const& u);
                        void rotate(T const& angle, Vector3D<T> const& axis);
                        void projection(T const& fov, T const& ratio, T const& zNear, T const& zFar);
                        void ortho(T const& left, T const& right, T const& bottom, T const& top, T const& zNear, T const& zFar);
                        void lookAt(Point3D<T> const& eye, Point3D<T> const& center, Vector3D<T> const& up);
                        const T* const value() const;

                    //## Access Operator ##//
                        /**
                         * @brief Write Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        Vector4D<T>& operator[](unsigned int const& index);
                        /**
                         * @brief Read Access Operator []
                         * Return the index's line from the matrix
                         * @param index : unsigned int, tell which line to return
                         * @return T*, the matrix's line
                         */
                        const Vector4D<T>& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        Matrix4x4<T>& operator=(Matrix4x4<T> const& m);
                        Matrix4x4<T>& operator=(Matrix4x4<T> && m);

                    //## Shortcut Operator ##//
                        Matrix4x4<T>& operator+=(Matrix4x4<T> const& m);
                        Matrix4x4<T>& operator-=(Matrix4x4<T> const& m);
                        Matrix4x4<T>& operator*=(T const& k);
                        Matrix4x4<T>& operator*=(Matrix4x4<T> const& m);
                        Matrix4x4<T>& operator/=(T const& k);
                        Matrix4x4<T>& operator/=(Matrix4x4<T> const& m);

                    //## Arithmetic Operator ##//
                        Matrix4x4<T> operator+(Matrix4x4<T> const& m) const;
                        Matrix4x4<T> operator-(Matrix4x4<T> const& m) const;
                        Matrix4x4<T> operator*(T const& k) const;
                        Matrix4x4<T> operator*(Matrix4x4<T> const& m) const;
                        Vector4D<T> operator*(Vector4D<T> const& u) const;
                        Matrix4x4<T> operator/(T const& k) const;
                        Matrix4x4<T> operator/(Matrix4x4<T> const& m) const;

                    //## Comparison Operator ##//
                        bool operator==(Matrix4x4<T> const& m) const;
                        bool operator!=(Matrix4x4<T> const& m) const;

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
