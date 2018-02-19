
    #include "NRE_VertexBuffer.hpp"

    namespace NRE {
        namespace GL {

            VertexBuffer::VertexBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            VertexBuffer::~VertexBuffer() {
                deleteID();
            }

            void VertexBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void VertexBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void VertexBuffer::reload() {
                deleteID();
                generateID();
            }

            void VertexBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) {
                bind();
                glBufferData(GL_ARRAY_BUFFER, size, NULL, usage);
                unbind();
            }

            void VertexBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) {
                bind();
                glBufferData(GL_ARRAY_BUFFER, offset, size, data);
                unbind();
            }

            void VertexBuffer::bind() {
                glBindBuffer(GL_ARRAY_BUFFER, getID();
            }

            void VertexBuffer::unbind() {
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            std::ostream& operator<<(std::ostream &stream, VertexBuffer const& buf) {
                stream << "(" << buf.getID() << ")";
                return stream;
            }

        };
    };
