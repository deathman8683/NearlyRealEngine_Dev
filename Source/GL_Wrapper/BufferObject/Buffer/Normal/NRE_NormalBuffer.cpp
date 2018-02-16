
    #include "NRE_NormalBuffer.hpp"

    namespace NRE {
        namespace GL {

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

            void NormalBuffer::allocate(unsigned int const& vertices, GLenum const& usage) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferData(GL_ARRAY_BUFFER, NORMAL_BUFFER_SIZE * vertices * 3, NULL, usage);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            void NormalBuffer::update(unsigned int const& vertices, GLvoid* const data) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferSubData(GL_ARRAY_BUFFER, 0, NORMAL_BUFFER_SIZE * vertices * 3, data);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

        };
    };
