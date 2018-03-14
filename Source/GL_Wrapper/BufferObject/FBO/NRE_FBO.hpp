
    /**
     * @file NRE_FBO.hpp
     * @brief Declaration of Engine's GL's Object : FBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Texture2D/NRE_Texture2D.hpp"
    #include "../../Buffer/FrameBuffer/NRE_FrameBuffer.hpp"
    #include "../../Buffer/RenderBuffer/NRE_RenderBuffer.hpp"

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
             * @class FBO
             * @brief GL's Object : Specialization of an BufferObject for frame managing
             */
            class FBO : public BufferObject, public FrameBuffer {
                private:
                    std::vector<Texture2D*> colorBuffer;
                    RenderBuffer depthStencilBuffer;

                public:
                    //## Constructor ##//
                    FBO();
                    FBO(GLsizei const& w, GLisizei const& h);
                    FBO(GLsizei const& w, GLisizei const& h, GLint const& nbColorBuffer);

                    //## Copy-Constructor ##//
                    FBO(FBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~FBO();

                    //## Getter ##//
                    std::vector<Texture2D*> const& getColorBuffers() const;
                    Texture2D* const& getColorBuffer(GLuint const& index) const;
                    RenderBuffer const& getDepthStencilBuffer() const;

                    //## Setter ##//
                    void setColorBuffers(std::vector<Texture2D*> const& buffers);
                    void setColorBuffer(GLuint const& index, Texture2D* const&& buffer);
                    void setDepthStencilBuffer(RenderBuffer const& buffer);

                    //## Methods ##//
                    void allocateColorBuffer(GLint const& nbColorBuffer);
                    void allocateRenderBuffer();
                    void push_back(Texture2D* const& buffer);
                    void access();

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
