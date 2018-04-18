
    /**
     * @file NRE_RenderBuffer.hpp
     * @brief Declaration of Engine's GL's Object : RenderBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../DepthBuffer/NRE_DepthBuffer.hpp"

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
             * @class RenderBuffer
             * @brief GL's Object : A specialized buffer for renderbuffer managing
             */
            class RenderBuffer : public Buffer, public DepthBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        RenderBuffer();
                        /**
                         * Construct the buffer and generate or not his id, need some parameters to configure the render buffer
                         * @param internalFormat the renderbuffer internal format
                         * @param w the renderbuffer width
                         * @param h the renderbuffer height
                         * @param generate tell if the base class has to generate an id or not
                         */
                        RenderBuffer(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h, bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        RenderBuffer(RenderBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        RenderBuffer(RenderBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * RenderBuffer Deconstructor
                         */
                        ~RenderBuffer();

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
                         * Allocate the renderbuffer storage with given parameters
                         * @param internalFormat the buffer internal format
                         * @param w              the buffer width
                         * @param h              the buffer height
                         */
                        void allocate(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h) const;
                        /**
                         * Store calls for VAO managing
                         */
                        void access() const;
                        /**
                         * Attach the buffer to a specific attachment point
                         * @param attachment the specific attachment point
                         */
                        void attach(GLenum const& attachment) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        RenderBuffer& operator=(RenderBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        RenderBuffer& operator=(RenderBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
