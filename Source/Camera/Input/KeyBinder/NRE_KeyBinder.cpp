
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
                keyMap.erase(keyMap.begin(), keyMap.end());
            }

            std::unordered_map<unsigned int, Key> const& KeyBinder::getKeyMap() const {
                return keyMap;
            }

            void KeyBinder::setKeyMap(std::unordered_map<unsigned int, Key> const& map) {
                keyMap = map;
            }

            void KeyBinder::insert(unsigned int const& code, Key const& k) {
                keyMap.insert({code, k});
            }

            void KeyBinder::swap(unsigned int const& first, unsigned int const& second) {
                Key tmp(keyMap[first]);
                keyMap[first] = keyMap[second];
                keyMap[second] = tmp;
            }

            Key& KeyBinder::operator[](unsigned int const& code) {
                return keyMap[code];
            }

            std::ostream& operator<<(std::ostream &stream, KeyBinder const& map) {
                for (unsigned int i = 0; i != map.getKeyMap().size(); i = i + 1) {
                    for (auto it = map.getKeyMap().begin(i); it != map.getKeyMap().end(i); ++it) {
                        stream << "(" << it->first << " | " << it->second << ")";
                    }
                    stream << std::endl;
                }
                return stream;
            }

        };
    };
