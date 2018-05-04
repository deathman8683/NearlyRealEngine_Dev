
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
                        /**
                         * Default Constructor
                         */
                        DirectionnalLight();
                        /**
                         * Construct a directionnal light from his position, color and direction
                         * @param coord     the light's position
                         * @param color     the light's color
                         * @param direction the light's direction
                         */
                        DirectionnalLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction);

                    //## Copy-Constructor ##//
                        /**
                         * Copy l into this
                         * @param l the directionnal light to copy the content
                         */
                        DirectionnalLight(DirectionnalLight const& l);

                    //## Move-Constructor ##//
                        /**
                         * Move l into this, leaving l empty
                         * @param l the directionnal light to move
                         */
                        DirectionnalLight(DirectionnalLight && l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * DirectionnalLight Deconstructor
                         */
                        ~DirectionnalLight();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of l into this
                         * @param l the directionnal light to copy into this
                         * @return the reference of himself
                         */
                        DirectionnalLight& operator=(DirectionnalLight const& l);
                        /**
                         * Move assigment of l into this, leaving l empty
                         * @param l the directionnal light to move into this
                         * @return the reference of himself
                         */
                        DirectionnalLight& operator=(DirectionnalLight && l);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
