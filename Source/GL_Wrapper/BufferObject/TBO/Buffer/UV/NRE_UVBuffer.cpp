
    #include "NRE_UVBuffer.hpp"

    namespace NRE {
        namespace Buffer {

            UVBuffer::UVBuffer() {
            }

            UVBuffer::UVBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            UVBuffer::~UVBuffer() {
                deleteID();
            }

            void UVBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void UVBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void UVBuffer::reload() {
                deleteID();
                generateID();
            }

            void UVBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void UVBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void UVBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target) {
                Buffer::allocateAndFill(size, usage, data, target);
            }

            void UVBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void UVBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
