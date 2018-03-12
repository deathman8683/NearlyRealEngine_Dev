
    /**
     * @file NRE_Surface.hpp
     * @brief Declaration of Engine's SDL's Object : Surface
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../PixelFormat/NRE_PixelFormat.hpp"

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
             * @brief SDL's Object : Wrapper of SDL_Surface*
             */
            class Surface {
                private:
                    SDL_Surface* item;
                    GLenum glFormat;
                    GLenum glInternalFormat;

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
                    GLenum const& getGLFormat() const;
                    GLenum const& getGLInternalFormat() const;
                    SDL_Rect const& getClipRect() const;
                    Uint32 const& getFlags() const;
                    PixelFormat const getFormat() const;
                    int const& getW() const;
                    int const& getH() const;
                    Maths::Vector2D<int> const getSize() const;
                    int const& getPitch() const;
                    void* const& getPixels() const;

                    //## Setter ##//
                    void setItem(SDL_Surface* const& s);
                    void setGLFormat(GLenum const& f);
                    void setGLInternalFormat(GLenum const& f);

                    //## Methods ##//
                    void free();
                    void lock();
                    void unlock();
                    void loadByIMG(std::string const& path);
                    void flip();
                    void loadFormat();

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
