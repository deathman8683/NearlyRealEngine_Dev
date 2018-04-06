
    #include "NRE_Light.hpp"

    namespace NRE {
        namespace Light {

            Light::Light() : Light(Maths::Point4D<NREfloat>(), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 1.0, 1.0, 90.0) {
            }

            Light::Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& attenuation, NREfloat const& ambientCoeff, NREfloat const& angle) : position(coord), intensities(color), coneDirection(dir), attenuation(attenuation), ambientCoeff(ambientCoeff), coneAngle(angle) {
            }

            Light::Light(Light const& l) : position(l.getPosition()), intensities(l.getIntensities()), coneDirection(l.getConeDirection()), attenuation(l.getAttenuation()), ambientCoeff(l.getAmbientCoeff()), coneAngle(l.getConeAngle()) {
            }

            Light::~Light() {
            }

            Maths::Point4D<NREfloat> const& Light::getPosition() const {
                return position;
            }

            Maths::Vector3D<NREfloat> const& Light::getIntensities() const {
                return intensities;
            }

            Maths::Vector3D<NREfloat> const& Light::getConeDirection() const {
                return coneDirection;
            }

            NREfloat const& Light::getAttenuation() const {
                return attenuation;
            }

            NREfloat const& Light::getAmbientCoeff() const {
                return ambientCoeff;
            }

            NREfloat const& Light::getConeAngle() const {
                return coneAngle;
            }

            NREfloat* const Light::getAttenuationValue() {
                return &attenuation;
            }

            NREfloat* const Light::getAmbientCoeffValue() {
                return &ambientCoeff;
            }

            NREfloat* const Light::getConeAngleValue() {
                return &coneAngle;
            }

            void Light::setPosition(Maths::Point4D<NREfloat> const& p) {
                position = p;
            }

            void Light::setIntensities(Maths::Vector3D<NREfloat> const& color) {
                intensities = color;
            }

            void Light::setConeDirection(Maths::Vector3D<NREfloat> const& dir) {
                coneDirection = dir;
            }

            void Light::setAttenuation(NREfloat const& coeff) {
                attenuation = coeff;
            }

            void Light::setAmbientCoeff(NREfloat const& coeff) {
                ambientCoeff = coeff;
            }

            void Light::setConeAngle(NREfloat const& angle) {
                coneAngle = angle;
            }

        };
    };
