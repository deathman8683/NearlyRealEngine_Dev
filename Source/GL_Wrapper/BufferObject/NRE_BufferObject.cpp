
    #include "NRE_BufferObject.hpp"

    namespace NRE {
        namespace GL {

            BufferObject::BufferObject() : allocated(false) {
            }

            BufferObject::~BufferObject(){
                std::cout << "Base deconstructor" << std::endl;
            }

        };
    };
