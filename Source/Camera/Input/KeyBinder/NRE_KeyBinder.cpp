
    #include "NRE_KeyBinder.hpp"

    namespace NRE {
        namespace Input {

            KeyBinder::KeyBinder() {
            }

            KeyBinder::KeyBinder(size_t const& n) : keyMap(n) {
            }

            KeyBinder::KeyBinder(size_t const& n, std::string const& path) : keyMap(n) {
                load(path);
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

            void KeyBinder::save(std::string const& path) {
                std::ofstream binderFile;
                binderFile.open(path, std::ios::out);
                if (binderFile.is_open()) {
                    for (unsigned int i = 0; i < getKeyMap().size() - 1; i = i + 1) {
                        auto it = getKeyMap().find(i);
                        binderFile << it->second.getCode() << ' ' << it->second.isSwitch() << ' ';
                    }
                    auto it = getKeyMap().find(getKeyMap().size() - 1);
                    binderFile << it->second.getCode() << ' ' << it->second.isSwitch();
                }
            }

            void KeyBinder::load(std::string const& path) {
                std::ifstream binderFile;
                binderFile.open(path, std::ios::in);
                if (binderFile.is_open()) {
                    std::string line;
                    std::getline(binderFile, line);
                    GLuint code, isSwitch, lineCounter = 0;
                    std::istringstream parser(line);
                    while (parser.rdbuf()->in_avail() > 0) {
                        parser >> code >> isSwitch;

                        insert(lineCounter, Key(code, false, isSwitch));
                        lineCounter = lineCounter + 1;
                    }
                }
            }

            std::unordered_map<unsigned int, Key>::iterator KeyBinder::operator[](unsigned int const& code) {
                return keyMap.find(code);
            }

        };
    };
