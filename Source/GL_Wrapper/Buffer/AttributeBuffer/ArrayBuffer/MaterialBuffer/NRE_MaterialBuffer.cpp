
    #include "NRE_MaterialBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint MaterialBuffer::INDEX = 4;
            GLenum MaterialBuffer::TYPE = GL_UNSIGNED_BYTE;
            GLint MaterialBuffer::TYPESIZE = sizeof(GLubyte);
            GLint MaterialBuffer::SIZE = 1;

            MaterialBuffer::MaterialBuffer() {
            }

            MaterialBuffer::MaterialBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            MaterialBuffer::MaterialBuffer(MaterialBuffer && buf) : ArrayBuffer::ArrayBuffer(std::move(buf)) {
            }

            MaterialBuffer::~MaterialBuffer() {
            }

            GLint const MaterialBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLint const MaterialBuffer::getSize() const {
                return SIZE;
            }

            GLenum const MaterialBuffer::getType() const {
                return TYPE;
            }

            GLint const MaterialBuffer::getIndex() const {
                return INDEX;
            }

            MaterialBuffer& MaterialBuffer::operator=(MaterialBuffer && buf) {
                ArrayBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
