
    namespace NRE {
        namespace Maths {

            template <class T>
            Plane<T>::Plane() {
            }

            template <class T>
            Plane<T>::Plane(Vector3D<T> const& n, Point3D<T> const& p) : n(n), p(p) {
            }

            template <class T>
            Plane<T>::Plane(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3) {
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
            void Plane<T>::setNormal(Vector3D<T> const& u) {
                n = u;
            }

            template <class T>
            void Plane<T>::setPoint(Point3D<T> const& p) {
                this->p = p;
            }

            template <class T>
            void Plane<T>::setNormalAndPoint(Vector3D<T> const& u, Point3D<T> const& p) {
                setNormal(u);
                setPoint(p);
            }

            template <class T>
            void Plane<T>::computeNormalFrom3Point(Point3D<T> const& p1, Point3D<T> const& p2, Point3D<T> const& p3) {
                Vector3D<T> v, u;
                v = p2 - p1;
                u = p3 - p1;
                setNormal(v ^ u);
                n.normalize();
            }

            template <class T>
            NREfloat const Plane<T>::distance(Point3D<T> const& p) const {
                T D = (-getNormal()) | getPoint();
                return (getNormal() | p) + D;
            }

        };
    };
