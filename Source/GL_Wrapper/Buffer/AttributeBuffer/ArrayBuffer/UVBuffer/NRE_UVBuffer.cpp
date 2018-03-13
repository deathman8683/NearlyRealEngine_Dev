
    #include "NRE_UVBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint UVBuffer::INDEX = 3;
            GLenum UVBuffer::TYPE = GL_SHORT;
            GLint UVBuffer::TYPESIZE = sizeof(GLshort);
            GLint UVBuffer::SIZE = 2;

            UVBuffer::UVBuffer() {
            }

            UVBuffer::UVBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            UVBuffer::UVBuffer(UVBuffer const& buf) : ArrayBuffer::ArrayBuffer(buf) {
            }

            UVBuffer::~UVBuffer() {
            }

            void UVBuffer::access(bool const& enableVAA) {
                ArrayBuffer::access(TYPE, INDEX, SIZE, enableVAA);
            }

        };
    };
