
    /**
     * @file NRE_Point2D.hpp
     * @brief Declaration of Engine's Maths's Object : Point2D
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

            template<class> class Vector2D;

            /**
             * @class Point2D
             * @brief Maths's Object : Cartesian 2D Generic Point
             */
            template <class T>
            class Point2D {
                private:
                    T x;    /**< The abscissa of this */
                    T y;    /**< The ordinate of this */

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 2D point with default coordinates
                         */
                        Point2D();
                        /**
                         * @brief Constructor
                         * Initialize a 2D point with x and y
                         * @param x : T, the x coordinate
                         * @param y : T, the y coordinate
                         */
                        Point2D(T const& x, T const& y);
                        /**
                         * @brief Constructor
                         * Convert a 2D generic-type point and a translation 2D generic-type vector into a 2D T point
                         * @param p : Point2D<K>, the point to convert
                         * @param u : Vector2D<L>, the translation vector applied to p
                         */
                        template <class K, class L>
                        Point2D(Point2D<K> const& p, Vector2D<L> const& u);

                        //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of p
                         * @param p : Point2D<T>, the point to copy
                         */
                        Point2D(Point2D const& p);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 2D generic-type point into a 2D T point
                         * @param p : Point2D<K>, the point to convert
                         */
                        template <class K>
                        Point2D(Point2D<K> const& p);
                        /**
                         * @brief Convertor
                         * Convert a 2D generic-type vector into a 2D T point
                         * @param u : Vector2D<K>, the vector to convert
                         */
                        template <class K>
                        Point2D(Vector2D<K> const& u);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 2D point
                         */
                        ~Point2D();

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
                         * @brief Distance getter
                         * Compute the distance between this and p, by default p is the default point
                         * @param p : Point2D<T>, the point to measure the distance with this
                         * @return NREfloat, the computed distance
                         */
                        NREfloat distance(Point2D<T> const& p = {DEFAULT_X, DEFAULT_Y}) const;
                        /**
                         * @brief DistanceSquared getter
                         * Compute the squared distance between this and p, by default p is the default point
                         * @param p : Point2D<T>, the point to measure the squared distance with this
                         * @return NREfloat, the computed squared distance
                         */
                        NREfloat distanceSquared(Point2D<T> const& p = {DEFAULT_X, DEFAULT_Y}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the translation of this with a translation 2D generic-type vector
                         * @param u : Vector2D<K>, the translation vector to applied to this
                         * @return Point2D<T>, this with the translation applied
                         */
                        template <class K>
                        Point2D<T>& operator+=(Vector2D<K> const& u);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the inverse translation of this with a translation 2D generic-type vector
                         * @param u : Vector2D<K>, the translation vector to applied to this
                         * @return Point2D<T>, this with the inverse translation applied
                         */
                        template <class K>
                        Point2D<T>& operator-=(Vector2D<K> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the translation of this with a translation 2D generic-type vector
                         * @param u : Vector2D<K>, the translation vector to applied to this
                         * @return Point2D<T>, a new point with the translation applied
                         */
                        template <class K>
                        Point2D<T> operator+(Vector2D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the inverse translation of this with a translation 2D generic-type vector
                         * @param u : Vector2D<K>, the translation vector to applied to this
                         * @return Point2D<T>, a new point with the inverse translation applied
                         */
                        template <class K>
                        Point2D<T> operator-(Vector2D<K> const& u) const;
                        template <class K>
                        Vector2D<T> operator-(Point2D<K> const& p) const;
                        /**
                         * @brief Negate Operator -
                         * Compute the negate of this
                         * @return Point2D<T>, a new point, the negate point of this
                         */
                        Point2D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 2D generic-type point are equal, based on built-in == comparison for T-type
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Point2D<K> const& p) const;
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 2D generic-type point aren't equal, based on the negation of the == test
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Point2D<K> const& p) const;
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 2D generic-type point , based on squared distance comparison
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Point2D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 2D generic-type point , based on squared distance comparison
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Point2D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is inferior or equal than a 2D generic-type point , based on squared distance comparison
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Point2D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior or equal than a 2D generic-type point , based on squared distance comparison
                         * @param p : Point2D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Point2D<K> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//;

                private:
                    static NREfloat DEFAULT_X;  /**< The default abscissa */
                    static NREfloat DEFAULT_Y;  /**< The default ordinate */
            };

            template <class T>
            NREfloat Point2D<T>::DEFAULT_X = 0.;
            template <class T>
            NREfloat Point2D<T>::DEFAULT_Y = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point2D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
            template <class T>
            std::ostream& operator<<(std::ostream &stream, Point2D<T> const& p);

        };
    };

    #include "NRE_Point2D.tpp"
