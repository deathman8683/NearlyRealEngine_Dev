
    /**
     * @file NRE_Window.hpp
     * @brief Declaration of Engine's SDL's Object : Window
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <string>
    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../../Exception/SDLException/NRE_SDLException.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace SDL
         * @brief Engine's SDL's Wrapper's Module
         */
        namespace SDL {

            /**
             * @class Window
             * @brief SDL's Object : Wrapper of SDL_Window*
             */
            class Window {
                private:
                    SDL_Window* item;   /**< SDL wrapped item */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Window() = delete;
                        /**
                         * Construct a window with her attributes
                         * @param title the window title
                         * @param coord the window position on screen
                         * @param size  the window size
                         * @param flags the window flag in initialisation
                         */
                        Window(std::string const& title, Maths::Point2D<int> const& coord, Maths::Vector2D<int> const& size, Uint32 const& flags);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param w the window to copy the content
                         */
                        Window(Window const& w) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move w into this, leaving w empty
                         * @param w the window to move
                         */
                        Window(Window && w);

                    //## Convertor ##//
                        /**
                         * Convert a C-style SDL_Window into his wrapped version
                         * @param w the C-style SDL_Window
                         */
                        Window(SDL_Window* const& w);

                    //## Deconstructor ##//
                        /**
                         * Window Deconstructor
                         */
                        virtual ~Window();

                    //## Getter ##//
                        /**
                         * Wrapped Item getter
                         * @return the wrapped item
                         */
                        SDL_Window* const& getItem() const;
                        /**
                         * Brightness getter
                         * @return the window's brightness
                         */
                        NREfloat const getBrightness() const;
                        /**
                         * Title getter
                         * @return the window's title
                         */
                        std::string const getTitle() const;
                        /**
                         * Size getter
                         * @return the window's size
                         */
                        Maths::Vector2D<int> const getSize() const;
                        /**
                         * Position getter
                         * @return the window's position
                         */
                        Maths::Point2D<int> const getCoord() const;
                        /**
                         * Minimum size getter
                         * @return the window's minimum size
                         */
                        Maths::Vector2D<int> const getMinSize() const;
                        /**
                         * Maximum size getter
                         * @return the window's maximum size
                         */
                        Maths::Vector2D<int> const getMaxSize() const;

                    //## Setter ##//
                        /**
                         * Brightness setter
                         * @param brightness the new brightness value
                         */
                        void setBrightness(NREfloat const& brightness);
                        /**
                         * Title setter
                         * @param title the new title value
                         */
                        void setTitle(std::string const& title);
                        /**
                         * Size setter
                         * @param size the new size value
                         */
                        void setSize(Maths::Vector2D<int> const& size);
                        /**
                         * Position setter
                         * @param coord the new position value
                         */
                        void setCoord(Maths::Point2D<int> const& coord);
                        /**
                         * Minimum size setter
                         * @param minSize the new minimum size value
                         */
                        void setMinSize(Maths::Vector2D<int> const& minSize);
                        /**
                         * Maximum size setter
                         * @param maxSize the new maximum size value
                         */
                        void setMaxSize(Maths::Vector2D<int> const& maxSize);

                    //## Methods ##//
                        /**
                         * Call the SDL command to create a window with different attributes
                         * @param title the window title
                         * @param coord the window position on screen
                         * @param size  the window size
                         * @param flags the window flag in initialisation
                         */
                        void createWindow(std::string const& title, Maths::Point2D<int> const& coord, Maths::Vector2D<int> const& size, Uint32 const& flags);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param w the window to copy into this
                         * @return the reference of himself
                         */
                        Window& operator=(Window const& w) = delete;
                        /**
                         * Move assigment of w into this, leaving w empty
                         * @param w the window to move into this
                         * @return the reference of himself
                         */
                        Window& operator=(Window && w);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
