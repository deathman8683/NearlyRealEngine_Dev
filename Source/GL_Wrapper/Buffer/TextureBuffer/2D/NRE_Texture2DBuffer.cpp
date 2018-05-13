
    #include "NRE_Texture2DBuffer.hpp"

    namespace NRE {
        namespace GL {

            Texture2DBuffer::Texture2DBuffer() {
            }

            Texture2DBuffer::Texture2DBuffer(bool const& generate) : TextureBuffer::TextureBuffer(generate) {
            }

            Texture2DBuffer::Texture2DBuffer(Texture2DBuffer && buf) {
            }

            Texture2DBuffer::~Texture2DBuffer() {
            }

            GLenum const Texture2DBuffer::getTarget() const {
                return GL_TEXTURE_2D;
            }

            void Texture2DBuffer::allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const {
                bind();
                    glTexImage2D(getTarget(), level, internalFormat, w, h, 0, format, getType(), 0);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void Texture2DBuffer::update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data) const {
                bind();
                    glTexSubImage2D(getTarget(), level, xOffset, yOffset, w, h, format, getType(), data);
                unbind();
            }

            void Texture2DBuffer::allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, GLvoid* const& data, bool const& callFilter) const {
                bind();
                    glTexImage2D(getTarget(), level, internalFormat, w, h, 0, format, getType(), data);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            Texture2DBuffer& Texture2DBuffer::operator=(Texture2DBuffer && buf) {
                return *this;
            }

        };
    };
