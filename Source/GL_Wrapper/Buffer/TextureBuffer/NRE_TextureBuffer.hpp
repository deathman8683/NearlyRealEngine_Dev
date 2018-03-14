
    /**
     * @file NRE_TextureBuffer.hpp
     * @brief Declaration of Engine's GL's Object : TextureBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../../SDL_Wrapper/Surface/NRE_Surface.hpp"

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
             * @class TextureBuffer
             * @brief GL's Object : A specialized buffer for texture managing
             */
            class TextureBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                    TextureBuffer();
                    TextureBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    TextureBuffer(TextureBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~TextureBuffer();

                    //## Getter ##//
                    virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void bind(GLenum const& target) const;
                    void unbind(GLenum const& target) const;
                    void allocate(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const;
                    void update(GLenum const& target, GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const;
                    void allocateAndFill(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data, bool const& callFilter) const;
                    virtual void applyFilter() const = 0;
                    void access(GLenum const& target) const;

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
