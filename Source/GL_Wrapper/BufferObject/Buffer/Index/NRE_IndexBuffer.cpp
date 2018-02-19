
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

            void NormalBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) {
                bind();
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, NULL, usage);
                unbind();
            }

            void NormalBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) {
                bind();
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, offset, size, data);
                unbind();
            }

            void NormalBuffer::bind() {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID();
            }

            void NormalBuffer::unbind() {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }

        };
    };
