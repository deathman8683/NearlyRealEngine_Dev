
    /**
     * @file NRE_FBO.hpp
     * @brief Declaration of Engine's GL's Object : FBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Maths/NRE_Maths.hpp"
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
                    RenderBuffer depthBuffer;
                    Maths::Vector2D<GLushort> size;

                public:
                    //## Constructor ##//
                    FBO();
                    FBO(GLsizei const& w, GLsizei const& h);
                    FBO(GLsizei const& w, GLsizei const& h, GLuint const& nbColorBuffer);

                    //## Copy-Constructor ##//
                    FBO(FBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~FBO();

                    //## Getter ##//
                    std::vector<Texture2D*> const& getColorBuffers() const;
                    Texture2D* const& getColorBuffer(GLuint const& index) const;
                    RenderBuffer const& getDepthBuffer() const;
                    Maths::Vector2D<GLushort> const& getSize() const;

                    //## Setter ##//
                    void setColorBuffers(std::vector<Texture2D*> const& buffers);
                    void setColorBuffer(GLuint const& index, Texture2D* const&& buffer);
                    void setDepthBuffer(RenderBuffer const& buffer);
                    void setSize(Maths::Vector2D<GLushort> const& size);

                    //## Methods ##//
                    void allocateColorBuffer(GLuint const& nbColorBuffer, std::vector<GLenum> const& format, std::vector<GLint> const& internalFormat, std::vector<GLenum> const& type);
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
                    static GLenum DEFAULT_FORMAT;
                    static GLenum DEFAULT_INTERNAL_FORMAT;
            };

        };
    };
