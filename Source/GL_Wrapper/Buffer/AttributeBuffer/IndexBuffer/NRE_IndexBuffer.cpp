
    #include "NRE_IndexBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLenum IndexBuffer::TYPE = GL_UNSIGNED_INT;
            GLint IndexBuffer::TYPESIZE = sizeof(GLuint);

            IndexBuffer::IndexBuffer() {
            }

            IndexBuffer::IndexBuffer(bool const& generate) : AttributeBuffer::AttributeBuffer(generate) {
            }

            IndexBuffer::IndexBuffer(IndexBuffer const& buf) : AttributeBuffer::AttributeBuffer(buf) {
            }

            IndexBuffer::~IndexBuffer() {
            }

            GLint const IndexBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLenum const IndexBuffer::getType() const {
                return TYPE;
            }

            void IndexBuffer::bind() const {
                AttributeBuffer::bind(GL_ELEMENT_ARRAY_BUFFER);
            }

            void IndexBuffer::unbind() const {
                AttributeBuffer::unbind(GL_ELEMENT_ARRAY_BUFFER);
            }

            void IndexBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) const {
                AttributeBuffer::allocate(GL_ELEMENT_ARRAY_BUFFER, size, usage);
            }
            void IndexBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const {
                AttributeBuffer::update(GL_ELEMENT_ARRAY_BUFFER, offset, size, data);
            }

            void IndexBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const {
                AttributeBuffer::allocateAndFill(GL_ELEMENT_ARRAY_BUFFER, size, usage, data);
            }

            void IndexBuffer::access() const {
                bind();
            }

        };
    };
