
    /**
     * @file NRE_Key.hpp
     * @brief Declaration of Engine's Input's Object : Key
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Generic/NRE_Type.hpp"

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
             * @class Key
             * @brief Input's Object : Base component for KeyBinder
             */
            class Key {
                private:
                    bool active;        /**< Tell if the key is pressed or not */
                    bool switchKey;     /**< Tell if the key have to pressed again to switch his state */
                    BaseCommand* action;/**< The command activated by the key when active */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Key();
                        /**
                         * Construct a key with passed attributes
                         * @param active    the base state of the key
                         * @param switchKey if the key is a switch or not
                         * @param cmd       the key command, can be null
                         */
                        Key(bool const& active, bool const& switchKey, BaseCommand* cmd);

                    //## Copy-Constructor ##//
                        /**
                         * Copy k into this
                         * @param k the key to copy the content
                         */
                        Key(Key const& k);

                    //## Move-Constructor ##//
                        /**
                         * Move k into this, leaving k empty
                         * @param k the key to move
                         */
                        Key(Key && k);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Key Deconstructor
                         */
                        ~Key();

                    //## Getter ##//
                        /**
                         * Active state getter
                         * @return the active state value
                         */
                        bool const& isActive() const;
                        /**
                         * Switch state getter
                         * @return the switch state value
                         */
                        bool const& isSwitch() const;
                        /**
                         * Command getter
                         * @return the key's command
                         */
                        BaseCommand* const getAction() const;

                    //## Setter ##//
                        /**
                         * Active state setter
                         * @param state the new active state value
                         */
                        void setActive(bool const& state);
                        /**
                         * Switch state setter
                         * @param state the new switch state value
                         */
                        void setSwitch(bool const& state);
                        /**
                         * Command setter
                         * @param cmd the new key's command
                         */
                        void setAction(BaseCommand* cmd);
                        /**
                         * Execute the key's command if not null
                         */
                        void execute();

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of k into this
                         * @param k the key to copy into this
                         * @return the reference of himself
                         */
                        Key& operator=(Key const& k);
                        /**
                         * Move assigment of k into this, leaving k empty
                         * @param k the key to move into this
                         * @return the reference of himself
                         */
                        Key& operator=(Key && k);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for Key
             * @param stream the out stream to add the key k
             * @param k the chunk to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, Key const& k) {
                stream << "(" << "," << k.isActive() << "," << k.isSwitch() << ")";
                return stream;
            }

        };
    };
