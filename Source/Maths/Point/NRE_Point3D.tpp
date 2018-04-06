
    namespace NRE {
        namespace Maths {

            template <class T>
            Point3D<T>::Point3D() : Point3D(DEFAULT_X, DEFAULT_Y, DEFAULT_Z) {
            }

            template <class T>
            template <class K, class L, class M>
            Point3D<T>::Point3D(K const& x, L const& y, M const& z) : data{static_cast <T> (x), static_cast <T> (y), static_cast <T> (z)} {
            }

            template <class T>
            Point3D<T>::Point3D(T const& value) : Point3D(value, value, value) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Point2D<K> const& p, T const& z) : Point3D(p.getX(), p.getY(), z) {
            }

            template <class T>
            template <class K, class L>
            Point3D<T>::Point3D(Point3D<K> const& p, Vector3D<L> const& u) : Point3D(p.getX() + u.getX(), p.getY() + u.getY(), p.getZ() + u.getZ()) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D const& p) : Point3D(p.getX(), p.getY(), p.getZ()) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Point3D<K> const& p) : Point3D(p.getX(), p.getY(), p.getZ()) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Vector3D<K> const& u) : Point3D(u.getX(), u.getY(), u.getZ()) {
            }

            template <class T>
            Point3D<T>::~Point3D() {
            }

            template <class T>
            T const& Point3D<T>::getX() const {
                return data[0];
            }

            template <class T>
            T const& Point3D<T>::getY() const {
                return data[1];
            }

            template <class T>
            T const& Point3D<T>::getZ() const {
                return data[2];
            }

            template <class T>
            template <class K>
            void Point3D<T>::setX(K const& x) {
                data[0] = x;
            }

            template <class T>
            template <class K>
            void Point3D<T>::setY(K const& y) {
                data[1] = y;
            }

            template <class T>
            template <class K>
            void Point3D<T>::setZ(K const& z) {
                data[2] = z;
            }

            template <class T>
            template <class K, class L, class M>
            void Point3D<T>::setCoord(K const& x, L const& y, M const& z) {
                setX(x);    setY(y);    setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Point3D<T>::setCoord(Point2D<K> const& p, L const& z) {
                setX(p.getX()); setY(p.getY()); setZ(z);
            }

            template <class T>
            NREfloat Point3D<T>::distance(Point3D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point3D<T>::distanceSquared(Point3D<T> const& p) const {
                NREfloat xLenght = p.getX() - getX();
                NREfloat yLenght = p.getY() - getY();
                NREfloat zLenght = p.getZ() - getZ();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght;
            }

            template <class T>
            const T* const Point3D<T>::value() const {
                return &data[0];
            }

            template <class T>
            template <class K>
            Point3D<T>& Point3D<T>::operator+=(Vector3D<K> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                setZ(getZ() + u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Point3D<T>& Point3D<T>::operator-=(Vector3D<K> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
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
                Point3D<T> tmp(-getX(), -getY(), -getZ());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point3D<T>::operator==(Point3D<K> const& p) const {
                return getX() == p.getX() && getY() == p.getY() && getZ() == p.getZ();
            }

            template <>
            template <class K>
            bool Point3D<NREfloat>::operator==(Point3D<K> const& p) const {
                return almostEqual(getX(), p.getX()) && almostEqual(getY(), p.getY()) && almostEqual(getZ(), p.getZ());
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

        };
    };
