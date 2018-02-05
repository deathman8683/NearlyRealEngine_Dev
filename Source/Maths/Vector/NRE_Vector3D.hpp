
    /**
     * @file NRE_Vector3D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector3D
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

            /**
             * @class Vector3D
             * @brief Maths's Object : Cartesian 3D Generic Vector
             */
            template <class T>
            class Vector3D : public Vector2D<T> {
                private:
                    T z;     /**< The z axis translation */

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 3D vector with default translation
                         */
                        Vector3D();
                        /**
                         * @brief Constructor
                         * Initialize a 3D vector with x, y and z
                         * @param x : K, the x translation
                         * @param y : L, the y translation
                         * @param z : M, the z translation
                         */
                        template <class K, class L, class M>
                        Vector3D(K const& x, L const& y, M const& z);
                        /**
                         * @brief Constructor
                         * Initialize a 3D vector with 2D generic-type vector and z
                         * @param u : Vector2D<K>, the base vector
                         * @param y : L, the z translation
                         */
                        template <class K, class L>
                        Vector3D(Vector2D<K> const& u, L const& z);
                        /**
                         * @brief Constructor
                         * Convert two 3D generic-type point into a 3D T vector
                         * @param a : Point3D<K>, the vector's start point
                         * @param b : Point3D<L>, the vector's end point
                         */
                        template <class K, class L>
                        Vector3D(Point3D<K> const& a, Point3D<L> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of u
                         * @param u : Vector3D<T>, the vector to copy
                         */
                        Vector3D(Vector3D const& u);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 3D generic-type vector into a 3D T vector
                         * @param u : Vector3D<K>, the vector to convert
                         */
                        template <class K>
                        Vector3D(Vector3D<K> const& u);
                        /**
                         * @brief Convertor
                         * Convert a 3D generic-type point into a 3D T vector
                         * @param p : Point3D<K>, the point to convert
                         */
                        template <class K>
                        Vector3D(Point3D<K> const& p);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 3D vector
                         */
                        ~Vector3D();

                    //## Getter ##//
                        /**
                         * @brief Z getter
                         * Return the z attribute
                         * @return T, the z value
                         */
                        T const& getZ() const;

                    //## Setter ##//
                        /**
                         * @brief Z setter
                         * Change the z value
                         * @param z : K, the new z value
                         */
                        template <class K>
                        void setZ(K const& z);
                        /**
                         * @brief X, y and z setter
                         * Change x, y and z values
                         * @param x : K, the new x value
                         * @param y : L, the new y value
                         * @param z : M, the new z value
                         */
                        template <class K, class L, class M>
                        void setCoord(K const& x, L const& y, M const& z);
                        /**
                         * @brief X, y and z setter
                         * Change x, y values from a base 2D vector and z value
                         * @param u : Vector2D<K>, the base vector for x and y values
                         * @param z : L, the new z value
                         */
                        template <class K, class L>
                        void setCoord(Vector2D<K> const& u, L const& z);

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

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                        * @brief Shortcut Operator +=
                        * Compute the addition between this and a 3D generic-type vector
                        * @param u : Vector3D<K>, the vector to add into this
                        * @return Vector3D<T>, this with the u added
                        */
                        template <class K>
                        Vector3D<T>& operator+=(Vector3D<K> const& u);
                        /**
                        * @brief Shortcut Operator -=
                        * Compute the substraction between this and a 3D generic-type vector
                        * @param u : Vector3D<K>, the vector to substract into this
                        * @return Vector3D<T>, this with the u substracted
                        */
                        template <class K>
                        Vector3D<T>& operator-=(Vector3D<K> const& u);
                        /**
                        * @brief Shortcut Operator *=
                        * Compute the multiplication of this by a generic-type factor k
                        * @param k : K, the multiplication factor
                        * @return Vector3D<T>, this multiplied by k
                        */
                        template <class K>
                        Vector3D<T>& operator*=(K const& k);
                        /**
                        * @brief Shortcut Operator /=
                        * Compute the division of this by a generic-type factor k
                        * @param k : K, the division factor
                        * @return Vector3D<T>, this divided by k
                        */
                        template <class K>
                        Vector3D<T>& operator/=(K const& k);
                        /**
                        * @brief Shortcut Operator |=
                        * Compute the scalar product between this and a 3D generic-type vector
                        * @param u : Vector3D<K>, the second vector for the scalar product
                        * @return NREfloat, the computed scalar product of this and u
                        */
                        template <class K>
                        NREfloat operator|=(Vector3D<K> const& u) const;
                        /**
                         * @brief Shortcut Operator ^=
                         * Compute the vectorial product between this and a 3D generic-type vector
                         * @param u : Vector3D<K>, the second vector for the vectorial product
                         * @return Vector3D<T>, the computed vector via vectorial product
                         */
                        template <class K>
                        Vector3D<T>& operator^=(Vector3D<K> const& u);

                    //## Arithmetic Operator ##//
                        /**
                        * @brief Arithmetic Operator +
                        * Compute the addition between this and a 3D generic-type vector
                        * @param u : Vector3D<K>, the vector to add into this
                        * @return Vector3D<T>, a new vector result of the addition of this and u
                        */
                        template <class K>
                        Vector3D<T> operator+(Vector3D<K> const& u);
                        /**
                        * @brief Arithmetic Operator -
                        * Compute the substraction between this and a 3D generic-type vector
                        * @param u : Vector3D<K>, the vector to substract into this
                        * @return Vector3D<T>, a new vector result of the substraction of this and u
                        */
                        template <class K>
                        Vector3D<T> operator-(Vector3D<K> const& u);
                        /**
                        * @brief Negate Operator -
                        * Compute the negate of this
                        * @return Vector3D<T>, a new vector, the negate vector of this
                        */
                        Vector3D<T> operator-();
                        /**
                        * @brief Arithmetic Operator *
                        * Compute the multiplication between this and a generic-type factor k
                        * @param k : K, the multiplication factor
                        * @return Vector3D<T>, a new vector result of the multiplication of this with k
                        */
                        template <class K>
                        Vector3D<T> operator*(K const& k);
                        /**
                        * @brief Arithmetic Operator /
                        * Compute the division between this and a generic-type factor k
                        * @param k : K, the division factor
                        * @return Vector3D<T>, a new vector result of the divison of this with k
                        */
                        template <class K>
                        Vector3D<T> operator/(K const& k);

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 3D generic-type vector are equal, based on built-in == comparison for T-type
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Vector3D<K> const& u);
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 3D generic-type vector aren't equal, based of the negation of the == test
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Vector3D<K> const& u);
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 3D generic-type vector, based on norm comparison
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Vector3D<K> const& u);
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 3D generic-type vector, based on norm comparison
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Vector3D<K> const& u);
                        /**
                         * @brief Comparison Operator <=
                         * Compare if this is inferior or equal than a 3D generic-type vector, based on norm comparison
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Vector3D<K> const& u);
                        /**
                         * @brief Comparison Operator >=
                         * Compare if this is superior or equal than a 3D generic-type vector, based on norm comparison
                         * @param u : Vector3D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Vector3D<K> const& u);

                    //## BitWise Operator ##//
                        /**
                         * @brief BitWise Operator |
                         * Compute the scalar product between this and a 3D generic-type vector
                         * @param u : Vector3D<K>, the second vector for the scalar product
                         * @return NREfloat, the computed scalar product between this and u
                         */
                        template <class K>
                        NREfloat operator|(Vector3D<K> const& u) const;
                        /**
                         * @brief BitWise Operator ^
                         * Compute the vectorial product between this and a 3D generic-type vector
                         * @param u : Vector3D<K>, the second vector for the vectorial product
                         * @return Vector3D<T>, the computed vector via vectorial product
                         */
                        template <class K>
                        Vector3D<T> operator^(Vector3D<K> const& u);


                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_Z;  /**< The default z axis translation */
            };

            template <class T>
            NREfloat Vector3D<T>::DEFAULT_Z = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y, z)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector3D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
           template <class T>
           std::ostream& operator<<(std::ostream &stream, Vector3D<T> const& u);

        };
    };

    #include "NRE_Vector3D.tpp"
