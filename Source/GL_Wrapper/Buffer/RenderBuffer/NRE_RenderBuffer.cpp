
    #include "NRE_RenderBuffer.hpp"

    namespace NRE {
        namespace GL {

            RenderBuffer::RenderBuffer() {
            }

            RenderBuffer::RenderBuffer(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h, bool const& generate) {
                if (generate) {
                    generateID();
                    allocate(internalFormat, w, h);
                }
            }

            RenderBuffer::RenderBuffer(RenderBuffer const& buf) : Buffer::Buffer(buf) {
            }

            RenderBuffer::~RenderBuffer() {
                deleteID();
            }

            void RenderBuffer::generateID() {
                glGenRenderbuffers(1, &id);
            }

            void RenderBuffer::deleteID() {
                glDeleteRenderbuffers(1, &id);
            }

            void RenderBuffer::bind() const {
                glBindRenderbuffer(GL_RENDERBUFFER, getID());
            }

            void RenderBuffer::unbind() const {
                glBindRenderbuffer(GL_RENDERBUFFER, 0);
            }

            void RenderBuffer::allocate(GLenum const& internalFormat, GLsizei const& w, GLsizei const& h) const {
                bind();
                    glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, w, h);
                unbind();
            }

            void RenderBuffer::access() const {
                bind();
            }

            void RenderBuffer::attach(GLenum const& attachment) const {
                glFramebufferRenderbuffer(GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, getID());
            }

        };
    };
