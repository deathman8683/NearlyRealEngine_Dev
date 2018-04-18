
    #include "NRE_Buffer.hpp"

    namespace NRE {
        namespace GL {

            Buffer::Buffer() : id(0) {
            }

            Buffer::Buffer(Buffer && buf) : id(std::move(buf.getID())) {
            }

            Buffer::~Buffer() {
            }

            GLuint const& Buffer::getID() const {
                return id;
            }

            void Buffer::reload() {
                deleteID();
                generateID();
            }

            Buffer& Buffer::operator=(Buffer && buf) {
                id = std::move(buf.getID());
                return *this;
            }

        };
    };
