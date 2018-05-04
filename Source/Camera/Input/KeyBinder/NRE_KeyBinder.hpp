
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
                    std::unordered_map<unsigned int, Key> keyMap;       /**< Hash map of input key */
                    std::unordered_map<unsigned int, Key*> activeKeys;  /**< Hash map with active (pressed) input key */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        KeyBinder();
                        /**
                         * Construct a keyBinder with n key inside the keyMap
                         * @param n the number of key at construction
                         */
                        KeyBinder(size_t const& n);

                    //## Copy-Constructor ##//
                        /**
                         * Copy map into this
                         * @param map the keyBinder to copy the content
                         */
                        KeyBinder(KeyBinder const& map);

                    //## Move-Constructor ##//
                        /**
                         * Move map into keyBinder, leaving map empty
                         * @param map the key to move
                         */
                        KeyBinder(KeyBinder && map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * KeyBinder Deconstructor
                         */
                        virtual ~KeyBinder();

                    //## Getter ##//
                        /**
                         * Specific key getter
                         * @param  code the key's code
                         * @return      the corresponding key, modifiable
                         */
                        Key& getKey(unsigned int const& code);
                        /**
                         * Specific key getter
                         * @param  code the key's code
                         * @return      the corresponding key, not modifiable
                         */
                        Key const& getKey(unsigned int const& code) const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Insert a new key in the map
                         * @param code the key's code
                         * @param k    the key to add
                         */
                        void insert(unsigned int const& code, Key const& k);
                        /**
                         * Swap to key in the keyBinder
                         * @param first  the first key's code
                         * @param second the second key's code
                         */
                        void swap(unsigned int const& first, unsigned int const& second);
                        /**
                         * Manage keyDown event
                         * @param code the pressed key
                         */
                        void keyDown(unsigned int const& code);
                        /**
                         * Manage keyUp event
                         * @param code the released key
                         */
                        void keyUp(unsigned int const& code);
                        /**
                         * Execute all actives key's commands
                         */
                        void execute();
                        /**
                         * KeyBinder size
                         * @return the number of key in the keyBinder
                         */
                        size_t const size() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of map into this
                         * @param map the keyBinder to copy into this
                         * @return the reference of himself
                         */
                        KeyBinder& operator=(KeyBinder const& map);
                        /**
                         * Move assigment of map into this, leaving map empty
                         * @param map the keyBinder to move into this
                         * @return the reference of himself
                         */
                        KeyBinder& operator=(KeyBinder && map);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for KeyBinder
             * @param stream the out stream to add the keyBinder map
             * @param map the keyBinder to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, KeyBinder const& map) {
                for (unsigned int i = 0; i != map.size(); i = i + 1) {
                    stream << "(" << i << " | " << map.getKey(i) << ")" << std::endl;
                }
                return stream;
            }

        };
    };
