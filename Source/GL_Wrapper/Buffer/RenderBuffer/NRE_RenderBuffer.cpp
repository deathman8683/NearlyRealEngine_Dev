
    #include "NRE_RenderBuffer.hpp"

    namespace NRE {
        namespace GL {

            RenderBuffer::RenderBuffer() {
            }

            RenderBuffer::RenderBuffer(bool const& generate) {
                if (generate) {
                    generateID();
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

        };
    };
