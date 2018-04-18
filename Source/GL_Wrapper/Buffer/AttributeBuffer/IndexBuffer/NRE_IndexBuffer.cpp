
    #include "NRE_IndexBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLenum IndexBuffer::TYPE = GL_UNSIGNED_INT;
            GLint IndexBuffer::TYPESIZE = sizeof(GLuint);

            IndexBuffer::IndexBuffer() {
            }

            IndexBuffer::IndexBuffer(bool const& generate) : AttributeBuffer::AttributeBuffer(generate) {
            }

            IndexBuffer::IndexBuffer(IndexBuffer && buf) : AttributeBuffer::AttributeBuffer(std::move(buf)) {
            }

            IndexBuffer::~IndexBuffer() {
            }

            GLint const IndexBuffer::getTypeSize() const {
                return TYPESIZE;
            }

            GLenum const IndexBuffer::getType() const {
                return TYPE;
            }

            GLenum const IndexBuffer::getTarget() const {
                return GL_ELEMENT_ARRAY_BUFFER;
            }

            void IndexBuffer::access() const {
                bind();
            }

            IndexBuffer& IndexBuffer::operator=(IndexBuffer && buf) {
                AttributeBuffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
