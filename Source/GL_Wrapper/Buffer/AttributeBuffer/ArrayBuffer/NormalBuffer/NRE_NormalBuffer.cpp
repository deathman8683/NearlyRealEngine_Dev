
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

            GLint const NormalBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLint const NormalBuffer::getSize() const {
                return SIZE;
            }

            GLenum const NormalBuffer::getType() const {
                return TYPE;
            }

            GLint const NormalBuffer::getIndex() const {
                return INDEX;
            }

        };
    };
