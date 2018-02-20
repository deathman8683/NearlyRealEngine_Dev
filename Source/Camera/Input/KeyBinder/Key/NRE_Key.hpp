
    /**
     * @file NRE_Key.hpp
     * @brief Declaration of Engine's Input's Object : Key
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Generic/NRE_Type.hpp"

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
             * @brief Input's Object : Base component for KeyBinder
             */
            class Key {
                private:
                    unsigned int code;
                    bool state;
                    bool switchKey;

                public:
                    //## Constructor ##//
                    Key();
                    Key(unsigned int const& code, bool const& state, bool const& switchKey);

                    //## Copy-Constructor ##//
                    Key(Key const& k);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Key();

                    //## Getter ##//
                    unsigned int const& getCode() const;
                    bool const& getState() const;
                    bool const& isSwitch() const;

                    //## Setter ##//
                    void setCode(unsigned int const& code);
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
