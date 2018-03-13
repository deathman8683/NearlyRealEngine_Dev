
    #include "NRE_NormalBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint NormalBuffer::INDEX = 2;
            GLenum NormalBuffer::TYPE = GL_BYTE;
            GLint NormalBuffer::TYPESIZE = sizeof(GLbyte);
            GLint NormalBuffer::SIZE = 3;

            NormalBuffer::NormalBuffer() {
            }

            NormalBuffer::NormalBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            NormalBuffer::NormalBuffer(NormalBuffer const& buf) : ArrayBuffer::ArrayBuffer(buf) {
            }

            NormalBuffer::~NormalBuffer() {
            }

            void NormalBuffer::access(bool const& enableVAA) {
                ArrayBuffer::access(TYPE, INDEX, SIZE, enableVAA);
            }

        };
    };
