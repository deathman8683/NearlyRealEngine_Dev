
    /**
     * @file NRE_Plane.hpp
     * @brief Declaration of Engine's Maths's Object : Plane
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Vector/NRE_Vector3D.hpp"
    #include "../../Point/NRE_Point3D.hpp"

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
                    Vector3D<T> n;
                    Point3D<T> p;

                public:
                    //## Constructor ##//
                    Plane();
                    template <class K, class L>
                    Plane(Vector3D<K> const& n, Point3D<L> const& p);
                    template <class K, class L, class M>
                    Plane(Point3D<K> const& p1, Point3D<L> const& p2, Point3D<M> const& p3);

                    //## Copy-Constructor ##//
                    Plane(Plane const& p);

                    //## Convertor ##//
                    template <class K>
                    Plane(Plane<K> const& p);

                    //## Deconstructor ##//
                    ~Plane();

                    //## Getter ##//
                    Vector3D<T> const& getNormal() const;
                    Point3D<T> const& getPoint() const;

                    //## Setter ##//
                    template <class K>
                    void setNormal(Vector3D<K> const& u);
                    template <class K>
                    void setPoint(Point3D<K> const& p);

                    //## Methods ##//
                    template <class K, class L, class M>
                    void computeNormalFrom3Point(Point3D<K> const& p1, Point3D<L> const& p2, Point3D<M> const& p3);
                    template <class K>
                    void distance(Point3D<K> const& p);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    #include "NRE_Plane.tpp"
