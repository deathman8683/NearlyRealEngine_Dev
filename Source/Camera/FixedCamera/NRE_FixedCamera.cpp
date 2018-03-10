
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
                nc = getEye() + getForward() * getDist().getX();
                fc = getEye() + getForward() * getDist().getY();

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

            size_t FixedCamera::getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf) {
                Math::Point3D<NREfloat> nc, fc;
                vBuf = new GLint[24];
                nc = getEye() + getForward() * getDist().getX() - (getNear() / 2);
                    vBuf[0] = nc.getX(); vBuf[1] = nc.getY(); vBuf[2] = nc.getZ();
                    vBuf[3] = nc.getX(); vBuf[4] = nc.getY(); vBuf[5] = nc.getZ() + getNear().getY();
                    vBuf[6] = nc.getX(); vBuf[7] = nc.getY() + getNear().getX(); vBuf[8] = nc.getZ();
                    vBuf[9] = nc.getX(); vBuf[10] = nc.getY() + getNear().getX(); vBuf[11] = nc.getZ() + getNear().getY();
                fc = getEye() + getForward() * getDist().getY();
                    vBuf[12] = fc.getX(); vBuf[13] = fc.getY(); vBuf[14] = fc.getZ();
                    vBuf[15] = fc.getX(); vBuf[16] = fc.getY(); vBuf[17] = fc.getZ() + getFar().getY();
                    vBuf[18] = fc.getX(); vBuf[19] = fc.getY() + getFar().getX(); vBuf[20] = fc.getZ() + getFar().getY();
                    vBuf[21] = fc.getX(); vBuf[22] = fc.getY() + getFar().getX(); vBuf[23] = fc.getZ();

                cBuf = new GLfloat[24];
                    Color::RGB voxColor = Color::RGB(255, 255, 255);
                    for (int i = 0; i < NB_VERTICES; i = i + 3) {
                        cBuf[i] = voxColor.getR() / 255.0;
                        cBuf[i + 1] = voxColor.getG() / 255.0;
                        cBuf[i + 2] = voxColor.getB() / 255.0;
                    }

                nBuf = new GLbyte[24];
                    for (int i = 0; i < NB_VERTICES; i = i + 3) {
                        nBuf[i] = 1;
                        nBuf[i + 1] = 0;
                        nBuf[i + 2] = 0;
                    }

                iBuf = new GLuint[108];
                    iBuf[0] = 0;
                    iBuf[1] = 1;
                    iBuf[2] = 2;
                    iBuf[3] = 3;
                    iBuf[4] = 2;
                    iBuf[5] = 1;
                    iBuf[6] = 0;
                    iBuf[7] = 1;
                    iBuf[8] = 4;
                    iBuf[9] = 5;
                    iBuf[10] = 4;
                    iBuf[11] = 1;
                    iBuf[12] = 1;
                    iBuf[13] = 5;
                    iBuf[14] = 3;
                    iBuf[15] = 6;
                    iBuf[16] = 3;
                    iBuf[17] = 5;
                    iBuf[18] = 0;
                    iBuf[19] = 2;
                    iBuf[20] = 4;
                    iBuf[21] = 7;
                    iBuf[22] = 4;
                    iBuf[23] = 2;
                    iBuf[24] = 4;
                    iBuf[25] = 5;
                    iBuf[26] = 7;
                    iBuf[27] = 6;
                    iBuf[28] = 7;
                    iBuf[29] = 5;
                    iBuf[30] = 2;
                    iBuf[31] = 3;
                    iBuf[32] = 7;
                    iBuf[33] = 6;
                    iBuf[34] = 7;
                    iBuf[35] = 3;

                return NB_INDEX;
            }

        };
    };
