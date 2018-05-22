
    #include "NRE_EngineLights.hpp"

    namespace NRE {
        namespace Light {

            std::vector<Light>* EngineLights::lights = 0;

            void EngineLights::init() {
                lights = new std::vector<Light>;
            }

            void EngineLights::free() {
                delete lights;
            }

            void EngineLights::push_back(Light && l) {
                lights->push_back(std::move(l));
            }

        };
    };
