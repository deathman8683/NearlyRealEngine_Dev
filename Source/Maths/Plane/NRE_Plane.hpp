
    /**
     * @file NRE_Plane.hpp
     * @brief Declaration of Engine's Maths's Object : Plane
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../Vector/3D/NRE_Vector3D.hpp"
    #include "../Point/3D/NRE_Point3D.hpp"

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

            /**
             * @class Plane
             * @brief Maths's Object : A simple 3D plane with a point and a vector
             */
            template <class T>
            class Plane {
                private:
                    Vector3D<T> n;  /**< the plane's normal */
                    Point3D<T> p;   /**< a plane's point */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Plane();
                        /**
                         * Construct a plane with a particular point and a normals
                         * @param n the new plane's normal
                         * @param p the new plane's point
                         */
                        Plane(Vector3D<T> const& n, Point3D<T> const& p);
                        /**
                         * Construct a plane with 3 points
                         * @param p1 the first point
                         * @param p2 the second point
                         * @param p3 the third point
                         */
                        Plane(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3);

                    //## Copy-Constructor ##//
                        /**
                         * Copy p into this
                         * @param p the plane to copy the content
                         */
                        Plane(Plane const& p);

                    //## Move-Constructor ##//
                        /**
                         * Move p into this, leaving p empty
                         * @param p the plane to move
                         */
                        Plane(Plane && p);

                    //## Convertor ##//
                        /**
                         * Convert a K-Type plane into a T-type plane
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Plane(Plane<K> const& p);

                    //## Deconstructor ##//
                        /**
                         * Plane Deconstructor
                         */
                        ~Plane();

                    //## Getter ##//
                        /**
                         * N getter
                         * @return the plane's normal
                         */
                        Vector3D<T> const& getNormal() const;
                        /**
                         * P getter
                         * @return the plane's point
                         */
                        Point3D<T> const& getPoint() const;

                    //## Setter ##//
                        /**
                         * N setter
                         * @param u the new value for n
                         */
                        void setNormal(Vector3D<T> const& u);
                        /**
                         * P setter
                         * @param p the new value for p
                         */
                        void setPoint(Point3D<T> const& p);
                        /**
                         * Set the values for both n and p
                         * @param u the new value for n
                         * @param p the new value for p
                         */
                        void setNormalAndPoint(Vector3D<T> const& u, Point3D<T> const& p);

                    //## Methods ##//
                        /**
                         * Compute the plane's normal and point from 3 points in the plane
                         * @param p1 the first point
                         * @param p2 the second point
                         * @param p3 the third point
                         */
                        void computeNormalFrom3Point(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3);
                        /**
                         * Compute the distance between a point and a plane
                         * @param  p the point to compute the distance with this
                         * @return the computed distance
                         */
                        NREfloat const distance(Point3D<T> const& p) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of p into this
                         * @param p the plane to copy into this
                         * @return the reference of himself
                         */
                        Plane<T>& operator=(Plane<T> const& p);
                        /**
                         * Move assigment of p into this, leaving p empty
                         * @param p the plane to move into this
                         * @return the reference of himself
                         */
                        Plane<T>& operator=(Plane<T> && p);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for plane
             * @param stream the out stream to add the plane p
             * @param p the plane to add in the stream
             * @return the modified outstream
             */
            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Plane<T> const& p) {
                stream << "(" << p.getPoint() << "," << p.getNormal() << ")";
                return stream;
            }

        };
    };

    #include "NRE_Plane.tpp"
