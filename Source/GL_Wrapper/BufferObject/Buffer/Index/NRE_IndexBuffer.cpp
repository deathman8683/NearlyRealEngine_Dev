
    #include "NRE_IndexBuffer.hpp"

    namespace NRE {
        namespace GL {

            IndexBuffer::IndexBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            IndexBuffer::~IndexBuffer() {
                deleteID();
            }

            void IndexBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void IndexBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void IndexBuffer::reload() {
                deleteID();
                generateID();
            }

            void IndexBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void IndexBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void IndexBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void IndexBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
