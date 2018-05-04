
    #include "NRE_FixedCamera.hpp"

    namespace NRE {
        namespace Camera {

            NREfloat FixedCamera::MAX_PHI = 269.9;
            NREfloat FixedCamera::MIN_PHI = 90.1;

            FixedCamera::FixedCamera() {
            }

            FixedCamera::FixedCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                     Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center)
                                    : Maths::Frustum<NREfloat>::Frustum(fov, ratio, dist), eye(eye), center(center) {
                initAngle();
                computeVector();
            }

            FixedCamera::FixedCamera(FixedCamera const& camera) : Maths::Frustum<NREfloat>::Frustum(camera), eye(camera.getEye()), center(camera.getCenter()),
                                                                  up(camera.getUp()), forward(camera.getForward()), left(camera.getLeft()), angle(camera.getAngle()) {
            }

            FixedCamera::FixedCamera(FixedCamera && camera) : Maths::Frustum<NREfloat>::Frustum(std::move(camera)), eye(std::move(camera.getEye())), center(std::move(camera.getCenter())),
                                                                  up(std::move(camera.getUp())), forward(std::move(camera.getForward())), left(std::move(camera.getLeft())), angle(std::move(camera.getAngle())) {
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

            void FixedCamera::initAngle() {
                angle.setX(Maths::toDeg(std::atan2((getCenter().getY() - getEye().getY()), (getCenter().getX() - getEye().getX()))));
                angle.setY(Maths::toDeg(std::acos((getCenter().getZ() - getEye().getZ()) / getCenter().distance(getEye()))));
                if (angle.getX() > 90.0) {
                    angle.setX(450.0 - angle.getX());
                } else {
                    angle.setX(90.0 - angle.getX());
                }
            }

            void FixedCamera::computeAngle() {
                if (getAngle().getX() > MAX_PHI) {
                    angle.setX(MAX_PHI);
                } else if (getAngle().getX() < MIN_PHI) {
                    angle.setX(MIN_PHI);
                }
            }

            void FixedCamera::computeVector() {
                NREfloat tmp = std::cos(Maths::toRad(getAngle().getX()));
                forward.setX(tmp * std::cos(Maths::toRad(getAngle().getY())));
                forward.setY(tmp * std::sin(Maths::toRad(getAngle().getY())));
                forward.setZ(std::sin(Maths::toRad(getAngle().getX())));
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

                planes[Maths::NEAR].setNormalAndPoint(getForward(), nc);
                planes[Maths::FAR].setNormalAndPoint(-getForward(), fc);


                a = (nc + getUp() * getNear().getY()) - getEye();
                a.normalize();
                normal = a ^ getLeft();
                planes[Maths::TOP].setNormalAndPoint(normal, nc + getUp() * getNear().getY());

                a = (nc - getUp() * getNear().getY()) - getEye();
                a.normalize();
                normal = getLeft() ^ a;
                planes[Maths::BOTTOM].setNormalAndPoint(normal, nc - getUp() * getNear().getY());

                a = (nc - getLeft() * getNear().getX()) - getEye();
                a.normalize();
                normal = a ^ getUp();
                planes[Maths::LEFT].setNormalAndPoint(normal, nc - getLeft() * getNear().getX());

                a = (nc + getLeft() * getNear().getX()) - getEye();
                a.normalize();
                normal = getUp() ^ a;
                planes[Maths::RIGHT].setNormalAndPoint(normal, nc + getLeft() * getNear().getX());
            }

            size_t FixedCamera::getVertices(GLfloat* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf) {
                Maths::Point3D<NREfloat> nc, fc, ftl, ftr, fbl, fbr, ntl, ntr, nbl, nbr;
                fc = getEye() + getForward() * getDist().getY();
                nc = getEye() + getForward() * getDist().getX();

                ftl = fc + (getUp() * getFar().getY() / 2) - (getLeft() * getFar().getX() / 2);
                ftr = fc + (getUp() * getFar().getY() / 2) + (getLeft() * getFar().getX() / 2);
                fbl = fc - (getUp() * getFar().getY() / 2) - (getLeft() * getFar().getX() / 2);
                fbr = fc - (getUp() * getFar().getY() / 2) + (getLeft() * getFar().getX() / 2);

                ntl = nc + (getUp() * getNear().getY() / 2) - (getLeft() * getNear().getX() / 2);
                ntr = nc + (getUp() * getNear().getY() / 2) + (getLeft() * getNear().getX() / 2);
                nbl = nc - (getUp() * getNear().getY() / 2) - (getLeft() * getNear().getX() / 2);
                nbr = nc - (getUp() * getNear().getY() / 2) + (getLeft() * getNear().getX() / 2);

                vBuf = new GLfloat[60];
                vBuf[0] = nbl.getX(); vBuf[1] = nbl.getY(); vBuf[2] = nbl.getZ();
                vBuf[3] = ntl.getX(); vBuf[4] = ntl.getY(); vBuf[5] = ntl.getZ();
                vBuf[6] = nbr.getX(); vBuf[7] = nbr.getY(); vBuf[8] = nbr.getZ();
                vBuf[9] = ntr.getX(); vBuf[10] = ntr.getY(); vBuf[11] = ntr.getZ();

                vBuf[12] = fbl.getX(); vBuf[13] = fbl.getY(); vBuf[14] = fbl.getZ();
                vBuf[15] = ftl.getX(); vBuf[16] = ftl.getY(); vBuf[17] = ftl.getZ();
                vBuf[18] = fbr.getX(); vBuf[19] = fbr.getY(); vBuf[20] = fbr.getZ();
                vBuf[21] = ftr.getX(); vBuf[22] = ftr.getY(); vBuf[23] = ftr.getZ();

                vBuf[24] = planes[Maths::TOP].getPoint().getX(); vBuf[25] = planes[Maths::TOP].getPoint().getY(); vBuf[26] = planes[Maths::TOP].getPoint().getZ();
                vBuf[27] = planes[Maths::TOP].getPoint().getX() + planes[Maths::TOP].getNormal().getX() * 10; vBuf[28] = planes[Maths::TOP].getPoint().getY() + planes[Maths::TOP].getNormal().getY() * 10; vBuf[29] = planes[Maths::TOP].getPoint().getZ() + planes[Maths::TOP].getNormal().getZ() * 10;
                vBuf[30] = planes[Maths::BOTTOM].getPoint().getX(); vBuf[31] = planes[Maths::BOTTOM].getPoint().getY(); vBuf[32] = planes[Maths::BOTTOM].getPoint().getZ();
                vBuf[33] = planes[Maths::BOTTOM].getPoint().getX() + planes[Maths::BOTTOM].getNormal().getX() * 10; vBuf[34] = planes[Maths::BOTTOM].getPoint().getY() + planes[Maths::BOTTOM].getNormal().getY() * 10; vBuf[35] = planes[Maths::BOTTOM].getPoint().getZ() + planes[Maths::BOTTOM].getNormal().getZ() * 10;

                vBuf[36] = planes[Maths::NEAR].getPoint().getX(); vBuf[37] = planes[Maths::NEAR].getPoint().getY(); vBuf[38] = planes[Maths::NEAR].getPoint().getZ();
                vBuf[39] = planes[Maths::NEAR].getPoint().getX() + planes[Maths::NEAR].getNormal().getX() * 10; vBuf[40] = planes[Maths::NEAR].getPoint().getY() + planes[Maths::NEAR].getNormal().getY() * 10; vBuf[41] = planes[Maths::NEAR].getPoint().getZ() + planes[Maths::NEAR].getNormal().getZ() * 10;
                vBuf[42] = planes[Maths::FAR].getPoint().getX(); vBuf[43] = planes[Maths::FAR].getPoint().getY(); vBuf[44] = planes[Maths::FAR].getPoint().getZ();
                vBuf[45] = planes[Maths::FAR].getPoint().getX() + planes[Maths::FAR].getNormal().getX() * 10; vBuf[46] = planes[Maths::FAR].getPoint().getY() + planes[Maths::FAR].getNormal().getY() * 10; vBuf[47] = planes[Maths::FAR].getPoint().getZ() + planes[Maths::FAR].getNormal().getZ() * 10;

                vBuf[48] = planes[Maths::LEFT].getPoint().getX(); vBuf[49] = planes[Maths::LEFT].getPoint().getY(); vBuf[50] = planes[Maths::LEFT].getPoint().getZ();
                vBuf[51] = planes[Maths::LEFT].getPoint().getX() + planes[Maths::LEFT].getNormal().getX() * 10; vBuf[52] = planes[Maths::LEFT].getPoint().getY() + planes[Maths::LEFT].getNormal().getY() * 10; vBuf[53] = planes[Maths::LEFT].getPoint().getZ() + planes[Maths::LEFT].getNormal().getZ() * 10;
                vBuf[54] = planes[Maths::RIGHT].getPoint().getX(); vBuf[55] = planes[Maths::RIGHT].getPoint().getY(); vBuf[56] = planes[Maths::RIGHT].getPoint().getZ();
                vBuf[57] = planes[Maths::RIGHT].getPoint().getX() + planes[Maths::RIGHT].getNormal().getX() * 10; vBuf[58] = planes[Maths::RIGHT].getPoint().getY() + planes[Maths::RIGHT].getNormal().getY() * 10; vBuf[59] = planes[Maths::RIGHT].getPoint().getZ() + planes[Maths::RIGHT].getNormal().getZ() * 10;

                cBuf = new GLfloat[60];
                    for (int i = 0; i < 24; i = i + 3) {
                        cBuf[i] = 1.0;
                        cBuf[i + 1] = 1.0;
                        cBuf[i + 2] = 1.0;
                    }
                    for (int i = 24; i < 60; i = i + 1) {
                        cBuf[i] = vBuf[i];
                    }

                nBuf = new GLbyte[60];
                    for (int i = 0; i < 24; i = i + 3) {
                        nBuf[i] = 1;
                        nBuf[i + 1] = 0;
                        nBuf[i + 2] = 0;
                    }
                    for (int i = 24; i < 60; i = i + 1) {
                        nBuf[i] = vBuf[i];
                    }

                iBuf = new GLuint[36];
                    iBuf[0] = 0;
                    iBuf[1] = 1;
                    iBuf[2] = 0;
                    iBuf[3] = 2;
                    iBuf[4] = 3;
                    iBuf[5] = 1;
                    iBuf[6] = 3;
                    iBuf[7] = 2;
                    iBuf[8] = 4;
                    iBuf[9] = 5;
                    iBuf[10] = 4;
                    iBuf[11] = 6;
                    iBuf[12] = 7;
                    iBuf[13] = 5;
                    iBuf[14] = 7;
                    iBuf[15] = 6;
                    iBuf[16] = 0;
                    iBuf[17] = 4;
                    iBuf[18] = 1;
                    iBuf[19] = 5;
                    iBuf[20] = 2;
                    iBuf[21] = 6;
                    iBuf[22] = 3;
                    iBuf[23] = 7;
                    for (int i = 24; i < 36; i = i + 1) {
                        iBuf[i] = i - 16;
                    }

                return 36;
            }

            FixedCamera& FixedCamera::operator=(FixedCamera const& camera) {
                Maths::Frustum<NREfloat>::operator=(camera);
                eye = camera.eye;
                center = camera.center;
                up = camera.up;
                forward = camera.forward;
                left = camera.left;
                angle = camera.angle;
                return *this;
            }

            FixedCamera& FixedCamera::operator=(FixedCamera && camera) {
                Maths::Frustum<NREfloat>::operator=(std::move(camera));
                eye = std::move(camera.eye);
                center = std::move(camera.center);
                up = std::move(camera.up);
                forward = std::move(camera.forward);
                left = std::move(camera.left);
                angle = std::move(camera.angle);
                return *this;
            }

        };
    };
