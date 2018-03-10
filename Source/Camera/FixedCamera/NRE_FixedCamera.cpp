
    #include "NRE_FixedCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat FixedCamera::MAX_PHI = 89;
            NREfloat FixedCamera::MIN_PHI = -89;

            FixedCamera::FixedCamera() {
            }

            FixedCamera::FixedCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                     Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle,
                                     bool const& calculate) : Frustum<NREfloat>::Frustum(fov, ratio, dist), eye(eye), center(center), angle(angle) {
                if (calculate) {
                    computeVector();
                }
            }


            FixedCamera::FixedCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                     Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle,
                                     Maths::Vector3D<NREfloat> const& up, Maths::Vector3D<NREfloat> const& forward, Maths::Vector3D<NREfloat> const& left) : Frustum<NREfloat>::Frustum(fov, ratio, dist), eye(eye), center(center), up(up), forward(forward), left(left), angle(angle) {
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

            void FixedCamera::computeVector() {
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
                computePlane();
            }

            void FixedCamera::computePlane() {
                Maths::Point3D<NREfloat> fc, nc;
                Maths::Vector3D<NREfloat> a, normal;
                fc = getEye() + getForward() * getDist().getX();
                nc = getEye() + getForward() * getDist().getY();

                plane[Maths::NEAR].setNormalAndPoint(getForward(), nc);
                plane[Maths::FAR].setNormalAndPoint(-getForward(), fc);


                a = (nc + getUp() * getNear().getY()) - getEye();
                a.normalize();
                normal = getLeft() ^ a;
                plane[Maths::TOP].setNormalAndPoint(normal, nc + getUp() * getNear().getY());

                a = (nc - getUp() * getNear().getY()) - getEye();
                a.normalize();
                normal = a ^ getLeft();
                plane[Maths::BOTTOM].setNormalAndPoint(normal, nc - getUp() * getNear().getY());

                a = (nc - getLeft() * getNear().getX()) - getEye();
                a.normalize();
                normal = getUp() ^ a;
                plane[Maths::RIGHT].setNormalAndPoint(normal, nc - getLeft() * getNear().getX());

                a = (nc + getLeft() * getNear().getX()) - getEye();
                a.normalize();
                normal = a ^ getUp();
                plane[Maths::LEFT].setNormalAndPoint(normal, nc + getLeft() * getNear().getX());
            }

        };
    };
