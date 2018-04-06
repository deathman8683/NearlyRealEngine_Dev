
    #include "NRE_DirectionnalLight.hpp"

    namespace NRE {
        namespace Light {

            DirectionnalLight::DirectionnalLight() {
            }

            DirectionnalLight::DirectionnalLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Maths::Vector3D<NREfloat> direction, NREfloat const& ambientCoeff) :
                Light(Maths::Point4D<NREfloat>(coord, 0.0), color, direction, 0.0, ambientCoeff, 360.0) {
            }

            DirectionnalLight::DirectionnalLight(DirectionnalLight const& l) : Light(l) {
            }

            DirectionnalLight::~DirectionnalLight() {
            }

        };
    };
