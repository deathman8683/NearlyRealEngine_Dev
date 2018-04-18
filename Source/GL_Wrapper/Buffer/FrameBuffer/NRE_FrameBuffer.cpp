
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

            FrameBuffer::FrameBuffer(FrameBuffer && buf) : Buffer::Buffer(std::move(buf)) {
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

            void FrameBuffer::attachBuffer(GLenum const& attachment, GLenum const& target, GLuint const& id, GLint const& level) const {
                glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, target, id, level);
            }

            void FrameBuffer::access() const {
                bind();
            }

            FrameBuffer& FrameBuffer::operator=(FrameBuffer && buf) {
                Buffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
