
    #include "NRE_DirectionnalLight.hpp"

    namespace NRE {
        namespace Light {

            DirectionnalLight::DirectionnalLight() {
            }

            DirectionnalLight::DirectionnalLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> direction) :
                SpotLight(coord, color, direction, 360.0) {
            }

            DirectionnalLight::DirectionnalLight(DirectionnalLight const& l) : SpotLight(l) {
            }

            DirectionnalLight::~DirectionnalLight() {
            }

        };
    };
