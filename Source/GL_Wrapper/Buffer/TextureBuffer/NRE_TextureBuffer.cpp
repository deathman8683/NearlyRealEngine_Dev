
    #include "NRE_TextureBuffer.hpp"

    namespace NRE {
        namespace GL {

            TextureBuffer::TextureBuffer() {
            }

            TextureBuffer::TextureBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            TextureBuffer::TextureBuffer(TextureBuffer && buf) : Buffer::Buffer(std::move(buf)) {
            }

            TextureBuffer::~TextureBuffer() {
                deleteID();
            }

            void TextureBuffer::generateID() {
                glGenTextures(1, &id);
            }

            void TextureBuffer::deleteID() {
                glDeleteTextures(1, &id);
            }

            void TextureBuffer::bind() const {
                glBindTexture(getTarget(), getID());
            }

            void TextureBuffer::unbind() const {
                glBindTexture(getTarget(), 0);
            }

            void TextureBuffer::allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const {
                bind();
                    glTexImage2D(getTarget(), level, internalFormat, w, h, 0, format, getType(), 0);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void TextureBuffer::update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const {
                bind();
                    glTexSubImage2D(getTarget(), level, xOffset, yOffset, w, h, format, getType(), data);
                unbind();
            }

            void TextureBuffer::allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data, bool const& callFilter) const {
                bind();
                    glTexImage2D(getTarget(), level, internalFormat, w, h, 0, format, getType(), data);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void TextureBuffer::access() const {
                bind();
            }

            TextureBuffer& TextureBuffer::operator=(TextureBuffer && buf) {
                Buffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
