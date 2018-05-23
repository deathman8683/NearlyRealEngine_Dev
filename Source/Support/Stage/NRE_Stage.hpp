
    /**
     * @file NRE_Stage.hpp
     * @brief Declaration of Engine's Support's Object : Stage
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/Init/NRE_Init.hpp"
    #include "../Viewport/NRE_Viewport.hpp"
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
             * @class Stage
             * @brief Support's Object : Manage the application window and viewport
             */
            class Stage : private Init {
                private:
                    SDL::Window window;     /**< The stage window */
                    Viewport viewport;      /**< The stage viewport */
                    SDL_GLContext context;  /**< The stage OpenGL context */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Stage() = delete;
                        /**
                         * Construct a stage with different parameters for the window construction
                         * @param title the window title
                         * @param size  the window size
                         * @param coord the window position
                         */
                        Stage(std::string const& title, Maths::Vector2D<int> size, Maths::Point2D<int> coord = Maths::Point2D<int>(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED));

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the stage to copy the content
                         */
                        Stage(Stage const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * No move allowed
                         * @param s the stage to move
                         */
                        Stage(Stage && s) = delete;

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Stage Deconstructor
                         */
                        ~Stage();

                    //## Getter ##//
                        /**
                         * Viewport getter
                         * @return the stage viewport
                         */
                        Viewport const& getViewport() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Refresh the screen
                         */
                        void updateScreen();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the stage to copy into this
                         * @return the reference of himself
                         */
                        Stage& operator=(Stage const& s) = delete;
                        /**
                         * No move allowed
                         * @param s the stage to move into this
                         * @return the reference of himself
                         */
                        Stage& operator=(Stage && s) = delete;

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    /**
                     * Initialize the SDL Screen
                     */
                    void initScreen();
                    /**
                     * Initialize OpenGL context
                     */
                    void initGL();

                    static Uint32 DEFAULT_FLAGS;    /**< Default flags for the window */
            };

        };
    };
