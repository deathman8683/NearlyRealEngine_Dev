
    #include "NRE_Light.hpp"

    namespace NRE {
        namespace Light {

            Light::Light() : Light(Maths::Point4D<NREfloat>(), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 1.0, 1.0, 90.0) {
            }

            Light::Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& attenuation, NREfloat const& ambientCoeff, NREfloat const& angle) : position{coord.getX(), coord.getY(), coord.getZ(), coord.getW()}, intensities{color.getX(), color.getY(), color.getZ()}, coneDirection{dir.getX(), dir.getY(), dir.getZ()}, attenuation(attenuation), ambientCoeff(ambientCoeff), coneAngle(angle) {
            }

            Light::Light(Light const& l) : position{l.getPosition().getX(), l.getPosition().getY(), l.getPosition().getZ(), l.getPosition().getW()}, intensities{l.getIntensities().getX(), l.getIntensities().getY(), l.getIntensities().getZ()}, coneDirection{l.getConeDirection().getX(), l.getConeDirection().getY(), l.getConeDirection().getZ()}, attenuation(l.getAttenuation()), ambientCoeff(l.getAmbientCoeff()), coneAngle(l.getConeAngle()) {
            }

            Light::~Light() {
            }

            Maths::Point4D<NREfloat> Light::getPosition() const {
                return Maths::Point4D<NREfloat>(position[0], position[1], position[2], position[3]);
            }

            Maths::Vector3D<NREfloat> Light::getIntensities() const {
                return Maths::Vector3D<NREfloat>(intensities[0], intensities[1], intensities[2]);
            }

            Maths::Vector3D<NREfloat> Light::getConeDirection() const {
                return Maths::Vector3D<NREfloat>(coneDirection[0], coneDirection[1], coneDirection[2]);
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

            NREfloat* const Light::getPositionValue() {
                return position;
            }

            NREfloat* const Light::getIntensitiesValue() {
                return intensities;
            }

            NREfloat* const Light::getConeDirectionValue() {
                return coneDirection;
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
                position[0] = p.getX();
                position[1] = p.getY();
                position[2] = p.getZ();
                position[3] = p.getW();
            }

            void Light::setIntensities(Maths::Vector3D<NREfloat> const& color) {
                intensities[0] = color.getX();
                intensities[1] = color.getY();
                intensities[2] = color.getZ();
            }

            void Light::setConeDirection(Maths::Vector3D<NREfloat> const& dir) {
                coneDirection[0] = dir.getX();
                coneDirection[1] = dir.getY();
                coneDirection[2] = dir.getZ();
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
