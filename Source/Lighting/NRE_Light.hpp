
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
                    NREfloat position[4];
                    NREfloat intensities[3];
                    NREfloat coneDirection[3];
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
                    ~Light();

                    //## Getter ##//
                    Maths::Point4D<NREfloat> getPosition() const;
                    Maths::Vector3D<NREfloat> getIntensities() const;
                    Maths::Vector3D<NREfloat> getConeDirection() const;
                    NREfloat const& getAttenuation() const;
                    NREfloat const& getAmbientCoeff() const;
                    NREfloat const& getConeAngle() const;
                    NREfloat* const getPositionValue();
                    NREfloat* const getIntensitiesValue();
                    NREfloat* const getConeDirectionValue();
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
