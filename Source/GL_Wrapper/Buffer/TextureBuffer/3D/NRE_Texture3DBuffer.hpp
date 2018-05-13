
    /**
     * @file NRE_Texture3DBuffer.hpp
     * @brief Declaration of Engine's GL's Object : Texture3DBuffer
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
         * @brief <Module_Desc>
         */
        namespace GL {

            /**
             * @class Texture3DBuffer
             * @brief GL's Object : Manage 3D texture
             */
            class Texture3DBuffer : public TextureBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Texture3DBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        Texture3DBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the 3D texture buffer to copy the content
                         */
                        Texture3DBuffer(Texture3DBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the 3D texture buffer to move
                         */
                        Texture3DBuffer(Texture3DBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Texture3DBuffer Deconstructor
                         */
                        ~Texture3DBuffer();

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
                         * Allocate the texture buffer with given parameters
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param z              the texture's level
                         * @param format         the texture's pixels' format
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, bool const& callFilter) const;
                        /**
                         * Update the texture buffer with given parameters
                         * @param level   the level of the texture used in mipmap
                         * @param xOffset the buffers xOffset for particular region update
                         * @param yOffset the buffers yOffset for particular region update
                         * @param zOffset the buffers zOffset for particular region update
                         * @param w       the updated region width
                         * @param h       the updated region height
                         * @param z       the updated region level
                         * @param format  the texture's pixels' format
                         * @param data    the texture's data
                         */
                        void update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLint const& zOffset, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, GLvoid* const& data) const;
                        /**
                         * Allocate the texture buffer with given parameters and fill it with given data
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param z              the texture's level
                         * @param format         the texture's pixels' format
                         * @param data           the texture's data
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, GLvoid* const& data, bool const& callFilter) const;
                        /**
                         * Texture specific filter
                         */
                        virtual void applyFilter() const = 0;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param buf the 3D texture buffer to copy into this
                         * @return the reference of himself
                         */
                        Texture3DBuffer& operator=(Texture3DBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the 3D texture buffer to move into this
                         * @return the reference of himself
                         */
                        Texture3DBuffer& operator=(Texture3DBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
