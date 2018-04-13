
    namespace NRE {
        namespace Maths {

            template <class T>
            Point4D<T>::Point4D() : Point4D(DEFAULT_X, DEFAULT_Y, DEFAULT_Z, DEFAULT_W) {
            }

            template <class T>
            template <class K, class L, class M, class N>
            Point4D<T>::Point4D(K const& x, L const& y, M const& z, N const& w) : data{static_cast <T> (x), static_cast <T> (y), static_cast <T> (z), static_cast <T> (w)} {
            }

            template <class T>
            Point4D<T>::Point4D(T const& value) : Point4D(value, value, value, value) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Point3D<K> const& p, T const& w) : Point4D(p.getX(), p.getY(), p.getZ(), w) {
            }

            template <class T>
            template <class K, class L>
            Point4D<T>::Point4D(Point4D<K> const& p, Vector4D<L> const& u) : Point4D(p.getX() + u.getX(), p.getY() + u.getY(), p.getZ() + u .getZ(), p.getW() + u.getW()) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D const& p) : Point4D(p.getX(), p.getY(), p.getZ(), p.getW()) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Point4D<K> const& p) : Point4D(p.getX(), p.getY(), p.getZ(), p.getW()) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Vector4D<K> const& u) : Point4D(u.getX(), u.getY(), u.getZ(), u.getW()) {
            }

            template <class T>
            Point4D<T>::~Point4D() {
            }

            template <class T>
            T const& Point4D<T>::getX() const {
                return data[0];
            }

            template <class T>
            T const& Point4D<T>::getY() const {
                return data[1];
            }

            template <class T>
            T const& Point4D<T>::getZ() const {
                return data[2];
            }

            template <class T>
            T const& Point4D<T>::getW() const {
                return data[3];
            }

            template <class T>
            template <class K>
            void Point4D<T>::setX(K const& x) {
                data[0] = x;
            }

            template <class T>
            template <class K>
            void Point4D<T>::setY(K const& y) {
                data[1] = y;
            }

            template <class T>
            template <class K>
            void Point4D<T>::setZ(K const& z) {
                data[2] = z;
            }

            template <class T>
            template <class K>
            void Point4D<T>::setW(K const& w) {
                data[3] = w;
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Point4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                setX(x);    setY(y);    setZ(z);    setW(w);
            }

            template <class T>
            template <class K, class L>
            void Point4D<T>::setCoord(Point3D<K> const& p, L const& w) {
                setX(p.getX()); setY(p.getY()); setZ(p.getZ()); setW(w);
            }

            template <class T>
            NREfloat Point4D<T>::distance(Point4D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point4D<T>::distanceSquared(Point4D<T> const& p) const {
                NREfloat xLenght = p.getX() - getX();
                NREfloat yLenght = p.getY() - getY();
                NREfloat zLenght = p.getZ() - getZ();
                NREfloat wLenght = p.getW() - getW();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght + wLenght * wLenght;
            }

            template <class T>
            const T* const Point4D<T>::value() const {
                return &data[0];
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator+=(Vector4D<K> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                setZ(getZ() + u.getZ());
                setW(getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator-=(Vector4D<K> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                setZ(getZ() - u.getZ());
                setW(getW() - u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Point4D<T> Point4D<T>::operator+(Vector4D<K> const& u) const {
                Point4D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Point4D<T> Point4D<T>::operator-(Vector4D<K> const& u) const {
                Point4D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            template <class K>
            Vector4D<T> Point4D<T>::operator-(Point4D<K> const& p) const {
                return Vector4D<T>(*this, p);
            }

            template <class T>
            Point4D<T> Point4D<T>::operator-() const {
                Point3D<T> tmp(-getX(), -getY(), -getZ(), -getW());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator==(Point4D<K> const& p) const {
                return getX() == p.getX() && getY() == p.getY() && getZ() == p.getZ() && getW() == p.getW();
            }

            template <>
            template <class K>
            bool Point4D<NREfloat>::operator==(Point4D<K> const& p) const {
                return almostEqual(getX(), p.getX()) && almostEqual(getY(), p.getY()) && almostEqual(getZ(), p.getZ()) && almostEqual(getW(), p.getW());
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator!=(Point4D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator<(Point4D<K> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator>(Point4D<K> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator<=(Point4D<K> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator>=(Point4D<K> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
