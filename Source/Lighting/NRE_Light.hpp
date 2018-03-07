
    /**
     * @file NRE_Light.hpp
     * @brief Declaration of Engine's Light's Object : Light
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Generic/NRE_Type.hpp"
    #include "../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Light
         * @brief <Module_Desc>
         */
        namespace Light {

            /**
             * @class Light
             * @brief Light's Object : <Class_Desc>
             */
            class Light {
                private:
                    NREfloat position[3];
                    NREfloat intensities[3];

                public:
                    //## Constructor ##//
                    Light();
                    Light(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color);

                    //## Copy-Constructor ##//
                    Light(Light const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Light();

                    //## Getter ##//
                    Maths::Point3D<NREfloat> getPosition() const;
                    Maths::Vector3D<NREfloat> getIntensities() const;
                    NREfloat* const getPositionValue();
                    NREfloat* const getIntensitiesValue();

                    //## Setter ##//
                    void setPosition(Maths::Point3D<NREfloat> const& p);
                    void setIntensities(Maths::Vector3D<NREfloat> const& color);

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
