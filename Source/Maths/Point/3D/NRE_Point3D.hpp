
    /**
     * @file NRE_Point3D.hpp
     * @brief Declaration of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Base/3D/NRE_Base3D.hpp"

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
             * @class Point3D
             * @brief Maths's Object : Cartesian 3D Generic Point
             */
            template <class T>
            class Point3D : public Base3D<T> {
                private:

                public:
                    //## Constructor ##//
                    Point3D();
                    Point3D(T const& x, T const& y, T const& z);
                    Point3D(T const& value);

                    //## Copy-Constructor ##//
                    Point3D(Base3D<T> const& p);

                    //## Move-Constructor ##//
                    Point3D(Base3D<T> && p);

                    //## Convertor ##//
                    Point3D(Base2D<T> const& p);
                    Point3D(Base2D<T> const& p, T const& z);

                    //## Deconstructor ##//
                    ~Point3D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    NREfloat const distance(Point3D<T> const& p = Point3D()) const;
                    NREfloat const distanceSquared(Point3D<T> const& p = Point3D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                    bool const operator<(Point3D<T> const& p) const;
                    bool const operator>(Point3D<T> const& p) const;
                    bool const operator<=(Point3D<T> const& p) const;
                    bool const operator>=(Point3D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    #include "NRE_Point3D.tpp"
