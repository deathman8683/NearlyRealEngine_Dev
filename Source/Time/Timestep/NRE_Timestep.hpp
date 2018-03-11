
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
                    NREfloat actualTime;
                    NREfloat lastTime;

                public:
                    //## Constructor ##//
                    Timestep();

                    //## Copy-Constructor ##//
                    Timestep(Timestep const& t);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Timestep();

                    //## Getter ##//
                    NREfloat const& getActualTime() const;
                    NREfloat const& getLastTime() const;
                    NREfloat const getTimestep() const;

                    //## Setter ##//
                    void setActualTime(NREfloat const& t);
                    void setLastTime(NREfloat const& t);

                    //## Methods ##//
                    void updateLastTime();
                    void updateActualTime();
                    virtual void update();

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
