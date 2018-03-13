
    #include "NRE_ColorBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint ColorBuffer::INDEX = 1;
            GLenum ColorBuffer::TYPE = GL_FLOAT;
            GLint ColorBuffer::TYPESIZE = sizeof(GLfloat);
            GLint ColorBuffer::SIZE = 3;

            ColorBuffer::ColorBuffer() {
            }

            ColorBuffer::ColorBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            ColorBuffer::ColorBuffer(ColorBuffer const& buf) : ArrayBuffer::ArrayBuffer(buf) {
            }

            ColorBuffer::~ColorBuffer() {
            }

            void ColorBuffer::access(bool const& enableVAA) {
                ArrayBuffer::access(TYPE, INDEX, SIZE, enableVAA);
            }

        };
    };
