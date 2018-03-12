
    #include "NRE_VertexBuffer.hpp"

    namespace NRE {
        namespace Buffer {

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

            void VertexBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void VertexBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void VertexBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target) {
                Buffer::allocateAndFill(size, usage, data, target);
            }

            void VertexBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void VertexBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
