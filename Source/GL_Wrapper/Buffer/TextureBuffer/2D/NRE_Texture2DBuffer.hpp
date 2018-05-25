
    /**
     * @file NRE_Texture2DBuffer.hpp
     * @brief Declaration of Engine's GL's Object : Texture2DBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_TextureBuffer.hpp"

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
             * @class Texture2DBuffer
             * @brief GL's Object : Manage 2D texture
             */
            class Texture2DBuffer : public TextureBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Texture2DBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        Texture2DBuffer(bool const& generate);
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate  tell if the base class has to generate an id or not
                         * @param type      the texture's type enum
                         */
                        Texture2DBuffer(bool const& generate, GLenum const& type);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the 2D texture buffer to copy the content
                         */
                        Texture2DBuffer(Texture2DBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the 2D texture buffer to move
                         */
                        Texture2DBuffer(Texture2DBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Texture2DBuffer Deconstructor
                         */
                        ~Texture2DBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        GLenum const getTarget() const override;

                    //## Setter ##//

                    //## Methods ##//
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

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param buf the 2D texture buffer to copy into this
                         * @return the reference of himself
                         */
                        Texture2DBuffer& operator=(Texture2DBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the 2D texture buffer to move into this
                         * @return the reference of himself
                         */
                        Texture2DBuffer& operator=(Texture2DBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
