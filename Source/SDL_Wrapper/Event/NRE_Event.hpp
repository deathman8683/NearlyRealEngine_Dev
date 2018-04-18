
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
                         * @param e the C-stule SDL_Event
                         */
                        Event(SDL_Event const& e);

                    //## Deconstructor ##//
                        /**
                         * Event Deconstructor
                         */
                        virtual ~Event();

                    //## Getter ##//
                        SDL_Event const& getItem() const;
                        Uint32 const& getType() const;
                        SDL_Scancode const& getKeyScancode() const;
                        SDL_Keycode const& getKeyKeycode() const;
                        Uint8 const& getMouseButton() const;
                        Maths::Point2D<unsigned short int> const getMouseClick() const;
                        Maths::Point2D<unsigned short int> const getMotion() const;
                        Maths::Vector2D<NREfloat> const getMotionRel() const;
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
