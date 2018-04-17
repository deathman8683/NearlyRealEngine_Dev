
    /**
     * @file NRE_Point3D.hpp
     * @brief Declaration of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../2D/NRE_Point2D.hpp"

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
                protected:
                    T z;    /**< z coordinates */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Point3D();
                        /**
                         * Construct a point with passed values
                         * @param x new x value
                         * @param y new y value
                         * @param z new z value
                         */
                        Point3D(T const& x, T const& y, T const& z);
                        /**
                         * Construct a point with an unique value for all coordinates
                         * @param value new x, y and z values
                         */
                        Point3D(T const& value);
                        /**
                         * Construct a point with the translation on another one
                         * @param p the base point
                         * @param u the translation vector applied to p
                         */
                        Point3D(Point3D<T> const& p, Vector3D<T> const& u);

                    //## Copy-Constructor ##//
                        /**
                         * Copy p into this
                         * @param p p the point to copy the content
                         */
                        Point3D(Point3D const& p);

                    //## Move-Constructor ##//
                        /**
                         * Move p into this, leaving p empty
                         * @param p the point to move
                         */
                        Point3D(Point3D && p);

                    //## Convertor ##//
                        /**
                         * Convert a K-type point into a T-type point
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Point3D(Point3D<K> const& p);
                        /**
                         * Convert a K-type vector into a T-type point
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Point3D(Vector3D<K> const& u);
                        /**
                         * Convert a base 2D point into a 3D point with a default z value
                         * @param p the 2D point to convert
                         */
                        Point3D(Point2D<T> const& p);
                        /**
                         * Convert a base 2D point into a 3D point with a passed z value
                         * @param p the 2D point to convert
                         * @param z the new z value
                         */
                        Point3D(Point2D<T> const& p, T const& z);

                    //## Deconstructor ##//
                        /**
                         * Point3D Deconstructor
                         */
                        ~Point3D();

                    //## Getter ##//
                        /**
                         * Z getter
                         * @return the z value
                         */
                        T const& getZ() const;

                    //## Setter ##//
                        /**
                         * Z setter
                         * @param z the new value for z
                         */
                        template <class K>
                        void setZ(K const& z);
                        /**
                         * Set the values for x, y and z
                         * @param x the new value for x
                         * @param y the new value for y
                         * @param z the new value for z
                         */
                        template <class K, class L, class M>
                        void setCoord(K const& x, L const& y, M const& z);
                        /**
                         * Set the values for x, y and z with a base 2D point
                         * @param p the base 2D point for x and y values
                         * @param z the new value for z
                         */
                        template <class K, class L>
                        void setCoord(Point2D<K> const& p, L const& z);

                    //## Methods ##//
                        /**
                         * Compute the distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the distance with this
                         * @return the computed distance
                         */
                        NREfloat const distance(Point3D<T> const& p = Point3D()) const
                        /**
                         * Compute the squared distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the square distance with this
                         * @return the computed squared distance
                         */
                        NREfloat const distanceSquared(Point3D<T> const& p = Point3D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of base into this
                         * @param base the point to copy into this
                         * @return the reference of himself
                         */
                        Point3D<T>& operator=(Point3D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the point to move into this
                         * @return the reference of himself
                         */
                        Point3D<T>& operator=(Point3D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Perform a translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point3D<T>& operator+=(Vector3D<T> const& u);
                        /**
                         * Perform an opposite translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point3D<T>& operator-=(Vector3D<T> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point3D<T> operator+(Vector3D<T> const& u) const;
                        /**
                         * Compute the opposite translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point3D<T> operator-(Vector3D<T> const& u) const;
                        /**
                         * Compute the vector measure the translation needed to go from this to p
                         * @param p the second point to compute the vector
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator-(Point3D<T> const& p) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite point
                         */
                        Point3D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator==(Point3D<K> const& p) const;
                        /**
                         * Difference test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator!=(Point3D<K> const& p) const;
                        /**
                         * Inferior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<(Point3D<T> const& p) const;
                        /**
                         * Superior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>(Point3D<T> const& p) const;
                        /**
                         * Inferior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<=(Point3D<T> const& p) const;
                        /**
                         * Superior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>=(Point3D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_Z;  /**< default z value */
            };

            template <class T>
            int Point3D<T>::DEFAULT_Z = 0.;

            /**
             * Outstream operation for 3D point
             * @param stream the out stream to add the point p
             * @param p the point to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point3D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Point3D.tpp"
