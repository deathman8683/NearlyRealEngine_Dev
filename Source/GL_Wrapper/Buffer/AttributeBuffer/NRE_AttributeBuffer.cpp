
    #include "NRE_AttributeBuffer.hpp"

    namespace NRE {
        namespace GL {

            AttributeBuffer::AttributeBuffer() {
            }

            AttributeBuffer::AttributeBuffer(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            AttributeBuffer::AttributeBuffer(AttributeBuffer && buf) : Buffer::Buffer(std::move(buf)) {
            }

            AttributeBuffer::~AttributeBuffer() {
                deleteID();
            }

            void AttributeBuffer::generateID() {
                glGenBuffers(1, &id);
            }

            void AttributeBuffer::deleteID() {
                glDeleteBuffers(1, &id);
            }

            void AttributeBuffer::bind() const {
                glBindBuffer(getTarget(), getID());
            }

            void AttributeBuffer::unbind() const {
                glBindBuffer(getTarget(), 0);
            }

            void AttributeBuffer::allocate(GLsizeiptr const& size, GLenum const& usage) const {
                bind();
                    glBufferData(getTarget(), size, 0, usage);
                unbind();
            }

            void AttributeBuffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const {
                bind();
                    glBufferSubData(getTarget(), offset, size, data);
                unbind();
            }

            void AttributeBuffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const {
                bind();
                    glBufferData(getTarget(), size, data, usage);
                unbind();
            }

            AttributeBuffer& AttributeBuffer::operator=(AttributeBuffer && buf) {
                Buffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
