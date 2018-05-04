
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
         * @brief Engine's Light Module
         */
        namespace Light {

            /**
             * @class Light
             * @brief Light's Object : A typical light
             */
            class Light {
                private:
                    Maths::Point4D<NREfloat> position;      /**< The light position */
                    Maths::Vector3D<NREfloat> intensities;  /**< The light color */
                    Maths::Vector3D<NREfloat> direction;    /**< The light direction, used in directionnal derived class */
                    NREfloat angle;                         /**< The light angle, used in spot derived class */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Light();
                        /**
                         * Construct a light with passed attributes
                         * @param coord the light's position
                         * @param color the light's color
                         * @param dir   the light's direction
                         * @param angle the light's angle
                         */
                        Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& angle);

                    //## Copy-Constructor ##//
                        /**
                         * Copy l into this
                         * @param l the light to copy the content
                         */
                        Light(Light const& l);

                    //## Move-Constructor ##//
                        /**
                         * Move l into this, leaving l empty
                         * @param l the light to move
                         */
                        Light(Light && l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Light Deconstructor
                         */
                        virtual ~Light();

                    //## Getter ##//
                        /**
                         * Position getter
                         * @return the light's position value
                         */
                        Maths::Point4D<NREfloat> const& getPosition() const;
                        /**
                         * Intensities getter
                         * @return the light's color value
                         */
                        Maths::Vector3D<NREfloat> const& getIntensities() const;
                        /**
                         * Direction getter
                         * @return the light's direction value
                         */
                        Maths::Vector3D<NREfloat> const& getDirection() const;
                        /**
                         * Angle getter
                         * @return the light's angle value
                         */
                        NREfloat const& getAngle() const;
                        /**
                         * Angle pointer getter
                         * @return the pointer to the angle value
                         */
                        NREfloat* const getAngleValue();

                    //## Setter ##//
                        /**
                         * Position setter
                         * @param p the new position value
                         */
                        void setPosition(Maths::Point4D<NREfloat> const& p);
                        /**
                         * Intensities setter
                         * @param color the new color value
                         */
                        void setIntensities(Maths::Vector3D<NREfloat> const& color);
                        /**
                         * Direction setter
                         * @param dir the new direction value
                         */
                        void setDirection(Maths::Vector3D<NREfloat> const& dir);
                        /**
                         * Angle setter
                         * @param angle the new angle value
                         */
                        void setAngle(NREfloat const& angle);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of l into this
                         * @param l the light to copy into this
                         * @return the reference of himself
                         */
                        Light& operator=(Light const& l);
                        /**
                         * Move assigment of l into this, leaving l empty
                         * @param l the light to move into this
                         * @return the reference of himself
                         */
                        Light& operator=(Light && l);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
