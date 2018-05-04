
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
                        /**
                         * Default Constructor
                         */
                        PointLight();
                        /**
                         * Construct a point light from his position and color
                         * @param coord the light's position
                         * @param color the light's color
                         */
                        PointLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color);

                    //## Copy-Constructor ##//
                        /**
                         * Copy l into this
                         * @param l the point light to copy the content
                         */
                        PointLight(PointLight const& l);

                    //## Move-Constructor ##//
                        /**
                         * Move l into this, leaving l empty
                         * @param l the point light to move
                         */
                        PointLight(PointLight && l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * PointLight Deconstructor
                         */
                        ~PointLight();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of l into this
                         * @param l the point light to copy into this
                         * @return the reference of himself
                         */
                        PointLight& operator=(PointLight const& l);
                        /**
                         * Move assigment of l into this, leaving l empty
                         * @param l the point light to move into this
                         * @return the reference of himself
                         */
                        PointLight& operator=(PointLight && l);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
