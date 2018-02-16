
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

            void IndexBuffer::allocate(unsigned int const& index, GLenum const& usage) {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID());
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, INDEX_BUFFER_SIZE * index, NULL, usage);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }

            void IndexBuffer::update(unsigned int const& index, GLvoid* const data) {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, getID());
                glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, INDEX_BUFFER_SIZE * index, data);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            }

        };
    };
