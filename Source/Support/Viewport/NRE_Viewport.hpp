
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
                    Maths::Point2D<GLushort> coord; /**< The viewport position */
                    Maths::Vector2D<GLushort> size; /**< The viewport size */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Viewport();
                        /**
                         * Construct the viewport with the current screen size
                         * @param createCurrentViewport tell if the viewport is constructed with the current screen size
                         */
                        Viewport(bool const& createCurrentViewport);
                        /**
                         * Construct a viewport with passed attributes
                         * @param coord the viewport posittion
                         * @param size  the viewport size
                         */
                        Viewport(Maths::Point2D<GLushort> const& coord, Maths::Vector2D<GLushort> const& size);

                    //## Copy-Constructor ##//
                        /**
                         * Copy v into this
                         * @param v the viewport to copy the content
                         */
                        Viewport(Viewport const& v);

                    //## Move-Constructor ##//
                        /**
                         * Move v into this, leaving v empty
                         * @param v the viewport to move
                         */
                        Viewport(Viewport && v);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Viewport Deconstructor
                         */
                        ~Viewport();

                    //## Getter ##//
                        /**
                         * Position getter
                         * @return the viewport position
                         */
                        Maths::Point2D<GLushort> const& getCoord() const;
                        /**
                         * Size getter
                         * @return the viewport size
                         */
                        Maths::Vector2D<GLushort> const& getSize() const;

                    //## Setter ##//
                        /**
                         * Position setter
                         * @param coord the new viewport position
                         */
                        void setCoord(Maths::Point2D<GLushort> const& coord);
                        /**
                         * Size setter
                         * @param size the new viewport size
                         */
                        void setSize(Maths::Vector2D<GLushort> const& size);

                    //## Methods ##//
                        /**
                         * Construct the viewport from the current OpenGL screen
                         */
                        void createCurrent();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of v into this
                         * @param v the viewport to copy into this
                         * @return the reference of himself
                         */
                        Viewport& operator=(Viewport const& v);
                        /**
                         * Move assigment of v into this, leaving v empty
                         * @param v the viewport to move into this
                         * @return the reference of himself
                         */
                        Viewport& operator=(Viewport && v);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
