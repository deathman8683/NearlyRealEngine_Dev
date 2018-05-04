
    /**
     * @file NRE_Input.hpp
     * @brief Declaration of Engine's Input's Object : Input
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "Keyboard/NRE_Keyboard.hpp"
    #include "Mouse/NRE_Mouse.hpp"
    #include "EventHandler/NRE_EventHandler.hpp"

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
             * @class Input
             * @brief Input's Object : Manage input system
             */
            class Input : public Keyboard, public Mouse, public EventHandler {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Input();
                        /**
                         * Construct an input system with different base object
                         * @param kb the input's keyboard
                         * @param m  the input's mouse
                         * @param e  the input's event handler
                         */
                        Input(Keyboard const& kb, Mouse const& m, EventHandler const& e);

                    //## Copy-Constructor ##//
                        /**
                         * Copy in into this
                         * @param in the input to copy the content
                         */
                        Input(Input const& in);

                    //## Move-Constructor ##//
                        /**
                         * Move in into this, leaving in empty
                         * @param in the input to move
                         */
                        Input(Input && in);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Input Deconstructor
                         */
                        virtual ~Input();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Update the input with his event handler, can update a camera angle passed
                         * @param cameraAngle if not null may be updated on mouse event
                         */
                        void update(Maths::Vector2D<NREfloat>* cameraAngle);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of in into this
                         * @param in the input to copy into this
                         * @return the reference of himself
                         */
                        Input& operator=(Input const& in);
                        /**
                         * Move assigment of in into this, leaving in empty
                         * @param in the input to move into this
                         * @return the reference of himself
                         */
                        Input& operator=(Input && in);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
