
    #include "NRE_KeyBinder.hpp"

    namespace NRE {
        namespace Camera {

            KeyBinder::KeyBinder(size_t const& n) : keyMap(n) {
                for (GLuint i = 0; i < n; i = i + 1) {
                    keyMap.emplace(i, Key());
                }
            }

            KeyBinder::KeyBinder(KeyBinder const& map) : keyMap(map.keyMap), activeKeys(map.activeKeys) {
            }

            KeyBinder::KeyBinder(KeyBinder && map) : keyMap(std::move(map.keyMap)), activeKeys(std::move(map.activeKeys)) {
            }

            KeyBinder::~KeyBinder() {
                keyMap.erase(keyMap.begin(), keyMap.end());
                activeKeys.erase(activeKeys.begin(), activeKeys.end());
            }

            Key& KeyBinder::getKey(unsigned int const& code) {
                return keyMap.at(code);
            }

            Key const& KeyBinder::getKey(unsigned int const& code) const {
                return keyMap.at(code);
            }

            void KeyBinder::insert(unsigned int const& code, Key const& k) {
                keyMap.insert({code, k});
            }

            void KeyBinder::swap(unsigned int const& first, unsigned int const& second) {
                Key tmp(keyMap[first]);
                keyMap[first] = keyMap[second];
                keyMap[second] = tmp;
            }

            void KeyBinder::keyDown(unsigned int const& code) {
                Key& tmp = keyMap.at(code);
                if (tmp.isSwitch()) {
                    tmp.setActive(!tmp.isActive());
                    if (tmp.isActive()) {
                        activeKeys.insert({code, &tmp});
                    } else {
                        activeKeys.erase(code);
                    }
                } else {
                    activeKeys.insert({code, &tmp});
                    tmp.setActive(true);
                }
            }

            void KeyBinder::keyUp(unsigned int const& code) {
                Key& tmp = keyMap.at(code);
                if (!tmp.isSwitch()) {
                    activeKeys.erase(code);
                    tmp.setActive(false);
                }
            }

            void KeyBinder::execute() {
                for (auto& it : activeKeys) {
                    it.second->execute();
                }
            }

            size_t const KeyBinder::size() const {
                return keyMap.size();
            }

            KeyBinder& KeyBinder::operator=(KeyBinder const& map) {
                keyMap = map.keyMap;
                activeKeys = map.activeKeys;
                return *this;
            }

            KeyBinder& KeyBinder::operator=(KeyBinder && map) {
                keyMap = std::move(map.keyMap);
                activeKeys = std::move(map.activeKeys);
                return *this;
            }

        };
    };
