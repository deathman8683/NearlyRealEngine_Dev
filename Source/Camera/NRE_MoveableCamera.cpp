
    #include "NRE_MoveableCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat MoveableCamera::DEFAULT_SPEED = 0.1;

            MoveableCamera::MoveableCamera() : speed(DEFAULT_SPEED) {
            }

            MoveableCamera::MoveableCamera(std::string const& kbPath, std::string const& mPath, Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle, bool const& calculate) : FixedCamera::FixedCamera(eye, center, angle, calculate), Input::Input(kbPath, mPath), speed(DEFAULT_SPEED) {
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

            void MoveableCamera::update() {
                Maths::Vector3D<NREfloat> tmp;
                Input::update(&angle);

                auto it = Keyboard::getKeyMap().find(SDL_SCANCODE_W);

                if (it->second.isActive()) {
                    tmp = tmp + getForward();
                }
                it = Keyboard::getKeyMap().find(SDL_SCANCODE_S);
                if (it->second.isActive()) {
                    tmp = tmp - getForward();
                }
                it = Keyboard::getKeyMap().find(SDL_SCANCODE_A);
                if (it->second.isActive()) {
                    tmp = tmp + getLeft();
                }
                it = Keyboard::getKeyMap().find(SDL_SCANCODE_D);
                if (it->second.isActive()) {
                    tmp = tmp - getLeft();
                }
                it = Keyboard::getKeyMap().find(SDL_SCANCODE_LSHIFT);
                if (it->second.isActive()) {
                    tmp = tmp - getUp();
                }
                it = Keyboard::getKeyMap().find(SDL_SCANCODE_SPACE);
                if (it->second.isActive()) {
                    tmp = tmp + getUp();
                }

                tmp = tmp * getSpeed();
                setEye(getEye() + tmp);
                setCenter(getEye() + getForward());
                calculateVector();
            }

        };
    };
