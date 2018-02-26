
    #include "NRE_FixedCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat FixedCamera::MAX_PHI = 89;
            NREfloat FixedCamera::MIN_PHI = -89;

            FixedCamera::FixedCamera() {
            }

            FixedCamera::FixedCamera(Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle, bool const& calculate) : eye(eye), center(center), angle(angle) {
                if (calculate) {
                    calculateVector();
                }
            }


            FixedCamera::FixedCamera(Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle,
                                     Maths::Vector3D<NREfloat> const& up, Maths::Vector3D<NREfloat> const& forward, Maths::Vector3D<NREfloat> const& left) : eye(eye), center(center), up(up), forward(forward), left(left), angle(angle) {
            }

            FixedCamera::FixedCamera(FixedCamera const& camera) : eye(camera.getEye()), center(camera.getCenter()),
                                                                  up(camera.getUp()), forward(camera.getForward()), left(camera.getLeft()), angle(camera.getAngle()) {
            }

            FixedCamera::~FixedCamera() {
            }

            Maths::Point3D<NREfloat> const& FixedCamera::getEye() const {
                return eye;
            }

            Maths::Point3D<NREfloat> const& FixedCamera::getCenter() const {
                return center;
            }

            Maths::Vector3D<NREfloat> const& FixedCamera::getUp() const {
                return up;
            }

            Maths::Vector3D<NREfloat> const& FixedCamera::getForward() const {
                return forward;
            }

            Maths::Vector3D<NREfloat> const& FixedCamera::getLeft() const {
                return left;
            }

            Maths::Vector2D<NREfloat> const& FixedCamera::getAngle() const {
                return angle;
            }

            void FixedCamera::setEye(Maths::Point3D<NREfloat> const& p) {
                eye = p;
            }

            void FixedCamera::setCenter(Maths::Point3D<NREfloat> const& p) {
                center = p;
            }

            void FixedCamera::setUp(Maths::Vector3D<NREfloat> const& u) {
                up = u;
            }

            void FixedCamera::setForward(Maths::Vector3D<NREfloat> const& u) {
                forward = u;
            }

            void FixedCamera::setLeft(Maths::Vector3D<NREfloat> const& u) {
                left = u;
            }

            void FixedCamera::setAngle(Maths::Vector2D<NREfloat> const& u) {
                angle = u;
            }

            void FixedCamera::setView(Maths::Matrix4x4<NREfloat>& modelview) const {
                modelview.lookAt(getEye(), getCenter(), getUp());
            }

            void FixedCamera::calculateVector() {
                if (getAngle().getX() > MAX_PHI) {
                    angle.setX(MAX_PHI);
                } else if (getAngle().getX() < MIN_PHI) {
                    angle.setX(MIN_PHI);
                }

                NREfloat tmp = std::cos(toRad(getAngle().getX()));
                forward.setX(tmp * std::cos(toRad(getAngle().getY())));
                forward.setY(tmp * std::sin(toRad(getAngle().getY())));
                forward.setZ(std::sin(toRad(getAngle().getX())));
                forward.normalize();

                left = Maths::Vector3D<NREfloat>(0, 0, 1) ^ forward;
                left.normalize();

                up = forward ^ left;
                up.normalize();
            }

            std::ostream& operator<<(std::ostream &stream, FixedCamera const& camera) {
                stream << "(" << camera.getEye() << "," << camera.getCenter() << "," << camera.getAngle() << ")" << std::endl;
                stream << "(" << camera.getForward() << "," << camera.getLeft() << "," << camera.getUp() << ")";
                return stream;
            }

        };
    };
