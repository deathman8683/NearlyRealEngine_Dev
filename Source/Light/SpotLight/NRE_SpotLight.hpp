
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
                        /**
                         * Default Constructor
                         */
                        SpotLight();
                        /**
                         * Construct a spot light from his position, color, direction and cutoff angle
                         * @param coord     the light's position
                         * @param color     the light's color
                         * @param direction the light's direction
                         * @param direction the light's cutoff angle
                         */
                        SpotLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction, NREfloat const& angle);

                    //## Copy-Constructor ##//
                        /**
                         * Copy l into this
                         * @param l the spot light to copy the content
                         */
                        SpotLight(SpotLight const& l);

                    //## Move-Constructor ##//
                        /**
                         * Move l into this, leaving l empty
                         * @param l the spot light to move
                         */
                        SpotLight(SpotLight && l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * SpotLight Deconstructor
                         */
                         virtual ~SpotLight();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of l into this
                         * @param l the spot light to copy into this
                         * @return the reference of himself
                         */
                        SpotLight& operator=(SpotLight const& l);
                        /**
                         * Move assigment of l into this, leaving l empty
                         * @param l the spot light to move into this
                         * @return the reference of himself
                         */
                        SpotLight& operator=(SpotLight && l);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
