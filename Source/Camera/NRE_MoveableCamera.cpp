
    #include "NRE_MoveableCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat MoveableCamera::DEFAULT_SPEED = 3.0;

            MoveableCamera::MoveableCamera() : speed(DEFAULT_SPEED) {
            }

            MoveableCamera::MoveableCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                           Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, NREfloat const& speed)
                                           : FixedCamera::FixedCamera(fov, ratio, dist, eye, center), speed(speed) {
                bindKey();
            }

            MoveableCamera::MoveableCamera(FixedCamera const& camera, Input const& in, NREfloat const& speed) : FixedCamera::FixedCamera(camera), Input::Input(in), speed(speed) {
                bindKey();
            }

            MoveableCamera::MoveableCamera(MoveableCamera const& camera) : FixedCamera::FixedCamera(camera), Input::Input(camera), speed(camera.getSpeed()) {
            }

            MoveableCamera::MoveableCamera(MoveableCamera && camera) : FixedCamera::FixedCamera(std::move(camera)), Input::Input(std::move(camera)), speed(std::move(camera.getSpeed())) {
            }

            MoveableCamera::MoveableCamera(FixedCamera const& camera) : FixedCamera::FixedCamera(camera), speed(DEFAULT_SPEED) {
                bindKey();
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
                computeAngle();
                computeVector();
                Input::update(&angle);
                moveCenter();
            }

            void MoveableCamera::bindKey() {
                Keyboard::keyMap[SDL_SCANCODE_W].setAction(new Command<MoveableCamera>(this, moveFront));
                Keyboard::keyMap[SDL_SCANCODE_S].setAction(new Command<MoveableCamera>(this, moveBack));
                Keyboard::keyMap[SDL_SCANCODE_A].setAction(new Command<MoveableCamera>(this, moveLeft));
                Keyboard::keyMap[SDL_SCANCODE_D].setAction(new Command<MoveableCamera>(this, moveRight));
                Keyboard::keyMap[SDL_SCANCODE_SPACE].setAction(new Command<MoveableCamera>(this, moveUp));
                Keyboard::keyMap[SDL_SCANCODE_LSHIFT].setAction(new Command<MoveableCamera>(this, moveDown));
            }

            void MoveableCamera::moveFront() {
                setEye(getEye() + (getForward() * getSpeed()));
            }

            void MoveableCamera::moveBack() {
                setEye(getEye() - (getForward() * getSpeed()));
            }

            void MoveableCamera::moveLeft() {
                setEye(getEye() + (getLeft() * getSpeed()));
            }

            void MoveableCamera::moveRight() {
                setEye(getEye() - (getLeft() * getSpeed()));
            }

            void MoveableCamera::moveUp() {
                setEye(getEye() + (getUp() * getSpeed()));
            }

            void MoveableCamera::moveDown() {
                setEye(getEye() - (getUp() * getSpeed()));
            }

            void MoveableCamera::moveCenter() {
                setCenter(getEye() + getForward());
            }

            MoveableCamera& MoveableCamera::operator=(MoveableCamera const& camera) {
                FixedCamera::operator=(camera);
                Input::operator=(camera);
                speed = camera.speed;
                return *this;
            }

            MoveableCamera& MoveableCamera::operator=(MoveableCamera && camera) {
                FixedCamera::operator=(std::move(camera));
                Input::operator=(std::move(camera));
                speed = std::move(camera.speed);
                return *this;
            }

        };
    };
