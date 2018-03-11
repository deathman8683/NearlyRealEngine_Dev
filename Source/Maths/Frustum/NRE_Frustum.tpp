
    namespace NRE {
        namespace Maths {

            template <class T>
            Frustum<T>::Frustum() : Frustum(DEFAULT_FOV, DEFAULT_RATIO, Vector2D<T>(0, 0)) {
            }

            template <class T>
            template <class K, class L, class M>
            Frustum<T>::Frustum(K const& fov, L const& ratio, Vector2D<M> const& dist) : plane(0), dist(dist), fov(fov), ratio(ratio) {
                plane = new Plane<T>[FACE_NUM];
                computeNearAndFar();
            }

            template <class T>
            Frustum<T>::Frustum(Frustum const& f) : plane(f.getPlanes()), near(f.getNear()), far(f.getFar()), dist(f.getDist()), fov(f.getFov()), ratio(f.getRatio()) {
            }

            template <class T>
            template <class K>
            Frustum<T>::Frustum(Frustum<K> const& f) : plane(f.getPlanes()), near(f.getNear()), far(f.getFar()), dist(f.getDist()), fov(f.getFov()), ratio(f.getRatio()) {
            }

            template <class T>
            Frustum<T>::~Frustum() {
                delete[] plane;
            }

            template <class T>
            Plane<T>* const& Frustum<T>::getPlanes() const {
                return plane;
            }

            template <class T>
            Plane<T> const& Frustum<T>::getPlane(unsigned int const& index) const {
                return plane[index];
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
            void Frustum<T>::setPlanes(Plane<T>* const& p) {
                plane = p;
            }

            template <class T>
            template <class K>
            void Frustum<T>::setPlane(Plane<K> const& p, unsigned int const& index) {
                plane[index] = p;
            }

            template <class T>
            template <class K>
            void Frustum<T>::setNear(Vector2D<K> const& size) {
                near = size;
            }

            template <class T>
            template <class K>
            void Frustum<T>::setFar(Vector2D<K> const& size) {
                far = size;
            }

            template <class T>
            template <class K>
            void Frustum<T>::setDist(Vector2D<K> const& size) {
                dist = size;
            }
            template <class T>
            template <class K>
            void Frustum<T>::setFov(K const& f) {
                fov = f;
            }

            template <class T>
            template <class K>
            void Frustum<T>::setRatio(K const& r) {
                ratio = r;
            }

            template <class T>
            void Frustum<T>::computeNearAndFar() {
                T tang = std::tan(toRad(getFov()) * 0.5);

                setNear(Vector2D<T>(0, tang * getDist().getX()));
                setNear(Vector2D<T>(getNear().getY() * getRatio(), getNear().getY()));
                setFar(Vector2D<T>(0, tang * getDist().getY()));
                setFar(Vector2D<T>(getFar().getY() * getRatio(), getFar().getY()));

            }

            template <class T>
            template <class K>
            Physics::CollisionResult const Frustum<T>::pointCollision(Point3D<K> const& p) const {
                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    if (getPlane(i).distance(p) < 0) {
                        return Physics::OUTSIDE;
                    }
                }
                return Physics::INSIDE;
            }

            template <class T>
            template <class K, class L>
            Physics::CollisionResult const Frustum<T>::sphereCollision(Point3D<K> const& p, L const& radius) const {
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
            template <class K>
            Physics::CollisionResult const Frustum<T>::AABBCollision(Physics::AABB<K> const& box) const {
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
            template <class K>
            void Frustum<T>::computeProjectionMatrix(Matrix4x4<K> &m) {
                m.projection(getFov(), getRatio(), getDist().getX(), getDist().getY());
            }

        };
    };
