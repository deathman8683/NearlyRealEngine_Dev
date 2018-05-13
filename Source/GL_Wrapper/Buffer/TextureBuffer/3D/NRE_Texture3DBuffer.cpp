
    #include "NRE_Texture3DBuffer.hpp"

    namespace NRE {
        namespace GL {

            Texture3DBuffer::Texture3DBuffer() {
            }

            Texture3DBuffer::Texture3DBuffer(bool const& generate) : TextureBuffer::TextureBuffer(generate) {
            }

            Texture3DBuffer::Texture3DBuffer(bool const& generate, GLenum const& type) : TextureBuffer::TextureBuffer(generate, type) {
            }

            Texture3DBuffer::Texture3DBuffer(Texture3DBuffer && buf) : TextureBuffer::TextureBuffer(std::move(buf)) {
            }

            Texture3DBuffer::~Texture3DBuffer() {
            }

            void Texture3DBuffer::allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, bool const& callFilter) const {
                bind();
                    glTexImage3D(getTarget(), level, internalFormat, w, h, z, 0, format, getType(), 0);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void Texture3DBuffer::update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLint const& zOffset, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, GLvoid* const& data) const {
                bind();
                    glTexSubImage3D(getTarget(), level, xOffset, yOffset, zOffset, w, h, z, format, getType(), data);
                unbind();
            }

            void Texture3DBuffer::allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, GLvoid* const& data, bool const& callFilter) const {
                bind();
                    glTexImage3D(getTarget(), level, internalFormat, w, h, z, 0, format, getType(), data);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            Texture3DBuffer& Texture3DBuffer::operator=(Texture3DBuffer && buf) {
                TextureBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
