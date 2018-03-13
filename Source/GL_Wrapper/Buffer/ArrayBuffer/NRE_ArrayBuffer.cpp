
    #include "NRE_ArrayBuffer.hpp"

    namespace NRE {
        namespace GL {

            ArrayBuffer::ArrayBuffer() {
            }

            ArrayBuffer::ArrayBuffer(bool const& generate) : {
                if (generate) {
                    generateID();
                }
            }

            ArrayBuffer::ArrayBuffer(ArrayBuffer const& buf) : Buffer::Buffer(buf) {
            }

            ArrayBuffer::~ArrayBuffer() {
            }

            void ArrayBuffer::generateID() {
                glGenVertexArrays(1, &id);
            }

            void ArrayBuffer::deleteID() {
                glDeleteVertexArrays(1, &id);
            }

            void ArrayBuffer::bind() const {
                glBindVertexArray(getID());
            }

            void ArrayBuffer::unbind() const {
                glBindVertexArray(0);
            }

        };
    };
