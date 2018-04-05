
    #include "NRE_Texture2D.hpp"

    namespace NRE {
        namespace GL {

            GLenum Texture2D::DEFAULT_TYPE = GL_UNSIGNED_BYTE;

            Texture2D::Texture2D() : TextureBuffer::TextureBuffer(true), type(DEFAULT_TYPE) {
            }

            Texture2D::Texture2D(std::string const& path) : TextureBuffer::TextureBuffer(true), SDL::Surface::Surface(path), type(DEFAULT_TYPE) {
                allocateAndFill(true);
            }

            Texture2D::Texture2D(GLsizei const& w, GLsizei const& h, GLenum const& glFormat, GLint const& glInternalFormat, GLenum const& t) : TextureBuffer::TextureBuffer(true), SDL::Surface::Surface(w, h, glFormat, glInternalFormat), type(t) {
                allocate(true);
            }

            Texture2D::Texture2D(Texture2D const& tex) : TextureBuffer::TextureBuffer(tex), BufferObject::BufferObject(tex), SDL::Surface::Surface(tex), type(tex.getType()) {
            }

            Texture2D::~Texture2D() {
            }

            GLenum const Texture2D::getType() const {
                return type;
            }

            GLenum const Texture2D::getTarget() const {
                return GL_TEXTURE_2D;
            }

            void Texture2D::setType(GLenum const& t) {
                type = t;
            }

            void Texture2D::bind() const {
                TextureBuffer::bind();
            }

            void Texture2D::unbind() const {
                TextureBuffer::unbind();
            }

            void Texture2D::allocate(bool const& callFilter) {
                TextureBuffer::allocate(0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), callFilter);
                setAllocated(true);
            }

            void Texture2D::update(GLint const& xOffset, GLint const& yOffset, GLvoid* const& data) const {
                TextureBuffer::update(0, xOffset, yOffset, getGLW(), getGLH(), getGLFormat(), data);
            }

            void Texture2D::allocateAndFill(bool const& callFilter) {
                TextureBuffer::allocateAndFill(0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), getPixels(), callFilter);
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

        };
    };
