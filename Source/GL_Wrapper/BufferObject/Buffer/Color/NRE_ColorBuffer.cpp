
    #include "NRE_ColorBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLenum ColorBuffer::COLOR_BUFFER_TYPE = GL_FLOAT;
            int ColorBuffer::COLOR_BUFFER_SIZE = sizeof(COLOR_BUFFER_TYPE);

            ColorBuffer::ColorBuffer() {
            }

            ColorBuffer::ColorBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            ColorBuffer::~ColorBuffer() {
                deleteID();
            }

            void ColorBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void ColorBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void ColorBuffer::reload() {
                deleteID();
                generateID();
            }

            void ColorBuffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                Buffer::allocate(size, usage, target);
            }

            void ColorBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                Buffer::update(offset, size, data, target);
            }

            void ColorBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target) {
                Buffer::allocateAndFill(size, usage, data, target);
            }

            void ColorBuffer::bind(GLenum const& target) const {
                Buffer::bind(target);
            }

            void ColorBuffer::unbind(GLenum const& target) const {
                Buffer::bind(target);
            }

        };
    };
