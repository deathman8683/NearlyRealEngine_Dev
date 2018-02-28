
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
         * @namespace Input
         * @brief Engine's Input Module
         */
        namespace Input {

            /**
             * @class KeyBinder
             * @brief Input's Object : Base component for a specialized input system
             */
            class KeyBinder {
                protected:
                    std::unordered_map<unsigned int, Key> keyMap;

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

                    //## Setter ##//
                    void setKeyMap(std::unordered_map<unsigned int, Key> const& map);

                    //## Methods ##//
                    void insert(unsigned int const& code, Key const& k);
                    void swap(unsigned int const& first, unsigned int const& second);
                    void save(std::string const& path);
                    void load(std::string const& path);

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

            std::ostream& operator<<(std::ostream &stream, KeyBinder const& map);

        };
    };
