
    #include "NRE_UVBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint UVBuffer::INDEX = 3;
            GLenum UVBuffer::TYPE = GL_FLOAT;
            GLint UVBuffer::TYPESIZE = sizeof(NREfloat);
            GLint UVBuffer::SIZE = 2;

            UVBuffer::UVBuffer() {
            }

            UVBuffer::UVBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            UVBuffer::UVBuffer(UVBuffer && buf) : ArrayBuffer::ArrayBuffer(std::move(buf)) {
            }

            UVBuffer::~UVBuffer() {
            }

            GLint const UVBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLint const UVBuffer::getSize() const {
                return SIZE;
            }

            GLenum const UVBuffer::getType() const {
                return TYPE;
            }

            GLint const UVBuffer::getIndex() const {
                return INDEX;
            }

            UVBuffer& UVBuffer::operator=(UVBuffer && buf) {
                ArrayBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
