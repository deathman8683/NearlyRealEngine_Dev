
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

            void KeyBinder::save(std::string const& path) {
                std::ofstream binderFile;
                binderFile.open(path, std::ios::out);
                if (binderFile.is_open()) {
                    for (unsigned int i = 0; i!= getKeyMap().size(); i = i + 1) {
                        auto it = getKeyMap().find(i);
                        binderFile << it->second.getCode() << ":" << it->second.isSwitch() << std::endl;
                    }
                }
            }

            void KeyBinder::load(std::string const& path) {
                std::ifstream binderFile;
                binderFile.open(path, std::ios::in | std::ios::out);
                if (binderFile.is_open()) {
                    std::string line;
                    unsigned int lineCounter = 0;
                    while (!binderFile.eof()) {
                        unsigned int code, isSwitch;
                        std::string separator;

                        std::getline(binderFile, line);
                        std::istringstream parser(line);
                        parser >> code >> isSwitch;

                        insert(lineCounter, Key(code, false, isSwitch));
                        lineCounter = lineCounter + 1;
                    }
                }
            }

            std::unordered_map<unsigned int, Key>::iterator KeyBinder::operator[](unsigned int const& code) {
                return keyMap.find(code);
            }

            std::ostream& operator<<(std::ostream &stream, KeyBinder const& map) {
                for (unsigned int i = 0; i != map.getKeyMap().size(); i = i + 1) {
                    auto it = map.getKeyMap().find(i);
                    stream << "(" << it->first << " | " << it->second << ")" << std::endl;
                }
                return stream;
            }

        };
    };
