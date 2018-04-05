
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

            void FrameBuffer::attachBuffer(GLenum const& attachment, GLenum const& target, GLuint const& id) const {
                glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, id, 0);
            }

            void FrameBuffer::access() const {
                bind();
            }

        };
    };
