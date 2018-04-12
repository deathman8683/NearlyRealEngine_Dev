
    /**
     * @file NRE_Point2D.hpp
     * @brief Declaration of Engine's Maths's Object : Point2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Base/2D/NRE_Base2D.hpp"

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
             * @class Point2D
             * @brief Maths's Object : Cartesian 2D Generic Point
             */
            template <class T>
            class Point2D : public Base2D<T> {
                private:

                public:
                    //## Constructor ##//
                    Point2D();
                    Point2D(T const& x, T const& y);
                    Point2D(T const& value);

                    //## Copy-Constructor ##//
                    Point2D(Base2D<T> const& p);

                    //## Move-Constructor ##//
                    Point2D(Base2D<T> && p);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Point2D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    NREfloat const distance(Point2D<T> const& p = Point2D()) const;
                    NREfloat const distanceSquared(Point2D<T> const& p = Point2D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                    bool const operator<(Point2D<T> const& p) const;
                    bool const operator>(Point2D<T> const& p) const;
                    bool const operator<=(Point2D<T> const& p) const;
                    bool const operator>=(Point2D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    namespace std {
        template <>
        class hash<NRE::Maths::Point2D<GLint>> {
            public:
                size_t operator()(NRE::Maths::Point2D<GLint> const& p) const
                {
                    size_t h1 = p.getX();
                    size_t h2 = p.getY();

                    size_t hV = h2 * 100'000'000 + h1;
                    return hV;
                }
        };
    };

    #include "NRE_Point2D.tpp"
