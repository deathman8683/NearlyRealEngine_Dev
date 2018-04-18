
    /**
     * @file NRE_Event.hpp
     * @brief Declaration of Engine's SDL's Object : Event
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace SDL
         * @brief Engine's SDL's Wrapper's Module
         */
        namespace SDL {

            /**
             * @class Event
             * @brief SDL's Object : Wrapper of SDL_Event
             */
            class Event {
                private:
                    SDL_Event item;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Event();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the event to copy the content
                         */
                        Event(Event const& e);

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the event to move
                         */
                        Event(Event && e);

                    //## Convertor ##//
                        /**
                         * Convert a C-style SDL_Event into his wrapped version
                         * @param e the C-style SDL_Event
                         */
                        Event(SDL_Event const& e);

                    //## Deconstructor ##//
                        /**
                         * Event Deconstructor
                         */
                        virtual ~Event();

                    //## Getter ##//
                        /**
                         * Wrapped Item getter
                         * @return the wrapped item
                         */
                        SDL_Event const& getItem() const;
                        /**
                         * Event type getter
                         * @return the current event type
                         */
                        Uint32 const& getType() const;
                        /**
                         * Event key scancode getter
                         * @return the current event key scancode
                         */
                        SDL_Scancode const& getKeyScancode() const;
                        /**
                         * Event key keycode getter
                         * @return the current event key keycode
                         */
                        SDL_Keycode const& getKeyKeycode() const;
                        /**
                         * Event mouse button getter
                         * @return the current event mouse button
                         */
                        Uint8 const& getMouseButton() const;
                        /**
                         * Event mouse click position
                         * @return a point with the current event mouse click coordinate
                         */
                        Maths::Point2D<unsigned short int> const getMouseClick() const;
                        /**
                         * Event mouse cursor position
                         * @return a point with the current event mouse cursor coordinate
                         */
                        Maths::Point2D<unsigned short int> const getMotion() const;
                        /**
                         * Event mouse relative movement getter
                         * @return a size vector with the current event mouse relative movement
                         */
                        Maths::Vector2D<NREfloat> const getMotionRel() const;
                        /**
                         * Event mouse's which value, tell which controller as occured the event
                         * @return the controller code
                         */
                        Uint32 const& getMouseWhich() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Poll an event, wrap the sdl function
                         * @return the sdl function return value
                         */
                        virtual int poll();
                        /**
                         * Wait an event, wrap the sdl function
                         * @return the sdl function return value
                         */
                        virtual int wait();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the event to copy into this
                         * @return the reference of himself
                         */
                        Event& operator=(Event const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the event to move into this
                         * @return the reference of himself
                         */
                        Event& operator=(Event && e);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
