
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
                    Maths::Vector2D<GLushort> wSize;
                    Maths::Vector2D<GLushort> glSize;

                public:
                    //## Constructor ##//
                    Viewport(bool const& createCurrentViewport = false);
                    Viewport(Maths::Vector2D<GLushort> const& wSize, Maths::Vector2D<GLushort> const& glSize);

                    //## Copy-Constructor ##//
                    Viewport(Viewport const& v);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Viewport();

                    //## Getter ##//
                    Maths::Vector2D<GLushort> const& getWSize() const;
                    Maths::Vector2D<GLushort> const& getGLSize() const;

                    //## Setter ##//
                    void setWSize(Maths::Vector2D<GLushort> const& size);
                    void setGLSize(Maths::Vector2D<GLushort> const& size);

                    //## Methods ##//

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
