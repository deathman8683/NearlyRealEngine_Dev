
    #include "NRE_VertexBuffer.hpp"

    namespace NRE {
        namespace GL {

            GLint VertexBuffer::INDEX = 0;
            GLint VertexBuffer::SIZE = 3;

            VertexBuffer::VertexBuffer() {
            }

            VertexBuffer::VertexBuffer(bool const& generate) : ArrayBuffer::ArrayBuffer(generate) {
            }

            VertexBuffer::VertexBuffer(VertexBuffer const& buf) : ArrayBuffer::ArrayBuffer(buf) {
            }

            VertexBuffer::~VertexBuffer() {
            }

            GLint const VertexBuffer::getSize() const {
                return SIZE;
            }

            void VertexBuffer::access(GLenum const& type, bool const& enableVAA) {
                ArrayBuffer::access(type, INDEX, SIZE, enableVAA);
            }

        };
    };
