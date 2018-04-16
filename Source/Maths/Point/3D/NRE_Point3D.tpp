
    namespace NRE {
        namespace Maths {

            template <class T>
            Point3D<T>::Point3D() : z(DEFAULT_Z) {
            }

            template <class T>
            Point3D<T>::Point3D(T const& x, T const& y, T const& z) : Point2D<T>::Point2D(x, y), z(z) {
            }

            template <class T>
            Point3D<T>::Point3D(T const& value) : Point2D<T>::Point2D(value), z(value) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D<T> const& p, Vector3D<T> const& u) : Point2D<T>::Point2D(p, u), z(p.getZ() + u.getZ()) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D const& p) : Point2D<T>::Point2D(p), z(p.getZ()) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D && p) : Point2D<T>::Point2D(std::move(p)), z(std::move(p.getZ())) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Point3D<K> const& p) : Point2D<T>::Point2D(p), z(static_cast <T> (p.getZ())) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Vector3D<K> const& u) : Point2D<T>::Point2D(u), z(static_cast <T> (u.getZ())) {
            }

            template <class T>
            Point3D<T>::Point3D(Point2D<T> const& p) : Point3D(p, DEFAULT_Z) {
            }

            template <class T>
            Point3D<T>::Point3D(Point2D<T> const& p, T const& z) : Point2D<T>::Point2D(p), z(z) {
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
                this->z = static_cast <T> (z);
            }

            template <class T>
            template <class K, class L, class M>
            void Point3D<T>::setCoord(K const& x, L const& y, M const& z) {
                Point2D<T>::setCoord(x, y);    setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Point3D<T>::setCoord(Point2D<K> const& p, L const& z) {
                Point2D<T>::setCoord(p.getX(), p.getY());    setZ(z);
            }

            template <class T>
            NREfloat const Point3D<T>::distance(Point3D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point3D<T>::distanceSquared(Point3D<T> const& p) const {
                NREfloat zLenght = p.getZ() - getZ();
                return Point2D<T>::distanceSquared(p) + zLenght * zLenght;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator=(Point3D<T> const& base) {
                Point2D<T>::operator=(base);
                this->z = base.getZ();
                return *this;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator=(Point3D<T> && base) {
                Point2D<T>::operator=(std::move(base));
                this->z = std::move(base.getZ());
                return *this;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator+=(Vector3D<T> const& u) {
                Point2D<T>::operator+=(u);
                this->setZ(this->getZ() + u.getZ());
                return *this;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator-=(Vector3D<T> const& u) {
                Point2D<T>::operator-=(u);
                this->setZ(this->getZ() - u.getZ());
                return *this;
            }

            template <class T>
            Point3D<T> Point3D<T>::operator+(Vector3D<T> const& u) const {
                Point3D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Point3D<T> Point3D<T>::operator-(Vector3D<T> const& u) const {
                Point3D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector3D<T> Point3D<T>::operator-(Point3D<T> const& p) const {
                return Vector3D<T>(*this, p);
            }

            template <class T>
            Point3D<T> Point3D<T>::operator-() const {
                Point3D<T> tmp(Point2D<T>::operator-(), -getZ());
                return tmp;
            }

            template <class T>
            template <class K>
            bool const Point3D<T>::operator==(Point3D<K> const& p) const {
                return Point2D<T>::operator==(p) && getZ() == p.getZ();
            }

            template <>
            template <class K>
            bool const Point3D<NREfloat>::operator==(Point3D<K> const& p) const {
                return Point2D<NREfloat>::operator==(p) && almostEqual(this->getZ(), p.getZ());
            }

            template <class T>
            template <class K>
            bool const Point3D<T>::operator!=(Point3D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            bool const Point3D<T>::operator<(Point3D<T> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator>(Point3D<T> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator<=(Point3D<T> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator>=(Point3D<T> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
