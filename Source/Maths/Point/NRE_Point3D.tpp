
    namespace NRE {
        namespace Maths {

            template <class T>
            Point3D<T>::Point3D() : z(DEFAULT_Z) {
            }

            template <class T>
            template <class K, class L, class M>
            Point3D<T>::Point3D(K const& x, L const& y, M const& z) : Point2D<T>::Point2D(x, y), z(z) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Point2D<K> const& p, T const& z) : Point2D<T>::Point2D(p), z(z) {
            }

            template <class T>
            template <class K, class L>
            Point3D<T>::Point3D(Point3D<K> const& p, Vector3D<L> const& u) : Point2D<T>::Point2D(p, u), z(p.getZ() + u.getZ()) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D const& p) : Point2D<T>::Point2D(p), z(p.getZ()) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Point3D<K> const& p) : Point2D<T>::Point2D(p), z(p.getZ()) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Vector3D<K> const& u) : Point2D<T>::Point2D(u), z(u.getZ()) {
            }

            template <class T>
            Point3D<T>::~Point3D() {
            }

            template <class T>
            T const& Point3D<T>::getZ() const {
                return z;
            }

            template <class T>
            template <class K>
            void Point3D<T>::setZ(K const& z) {
                this->z = z;
            }

            template <class T>
            template <class K, class L, class M>
            void Point3D<T>::setCoord(K const& x, L const& y, M const& z) {
                Point2D<T>::setCoord(x, y);
                setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Point3D<T>::setCoord(Point2D<K> const& p, L const& z) {
                Point2D<T>::setCoord(p.getX(), p.getY());
                setZ(z);
            }

            template <class T>
            NREfloat Point3D<T>::distance(Point3D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point3D<T>::distanceSquared(Point3D<T> const& p) const {
                NREfloat zLenght = p.getZ() - getZ();
                return Point2D<T>::distanceSquared(p) + zLenght * zLenght;
            }

            template <class T>
            template <class K>
            Point3D<T>& Point3D<T>::operator+=(Vector3D<K> const& u) {
                Point2D<T>::operator+=(u);
                setZ(getZ() + u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Point3D<T>& Point3D<T>::operator-=(Vector3D<K> const& u) {
                Point2D<T>::operator-=(u);
                setZ(getZ() - u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Point3D<T> Point3D<T>::operator+(Vector3D<K> const& u) const {
                Point3D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Point3D<T> Point3D<T>::operator-(Vector3D<K> const& u) const {
                Point3D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            template <class K>
            Vector3D<T> Point3D<T>::operator-(Point3D<K> const& p) const {
                return Vector3D<T>(*this, p);
            }

            template <class T>
            Point3D<T> Point3D<T>::operator-() const {
                Point3D<T> tmp(Point2D<T>::operator-(), -getZ());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator==(Point3D<K> const& p) const {
                return Point2D<T>::operator==(p) && getZ() == p.getZ();
            }

            template <>
            template <class K>
            bool Point3D<NREfloat>::operator==(Point3D<K> const& p) const {
                return Point2D<NREfloat>::operator==(p) && almostEqual(getZ(), p.getZ());
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator!=(Point3D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator<(Point3D<K> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator>(Point3D<K> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator<=(Point3D<K> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator>=(Point3D<K> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Point3D<T> const& p) {
                stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";
                return stream;
            }

        };
    };
