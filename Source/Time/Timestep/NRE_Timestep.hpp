
    /**
     * @file NRE_Timestep.hpp
     * @brief Declaration of Engine's Time's Object : Timestep
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

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
             * @class Timestep
             * @brief Time's Object : A timestep between 2 moment
             */
            class Timestep {
                private:
                    NREfloat actualTime;    /**< Actual time */
                    NREfloat lastTime;      /**< The last "actual time" */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Timestep();

                    //## Copy-Constructor ##//
                        /**
                         * Copy t into this
                         * @param t the timestep to copy the content
                         */
                        Timestep(Timestep const& t);

                    //## Move-Constructor ##//
                        /**
                         * Move t into this, leaving t empty
                         * @param t the timestep to move
                         */
                        Timestep(Timestep && t);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Timestep Deconstructor
                         */
                        virtual ~Timestep();

                    //## Getter ##//
                        /**
                         * Actual time getter
                         * @return the timestep's actual time
                         */
                        NREfloat const& getActualTime() const;
                        /**
                         * Last time getter
                         * @return the timestep's last time
                         */
                        NREfloat const& getLastTime() const;
                        /**
                         * Timestep getter
                         * @return the computed timestep (difference between the actual and the last time)
                         */
                        NREfloat const getTimestep() const;

                    //## Setter ##//
                        /**
                         * Actual time setter
                         * @param t the new actual time value
                         */
                        void setActualTime(NREfloat const& t);
                        /**
                         * Last time setter
                         * @param t the new last time value
                         */
                        void setLastTime(NREfloat const& t);

                    //## Methods ##//
                        /**
                         * Update the last time with the current actual time value
                         */
                        void updateLastTime();
                        /**
                         * Update the actual time with an SDL command
                         */
                        void updateActualTime();
                        /**
                         * Update both actual and last time
                         */
                        virtual void update();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of t into this
                         * @param t the timestep to copy into this
                         * @return the reference of himself
                         */
                        Timestep& operator=(Timestep const& t);
                        /**
                         * Move assigment of t into this, leaving t empty
                         * @param t the timestep to move into this
                         * @return the reference of himself
                         */
                        Timestep& operator=(Timestep && t);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
