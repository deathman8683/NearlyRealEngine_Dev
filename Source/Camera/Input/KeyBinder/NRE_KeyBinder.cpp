
    #include "NRE_KeyBinder.hpp"

    namespace NRE {
        namespace Input {

            KeyBinder::KeyBinder() {
            }

            KeyBinder::KeyBinder(size_t const& n) : keyMap(n) {
            }

            KeyBinder::KeyBinder(KeyBinder const& map) : keyMap(map.getKeyMap()) {
            }

            KeyBinder::~KeyBinder() {
            }

            std::unordered_map<unsigned int, Key> const& KeyBinder::getKeyMap() const {
                return keyMap;
            }

            void KeyBinder::setKeyMap(std::unordered_map<unsigned int, Key> const& map) {
                keyMap = map;
            }

        };
    };
