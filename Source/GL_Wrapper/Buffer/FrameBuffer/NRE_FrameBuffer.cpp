
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

            void FrameBuffer::bind(GLenum const& target) const {
                glBindFramebuffer(target, getID());
            }

            void FrameBuffer::unbind(GLenum const& target) const {
                glBindFramebuffer(target, 0);
            }

            void FrameBuffer::attachColorBuffer(GLenum const& target, GLenum const& attachment, Texture2D const& texture) const {
                glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture.getID(), 0);
            }

            void FrameBuffer::attachRenderBuffer(GLenum const& target, GLenum const& attachment, GLenum const& renderBufferTarget, GLuint const& renderBuffer) const {
                glFramebufferRenderbuffer(target, attachment, renderBufferTarget, renderBuffer);
            }

            void FrameBuffer::access(GLenum const& target) const {
                bind(target);
            }

        };
    };
