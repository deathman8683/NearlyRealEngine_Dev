
    /**
     * @file NRE_Clock.hpp
     * @brief Declaration of Engine's Time's Object : Clock
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../AdvancedDate/NRE_AdvancedDate.hpp"
    #include "../Timestep/NRE_Timestep.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Time
         * @brief Engine's Time's Module
         */
        namespace Time {

            /**
             * @class Clock
             * @brief Time's Object : Manage time in application
             */
            class Clock : public AdvancedDate, public Timestep {
                private:

                public:
                    //## Constructor ##//
                    Clock();

                    //## Copy-Constructor ##//
                    Clock(Clock const& c);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Clock();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void updateTimestep(NREfloat const& minTimestep);
                    void updateTime(bool const& convert);

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
