
    /**
     * @file NRE_KeyBinder.hpp
     * @brief Declaration of Engine's Input's Object : KeyBinder
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include <unordered_map>
    #include "../../../Generic/NRE_Type.hpp"
    #include "Key/NRE_Key.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Camera
         * @brief Engine's Camera Module
         */
        namespace Camera {

            /**
             * @class KeyBinder
             * @brief Input's Object : Base component for a specialized input system
             */
            class KeyBinder {
                protected:
                    std::unordered_map<unsigned int, Key> keyMap;
                    std::unordered_map<unsigned int, Key*> activeKeys;

                public:
                    //## Constructor ##//
                    KeyBinder();
                    KeyBinder(size_t const& n);
                    KeyBinder(size_t const& n, std::string const& path);

                    //## Copy-Constructor ##//
                    KeyBinder(KeyBinder const& map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~KeyBinder();

                    //## Getter ##//
                    std::unordered_map<unsigned int, Key> const& getKeyMap() const;
                    std::unordered_map<unsigned int, Key*> const& getActiveKeys() const;

                    //## Setter ##//
                    void setKeyMap(std::unordered_map<unsigned int, Key> const& map);
                    void setActiveKeys(std::unordered_map<unsigned int, Key*> const& keys);

                    //## Methods ##//
                    void insert(unsigned int const& code, Key const& k);
                    void swap(unsigned int const& first, unsigned int const& second);
                    void save(std::string const& path);
                    void load(std::string const& path);
                    void keyDown(unsigned int const& code);
                    void keyUp(unsigned int const& code);
                    void execute();

                    //## Access Operator ##//
                    std::unordered_map<unsigned int, Key>::iterator operator[](unsigned int const& code);

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, KeyBinder const& map) {
                for (unsigned int i = 0; i != map.getKeyMap().size(); i = i + 1) {
                    auto it = map.getKeyMap().find(i);
                    stream << "(" << it->first << " | " << it->second << ")" << std::endl;
                }
                return stream;
            }

        };
    };
