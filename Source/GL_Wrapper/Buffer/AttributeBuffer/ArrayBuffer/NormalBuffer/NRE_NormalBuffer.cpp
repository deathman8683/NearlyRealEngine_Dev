
    #include "NRE_NormalBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint NormalBuffer::INDEX = 2;
            GLenum NormalBuffer::TYPE = GL_FLOAT;
            GLint NormalBuffer::TYPESIZE = sizeof(NREfloat);
            GLint NormalBuffer::SIZE = 3;

            NormalBuffer::NormalBuffer() {
            }

            NormalBuffer::NormalBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            NormalBuffer::NormalBuffer(NormalBuffer && buf) : ArrayBuffer::ArrayBuffer(std::move(buf)) {
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

            NormalBuffer& NormalBuffer::operator=(NormalBuffer && buf) {
                ArrayBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
