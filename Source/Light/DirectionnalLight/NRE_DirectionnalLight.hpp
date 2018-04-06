
    /**
     * @file NRE_DirectionnalLight.hpp
     * @brief Declaration of Engine's Light's Object : DirectionnalLight
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../SpotLight/NRE_SpotLight.hpp"

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
             * @class DirectionnalLight
             * @brief Light's Object : A specialized version of Light to manage directionnal light
             */
            class DirectionnalLight : public SpotLight {
                private:

                public:
                    //## Constructor ##//
                    DirectionnalLight();
                    DirectionnalLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction);

                    //## Copy-Constructor ##//
                    DirectionnalLight(DirectionnalLight const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~DirectionnalLight();

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
