
    /**
     * @file NRE_PointLight.hpp
     * @brief Declaration of Engine's Light's Object : PointLight
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
             * @class PointLight
             * @brief Light's Object : A specialized version of Light to manage point light
             */
            class PointLight : public Light {
                private:

                public:
                    //## Constructor ##//
                    PointLight();
                    PointLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color);

                    //## Copy-Constructor ##//
                    PointLight(PointLight const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~PointLight();

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
