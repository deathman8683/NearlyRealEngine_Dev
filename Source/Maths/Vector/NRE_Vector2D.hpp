
    /**
     * @file NRE_Vector2D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector2D
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

            /**
             * @class Vector2D
             * @brief Maths's Object : Cartesian 2D Generic Vector
             */
            template <class T>
            class Vector2D {
                private:
                    T x;    /**< The x axis translation */
                    T y;    /**< The y axis translation */

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 2D vector with default translation
                         */
                        Vector2D();
                        /**
                         * @brief Constructor
                         * Initialize a 2D vector with x and y
                         * @param x : T, the x translation
                         * @param y : T, the y translation
                         */
                        Vector2D(T const& x, T const& y);
                        /**
                         * @brief Constructor
                         * Convert two 2D generic-type point into a 2D T vector
                         * @param a : Point2D<K>, the vector's start point
                         * @param b : Point2D<L>, the vector's end point
                         */
                        template <class K, class L>
                        Vector2D(Point2D<K> const& a, Point2D<L> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of u
                         * @param u : Vector2D<T>, the vector to copy
                         */
                        Vector2D(Vector2D const& u);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 2D generic-type vector into a 2D T vector
                         * @param u : Vector2D<K>, the vector to convert
                         */
                        template <class K>
                        Vector2D(Vector2D<K> const& u);
                        /**
                         * @brief Convertor
                         * Convert a 2D generic-type point into a 2D T vector
                         * @param p : Point2D<K>, the point to convert
                         */
                        template <class K>
                        Vector2D(Point2D<K> const& p);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 2D vector
                         */
                        virtual ~Vector2D();

                    //## Getter ##//
                        /**
                         * @brief X getter
                         * Return the x attribute
                         * @return T, the x value
                         */
                        T const& getX() const;
                        /**
                         * @brief Y getter
                         * Return the y attribute
                         * @return T, the Y value
                         */
                        T const& getY() const;

                    //## Setter ##//
                        /**
                         * @brief X setter
                         * Change the x value
                         * @param x : K, the new x value
                         */
                        template <class K>
                        void setX(K const& x);
                        /**
                         * @brief Y setter
                         * Change the y value
                         * @param y : K, the new y value
                         */
                        template <class K>
                        void setY(K const& y);
                        /**
                         * @brief X and Y setter
                         * Change both x and y values
                         * @param x : K, the new x value
                         * @param y : L, the new y value
                         */
                        template <class K, class L>
                        void setCoord(K const& x, L const& y);

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
                        /**
                         * @brief 2D rotation
                         * Rotate the vector by a given generic-type theta
                         * @param theta : K, the rotation's angle
                         */
                        template <class K>
                        void rotate(K const& theta);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the addition between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the vector to add into this
                         * @return Vector2D<T>, this with the u added
                         */
                        template <class K>
                        Vector2D<T>& operator+=(Vector2D<K> const& u);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the substraction between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the vector to substract into this
                         * @return Vector2D<T>, this with the u substracted
                         */
                        template <class K>
                        Vector2D<T>& operator-=(Vector2D<K> const& u);
                        /**
                         * @brief Shortcut Operator *=
                         * Compute the multiplication of this by a generic-type factor k
                         * @param k : K, the multiplication factor
                         * @return Vector2D<T>, this multiplied by k
                         */
                        template <class K>
                        Vector2D<T>& operator*=(K const& k);
                        /**
                         * @brief Shortcut Operator /=
                         * Compute the division of this by a generic-type factor k
                         * @param k : K, the division factor
                         * @return Vector2D<T>, this divided by k
                         */
                        template <class K>
                        Vector2D<T>& operator/=(K const& k);
                        /**
                         * @brief Shortcut Operator |=
                         * Compute the scalar product between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the second vector for the scalar product
                         * @return NREfloat, the computed scalar product of this and u
                         */
                        template <class K>
                        NREfloat operator|=(Vector2D<K> const& u) const;

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the addition between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the vector to add into this
                         * @return Vector2D<T>, a new vector result of the addition of this and u
                         */
                        template <class K>
                        Vector2D<T> operator+(Vector2D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the substraction between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the vector to substract into this
                         * @return Vector2D<T>, a new vector result of the substraction of this and u
                         */
                        template <class K>
                        Vector2D<T> operator-(Vector2D<K> const& u) const;
                        /**
                         * @brief Negate Operator -
                         * Compute the negate of this
                         * @return Vector2D<T>, a new vector, the negate vector of this
                         */
                        Vector2D<T> operator-() const;
                        /**
                         * @brief Arithmetic Operator *
                         * Compute the multiplication between this and a generic-type factor k
                         * @param k : K, the multiplication factor
                         * @return Vector2D<T>, a new vector result of the multiplication of this with k
                         */
                        template <class K>
                        Vector2D<T> operator*(K const& k) const;
                        /**
                         * @brief Arithmetic Operator /
                         * Compute the division between this and a generic-type factor k
                         * @param k : K, the division factor
                         * @return Vector2D<T>, a new vector result of the divison of this with k
                         */
                        template <class K>
                        Vector2D<T> operator/(K const& k) const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 2D generic-type vector are equal, based on built-in == comparison for T-type
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Vector2D<K> const& u) const;
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 2D generic-type vector aren't equal, based of the negation of the == test
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Vector2D<K> const& u) const;
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 2D generic-type vector, based on norm comparison
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Vector2D<K> const& u) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 2D generic-type vector, based on norm comparison
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Vector2D<K> const& u) const;
                        /**
                         * @brief Comparison Operator <=
                         * Compare if this is inferior or equal than a 2D generic-type vector, based on norm comparison
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Vector2D<K> const& u) const;
                        /**
                         * @brief Comparison Operator >=
                         * Compare if this is superior or equal than a 2D generic-type vector, based on norm comparison
                         * @param u : Vector2D<K>, the vector to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Vector2D<K> const& u) const;

                    //## BitWise Operator ##//
                        /**
                         * @brief BitWise Operator |
                         * Compute the scalar product between this and a 2D generic-type vector
                         * @param u : Vector2D<K>, the second vector for the scalar product
                         * @return NREfloat, the computed scalar product between this and u
                         */
                        template <class K>
                        NREfloat operator|(Vector2D<K> const& u) const;

                    //## Shift (Usually for printing methods) Operator ##//


                protected:
                    static int DEFAULT_X;  /**< The default x axis translation */
                    static int DEFAULT_Y;  /**< The default y axis translation */
            };

            template <class T>
            int Vector2D<T>::DEFAULT_X = 0.;
            template <class T>
            int Vector2D<T>::DEFAULT_Y = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector2D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
           template <class T>
           inline std::ostream& operator<<(std::ostream &stream, Vector2D<T> const& u);

        };
    };

    #include "NRE_Vector2D.tpp"
