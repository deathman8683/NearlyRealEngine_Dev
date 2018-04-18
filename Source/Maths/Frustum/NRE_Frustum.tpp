
    namespace NRE {
        namespace Maths {

            template <class T>
            Frustum<T>::Frustum() : Frustum(DEFAULT_FOV, DEFAULT_RATIO, Vector2D<T>()) {
            }

            template <class T>
            Frustum<T>::Frustum(T const& fov, T const& ratio, Vector2D<T> const& dist) : planes(new Plane<T>[FACE_NUM]), dist(dist), fov(fov), ratio(ratio) {
                computeNearAndFar();
            }

            template <class T>
            Frustum<T>::Frustum(Frustum const& f) : planes(new Plane<T>[FACE_NUM]), near(f.getNear()), far(f.getFar()), dist(f.getDist()), fov(f.getFov()), ratio(f.getRatio()) {
                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    planes[i] = f.getPlane(i);
                }
            }

            template <class T>
            Frustum<T>::Frustum(Frustum && f) : planes(std::move(f.planes)), near(std::move(f.getNear())), far(std::move(f.getFar())), dist(std::move(f.getDist())), fov(std::move(f.getFov())), ratio(std::move(f.getRatio())) {
            }

            template <class T>
            template <class K>
            Frustum<T>::Frustum(Frustum<K> const& f) : planes(f.getPlanes()), near(f.getNear()), far(f.getFar()), dist(f.getDist()), fov(f.getFov()), ratio(f.getRatio()) {
            }

            template <class T>
            Frustum<T>::~Frustum() {
            }

            template <class T>
            Plane<T> const& Frustum<T>::getPlane(unsigned int const& index) const {
                return planes[index];
            }

            template <class T>
            Vector2D<T> const& Frustum<T>::getNear() const {
                return near;
            }

            template <class T>
            Vector2D<T> const& Frustum<T>::getFar() const {
                return far;
            }

            template <class T>
            Vector2D<T> const& Frustum<T>::getDist() const {
                return dist;
            }
            template <class T>
            T const& Frustum<T>::getFov() const {
                return fov;
            }

            template <class T>
            T const& Frustum<T>::getRatio() const {
                return ratio;
            }

            template <class T>
            void Frustum<T>::computeNearAndFar() {
                T tang = std::tan(toRad(getFov()) * 0.5);

                near = Vector2D<T>(0, tang * getDist().getX());
                near = Vector2D<T>(getNear().getY() * getRatio(), getNear().getY());
                far = Vector2D<T>(0, tang * getDist().getY());
                far = Vector2D<T>(getFar().getY() * getRatio(), getFar().getY());

            }

            template <class T>
            Physics::CollisionResult const Frustum<T>::pointCollision(Point3D<T> const& p) const {
                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    if (getPlane(i).distance(p) < 0) {
                        return Physics::OUTSIDE;
                    }
                }
                return Physics::INSIDE;
            }

            template <class T>
            Physics::CollisionResult const Frustum<T>::sphereCollision(Point3D<T> const& p, T const& radius) const {
                T distance;
                Physics::CollisionResult result = Physics::INSIDE;

                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    distance = getPlane(i).distance(p);
                    if (distance < -radius) {
                        return Physics::OUTSIDE;
                    } else if (distance < radius) {
                        result = Physics::INTERSECT;
                    }
                }
                return result;
            }

            template <class T>
            Physics::CollisionResult const Frustum<T>::AABBCollision(Physics::AABB<T> const& box) const {
                Physics::CollisionResult result = Physics::INSIDE;

                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    if (getPlane(i).distance(box.getPVertex(getPlane(i).getNormal())) < 0) {
                        return Physics::OUTSIDE;
                    } else if (getPlane(i).distance(box.getNVertex(getPlane(i).getNormal())) < 0) {
                        result = Physics::INTERSECT;
                    }
                }

                return result;
            }

            template <class T>
            void Frustum<T>::computeProjectionMatrix(Matrix4x4<T> &m) {
                m.projection(getFov(), getRatio(), getDist().getX(), getDist().getY());
            }

            template <class T>
            Frustum<T>& Frustum<T>::operator=(Frustum<T> const& f) {
                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    planes[i] = f.getPlane(i);
                }
                near = f.getNear();
                far = f.getFar();
                dist = f.getDist();
                fov = f.getFov();
                ratio = f.getRatio();
            }

            template <class T>
            Frustum<T>& Frustum<T>::operator=(Frustum<T> && f) {
                planes = std::move(f.planes);
                near = std::move(f.getNear());
                far = std::move(f.getFar());
                dist = std::move(f.getDist());
                fov = std::move(f.getFov());
                ratio = std::move(f.getRatio());
            }

        };
    };
