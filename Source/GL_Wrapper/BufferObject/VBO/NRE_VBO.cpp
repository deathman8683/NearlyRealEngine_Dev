
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::~VBO(){
                std::cout << "Derived deconstructor" << std::endl;
            }

        };
    };
