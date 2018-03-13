
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

            void ArrayBuffer::bind() const {
                AttributeBuffer::bind(GL_ARRAY_BUFFER);
            }

            void ArrayBuffer::unbind() const {
                AttributeBuffer::unbind(GL_ARRAY_BUFFER);
            }

            void ArrayBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) const {
                AttributeBuffer::(GL_ARRAY_BUFFER, size, usage);
            }
            void ArrayBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const {
                AttributeBuffer::(GL_ARRAY_BUFFER, offset, size, data);
            }

            void ArrayBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const {
                AttributeBuffer::(GL_ARRAY_BUFFER, size, usage, data);
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
