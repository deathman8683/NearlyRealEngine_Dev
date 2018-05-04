
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
         * @namespace Camera
         * @brief Engine's Camera Module
         */
        namespace Camera {

            /**
             * @class Keyboard
             * @brief Input's Object : A particular input system
             */
            class Keyboard : public KeyBinder  {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Keyboard();

                    //## Copy-Constructor ##//
                        /**
                         * Copy kb into this
                         * @param kb the keyboard to copy the content
                         */
                        Keyboard(Keyboard const& kb);

                    //## Move-Constructor ##//
                        /**
                         * Move kb into this, leaving kb empty
                         * @param kb the keyboard to move
                         */
                        Keyboard(Keyboard && kb);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Keyboard Deconstructor
                         */
                        virtual ~Keyboard();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of kb into this
                         * @param kb the keyboard to copy into this
                         * @return the reference of himself
                         */
                        Keyboard& operator=(Keyboard const& kb);
                        /**
                         * Move assigment of kb into this, leaving kb empty
                         * @param kb the keyboard to move into this
                         * @return the reference of himself
                         */
                        Keyboard& operator=(Keyboard && kb);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
