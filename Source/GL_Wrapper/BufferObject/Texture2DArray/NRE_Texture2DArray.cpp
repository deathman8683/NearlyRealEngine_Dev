
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

           void Texture2DArray::allocate(GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLsizei const& z, GLenum const& format, bool const& callFilter) {
               Texture3DBuffer::allocate(0, internalFormat, w, h, z, format, callFilter);
               setAllocated(true);
           }

           void Texture2DArray::allocate(GLsizei const& z, Texture2D const& tex, bool const& callFilter) {
               Texture2DArray::allocate(tex.getGLInternalFormat(), tex.getGLW(), tex.getGLH(), z, tex.getGLFormat(), callFilter);
               setAllocated(true);
           }

           void Texture2DArray::sendTexture(Texture2D const& tex, GLint const& layer) {
               Texture2DArray::update(0, 0, 0, layer, tex.getGLW(), tex.getGLH(), 1, tex.getGLFormat(), tex.getPixels());
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
