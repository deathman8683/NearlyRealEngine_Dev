
    #include "NRE_ArrayBuffer.hpp"

    namespace NRE {
        namespace GL {

            ArrayBuffer::ArrayBuffer() {
            }

            ArrayBuffer::ArrayBuffer(bool const& generate) : AttributeBuffer::AttributeBuffer(generate) {
            }

            ArrayBuffer::ArrayBuffer(ArrayBuffer const& buf) : AttributeBuffer::AttributeBuffer(buf) {
            }

            ArrayBuffer::~ArrayBuffer() {
            }

            GLenum const ArrayBuffer::getTarget() const {
                return GL_ARRAY_BUFFER;
            }

            void ArrayBuffer::access(GLenum const& type, GLint const& index, GLint const& size, bool const& enableVAA) {
                bind();
                    glVertexAttribPointer(index, size, type, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(index);
                    }
            }

        };
    };
