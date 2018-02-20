
    /**
     * @file NRE_Key.hpp
     * @brief Declaration of Engine's Input's Object : Key
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "<Path>/Generic/NRE_Type.hpp"

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
             * @class Key
             * @brief Input's Object : Base composant for input, a key
             */
            class Key {
                private:
                    bool state;
                    bool isSwitch;

                public:
                    //## Constructor ##//
                    Key();
                    Key(bool const& state, bool const& isSwitch);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
