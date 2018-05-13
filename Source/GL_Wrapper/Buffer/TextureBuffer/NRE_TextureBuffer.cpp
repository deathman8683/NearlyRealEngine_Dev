
    #include "NRE_TextureBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLenum TextureBuffer::DEFAULT_TYPE = GL_UNSIGNED_BYTE;

            TextureBuffer::TextureBuffer() {
            }

            TextureBuffer::TextureBuffer(bool const& generate) : TextureBuffer(generate, DEFAULT_TYPE) {
            }

            TextureBuffer::TextureBuffer(bool const& generate, GLenum const& type) : type(type) {
                if (generate) {
                    generateID();
                }
            }

            TextureBuffer::TextureBuffer(TextureBuffer && buf) : Buffer::Buffer(std::move(buf)), type(std::move(buf.type)) {
            }

            TextureBuffer::~TextureBuffer() {
                deleteID();
            }

            GLenum const& TextureBuffer::getType() const {
                return type;
            }

            void TextureBuffer::setType(GLenum const& t) {
                type = t;
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

            void TextureBuffer::access() const {
                bind();
            }

            TextureBuffer& TextureBuffer::operator=(TextureBuffer && buf) {
                Buffer::operator=(std::move(buf));
                type = std::move(buf.type);
                return *this;
            }

        };
    };
