
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

            void Buffer::allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target) {
                bind(target);
                glBufferData(target, size, NULL, usage);
                unbind(target);
            }

            void Buffer::update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target) {
                bind(target);
                glBufferSubData(target, offset, size, data);
                unbind(target);
            }

            void Buffer::allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target) {
                bind(target);
                glBufferData(target, size, data, usage);
                unbind(target);
            }

            void Buffer::bind(GLenum const& target) const {
                glBindBuffer(target, id);
            }

            void Buffer::unbind(GLenum const& target) const {
                glBindBuffer(target, 0);
            }

            std::ostream& operator<<(std::ostream &stream, Buffer const& buf) {
                stream << "(" << buf.getID() << ")";
                return stream;
            }

        };
    };
