
    /**
     * @file NRE_Keyboard.hpp
     * @brief Declaration of Engine's Input's Object : Keyboard
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../KeyBinder/NRE_KeyBinder.hpp"

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
             * @class Keyboard
             * @brief Input's Object : A particular input system
             */
            class Keyboard : public KeyBinder  {
                private:

                public:
                    //## Constructor ##//
                    Keyboard();

                    //## Copy-Constructor ##//
                    Keyboard(Keyboard const& kb);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Keyboard();

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
