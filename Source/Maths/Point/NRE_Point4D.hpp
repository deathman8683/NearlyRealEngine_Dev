
    /**
     * @file NRE_Point4D.hpp
     * @brief Declaration of Engine's Maths's Object : Point4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Base/4D/NRE_Base4D.hpp"

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
             * @class Point4D
             * @brief Maths's Object : Homogeneous 3D Generic Point
             */
            template <class T>
            class Point4D : public Base4D<T> {
                private:

                public:
                    //## Constructor ##//
                        Point4D();
                        Point4D(T const& x, T const& y, T const& z, T const& w);
                        Point4D(T const& value);

                    //## Copy-Constructor ##//
                        Point4D(Point4D const& p);

                    //## Move-Constructor ##//
                        Point4D(Point4D && p);

                    //## Convertor ##//
                        template <class K>
                        Point4D(Base4D<K> const& p);
                        Point4D(Point3D<T> const& p);
                        Point4D(Point3D<T> const& p, T const& w);

                    //## Deconstructor ##//
                        ~Point4D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        NREfloat const distance(Point4D<T> const& p = Point4D()) const;
                        NREfloat const distanceSquared(Point4D<T> const& p = Point4D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Point4D<T>& operator=(Point4D<T> const& p);
                        Point4D<T>& operator=(Point4D<T> && p);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                        bool const operator<(Point4D<T> const& p) const;
                        bool const operator>(Point4D<T> const& p) const;
                        bool const operator<=(Point4D<T> const& p) const;
                        bool const operator>=(Point4D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
            };

        };
    };

    #include "NRE_Point4D.tpp"
