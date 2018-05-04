
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

            DirectionnalLight::DirectionnalLight(DirectionnalLight && l) : SpotLight(std::move(l)) {
            }

            DirectionnalLight::~DirectionnalLight() {
            }

            DirectionnalLight& DirectionnalLight::operator=(DirectionnalLight const& l) {
                SpotLight::operator=(l);
                return *this;
            }

            DirectionnalLight& DirectionnalLight::operator=(DirectionnalLight && l) {
                SpotLight::operator=(std::move(l));
                return *this;
            }

        };
    };
