
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
                deleteID();
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

            void TextureBuffer::allocate(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const {
                glTexImage2D(target, level, internalFormat, w, h, 0, format, getType(), 0);
                if (callFilter) {
                    applyFilter();
                }
            }

            void TextureBuffer::update(GLenum const& target, GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const {
                glTexSubImage2D(target, level, xOffset, yOffset, w, h, format, getType(), data);
            }

            void TextureBuffer::allocateAndFill(GLenum const& target, GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data, bool const& callFilter) const {
                glTexImage2D(target, level, internalFormat, w, h, 0, format, getType(), data);
                if (callFilter) {
                    applyFilter();
                }
            }

            void TextureBuffer::access(GLenum const& target) const {
                bind(target);
            }

        };
    };
