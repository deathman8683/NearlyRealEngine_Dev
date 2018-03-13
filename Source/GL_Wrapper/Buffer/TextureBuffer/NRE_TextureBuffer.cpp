
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

            TextureBuffer::TextureBuffer(TextureBuffer const& buf) : Buffer::Buffer(buf) {
            }

            TextureBuffer::~TextureBuffer() {
            }

            void TextureBuffer::generateID() {
                glGenTextures(1, &id);
            }

            void TextureBuffer::deleteID() {
                glDeleteTextures(1, &id);
            }

            void TextureBuffer::bind(GLenum const& target) const {
                glBindTexture(target, getID());
            }

            void TextureBuffer::unbind(GLenum const& target) const {
                glBindTexture(target, 0);
            }

            void TextureBuffer::allocate(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLenum const& type, bool const& callFilter) const {
                bind(target);
                    glTexImage2D(target, level, internalFormat, w, h, 0, format, type, 0);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind(target);
            }

            void TextureBuffer::update(GLenum const& target, GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLenum const& type, GLvoid* const& data) const {
                bind(target);
                    glTexSubImage2D(target, level, xOffset, yOffset, w, h, format, type, data);
                unbind(target);
            }

            void TextureBuffer::allocateAndFill(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLenum const& type, GLvoid* const& data, bool const& callFilter) const {
                bind(target);
                    glTexImage2D(target, level, internalFormat, w, h, 0, format, type, data);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind(target);
            }

        };
    };
