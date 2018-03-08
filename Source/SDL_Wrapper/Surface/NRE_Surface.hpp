
    /**
     * @file NRE_Surface.hpp
     * @brief Declaration of Engine's SDL's Object : Surface
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
         * @namespace SDL
         * @brief Engine's SDL's Wrapper's Module
         */
        namespace SDL {

            /**
             * @class Surface
             * @brief SDL's Object : Wrapper of SDL_Surface
             */
            class Surface {
                private:
                    SDL_Surface* item;

                public:
                    //## Constructor ##//
                    Surface();
                    Surface(std::string const& path);

                    //## Copy-Constructor ##//
                    Surface(Surface const& s);

                    //## Convertor ##//
                    Surface(SDL_Surface* const& s);

                    //## Deconstructor ##//
                    virtual ~Surface();

                    //## Getter ##//
                    SDL_Surface* const& getItem() const;
                    SDL_Rect const& getClipRect() const;
                    Uint32 const& getFlags() const;
                    SDL_PixelFormat* const& getFormat() const;
                    int const& getW() const;
                    int const& getH() const;
                    Maths::Vector2D<int> const getSize() const;
                    int const& getPitch() const;
                    void* const& getPixels() const;

                    //## Setter ##//

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
