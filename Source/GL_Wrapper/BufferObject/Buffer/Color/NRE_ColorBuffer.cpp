
    #include "NRE_ColorBuffer.hpp"

    namespace NRE {
        namespace GL {

            ColorBuffer::ColorBuffer(bool const& generate) : type(type) {
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

            void ColorBuffer::allocate(unsigned int const& vertices, GLenum const& usage) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferData(GL_ARRAY_BUFFER, sizeof(COLOR_BUFFER_SIZE) * vertices * 3, NULL, usage);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            void ColorBuffer::update(unsigned int const& vertices, GLvoid* const data) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(COLOR_BUFFER_SIZE) * vertices * 3, data);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

        };
    };
