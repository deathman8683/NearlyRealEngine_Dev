
    /**
     * @file NRE_Window.hpp
     * @brief Declaration of Engine's SDL's Object : Window
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <string>
    #include <SDL2/SDL.h>
    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

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
                    SDL_Window* item;

                public:
                    //## Constructor ##//
                    Window();
                    Window(std::string const& title, int const& x, int const& y, int const& w, int const& h, Uint32 const& flags);

                    //## Copy-Constructor ##//
                    Window(Window const& w);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Window();

                    //## Getter ##//
                    SDL_Window* const& getItem() const;
                    NREfloat const getBrightness() const;
                    std::string const getTitle() const;
                    Maths::Vector2D<int> const getSize() const;
                    Maths::Point2D<int> const getCoord() const;
                    Maths::Vector2D<int> const getMinSize() const;
                    Maths::Vector2D<int> const getMaxSize() const;

                    //## Setter ##//
                    void setItem(SDL_Window* const& w);
                    void setBrightness(NREfloat const& brightness);
                    void setTitle(std::string const& title);
                    void setSize(Maths::Vector2D<int> const& size);
                    void setCoord(Maths::Point2D<int> const& coord);
                    void setMinSize(Maths::Vector2D<int> const& minSize);
                    void setMaxSize(Maths::Vector2D<int> const& maxSize);

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
