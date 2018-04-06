
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

            SpotLight::~SpotLight() {
            }

        };
    };
