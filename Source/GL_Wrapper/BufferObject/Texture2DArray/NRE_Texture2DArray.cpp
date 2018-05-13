
    #include "NRE_Texture2DArray.hpp"

    namespace NRE {
        namespace GL {

            Texture2DArray::Texture2DArray() : Texture3DBuffer::Texture3DBuffer(true) {
            }

            Texture2DArray::Texture2DArray(Texture2DArray && tex) : Texture3DBuffer::Texture3DBuffer(std::move(tex)), BufferObject::BufferObject(std::move(tex)) {
            }

            Texture2DArray::~Texture2DArray() {
            }

            GLenum const Texture2DArray::getTarget() const {
                return GL_TEXTURE_2D_ARRAY;
            }

            void Texture2DArray::applyFilter() const {
                glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            }

            Texture2DArray& Texture2DArray::operator=(Texture2DArray && tex) {
                Texture3DBuffer::operator=(std::move(tex));
                BufferObject::operator=(std::move(tex));
                return *this;
            }

        };
    };
