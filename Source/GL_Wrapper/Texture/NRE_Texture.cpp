
    #include "NRE_Texture.hpp"

    namespace NRE {
        namespace GL {

            Texture::Texture() : id(0) {
            }

            Texture::Texture(std::string const& path) : SDL::Surface::Surface(path), id(0) {
                generateID();
            }

            Texture::Texture(Texture const& tex) : SDL::Surface::Surface(tex), id(tex.getId()) {
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
                glDeleteTexture(1 ,&id);
            }

            void Texture::reload() {
                deleteID();
                generateID();
            }

            void Texture::bind(GLenum target) const {
                glBindTexture(target, getID());
            }
            void Texture::unbind(GLenum target) const {
                glBindTexture(target, 0);
            }

        };
    };
