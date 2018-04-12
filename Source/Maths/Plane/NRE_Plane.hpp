
    /**
     * @file NRE_Plane.hpp
     * @brief Declaration of Engine's Maths's Object : Plane
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../Vector/NRE_Vector3D.hpp"
    #include "../Point/NRE_Point3D.hpp"

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
                    Plane(Vector3D<T> const& n, Point3D<T> const& p);
                    Plane(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3);

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
                    void setNormal(Vector3D<T> const& u);
                    void setPoint(Point3D<T> const& p);
                    void setNormalAndPoint(Vector3D<T> const& u, Point3D<T> const& p);

                    //## Methods ##//
                    void computeNormalFrom3Point(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3);
                    NREfloat const distance(Point3D<T> const& p) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Plane<T> const& p) {
                stream << "(" << p.getPoint() << "," << p.getNormal() << ")";
                return stream;
            }

        };
    };

    #include "NRE_Plane.tpp"
