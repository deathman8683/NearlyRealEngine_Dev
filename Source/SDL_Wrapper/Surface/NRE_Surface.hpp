
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
    #include "../../IO/File/NRE_File.hpp"
    #include "../../Exception/NRE_Exception.hpp"

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
                    SDL_Surface* item;      /**< SDL wrapped item */
                    GLsizei glW;            /**< Surface width, usually the same as item width but can be used for texture not used with SDL*/
                    GLsizei glH;            /**< Surface width, usually the same as item height but can be used for texture not used with SDL */
                    GLenum glFormat;        /**< Surface pixel format */
                    GLint glInternalFormat; /**< Surfacec internal pixel format */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Surface() = delete;
                        /**
                         * Construct a surface with SDL image library with a file path
                         * @param file the file path
                         */
                        Surface(IO::File const& file);
                        /**
                         * Construct an empty surface for OpenGL only purpose
                         * @param w                the surface width
                         * @param h                the surface height
                         * @param glFormat         the pixel format
                         * @param glInternalFormat the internal pixel format
                         */
                        Surface(GLsizei const& w, GLsizei const& h, GLenum const& glFormat, GLint const& glInternalFormat);

                    //## Copy-Constructor ##//
                        /**
                         * Copy s into this
                         * @param s the surface to copy the content
                         */
                        Surface(Surface const& s);

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the surface to move
                         */
                        Surface(Surface && s);

                    //## Convertor ##//
                        /**
                         * Convert a C-style SDL_Surface into his wrapped version
                         * @param s the C-style SDL_Surface
                         */
                        Surface(SDL_Surface* const& s);

                    //## Deconstructor ##//
                        /**
                         * Surface Deconstructor
                         */
                        virtual ~Surface();

                    //## Getter ##//
                        /**
                         * Wrapped Item getter
                         * @return the wrapped item
                         */
                        SDL_Surface* const& getItem() const;
                        /**
                         * GL width getter
                         * @return the object width, not the surface width
                         */
                        GLsizei const& getGLW() const;
                        /**
                         * GL height getter
                         * @return the object height, not the surface height
                         */
                        GLsizei const& getGLH() const;
                        /**
                         * GL pixel format getter
                         * @return the object pixel format, not the surface pixel format
                         */
                        GLenum const& getGLFormat() const;
                        /**
                         * GL internal pixel format getter
                         * @return the object internal pixel format, not the surface internal pixel format
                         */
                        GLint const& getGLInternalFormat() const;
                        /**
                         * Surface flag getter
                         * @return the surface flags
                         */
                        Uint32 const& getFlags() const;
                        /**
                         * Surface pixel format getter
                         * @return the surface pixel format
                         */
                        PixelFormat const getFormat() const;
                        /**
                         * Surface width getter
                         * @return the surface width
                         */
                        int const& getW() const;
                        /**
                         * Surface height getter
                         * @return the surface height
                         */
                        int const& getH() const;
                        /**
                         * Surface size getter
                         * @return the surface size vector
                         */
                        Maths::Vector2D<int> const getSize() const;
                        /**
                         * Surface pitch getter
                         * @return the surface pitch
                         */
                        int const& getPitch() const;
                        /**
                         * Surface Pixels getter
                         * @return the pointer to the array of surface pixels
                         */
                        void* const& getPixels() const;

                    //## Setter ##//
                        /**
                         * GL width setter
                         * @param w the new gl width value
                         */
                        void setGLW(GLsizei const& w);
                        /**
                         * GL height setter
                         * @param h the new gl height value
                         */
                        void setGLH(GLsizei const& h);
                        /**
                         * GL pixel format setter
                         * @param f the new gl pixel format value
                         */
                        void setGLFormat(GLenum const& f);
                        /**
                         * GL internal pixel format setter
                         * @param f the new gl internal pixel format value
                         */
                        void setGLInternalFormat(GLint const& f);

                    //## Methods ##//
                        /**
                         * Desallocate the SDL surface memory
                         */
                        void free();
                        /**
                         * Lock the surface
                         */
                        void lock();
                        /**
                         * Unlock the surface
                         */
                        void unlock();
                        /**
                         * Load a surface with SDL Image library
                         * @param file the file to load
                         */
                        void loadByIMG(IO::File const& file);
                        /**
                         * Flip the surface to get OpenGL order
                         */
                        void flip();
                        /**
                         * Load the glFormat and glInternalFormat from the surface BytesPerPixel
                         */
                        void loadFormat();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of s into this
                         * @param s the surface to copy into this
                         * @return the reference of himself
                         */
                        Surface& operator=(Surface const& s);
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the surface to move into this
                         * @return the reference of himself
                         */
                        Surface& operator=(Surface && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
