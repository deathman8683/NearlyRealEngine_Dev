
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
                    bool quit;  /**< Quit state, used to quit the application */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        EventHandler();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the event handler to copy the content
                         */
                        EventHandler(EventHandler const& e);

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the event handler to move
                         */
                        EventHandler(EventHandler && e);

                    //## Convertor ##//
                        /**
                         * Convert a wrapped SDL event into a more advanced event handler
                         * @param e the wrapped SDL event
                         */
                        EventHandler(SDL::Event const& e);

                    //## Deconstructor ##//
                        /**
                         * EventHandler Deconstructor
                         */
                         virtual ~EventHandler();

                    //## Getter ##//
                        /**
                         * Quit state getter
                         * @return the quit state value
                         */
                        bool const& getQuit() const;

                    //## Setter ##//
                        /**
                         * Quit state setter
                         * @param state the new quit state value
                         */
                        void setQuit(bool const& state);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the event handler to copy into this
                         * @return the reference of himself
                         */
                        EventHandler& operator=(EventHandler const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the event handler to move into this
                         * @return the reference of himself
                         */
                        EventHandler& operator=(EventHandler && e);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
