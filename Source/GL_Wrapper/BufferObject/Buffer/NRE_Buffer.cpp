
    #include "NRE_Buffer.hpp"

    namespace NRE {
        namespace GL {

            Buffer::Buffer() {
            }

            Buffer::Buffer(Buffer const& buf) : id(buf.getID()) {
            }

            Buffer::~Buffer() {
            }

            GLuint const& Buffer::getID() const {
                return id;
            }

            void Buffer::setID(GLuint const& id) {
                this->id = id;
            }

            void ColorBuffer::allocate(GLenum const& target, GLsizeiptr const& size, GLenum const& usage) {
                bind(target);
                glBufferData(target, size, NULL, usage);
                unbind(target);
            }

            void ColorBuffer::update(GLenum const& target, GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) {
                bind(target);
                glBufferSubData(target, offset, size, data);
                unbind(target);
            }

            void Buffer::bind(GLenum const& target) {
                glBindBuffer(target, id);
            }

            void Buffer::unbind(GLenum const& target) {
                glBindBuffer(target, 0);
            }

            std::ostream& operator<<(std::ostream &stream, Buffer const& buf) {
                stream << "(" << buf.getID() << ")";
                return stream;
            }

        };
    };
