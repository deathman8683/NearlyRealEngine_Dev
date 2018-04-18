
    /**
     * @file NRE_FrameBuffer.hpp
     * @brief Declaration of Engine's GL's Object : FrameBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../BufferObject/Texture2D/NRE_Texture2D.hpp"

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
             * @class FrameBuffer
             * @brief GL's Object : A specialized buffer for frame managing
             */
            class FrameBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FrameBuffer();
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        FrameBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        FrameBuffer(FrameBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        FrameBuffer(FrameBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FrameBuffer Deconstructor
                         */
                        virtual ~FrameBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        void generateID() override;
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        void deleteID() override;
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        void bind() const override;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        void unbind() const override;
                        /**
                         * Attach a buffer to specific attachment point with given parameters
                         * @param attachment the specific attachment point
                         * @param target     the buffer target
                         * @param id         the buffer id
                         * @param level      the buffer level, for texture only
                         */
                        void attachBuffer(GLenum const& attachment, GLenum const& target, GLuint const& id, GLint const& level = 0) const;
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
                        FrameBuffer& operator=(FrameBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        FrameBuffer& operator=(FrameBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
