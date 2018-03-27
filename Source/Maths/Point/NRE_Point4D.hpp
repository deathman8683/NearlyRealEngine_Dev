
    /**
     * @file NRE_Point4D.hpp
     * @brief Declaration of Engine's Maths's Object : Point4D
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

            template<class> class Vector4D;

            /**
             * @class Point4D
             * @brief Maths's Object : Homogeneous 3D Generic Point
             */
            template <class T>
            class Point4D {
                private:
                    T data[4];

                public:
                    //## Constructor ##//
                        /**
                         * @brief Constructor
                         * Default constructor, iniatlize a 4D point with default coordinates
                         */
                        Point4D();
                        /**
                         * @brief Constructor
                         * Initialize a 4D point with x, y, z and w
                         * @param x : K, the x coordinate
                         * @param y : L, the y coordinate
                         * @param z : M, the z coordinate
                         * @param w : N, the w coordinate
                         */
                        template <class K, class L, class M, class N>
                        Point4D(K const& x, L const& y, M const& z, N const& w);
                        /**
                         * @brief Constructor
                         * Initialize a 4D point with a base 3D point and w
                         * @param p : Point3D<K>, the base point
                         * @param w : T, the w coordinate
                         */
                        template <class K>
                        Point4D(Point3D<K> const& p, T const& w);
                        /**
                         * @brief Constructor
                         * Convert a 4D generic-type point and a translation 4D generic-type vector into a 4D T point
                         * @param p : Point4D<K>, the point to convert
                         * @param u : Vector4D<L>, the translation vector applied to p
                         */
                        template <class K, class L>
                        Point4D(Point4D<K> const& p, Vector4D<L> const& u);

                    //## Copy-Constructor ##//
                        /**
                         * @brief Copy-Constructor
                         * Construct a copy of p
                         * @param p : Point4D<T>, the point to copy
                         */
                        Point4D(Point4D const& p);

                    //## Convertor ##//
                        /**
                         * @brief Convertor
                         * Convert a 4D generic-type point into a 4D T point
                         * @param p : Point4D<K>, the point to convert
                         */
                        template <class K>
                        Point4D(Point4D<K> const& p);
                        /**
                         * @brief Convertor
                         * Convert a 4D generic-type vector into a 4D T point
                         * @param u : Vector4D<K>, the vector to convert
                         */
                        template <class K>
                        Point4D(Vector4D<K> const& u);

                    //## Deconstructor ##//
                        /**
                         * @brief Deconstructor
                         * Deconstruct a 4D point
                         */
                        ~Point4D();

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
                         * @brief X, y and z setter
                         * Change x, y, z values from a base 3D point and w value
                         * @param p : Point3D<K>, the base vector for x, y and z values
                         * @param w : L, the new w value
                         */
                        template <class K, class L>
                        void setCoord(Point3D<K> const& p, L const& w);

                    //## Methods ##//
                        /**
                         * @brief Distance getter
                         * Compute the distance between this and p, by default p is the default point
                         * @param p : Point4D<T>, the point to measure the distance with this
                         * @return NREfloat, the computed distance
                         */
                        NREfloat distance(Point4D<T> const& p = {DEFAULT_X, DEFAULT_Y, DEFAULT_Z, DEFAULT_W}) const;
                        /**
                         * @brief DistanceSquared getter
                         * Compute the squared distance between this and p, by default p is the default point
                         * @param p : Point4D<T>, the point to measure the squared distance with this
                         * @return NREfloat, the computed squared distance
                         */
                        NREfloat distanceSquared(Point4D<T> const& p = {DEFAULT_X, DEFAULT_Y, DEFAULT_Z, DEFAULT_W}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                        /**
                         * @brief Shortcut Operator +=
                         * Compute the translation of this with a translation 4D generic-type vector
                         * @param u : Vector4D<K>, the translation vector to applied to this
                         * @return Point4D<T>, this with the translation applied
                         */
                        template <class K>
                        Point4D<T>& operator+=(Vector4D<K> const& u);
                        /**
                         * @brief Shortcut Operator -=
                         * Compute the inverse translation of this with a translation 4D generic-type vector
                         * @param u : Vector4D<K>, the translation vector to applied to this
                         * @return Point4D<T>, this with the inverse translation applied
                         */
                        template <class K>
                        Point4D<T>& operator-=(Vector4D<K> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * @brief Arithmetic Operator +
                         * Compute the translation of this with a translation 4D generic-type vector
                         * @param u : Vector4D<K>, the translation vector to applied to this
                         * @return Point4D<T>, a new point with the translation applied
                         */
                        template <class K>
                        Point4D<T> operator+(Vector4D<K> const& u) const;
                        /**
                         * @brief Arithmetic Operator -
                         * Compute the inverse translation of this with a translation 4D generic-type vector
                         * @param u : Vector4D<K>, the translation vector to applied to this
                         * @return Point4D<T>, a new point with the inverse translation applied
                         */
                        template <class K>
                        Point4D<T> operator-(Vector4D<K> const& u) const;
                        template <class K>
                        Vector4D<T> operator-(Point4D<K> const& p) const;
                        /**
                         * @brief Negate Operator -
                         * Compute the negate of this
                         * @return Point4D<T>, a new point, the negate point of this
                         */
                        Point4D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * @brief Comparison Operator ==
                         * Compare if this and a 4D generic-type point are equal, based on built-in == comparison for T-type
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator==(Point4D<K> const& p) const;
                        /**
                         * @brief Comparison Operator !=
                         * Compare if this and a 4D generic-type point aren't equal, based on the negation of the == test
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator!=(Point4D<K> const& p) const;
                        /**
                         * @brief Comparison Operator <
                         * Compare if this is inferior than a 4D generic-type point , based on squared distance comparison
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<(Point4D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior than a 4D generic-type point , based on squared distance comparison
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>(Point4D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is inferior or equal than a 4D generic-type point , based on squared distance comparison
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator<=(Point4D<K> const& p) const;
                        /**
                         * @brief Comparison Operator >
                         * Compare if this is superior or equal than a 4D generic-type point , based on squared distance comparison
                         * @param p : Point4D<K>, the point to test
                         * @return bool, the test's result
                         */
                        template <class K>
                        bool operator>=(Point4D<K> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_X;  /**< The default abscissa */
                    static int DEFAULT_Y;  /**< The default ordinate */
                    static int DEFAULT_Z;  /**< The default applicate */
                    static int DEFAULT_W;  /**< The default homogeneous coordinate */
            };

            template <class T>
            int Point4D<T>::DEFAULT_X = 0.;
            template <class T>
            int Point4D<T>::DEFAULT_Y = 0.;
            template <class T>
            int Point4D<T>::DEFAULT_Z = 0.;
            template <class T>
            int Point4D<T>::DEFAULT_W = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y, z, w)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point4D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point4D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << "," << p.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Point4D.tpp"
