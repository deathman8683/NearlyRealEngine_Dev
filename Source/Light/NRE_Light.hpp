
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
                    Maths::Vector3D<NREfloat> coneDirection;
                    NREfloat attenuation;
                    NREfloat ambientCoeff;
                    NREfloat coneAngle;

                public:
                    //## Constructor ##//
                    Light();
                    Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& attenuation, NREfloat const& ambientCoeff, NREfloat const& angle);

                    //## Copy-Constructor ##//
                    Light(Light const& l);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Light();

                    //## Getter ##//
                    Maths::Point4D<NREfloat> const& getPosition() const;
                    Maths::Vector3D<NREfloat> const& getIntensities() const;
                    Maths::Vector3D<NREfloat> const& getConeDirection() const;
                    NREfloat const& getAttenuation() const;
                    NREfloat const& getAmbientCoeff() const;
                    NREfloat const& getConeAngle() const;
                    NREfloat* const getAttenuationValue();
                    NREfloat* const getAmbientCoeffValue();
                    NREfloat* const getConeAngleValue();

                    //## Setter ##//
                    void setPosition(Maths::Point4D<NREfloat> const& p);
                    void setIntensities(Maths::Vector3D<NREfloat> const& color);
                    void setConeDirection(Maths::Vector3D<NREfloat> const& dir);
                    void setAttenuation(NREfloat const& coeff);
                    void setAmbientCoeff(NREfloat const& coeff);
                    void setConeAngle(NREfloat const& angle);

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
