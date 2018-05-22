
    #include "NRE_TangentBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint TangentBuffer::INDEX = 5;
            GLenum TangentBuffer::TYPE = GL_FLOAT;
            GLint TangentBuffer::TYPESIZE = sizeof(GLfloat);
            GLint TangentBuffer::SIZE = 3;

            TangentBuffer::TangentBuffer() {
            }

            TangentBuffer::TangentBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            TangentBuffer::TangentBuffer(TangentBuffer && buf) : ArrayBuffer::ArrayBuffer(std::move(buf)) {
            }

            TangentBuffer::~TangentBuffer() {
            }

            GLint const TangentBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLint const TangentBuffer::getSize() const {
                return SIZE;
            }

            GLenum const TangentBuffer::getType() const {
                return TYPE;
            }

            GLint const TangentBuffer::getIndex() const {
                return INDEX;
            }

            TangentBuffer& TangentBuffer::operator=(TangentBuffer && buf) {
                ArrayBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
