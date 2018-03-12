
    #include "NRE_Texture.hpp"

    namespace NRE {
        namespace GL {

            Texture::Texture() : id(0) {
            }

            Texture::Texture(std::string const& path) : SDL::Surface::Surface(path), id(0) {
                generateID();
                load();
                free();
            }

            Texture::Texture(Texture const& tex) : SDL::Surface::Surface(tex), id(tex.getID()) {
            }

            Texture::~Texture() {
                deleteID();
            }

            GLuint const& Texture::getID() const {
                return id;
            }

            void Texture::setID(GLuint const& id) {
                this->id = id;
            }

            void Texture::generateID() {
                glGenTextures(1, &id);
            }

            void Texture::deleteID() {
                glDeleteTextures(1 ,&id);
            }

            void Texture::reload() {
                deleteID();
                generateID();
            }

            void Texture::bind() const {
                glBindTexture(GL_TEXTURE_2D, getID());
            }

            void Texture::unbind() const {
                glBindTexture(GL_TEXTURE_2D, 0);
            }

            void Texture::load() {
                bind();
                glTexImage2D(GL_TEXTURE_2D, 0, getGLInternalFormat(), getW(), getH(), 0, getGLFormat(), GL_UNSIGNED_BYTE, getPixels());
                applyFilter();
                unbind();
            }

            void Texture::applyFilter() {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            }

        };
    };
