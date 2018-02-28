
    namespace NRE {
        namespace Maths {

            template <class T>
            Point4D<T>::Point4D() : w(DEFAULT_W) {
            }

            template <class T>
            template <class K, class L, class M, class N>
            Point4D<T>::Point4D(K const& x, L const& y, M const& z, N const& w) : Point3D<T>::Point3D(x, y, z), w(w) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Point3D<K> const& p, T const& w) : Point3D<T>::Point3D(p), w(w) {
            }

            template <class T>
            template <class K, class L>
            Point4D<T>::Point4D(Point4D<K> const& p, Vector4D<L> const& u) : Point3D<T>::Point3D(p, u), w(p.getW() + u.getW()) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D const& p) : Point3D<T>::Point3D(p), w(p.getW()) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Point4D<K> const& p) : Point3D<T>::Point3D(p), w(p.getW()) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Vector4D<K> const& u) : Point3D<T>::Point3D(u), w(u.getW()) {
            }

            template <class T>
            Point4D<T>::~Point4D() {
            }

            template <class T>
            T const& Point4D<T>::getW() const {
                return w;
            }

            template <class T>
            template <class K>
            void Point4D<T>::setW(K const& w) {
                this->w = w;
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Point4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                Point3D<T>::setCoord(x, y, z);
                setW(w);
            }

            template <class T>
            template <class K, class L>
            void Point4D<T>::setCoord(Point3D<K> const& p, L const& w) {
                Point3D<T>::setCoord(p.getX(), p.getY(), p.getZ());
                setW(w);
            }

            template <class T>
            NREfloat Point4D<T>::distance(Point4D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point4D<T>::distanceSquared(Point4D<T> const& p) const {
                NREfloat wLenght = p.getW() - getW();
                return Point3D<T>::distanceSquared(p) + wLenght * wLenght;
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator+=(Vector4D<K> const& u) {
                Point3D<T>::operator+=(u);
                setW(getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator-=(Vector4D<K> const& u) {
                Point3D<T>::operator-=(u);
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
                Point3D<T> tmp(Point3D<T>::operator-(), -getW());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator==(Point4D<K> const& p) const {
                return Point3D<T>::operator==(p) && getW() == p.getW();
            }

            template <>
            template <class K>
            bool Point4D<NREfloat>::operator==(Point4D<K> const& p) const {
                return Point3D<NREfloat>::operator==(p) && almostEqual(getW(), p.getW());
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
