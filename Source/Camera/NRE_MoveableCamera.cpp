
    #include "NRE_MoveableCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat MoveableCamera::DEFAULT_SPEED = 1.0;

            MoveableCamera::MoveableCamera() : speed(DEFAULT_SPEED) {
            }

            MoveableCamera::MoveableCamera(FixedCamera const& camera, Input const& in, NREfloat const& speed) : FixedCamera::FixedCamera(camera), Input::Input(in), speed(speed) {
            }

            MoveableCamera::MoveableCamera(MoveableCamera const& camera) : FixedCamera::FixedCamera(camera), Input::Input(camera), speed(camera.getSpeed()) {
            }

            MoveableCamera::MoveableCamera(FixedCamera const& camera) : FixedCamera::FixedCamera(camera), speed(DEFAULT_SPEED) {
            }

            MoveableCamera::~MoveableCamera() {
            }

            NREfloat const& MoveableCamera::getSpeed() const {
                return speed;
            }

            void MoveableCamera::setSpeed(NREfloat const& speed) {
                this->speed = speed;
            }

        };
    };
