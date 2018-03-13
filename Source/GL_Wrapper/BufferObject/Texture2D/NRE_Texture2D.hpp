
    /**
     * @file NRE_Texture.hpp
     * @brief Declaration of Engine's GL's Object : Texture2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/TextureBuffer/NRE_TextureBuffer.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace GL {

            /**
             * @class Texture2D
             * @brief GL's Object : A simple 2D Texture
             */
            class Texture2D : public TextureBuffer, public BufferObject, public SDL::Surface {
                private:

                public:
                    //## Constructor ##//
                    Texture2D();
                    Texture2D(std::string const& path);

                    //## Copy-Constructor ##//
                    Texture2D(Texture2D const& tex);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Texture2D();

                    //## Getter ##//
                    GLenum const getType() const;

                    //## Setter ##//

                    //## Methods ##//
                    void bind() const;
                    void unbind() const;
                    void allocate(bool const& callFilter);
                    void update(GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const;
                    void allocateAndFill(bool const& callFilter);
                    void applyFilter() const;
                    void access() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE;
            };

        };
    };
