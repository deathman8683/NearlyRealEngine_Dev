
    namespace NRE {
        namespace Maths {

            template <class T>
            Frustum<T>::Frustum() : Frustum(Vector2D<T>(0, 0)) {
            }

            template <class T>
            template <class K, class L, class M>
            Frustum<T>::Frustum(K const& fov, L const& ratio, Vector2D<M> const& dist) : plane(0), dist(dist) {
                plane = new Plane<T>[FACE_NUM];
                computeNearAndFar(fov, ratio);
            }

            template <class T>
            template <class K, class L, class M>
            Frustum<T>::Frustum(Vector2D<K> const& near, Vector2D<L> const& far, Vector2D<M> const& dist) : plane(0), near(near), far(far), dist(dist) {
                plane = new Plane<T>[FACE_NUM];
            }

            template <class T>
            Frustum<T>::Frustum(Frustum const& f) : plane(f.getPlanes()), near(f.getNear()), far(f.getFar()), dist(f.getDist()) {
            }

            template <class T>
            template <class K>
            Frustum<T>::Frustum(Frustum<K> const& f) : plane(f.getPlanes()), near(f.getNear()), far(f.getFar()), dist(f.getDist()) {
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
            template <class K, class L>
            void Frustum<T>::computeNearAndFar(K const& fov, L const& ratio) {
                T tang = std::tan(toRad(fov) * 0.5);

                setNear(Vector2D<T>(tang * getDist().getX(), getNear().getY() * ratio));
                setFar(Vector2D<T>(tang * getDist().getY(), getFar().getY() * ratio));
            }

            template <class T>
            template <class K>
            Physics::CollisionResult const& Frustum<T>::pointCollision(Point3D<K> const& p) const {
                for (GLuint i = 0; i < FACE_NUM; i = i + 1) {
                    if (getPlane(i).distance(p) < 0) {
                        return Physics::OUTSIDE;
                    }
                }
                return Physics::INSIDE;
            }

            template <class T>
            template <class K, class L>
            Physics::CollisionResult const& Frustum<T>::sphereCollision(Point3D<K> const& p, L const& radius) {
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

        };
    };
