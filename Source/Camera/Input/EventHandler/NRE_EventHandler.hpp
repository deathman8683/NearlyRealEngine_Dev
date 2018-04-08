
    /**
     * @file NRE_EventHandler.hpp
     * @brief Declaration of Engine's Input's Object : EventHandler
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../SDL_Wrapper/Event/NRE_Event.hpp"

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
             * @class EventHandler
             * @brief Input's Object : Handle event
             */
            class EventHandler : public SDL::Event {
                private:
                    bool quit;

                public:
                    //## Constructor ##//
                    EventHandler();

                    //## Copy-Constructor ##//
                    EventHandler(EventHandler const& e);

                    //## Convertor ##//
                    EventHandler(SDL::Event const& e);

                    //## Deconstructor ##//
                    virtual ~EventHandler();

                    //## Getter ##//
                    bool const& getQuit() const;

                    //## Setter ##//
                    void setQuit(bool const& state);

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
