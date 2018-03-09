
    namespace NRE {
        namespace Maths {

            template <class T>
            Plane<T>::Plane() {
            }

            template <class T>
            template <class K, class L>
            Plane<T>::Plane(Vector3D<K> const& n, Point3D<L> const& p) : n(n), p(p) {
            }

            template <class T>
            template <class K, class L, class M>
            Plane<T>::Plane(Point3D<K> const& p1, Point3D<L> const& p2, Point3D<M> const& p3) {
                computeNormalFrom3Point(p1, p2, p3);
            }

            template <class T>
            Plane<T>::Plane(Plane const& p) : n(p.getNormal()), p(p.getPoint()) {
            }

            template <class T>
            template <class K>
            Plane<T>::Plane(Plane<K> const& p) : n(p.getNormal()), p(p.getPoint()) {
            }

            template <class T>
            Plane<T>::~Plane() {
            }

            template <class T>
            Vector3D<T> const& Plane<T>::getNormal() const {
                return n;
            }

            template <class T>
            Point3D<T> const& Plane<T>::getPoint() const {
                return p;
            }

            template <class T>
            template <class K>
            void Plane<T>::setNormal(Vector3D<K> const& u) {
                n = u;
            }

            template <class T>
            template <class K>
            void Plane<T>::setPoint(Point3D<K> const& p) {
                this->p = p;
            }

            template <class T>
            template <class K, class L, class M>
            void Plane<T>::computeNormalFrom3Point(Point3D<K> const& p1, Point3D<L> const& p2, Point3D<M> const& p3) {
                Vector3D<T> v, u;
                v = p2 - p1;
                u = p3 - p1;
                setNormal((v ^ u).normalize());
            }

            template <class T>
            template <class K>
            void Plane<T>::distance(Point3D<K> const& p) {
                T D = (-getNormal()) | Vector3D<T>(getPoint());
                return (getNormal() | Vector3D<T>(p)) + D;
            }

        };
    };
