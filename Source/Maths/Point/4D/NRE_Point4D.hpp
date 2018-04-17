
    /**
     * @file NRE_Point4D.hpp
     * @brief Declaration of Engine's Maths's Object : Point4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../3D/NRE_Point3D.hpp"

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
            class Point4D : public Point3D<T> {
                private:
                    T w;    /**< w coordinates */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Point4D();
                        /**
                         * Construct a point with passed values
                         * @param x new x value
                         * @param y new y value
                         * @param z new z value
                         * @param w new w value
                         */
                        Point4D(T const& x, T const& y, T const& z, T const& w);
                        /**
                         * Construct a point with an unique value for all coordinates
                         * @param value new x, y, z and w values
                         */
                        Point4D(T const& value);
                        /**
                         * Construct a point with the translation on another one
                         * @param p the base point
                         * @param u the translation vector applied to p
                         */
                        Point4D(Point4D<T> const& p, Vector4D<T> const& u);

                    //## Copy-Constructor ##//
                        /**
                         * Copy p into this
                         * @param p p the point to copy the content
                         */
                        Point4D(Point4D const& p);

                    //## Move-Constructor ##//
                        /**
                         * Move p into this, leaving p empty
                         * @param p the point to move
                         */
                        Point4D(Point4D && p);

                    //## Convertor ##//
                        /**
                         * Convert a K-type point into a T-type point
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Point4D(Point4D<K> const& p);
                        /**
                         * Convert a K-type vector into a T-type point
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Point4D(Vector4D<K> const& u);
                        /**
                         * Convert a base 3D point into a 4D point with a default z value
                         * @param p the 3D point to convert
                         */
                        Point4D(Point3D<T> const& p);
                        /**
                         * Convert a base 3D point into a 4D point with a passed z value
                         * @param p the 3D point to convert
                         * @param w the new w value
                         */
                        Point4D(Point3D<T> const& p, T const& w);

                    //## Deconstructor ##//
                        /**
                         * Point4D Deconstructor
                         */
                        ~Point4D();

                    //## Getter ##//
                        /**
                         * W getter
                         * @return the w value
                         */
                        T const& getW() const;

                    //## Setter ##//
                        /**
                         * W setter
                         * @param w the new value for w
                         */
                        template <class K>
                        void setW(K const& w);
                        /**
                         * Set the values for x, y, z and w
                         * @param x the new value for x
                         * @param y the new value for y
                         * @param z the new value for z
                         * @param w the new value for w
                         */
                        template <class K, class L, class M, class N>
                        void setCoord(K const& x, L const& y, M const& z, N const& w);
                        /**
                         * Set the values for x, y, z and w with a base 3D point
                         * @param p the base 3D point for x, y and z values
                         * @param w the new value for w
                         */
                        template <class K, class L>
                        void setCoord(Point3D<K> const& p, L const& w);

                    //## Methods ##//
                        /**
                         * Compute the distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the distance with this
                         * @return the computed distance
                         */
                        NREfloat const distance(Point4D<T> const& p = Point4D()) const;
                        /**
                         * Compute the squared distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the square distance with this
                         * @return the computed squared distance
                         */
                        NREfloat const distanceSquared(Point4D<T> const& p = Point4D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of base into this
                         * @param base the point to copy into this
                         * @return the reference of himself
                         */
                        Point4D<T>& operator=(Point4D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the point to move into this
                         * @return the reference of himself
                         */
                        Point4D<T>& operator=(Point4D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Perform a translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point4D<T>& operator+=(Vector4D<T> const& u);
                        /**
                         * Perform an opposite translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point4D<T>& operator-=(Vector4D<T> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point4D<T> operator+(Vector4D<T> const& u) const;
                        /**
                         * Compute the opposite translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point4D<T> operator-(Vector4D<T> const& u) const;
                        /**
                         * Compute the vector measure the translation needed to go from this to p
                         * @param p the second point to compute the vector
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator-(Point4D<T> const& p) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite point
                         */
                        Point4D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator==(Point4D<K> const& p) const;
                        /**
                         * Difference test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator!=(Point4D<K> const& p) const;
                        /**
                         * Inferior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<(Point4D<T> const& p) const;
                        /**
                         * Superior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>(Point4D<T> const& p) const;
                        /**
                         * Inferior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<=(Point4D<T> const& p) const;
                        /**
                         * Superior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>=(Point4D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static int DEFAULT_W;   /**< default z value */
            };

            template <class T>
            int Point4D<T>::DEFAULT_W = 0;

            /**
             * Outstream operation for 4D point
             * @param stream the out stream to add the point p
             * @param p the point to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point4D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << "," << p.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Point4D.tpp"
