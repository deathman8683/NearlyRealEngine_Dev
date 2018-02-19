
    #include "NRE_ColorBuffer.hpp"

    namespace NRE {
        namespace GL {

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

            void NormalBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) {
                bind();
                glBufferData(GL_ARRAY_BUFFER, size, NULL, usage);
                unbind();
            }

            void NormalBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) {
                bind();
                glBufferData(GL_ARRAY_BUFFER, offset, size, data);
                unbind();
            }

            void NormalBuffer::bind() {
                glBindBuffer(GL_ARRAY_BUFFER, getID();
            }

            void NormalBuffer::unbind() {
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

        };
    };
