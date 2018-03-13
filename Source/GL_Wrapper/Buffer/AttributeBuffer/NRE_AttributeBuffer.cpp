
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

            AttributeBuffer::AttributeBuffer(AttributeBuffer const& buf) : Buffer::Buffer(buf) {
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

            void AttributeBuffer::bind(GLenum const& target) const {
                glBindBuffer(target, getID());
            }

            void AttributeBuffer::unbind(GLenum const& target) const {
                glBindBuffer(target, 0);
            }

            void AttributeBuffer::allocate(GLenum const& target, GLsizeiptr const& size, GLenum const& usage) const {
                bind(target);
                    glBufferData(target, size, 0, usage);
                unbind(target);
            }

            void AttributeBuffer::update(GLenum const& target, GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const {
                bind(target);
                    glBufferSubData(target, offset, size, data);
                unbind(target);
            }

            void AttributeBuffer::allocateAndFill(GLenum const& target, GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const {
                bind(target);
                    glBufferData(target, size, data, usage);
                unbind(target);
            }

        };
    };
