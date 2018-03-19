
    #include "NRE_FrameBuffer.hpp"

    namespace NRE {
        namespace GL {

            FrameBuffer::FrameBuffer() {
            }

            FrameBuffer::FrameBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            FrameBuffer::FrameBuffer(FrameBuffer const& buf) : Buffer::Buffer(buf) {
            }

            FrameBuffer::~FrameBuffer() {
                deleteID();
            }

            void FrameBuffer::generateID() {
                glGenFramebuffers(1, &id);
            }

            void FrameBuffer::deleteID() {
                glDeleteFramebuffers(1, &id);
            }

            void FrameBuffer::bind() const {
                glBindFramebuffer(GL_FRAMEBUFFER, getID());
            }

            void FrameBuffer::unbind() const {
                glBindFramebuffer(GL_FRAMEBUFFER, 0);
            }

            void FrameBuffer::attachBuffer(GLenum const& attachment, Texture2D const& texture) const {
                glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, texture.getID(), 0);
            }

            void FrameBuffer::attachRenderBuffer(GLenum const& attachment, GLenum const& renderBufferTarget, GLuint const& renderBuffer) const {
                glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, renderBufferTarget, renderBuffer);
            }

            void FrameBuffer::access() const {
                bind();
            }

        };
    };
