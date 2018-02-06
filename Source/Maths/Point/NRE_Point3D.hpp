
    /**
     * @file NRE_Point3D.hpp
     * @brief Declaration of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "NRE_Point2D.hpp"

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

            template<class> class Vector3D;

            /**
             * @class Point3D
             * @brief Maths's Object : Cartesian 3D Generic Point
             */
            template <class T>
            class Point3D : public Point2D<T> {
                private:
                    T z;    /**< The applicate of this */

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 3D point with default coordinates
                         */
                        Point3D();
                        /**
                         * @brief Constructor
                         * Initialize a 3D point with x, y and z
                         * @param x : K, the x coordinate
                         * @param y : L, the y coordinate
                         * @param z : M, the z coordinate
                         */
                        template <class K, class L, class M>
                        Point3D(K const& x, L const& y, M const& z);
                        /**
                         * @brief Constructor
                         * Initialize a 3D point with a base 2D point and z
                         * @param p : Point2D<K>, the base point
                         * @param z : L, the z coordinate
                         */
                        template <class K, class L>
                        Point3D(Point2D<K> const& p, L const& z);
                        /**
                         * @brief Constructor
                         * Convert a 3D generic-type point and a translation 3D generic-type vector into a 3D T point
                         * @param p : Point3D<K>, the point to convert
                         * @param u : Vector3D<L>, the translation vector applied to p
                         */
                        template <class K, class L>
                        Point3D(Point3D<K> const& p, Vector3D<L> const& u);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of p
                         * @param p : Point3D<T>, the point to copy
                         */
                        Point3D(Point3D const& p);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 3D generic-type point into a 3D T point
                         * @param p : Point3D<K>, the point to convert
                         */
                        template <class K>
                        Point3D(Point3D<K> const& p);
                        /**
                         * @brief Convertor
                         * Convert a 3D generic-type vector into a 3D T point
                         * @param u : Vector3D<K>, the vector to convert
                         */
                        template <class K>
                        Point3D(Vector3D<K> const& u);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 3D point
                         */
                        ~Point3D();

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
                         * Change x, y values from a base 2D point and z value
                         * @param p : Point2D<K>, the base vector for x and y values
                         * @param z : L, the new z value
                         */
                        template <class K, class L>
                        void setCoord(Point2D<K> const& p, L const& z);

                    //## Methods ##//
                        /**
                         * @brief Distance getter
                         * Compute the distance between this and p, by default p is the default point
                         * @param p : Point3D<T>, the point to measure the distance with this
                         * @return NREfloat, the computed distance
                         */
                        NREfloat distance(Point3D<T> const& p = {Point2D<T>::DEFAULT_X, Point2D<T>::DEFAULT_Y, DEFAULT_Z}) const;
                        /**
                         * @brief DistanceSquared getter
                         * Compute the squared distance between this and p, by default p is the default point
                         * @param p : Point3D<T>, the point to measure the squared distance with this
                         * @return NREfloat, the computed squared distance
                         */
                        NREfloat distanceSquared(Point3D<T> const& p = {Point2D<T>::DEFAULT_X, Point2D<T>::DEFAULT_Y, DEFAULT_Z}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the translation of this with a translation 3D generic-type vector
                         * @param u : Vector3D<K>, the translation vector to applied to this
                         * @return Point3D<T>, this with the translation applied
                         */
                        template <class K>
                        Point3D<T>& operator+=(Vector3D<K> const& u);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the inverse translation of this with a translation 3D generic-type vector
                         * @param u : Vector3D<K>, the translation vector to applied to this
                         * @return Point3D<T>, this with the inverse translation applied
                         */
                        template <class K>
                        Point3D<T>& operator-=(Vector3D<K> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the translation of this with a translation 3D generic-type vector
                         * @param u : Vector3D<K>, the translation vector to applied to this
                         * @return Point3D<T>, a new point with the translation applied
                         */
                        template <class K>
                        Point3D<T> operator+(Vector3D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the inverse translation of this with a translation 3D generic-type vector
                         * @param u : Vector3D<K>, the translation vector to applied to this
                         * @return Point3D<T>, a new point with the inverse translation applied
                         */
                        template <class K>
                        Point3D<T> operator-(Vector3D<K> const& u) const;
                        template <class K>
                        Vector3D<T> operator-(Point3D<K> const& p) const;
                        /**
                         * @brief Negate Operator -
                         * Compute the negate of this
                         * @return Point3D<T>, a new point, the negate point of this
                         */
                        Point3D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 3D generic-type point are equal, based on built-in == comparison for T-type
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Point3D<K> const& p) const;
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 3D generic-type point aren't equal, based on the negation of the == test
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Point3D<K> const& p) const;
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 3D generic-type point , based on squared distance comparison
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Point3D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 3D generic-type point , based on squared distance comparison
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Point3D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is inferior or equal than a 3D generic-type point , based on squared distance comparison
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Point3D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior or equal than a 3D generic-type point , based on squared distance comparison
                         * @param p : Point3D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Point3D<K> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_Z;  /**< The default applicate */
            };

            template <class T>
            int Point3D<T>::DEFAULT_Z = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y, z)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point3D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
            template <class T>
            std::ostream& operator<<(std::ostream &stream, Point3D<T> const& p);

        };
    };

    #include "NRE_Point3D.tpp"
