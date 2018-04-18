
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
                        /**
                         * Default Constructor
                         */
                        TextureBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        TextureBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        TextureBuffer(TextureBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        TextureBuffer(TextureBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * TextureBuffer Deconstructor
                         */
                        virtual ~TextureBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute type enum, used with derived class
                         * @return the attribute type enum
                         */
                        virtual GLenum const getType() const = 0;
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        virtual GLenum const getTarget() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        void generateID();
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        void deleteID();
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        void bind() const override;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        void unbind() const override;
                        /**
                         * Allocate the texture buffer with given parameters
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param format         the texture's pixels' format
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const;
                        /**
                         * Update the texture buffer with given parameters
                         * @param level   the level of the texture used in mipmap
                         * @param xOffset the buffers xOffset for particular region update
                         * @param yOffset the buffers yOffset for particular region update
                         * @param w       the updated region width
                         * @param h       the updated region height
                         * @param format  the texture's pixels' format
                         * @param data    the texture's data
                         */
                        void update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const;
                        /**
                         * Allocate the texture buffer with given parameters and fill it with given data
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param format         the texture's pixels' format
                         * @param data           the texture's data
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data, bool const& callFilter) const;
                        /**
                         * Texture specific filter
                         */
                        virtual void applyFilter() const = 0;
                        /**
                         * Store calls for VAO managing
                         */
                        void access() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        TextureBuffer& operator=(TextureBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        TextureBuffer& operator=(TextureBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
