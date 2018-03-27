
    /**
     * @file NRE_Vector4D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector4D
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

            /**
             * @class Vector4D
             * @brief Maths's Object : Homogeneous 3D Generic Vector
             */
            template <class T>
            class Vector4D {
                private:
                    T data[4];

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 4D vector with default translation
                         */
                        Vector4D();
                        /**
                         * @brief Constructor
                         * Initialize a 4D vector with x, y, z and w
                         * @param x : K, the x translation
                         * @param y : L, the y translation
                         * @param z : M, the z translation
                         * @param w : N, the w translation
                         */
                        template <class K, class L, class M, class N>
                        Vector4D(K const& x, L const& y, M const& z, N const& w);
                        /**
                         * @brief Constructor
                         * Initialize a 4D vector with 3D generic-type vector and w
                         * @param u : Vector3D<K>, the base vector
                         * @param w : T, the w translation
                         */
                        template <class K>
                        Vector4D(Vector3D<K> const& u, T const& w);
                        /**
                         * @brief Constructor
                         * Convert two 4D generic-type point into a 4D T vector
                         * @param a : Point4D<K>, the vector's start point
                         * @param b : Point4D<L>, the vector's end point
                         */
                        template <class K, class L>
                        Vector4D(Point4D<K> const& a, Point4D<L> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of u
                         * @param u : Vector4D<T>, the vector to copy
                         */
                        Vector4D(Vector4D const& u);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 4D generic-type vector into a 4D T vector
                         * @param u : Vector4D<K>, the vector to convert
                         */
                        template <class K>
                        Vector4D(Vector4D<K> const& u);
                        /**
                         * @brief Convertor
                         * Convert a 4D generic-type point into a 4D T vector
                         * @param p : Point4D<K>, the point to convert
                         */
                        template <class K>
                        Vector4D(Point4D<K> const& p);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 4D vector
                         */
                        ~Vector4D();

                    //## Getter ##//
                        T const& getX() const;
                        T const& getY() const;
                        T const& getZ() const;
                        /**
                         * @brief W getter
                         * Return the w attribute
                         * @return T, the w value
                         */
                        T const& getW() const;

                    //## Setter ##//
                        template <class K>
                        void setX(K const& x);
                        template <class K>
                        void setY(K const& y);
                        template <class K>
                        void setZ(K const& z);
                        /**
                         * @brief W setter
                         * Change the w value
                         * @param w : K, the new w value
                         */
                        template <class K>
                        void setW(K const& w);
                        /**
                         * @brief X, y, z and w setter
                         * Change x, y, z and w values
                         * @param x : K, the new x value
                         * @param y : L, the new y value
                         * @param z : M, the new z value
                         * @param w : N, the new w value
                         */
                        template <class K, class L, class M, class N>
                        void setCoord(K const& x, L const& y, M const& z, N const& w);
                        /**
                         * @brief X, y, z and w setter
                         * Change x, y, z values from a base 3D vector and w value
                         * @param u : Vector3D<K>, the base vector for x, y and z values
                         * @param w : L, the new w value
                         */
                        template <class K, class L>
                        void setCoord(Vector3D<K> const& u, L const& w);

                    //## Methods ##//
                        /**
                         * @brief Norm getter
                         * Compute the vector's norm
                         * @return NREfloat, the computed norm
                         */
                        NREfloat norm() const;
                        /**
                         * @brief NormSquared getter
                         * Compute the vector's squared norm
                         * @return NREfloat, the computed squared norm
                         */
                        NREfloat normSquared() const;
                        /**
                         * @brief Normlization
                         * Normalize the vector, doesn't check if the vector's norm is null
                         */
                        void normalize();
                        T* const value();

                    //## Access Operator ##//
                        T& operator[](unsigned int const& index);
                        const T& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                        * @brief Shortcut Operator +=
                        * Compute the addition between this and a 4D generic-type vector
                        * @param u : Vector4D<K>, the vector to add into this
                        * @return Vector4D<T>, this with the u added
                        */
                        template <class K>
                        Vector4D<T>& operator+=(Vector4D<K> const& u);
                        /**
                        * @brief Shortcut Operator -=
                        * Compute the substraction between this and a 4D generic-type vector
                        * @param u : Vector4D<K>, the vector to substract into this
                        * @return Vector4D<T>, this with the u substracted
                        */
                        template <class K>
                        Vector4D<T>& operator-=(Vector4D<K> const& u);
                        /**
                        * @brief Shortcut Operator *=
                        * Compute the multiplication of this by a generic-type factor k
                        * @param k : K, the multiplication factor
                        * @return Vector4D<T>, this multiplied by k
                        */
                        template <class K>
                        Vector4D<T>& operator*=(K const& k);
                        /**
                        * @brief Shortcut Operator /=
                        * Compute the division of this by a generic-type factor k
                        * @param k : K, the division factor
                        * @return Vector4D<T>, this divided by k
                        */
                        template <class K>
                        Vector4D<T>& operator/=(K const& k);
                        /**
                        * @brief Shortcut Operator |=
                        * Compute the scalar product between this and a 4D generic-type vector
                        * @param u : Vector4D<K>, the second vector for the scalar product
                        * @return NREfloat, the computed scalar product of this and u
                        */
                        template <class K>
                        NREfloat operator|=(Vector4D<K> const& u) const;

                    //## Arithmetic Operator ##//
                        /**
                        * @brief Arithmetic Operator +
                        * Compute the addition between this and a 4D generic-type vector
                        * @param u : Vector4D<K>, the vector to add into this
                        * @return Vector4D<T>, a new vector result of the addition of this and u
                        */
                        template <class K>
                        Vector4D<T> operator+(Vector4D<K> const& u) const;
                        /**
                        * @brief Arithmetic Operator -
                        * Compute the substraction between this and a 4D generic-type vector
                        * @param u : Vector4D<K>, the vector to substract into this
                        * @return Vector4D<T>, a new vector result of the substraction of this and u
                        */
                        template <class K>
                        Vector4D<T> operator-(Vector4D<K> const& u) const;
                        /**
                        * @brief Negate Operator -
                        * Compute the negate of this
                        * @return Vector4D<T>, a new vector, the negate vector of this
                        */
                        Vector4D<T> operator-() const;
                        /**
                        * @brief Arithmetic Operator *
                        * Compute the multiplication between this and a generic-type factor k
                        * @param k : K, the multiplication factor
                        * @return Vector4D<T>, a new vector result of the multiplication of this with k
                        */
                        template <class K>
                        Vector4D<T> operator*(K const& k) const;
                        /**
                        * @brief Arithmetic Operator /
                        * Compute the division between this and a generic-type factor k
                        * @param k : K, the division factor
                        * @return Vector4D<T>, a new vector result of the divison of this with k
                        */
                        template <class K>
                        Vector4D<T> operator/(K const& k) const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 4D generic-type vector are equal, based on built-in == comparison for T-type
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Vector4D<K> const& u) const;
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 4D generic-type vector aren't equal, based of the negation of the == test
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Vector4D<K> const& u) const;
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 4D generic-type vector, based on norm comparison
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Vector4D<K> const& u) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 4D generic-type vector, based on norm comparison
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Vector4D<K> const& u) const;
                        /**
                         * @brief Comparison Operator <=
                         * Compare if this is inferior or equal than a 4D generic-type vector, based on norm comparison
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Vector4D<K> const& u) const;
                        /**
                         * @brief Comparison Operator >=
                         * Compare if this is superior or equal than a 4D generic-type vector, based on norm comparison
                         * @param u : Vector4D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Vector4D<K> const& u) const;

                    //## BitWise Operator ##//
                        /**
                         * @brief BitWise Operator |
                         * Compute the scalar product between this and a 4D generic-type vector
                         * @param u : Vector4D<K>, the second vector for the scalar product
                         * @return NREfloat, the computed scalar product between this and u
                         */
                        template <class K>
                        NREfloat operator|(Vector4D<K> const& u) const;


                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_X;  /**< The default x axis translation */
                    static int DEFAULT_Y;  /**< The default y axis translation */
                    static int DEFAULT_Z;  /**< The default z axis translation */
                    static int DEFAULT_W;  /**< The default w axis translation */
            };

            template <class T>
            int Vector4D<T>::DEFAULT_X = 0.;
            template <class T>
            int Vector4D<T>::DEFAULT_Y = 0.;
            template <class T>
            int Vector4D<T>::DEFAULT_Z = 0.;
            template <class T>
            int Vector4D<T>::DEFAULT_W = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y, z, w)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector4D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             std::ostream& operator<<(std::ostream &stream, Vector4D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << "," << u.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector4D.tpp"
