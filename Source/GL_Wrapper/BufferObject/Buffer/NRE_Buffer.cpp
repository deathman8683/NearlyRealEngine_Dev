
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

            void Buffer::bind() {
                glBindBuffer(id);
            }

            void Buffer::unbind() {
                glBindBuffer(0);
            }

        };
    };
