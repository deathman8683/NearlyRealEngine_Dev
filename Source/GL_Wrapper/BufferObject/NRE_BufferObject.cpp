
    #include "NRE_BufferObject.hpp"

    namespace NRE {
        namespace GL {

            BufferObject::BufferObject() : allocated(false) {
            }

            BufferObject::BufferObject(BufferObject const& buf) : allocated(buf.isAllocated()) {
            }

            BufferObject::~BufferObject() {
            }

            bool const& BufferObject::isAllocated() const {
                return allocated;
            }

            void BufferObject::setAllocated(bool const& state) {
                allocated = state;
            }

        };
    };
