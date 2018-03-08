
    /**
     * @file NRE_Viewport.hpp
     * @brief Declaration of Engine's Support's Object : Viewport
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Support
         * @brief Engine's Application's Support Module
         */
        namespace Support {

            /**
             * @class Viewport
             * @brief Support's Object : Manage proportion between screen and application
             */
            class Viewport {
                private:
                    Maths::Point2D<GLushort> coord;
                    Maths::Vector2D<GLushort> size;

                public:
                    //## Constructor ##//
                    Viewport();
                    Viewport(bool const& createCurrentViewport);
                    Viewport(Maths::Point2D<GLushort> const& coord, Maths::Vector2D<GLushort> const& size);

                    //## Copy-Constructor ##//
                    Viewport(Viewport const& v);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Viewport();

                    //## Getter ##//
                    Maths::Point2D<GLushort> const& getCoord() const;
                    Maths::Vector2D<GLushort> const& getSize() const;

                    //## Setter ##//
                    void setCoord(Maths::Point2D<GLushort> const& coord);
                    void setSize(Maths::Vector2D<GLushort> const& size);

                    //## Methods ##//
                    void createCurrent();

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
