
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
                        /**
                         * Default Constructor
                         */
                        Clock();

                    //## Copy-Constructor ##//
                        /**
                         * Copy c into this
                         * @param c the clock to copy the content
                         */
                        Clock(Clock const& c);

                    //## Move-Constructor ##//
                        /**
                         * Move c into this, leaving c empty
                         * @param c the clock to move
                         */
                        Clock(Clock && c);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Clock Deconstructor
                         */
                        ~Clock();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Update the timestep with a minimum timestep to get, freeze the program if inferior
                         * @param minTimestep the minimum timestep
                         */
                        void updateTimestep(NREfloat const& minTimestep);
                        /**
                         * Update the clock's date
                         * @param convert tell if the object have to convert the ms value into a date
                         */
                        void updateTime(bool const& convert);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of c into this
                         * @param c the clock to copy into this
                         * @return the reference of himself
                         */
                        Clock& operator=(Clock const& c);
                        /**
                         * Move assigment of c into this, leaving c empty
                         * @param c the clock to move into this
                         * @return the reference of himself
                         */
                        Clock& operator=(Clock && c);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
