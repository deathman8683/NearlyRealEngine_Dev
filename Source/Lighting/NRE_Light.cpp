
    #include "NRE_Light.hpp"

    namespace NRE {
        namespace Light {

            Light::Light() : Light(Maths::Point3D<NREfloat>(), Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0)) {
            }

            Light::Light(Maths::Point3D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color) : position{coord.getX(), coord.getY(), coord.getZ()}, intensities{color.getX(), color.getY(), color.getZ()} {
            }

            Light::Light(Light const& l) : position{l.getPosition().getX(), l.getPosition().getY(), l.getPosition().getZ()}, intensities{l.getIntensities().getX(), l.getIntensities().getY(), l.getIntensities().getZ()} {
            }

            Light::~Light() {
            }

            Maths::Point3D<NREfloat> Light::getPosition() const {
                return Maths::Point3D<NREfloat>(position[0], position[1], position[2]);
            }

            Maths::Vector3D<NREfloat> Light::getIntensities() const {
                return Maths::Vector3D<NREfloat>(intensities[0], intensities[1], intensities[2]);
            }

            NREfloat* const Light::getPositionValue() {
                return position;
            }

            NREfloat* const Light::getIntensitiesValue() {
                return intensities;
            }

            void Light::setPosition(Maths::Point3D<NREfloat> const& p) {
                position[0] = p.getX();
                position[1] = p.getY();
                position[2] = p.getZ();
            }

            void Light::setIntensities(Maths::Vector3D<NREfloat> const& color) {
                intensities[0] = color.getX();
                intensities[1] = color.getY();
                intensities[2] = color.getZ();
            }

        };
    };
