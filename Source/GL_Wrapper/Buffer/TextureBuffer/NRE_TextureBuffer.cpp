
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

            TextureBuffer::TextureBuffer(TextureBuffer && buf) : Buffer::Buffer(std::move(buf)) {
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
                return *this;
            }

        };
    };
