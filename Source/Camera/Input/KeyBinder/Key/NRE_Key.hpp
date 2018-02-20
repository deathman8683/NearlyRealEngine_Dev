
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
                    SDL_Scancode code;
                    bool state;
                    bool isSwitch;

                public:
                    //## Constructor ##//
                    Key();
                    Key(SDL_Scancode const& code, bool const& state, bool const& isSwitch);

                    //## Copy-Constructor ##//
                    Key(Key const& k);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Key();

                    //## Getter ##//
                    SDL_Scancode const& getCode() const;
                    bool const& getState() const;
                    bool const& isSwitch() const;

                    //## Setter ##//
                    void setCode(SDL_Scancode const& code);
                    void setState(bool const& state);
                    void setSwitch(bool const& state);

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
