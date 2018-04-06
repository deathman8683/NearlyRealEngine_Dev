
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
                    Maths::Point4D<NREfloat> position;
                    Maths::Vector3D<NREfloat> intensities;
                    Maths::Vector3D<NREfloat> direction;
                    NREfloat angle;

                public:
                    //## Constructor ##//
                    Light();
                    Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& angle);

                    //## Copy-Constructor ##//
                    Light(Light const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Light();

                    //## Getter ##//
                    Maths::Point4D<NREfloat> const& getPosition() const;
                    Maths::Vector3D<NREfloat> const& getIntensities() const;
                    Maths::Vector3D<NREfloat> const& getDirection() const;
                    NREfloat const& getAngle() const;
                    NREfloat* const getAngleValue();

                    //## Setter ##//
                    void setPosition(Maths::Point4D<NREfloat> const& p);
                    void setIntensities(Maths::Vector3D<NREfloat> const& color);
                    void setDirection(Maths::Vector3D<NREfloat> const& dir);
                    void setAmbientCoeff(NREfloat const& coeff);
                    void setAngle(NREfloat const& angle);

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
