
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
            template<class> class Matrix4x4;

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
                        Matrix3x3();
                        Matrix3x3(T const& a, T const& b, T const& c,
                                  T const& d, T const& e, T const& f,
                                  T const& g, T const& h, T const& i);
                        Matrix3x3(T const& value);
                        Matrix3x3(Vector3D<T> const& l1, Vector3D<T> const& l2, Vector3D<T> const& l3);
                        Matrix3x3(Point3D<T> const& l1, Point3D<T> const& l2, Point3D<T> const& l3);

                    //## Copy-Constructor ##//
                        Matrix3x3(Matrix3x3 const& m);

                    //## Move-Constructor ##//
                        Matrix3x3(Matrix3x3 && m);

                    //## Convertor ##//
                        template <class K>
                        Matrix3x3(Matrix3x3<K> const& m);
                        template <class K>
                        Matrix3x3(Matrix4x4<K> const& m);

                    //## Deconstructor ##//
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
                        NREfloat const getDeterminant() const;

                    //## Setter ##//
                        void setL1(Vector3D<T> const& l1);
                        void setL2(Vector3D<T> const& l2);
                        void setL3(Vector3D<T> const& l3);
                        void setC1(Vector3D<T> const& c1);
                        void setC2(Vector3D<T> const& c2);
                        void setC3(Vector3D<T> const& c3);
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
                        void translate(Vector2D<T> const& u);
                        void scale(Vector2D<T> const& u);
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
                        Matrix3x3<T>& operator=(Matrix3x3<T> const& m);
                        Matrix3x3<T>& operator=(Matrix3x3<T> && m);

                    //## Shortcut Operator ##//
                        Matrix3x3<T>& operator+=(Matrix3x3<T> const& m);
                        Matrix3x3<T>& operator-=(Matrix3x3<T> const& m);
                        Matrix3x3<T>& operator*=(T const& k);
                        Matrix3x3<T>& operator*=(Matrix3x3<T> const& m);
                        Matrix3x3<T>& operator/=(T const& k);
                        Matrix3x3<T>& operator/=(Matrix3x3<T> const& m);

                    //## Arithmetic Operator ##//
                        Matrix3x3<T> operator+(Matrix3x3<T> const& m) const;
                        Matrix3x3<T> operator-(Matrix3x3<T> const& m) const;
                        Matrix3x3<T> operator*(T const& k) const;
                        Matrix3x3<T> operator*(Matrix3x3<T> const& m) const;
                        Vector3D<T> operator*(Vector3D<T> const& u) const;
                        Matrix3x3<T> operator/(T const& k) const;
                        Matrix3x3<T> operator/(Matrix3x3<T> const& m) const;

                    //## Comparison Operator ##//
                        bool operator==(Matrix3x3<T> const& m) const;
                        bool operator!=(Matrix3x3<T> const& m) const;

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
                 stream << "[" << m[0][0] << " " << m[0][1] << " " << m[0][2] << "]" << '\n';
                 stream << "[" << m[1][0] << " " << m[1][1] << " " << m[1][2] << "]" << '\n';
                 stream << "[" << m[2][0] << " " << m[2][1] << " " << m[2][2] << "]";
                 return stream;
             }

        };
    };

    #include "NRE_Matrix3x3.tpp"
