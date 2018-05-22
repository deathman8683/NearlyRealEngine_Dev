
    #include "NRE_RegionsManager.hpp"

    namespace NRE {
        namespace World {

            RegionsManager::RegionsManager() {
            }

            RegionsManager::RegionsManager(RegionsManager const& rm) {
            }

            RegionsManager::RegionsManager(RegionsManager && rm) {
            }

            RegionsManager::~RegionsManager() {
            }

            RegionsManager& RegionsManager::operator=(RegionsManager const& rm) {
                return *this;
            }

            RegionsManager& RegionsManager::operator=(RegionsManager && rm) {
                return *this;
            }

        };
    };
