
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
                    Input();
                    Input(std::string const& kbPath, std::string const& mPath);
                    Input(Keyboard const& kb, Mouse const& m, EventHandler const& e);

                    //## Copy-Constructor ##//
                    Input(Input const& in);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Input();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void update(Maths::Vector2D<NREfloat>* cameraAngle);

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
