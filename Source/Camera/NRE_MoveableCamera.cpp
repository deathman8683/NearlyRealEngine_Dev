
    #include "NRE_MoveableCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat MoveableCamera::DEFAULT_SPEED = 3.0;

            MoveableCamera::MoveableCamera() : speed(DEFAULT_SPEED), world(0) {
            }

            MoveableCamera::MoveableCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                           Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, World::World* world, NREfloat const& speed)
                                           : FixedCamera::FixedCamera(fov, ratio, dist, eye, center), speed(speed), world(world) {
                bindKey();
            }

            MoveableCamera::MoveableCamera(FixedCamera const& camera, Input const& in, World::World* world, NREfloat const& speed) : FixedCamera::FixedCamera(camera), Input::Input(in), speed(speed), world(world) {
                bindKey();
            }

            MoveableCamera::MoveableCamera(MoveableCamera const& camera) : FixedCamera::FixedCamera(camera), Input::Input(camera), speed(camera.getSpeed()), world(camera.world) {
            }

            MoveableCamera::MoveableCamera(MoveableCamera && camera) : FixedCamera::FixedCamera(std::move(camera)), Input::Input(std::move(camera)), speed(std::move(camera.getSpeed())), world(std::move(camera.world)) {
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
                Mouse::keyMap[SDL_BUTTON_LEFT].setAction(new Command<Camera::MoveableCamera>(this, Camera::MoveableCamera::interact));
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

            void MoveableCamera::interact() {
                World::VoxelPoint voxel = rayCast();
                world->getChunk(voxel.getChunkCoord())->setType(voxel.getCoord(), World::VOID);
            }

            World::VoxelPoint const MoveableCamera::rayCast() const {
                Maths::Point3D<GLint> voxel(std::floor(getEye().getX()), std::floor(getEye().getY()), std::floor(getEye().getZ()));
                World::VoxelPoint res(voxel);

                NREfloat dx = getForward().getX();
                NREfloat dy = getForward().getY();
                NREfloat dz = getForward().getZ();

                GLint stepX = Maths::numSign(dx);
                GLint stepY = Maths::numSign(dy);
                GLint stepZ = Maths::numSign(dz);

                NREfloat tMaxX = Maths::intBound(getEye().getX(), dx);
                NREfloat tMaxY = Maths::intBound(getEye().getY(), dy);
                NREfloat tMaxZ = Maths::intBound(getEye().getZ(), dz);

                NREfloat tDeltaX = stepX / dx;
                NREfloat tDeltaY = stepY / dy;
                NREfloat tDeltaZ = stepZ / dz;

                NREfloat radius = 10;
                radius = radius / getForward().norm();

                bool find = false, stop = false;

                while (world->isInBound(voxel) && !find && !stop) {
                    if (world->getChunk(res.getChunkCoord())->getModel().getVoxel(res.getCoord()).getType() != World::VOID) {
                        find = true;
                    } else {
                        if (tMaxX < tMaxY) {
                            if (tMaxX < tMaxZ) {
                                if (tMaxX > radius) {
                                    stop = true;
                                } else {
                                    voxel.setX(voxel.getX() + stepX);
                                    tMaxX = tMaxX + tDeltaX;
                                }
                            } else {
                                if (tMaxZ > radius) {
                                    stop = true;
                                } else {
                                    voxel.setZ(voxel.getZ() + stepZ);
                                    tMaxZ = tMaxZ + tDeltaZ;
                                }
                            }
                        } else {
                            if (tMaxY < tMaxZ) {
                                if (tMaxY > radius) {
                                    stop = true;
                                } else {
                                    voxel.setY(voxel.getY() + stepY);
                                    tMaxY = tMaxY + tDeltaY;
                                }
                            } else {
                                if (tMaxZ > radius) {
                                    stop = true;
                                } else {
                                    voxel.setZ(voxel.getZ() + stepZ);
                                    tMaxZ = tMaxZ + tDeltaZ;
                                }
                            }
                        }
                    }
                    res.compute(voxel);
                }

                return res;
            }

            MoveableCamera& MoveableCamera::operator=(MoveableCamera const& camera) {
                FixedCamera::operator=(camera);
                Input::operator=(camera);
                speed = camera.speed;
                world = camera.world;
                return *this;
            }

            MoveableCamera& MoveableCamera::operator=(MoveableCamera && camera) {
                FixedCamera::operator=(std::move(camera));
                Input::operator=(std::move(camera));
                speed = std::move(camera.speed);
                world = std::move(camera.world);
                return *this;
            }

        };
    };
