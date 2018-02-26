
    #include "NRE_NormalBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLenum NormalBuffer::NORMAL_BUFFER_TYPE = GL_BYTE;
            int NormalBuffer::NORMAL_BUFFER_SIZE = sizeof(NORMAL_BUFFER_TYPE);

            NormalBuffer::NormalBuffer() {
            }

            NormalBuffer::NormalBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            NormalBuffer::~NormalBuffer() {
                deleteID();
            }

            void NormalBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void NormalBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void NormalBuffer::reload() {
                deleteID();
                generateID();
            }

            void NormalBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void NormalBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void NormalBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target) {
                Buffer::allocateAndFill(size, usage, data, target);
            }

            void NormalBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void NormalBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
