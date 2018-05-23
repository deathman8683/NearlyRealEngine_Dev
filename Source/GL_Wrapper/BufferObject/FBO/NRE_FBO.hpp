
    /**
     * @file NRE_FBO.hpp
     * @brief Declaration of Engine's GL's Object : FBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include "../../../Maths/NRE_Maths.hpp"
    #include "../../Buffer/FrameBuffer/NRE_FrameBuffer.hpp"
    #include "../../Buffer/DepthBuffer/NRE_DepthBuffer.hpp"
    #include "../../Buffer/RenderBuffer/NRE_RenderBuffer.hpp"
    #include "../../../Exception/GLException/NRE_GLException.hpp"

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
                    std::vector<Texture2D*> colorBuffers;    /**< The FBO's colorbuffer array */
                    DepthBuffer* depthBuffer;               /**< The FBO's depthBuffer */
                    Maths::Vector2D<GLushort> size;         /**< The FBO's size */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FBO() = delete;
                        /**
                         * Construct a frame buffer object with a given size
                         * @param w the fbo's width
                         * @param h the fbo's height
                         */
                        FBO(GLsizei const& w, GLsizei const& h);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the fbo to copy
                         */
                        FBO(FBO const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the fbo to move
                         */
                        FBO(FBO && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FBO Deconstructor
                         */
                        ~FBO();

                    //## Getter ##//
                        /**
                         * Return a specific colorBuffer
                         * @param  index the colorBuffer index
                         * @return       a 2D texture representing the colorBuffer
                         */
                        Texture2D* const& getColorBuffer(GLuint const& index) const;
                        /**
                         * DepthBuffer getter
                         * @return the fbo's depth buffer
                         */
                        DepthBuffer* const& getDepthBuffer() const;
                        /**
                         * Size getter
                         * @return the fbo's size
                         */
                        Maths::Vector2D<GLushort> const& getSize() const;

                    //## Setter ##//
                        /**
                         * DepthBuffer setter
                         * @param buffer the new fbo's depthBuffer
                         */
                        void setDepthBuffer(DepthBuffer* const& buffer);

                    //## Methods ##//
                        /**
                         * Allocate some colorbuffer for the fbo, with given array of parameters
                         * @param nbColorBuffer  the number of colorBuffer to allocate
                         * @param format         colorBuffer's format
                         * @param internalFormat colorBuffer's internal format
                         * @param type           colorBuffer's type enum
                         */
                        void allocateColorBuffer(GLuint const& nbColorBuffer, std::vector<GLenum> const& format, std::vector<GLint> const& internalFormat, std::vector<GLenum> const& type);
                        /**
                         * Attach the depth buffer to a specific attachment point
                         * @param attachment the specific attachment point
                         */
                        void attachDepthBuffer(GLenum const& attachment) const;
                        /**
                         * Store calls for VAO managing
                         */
                        void access();
                        /**
                         * Check if the FBO is complete, throw an exception if not
                         */
                        void checkIntegrity();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the fbo to copy
                         */
                        FBO& operator=(FBO const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the fbo to move into this
                         * @return the reference of himself
                         */
                        FBO& operator=(FBO && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
