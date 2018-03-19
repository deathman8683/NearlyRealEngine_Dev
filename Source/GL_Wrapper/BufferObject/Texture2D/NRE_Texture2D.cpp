
    #include "NRE_Texture2D.hpp"

    namespace NRE {
        namespace GL {

            GLenum Texture2D::DEFAULT_TYPE = GL_UNSIGNED_BYTE;

            Texture2D::Texture2D() {
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

            void Texture2D::setType(GLenum const& t) {
                type = t;
            }

            void Texture2D::bind() const {
                TextureBuffer::bind(GL_TEXTURE_2D);
            }

            void Texture2D::unbind() const {
                TextureBuffer::unbind(GL_TEXTURE_2D);
            }

            void Texture2D::allocate(bool const& callFilter) {
                bind();
                    TextureBuffer::allocate(GL_TEXTURE_2D, 0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), callFilter);
                unbind();
                setAllocated(true);
            }

            void Texture2D::update(GLint const& xOffset, GLint const& yOffset, GLvoid* const& data) const {
                bind();
                    TextureBuffer::update(GL_TEXTURE_2D, 0, xOffset, yOffset, getGLW(), getGLH(), getGLFormat(), data);
                unbind();
            }

            void Texture2D::allocateAndFill(bool const& callFilter) {
                bind();
                    TextureBuffer::allocateAndFill(GL_TEXTURE_2D, 0, getGLInternalFormat(), getGLW(), getGLH(), getGLFormat(), getPixels(), callFilter);
                unbind();
                setAllocated(true);
                free();
            }

            void Texture2D::applyFilter() const {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            }

            void Texture2D::access() const {
                TextureBuffer::access(GL_TEXTURE_2D);
            }

        };
    };