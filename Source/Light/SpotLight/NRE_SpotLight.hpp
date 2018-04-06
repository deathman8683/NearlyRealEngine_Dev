
    /**
     * @file NRE_SpotLight.hpp
     * @brief Declaration of Engine's Light's Object : SpotLight
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Light.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Light
         * @brief Engine's Light Module
         */
        namespace Light {

            /**
             * @class SpotLight
             * @brief Light's Object : A specialized version of light to manage spot light
             */
            class SpotLight : public Light {
                private:

                public:
                    //## Constructor ##//
                    SpotLight();
                    SpotLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction, NREfloat const& ambientCoeff, NREfloat const& angle);

                    //## Copy-Constructor ##//
                    SpotLight(SpotLight const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~SpotLight();

                    //## Getter ##//

                    //## Setter ##//

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
