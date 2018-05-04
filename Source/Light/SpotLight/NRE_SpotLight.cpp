
    #include "NRE_SpotLight.hpp"

    namespace NRE {
        namespace Light {

            SpotLight::SpotLight() {
            }

            SpotLight::SpotLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction, NREfloat const& angle) :
                Light(Maths::Point4D<NREfloat>(coord, 0.0), color, direction, angle) {
            }

            SpotLight::SpotLight(SpotLight const& l) : Light(l) {
            }

            SpotLight::SpotLight(SpotLight && l) : Light(std::move(l)) {
            }

            SpotLight::~SpotLight() {
            }

            SpotLight& SpotLight::operator=(SpotLight const& l) {
                Light::operator=(l);
                return *this;
            }

            SpotLight& SpotLight::operator=(SpotLight && l) {
                Light::operator=(std::move(l));
                return *this;
            }

        };
    };
