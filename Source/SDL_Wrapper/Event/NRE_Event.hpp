
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
                    Event();

                    //## Copy-Constructor ##//
                    Event(Event const& e);

                    //## Convertor ##//
                    Event(SDL_Event const& e);

                    //## Deconstructor ##//
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
                    void setItem(SDL_Event const& e);

                    //## Methods ##//
                    virtual int poll();
                    virtual int wait();

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
