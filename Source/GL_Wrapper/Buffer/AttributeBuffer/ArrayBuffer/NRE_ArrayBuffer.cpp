
    #include "NRE_ArrayBuffer.hpp"

    namespace NRE {
        namespace GL {

            ArrayBuffer::ArrayBuffer() {
            }

            ArrayBuffer::ArrayBuffer(bool const& generate) : AttributeBuffer::AttributeBuffer(generate) {
            }

            ArrayBuffer::ArrayBuffer(ArrayBuffer && buf) : AttributeBuffer::AttributeBuffer(std::move(buf)) {
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

            ArrayBuffer& ArrayBuffer::operator=(ArrayBuffer && buf) {
                AttributeBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
