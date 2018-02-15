
    #include "NRE_Buffer.hpp"

    namespace NRE {
        namespace GL {

            Buffer::Buffer() {
            }

            Buffer::~Buffer() {
            }

            GLuint const& Buffer::getID() const {
                return id;
            }

            void Buffer::setID(GLuint const& id) {
                this->id = id;
            }

        };
    };
