
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
                    RenderBuffer();
                    RenderBuffer(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h, bool const& generate);

                    //## Copy-Constructor ##//
                    RenderBuffer(RenderBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~RenderBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void bind() const;
                    void unbind() const;
                    void allocate(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h) const;
                    void access() const;
                    void attach(GLenum const& attachment) const;

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
