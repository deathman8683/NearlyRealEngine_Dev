
    #include "NRE_PointLight.hpp"

    namespace NRE {
        namespace Light {

            PointLight::PointLight() {
            }

            PointLight::PointLight(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, NREfloat const& attenuation) :
                Light(Maths::Point4D<NREfloat>(coord, 1.0), color, Maths::Vector3D<NREfloat>(0.0, 0.0, 0.0), attenuation, 0.0, 360.0) {
            }

            PointLight::PointLight(PointLight const& l) : Light(l) {
            }

            PointLight::~PointLight() {
            }

        };
    };
