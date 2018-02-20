
    #include "NRE_VertexBuffer.hpp"

    namespace NRE {
        namespace GL {

            VertexBuffer::VertexBuffer() {
            }

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

            void VertexBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void VertexBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void VertexBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void VertexBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
