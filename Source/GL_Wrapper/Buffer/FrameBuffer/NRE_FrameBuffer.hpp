
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
                    FrameBuffer();
                    FrameBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    FrameBuffer(FrameBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~FrameBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void bind() const;
                    void unbind() const;
                    void attachColorBuffer(GLenum const& attachment, Texture2D const& texture) const;
                    void attachRenderBuffer(GLenum const& attachment, GLenum const& renderBufferTarget, GLuint const& renderBuffer) const;
                    void access() const;

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
