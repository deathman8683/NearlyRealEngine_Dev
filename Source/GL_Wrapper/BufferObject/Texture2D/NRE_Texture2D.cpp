
    #include "NRE_Texture2D.hpp"

    namespace NRE {
        namespace GL {

            Texture2D::Texture2D(IO::File const& path, bool const& loadImmedialty) : Texture2DBuffer::Texture2DBuffer(true), SDL::Surface::Surface(path) {
                if (loadImmedialty) {
                    allocateAndFill(true);
                }
            }

            Texture2D::Texture2D(GLsizei const& w, GLsizei const& h, GLenum const& glFormat, GLint const& glInternalFormat, GLenum const& t) : Texture2DBuffer::Texture2DBuffer(true, t), SDL::Surface::Surface(w, h, glFormat, glInternalFormat) {
                allocate(true);
            }

            Texture2D::Texture2D(Texture2D && tex) : Texture2DBuffer::Texture2DBuffer(std::move(tex)), BufferObject::BufferObject(std::move(tex)), SDL::Surface::Surface(std::move(tex))  {
            }

            Texture2D::~Texture2D() {
            }

            GLenum const Texture2D::getTarget() const {
                return GL_TEXTURE_2D;
            }

            void Texture2D::bind() const {
                Texture2DBuffer::bind();
            }

            void Texture2D::unbind() const {
                Texture2DBuffer::unbind();
            }

            void Texture2D::allocate(bool const& callFilter) {
                Texture2DBuffer::allocate(0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), callFilter);
                setAllocated(true);
            }

            void Texture2D::update(GLint const& xOffset, GLint const& yOffset, GLvoid* const& data) const {
                Texture2DBuffer::update(0, xOffset, yOffset, getGLW(), getGLH(), getGLFormat(), data);
            }

            void Texture2D::allocateAndFill(bool const& callFilter) {
                Texture2DBuffer::allocateAndFill(0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), getPixels(), callFilter);
                setAllocated(true);
                free();
            }

            void Texture2D::applyFilter() const {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }

            void Texture2D::attach(GLenum const& attachment) const {
                glFramebufferTexture2D(GL_FRAMEBUFFER, attachment, GL_TEXTURE_2D, getID(), 0);
            }

            Texture2D& Texture2D::operator=(Texture2D && tex) {
                Texture2DBuffer::operator=(std::move(tex));
                BufferObject::operator=(std::move(tex));
                SDL::Surface::operator=(std::move(tex));
                DepthBuffer::operator=(std::move(tex));
                return *this;
            }

        };
    };
