
    #include "NRE_LightsManager.hpp"

    namespace NRE {
        namespace Light {

            std::vector<Light>* LightsManager::lights = 0;

            void LightsManager::init() {
                lights = new std::vector<Light>;
            }

            void LightsManager::free() {
                delete lights;
            }

            void LightsManager::push_back(Light && l) {
                lights->push_back(std::move(l));
            }

        };
    };
