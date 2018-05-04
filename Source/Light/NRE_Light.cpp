
    #include "NRE_Light.hpp"

    namespace NRE {
        namespace Light {

            Light::Light() : Light(Maths::Point4D<NREfloat>(0.0), Maths::Vector3D<NREfloat>(1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 90.0) {
            }

            Light::Light(Maths::Point4D<NREfloat> const& coord, Maths::Vector3D<NREfloat> const& color, Maths::Vector3D<NREfloat> const& dir, NREfloat const& angle) : position(coord), intensities(color), direction(dir), angle(angle) {
            }

            Light::Light(Light const& l) : position(l.getPosition()), intensities(l.getIntensities()), direction(l.getDirection()), angle(l.getAngle()) {
            }

            Light::Light(Light && l) : position(std::move(l.getPosition())), intensities(std::move(l.getIntensities())), direction(std::move(l.getDirection())), angle(std::move(l.getAngle())) {
            }

            Light::~Light() {
            }

            Maths::Point4D<NREfloat> const& Light::getPosition() const {
                return position;
            }

            Maths::Vector3D<NREfloat> const& Light::getIntensities() const {
                return intensities;
            }

            Maths::Vector3D<NREfloat> const& Light::getDirection() const {
                return direction;
            }

            NREfloat const& Light::getAngle() const {
                return angle;
            }

            NREfloat* const Light::getAngleValue() {
                return &angle;
            }

            void Light::setPosition(Maths::Point4D<NREfloat> const& p) {
                position = p;
            }

            void Light::setIntensities(Maths::Vector3D<NREfloat> const& color) {
                intensities = color;
            }

            void Light::setDirection(Maths::Vector3D<NREfloat> const& dir) {
                direction = dir;
            }

            void Light::setAngle(NREfloat const& angle) {
                this->angle = angle;
            }

            Light& Light::operator=(Light const& l) {
                position = l.position;
                intensities = l.intensities;
                direction = l.direction;
                angle = l.angle;
                return *this;
            }

            Light& Light::operator=(Light && l) {
                position = std::move(l.position);
                intensities = std::move(l.intensities);
                direction = std::move(l.direction);
                angle = std::move(l.angle);
                return *this;
            }

        };
    };
