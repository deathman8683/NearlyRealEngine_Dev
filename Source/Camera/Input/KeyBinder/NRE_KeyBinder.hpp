
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

                    //## Copy-Constructor ##//
                    KeyBinder(KeyBinder const& map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~KeyBinder();

                    //## Getter ##//
                    Key& getKey(unsigned int const& code);
                    Key const& getKey(unsigned int const& code) const;

                    //## Setter ##//
                    void setKeyMap(std::unordered_map<unsigned int, Key> const& map);
                    void setActiveKeys(std::unordered_map<unsigned int, Key*> const& keys);

                    //## Methods ##//
                    void insert(unsigned int const& code, Key const& k);
                    void swap(unsigned int const& first, unsigned int const& second);
                    void keyDown(unsigned int const& code);
                    void keyUp(unsigned int const& code);
                    void execute();
                    size_t const size() const;

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
                for (unsigned int i = 0; i != map.size(); i = i + 1) {
                    stream << "(" << i << " | " << map.getKey(i) << ")" << std::endl;
                }
                return stream;
            }

        };
    };
