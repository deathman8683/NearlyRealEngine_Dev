
    namespace NRE {
        namespace Maths {

            template <class T>
            Point4D<T>::Point4D() : w(DEFAULT_W) {
            }

            template <class T>
            Point4D<T>::Point4D(T const& x, T const& y, T const& z, T const& w) : Point3D<T>::Point3D(x, y, z), w(w) {
            }

            template <class T>
            Point4D<T>::Point4D(T const& value) : Point3D<T>::Point3D(value), w(value) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D<T> const& p, Vector4D<T> const& u) : Point3D<T>::Point3D(p, u), w(p.getW() + u.getW()) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D const& p) : Point3D<T>::Point3D(p), w(p.getW()) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D && p) : Point3D<T>::Point3D(std::move(p)), w(std::move(p.getW())) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Point4D<K> const& p) : Point3D<T>::Point3D(p), w(static_cast <T> (p.getW())) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Vector4D<K> const& u) : Point3D<T>::Point3D(u), w(static_cast <T> (u.getW())) {
            }

            template <class T>
            Point4D<T>::Point4D(Point3D<T> const& p) : Point4D(p, DEFAULT_W) {
            }

            template <class T>
            Point4D<T>::Point4D(Point3D<T> const& p, T const& w) : Point3D<T>::Point3D(p), w(w) {
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
                Point3D<T>::setCoord(x, y, z);    setW(w);
            }

            template <class T>
            template <class K, class L>
            void Point4D<T>::setCoord(Point3D<K> const& p, L const& w) {
                Point3D<T>::setCoord(p.getX(), p.getY(), p.getZ()); setW(w);
            }

            template <class T>
            NREfloat const Point4D<T>::distance(Point4D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point4D<T>::distanceSquared(Point4D<T> const& p) const {
                NREfloat wLenght = p.getW() - getW();
                return Point3D<T>::distanceSquared(p) + wLenght * wLenght;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator=(Point4D<T> const& base) {
                Point3D<T>::operator=(base);
                this->w = base.getW();
                return *this;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator=(Point4D<T> && base) {
                Point3D<T>::operator=(std::move(base));
                this->w = std::move(base.getW());
                return *this;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator+=(Vector4D<T> const& u) {
                Point3D<T>::operator+=(u);
                this->setW(this->getW() + u.getW());
                return *this;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator-=(Vector4D<T> const& u) {
                Point3D<T>::operator-=(u);
                this->setW(this->getW() - u.getW());
                return *this;
            }

            template <class T>
            Point4D<T> Point4D<T>::operator+(Vector4D<T> const& u) const {
                Point4D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Point4D<T> Point4D<T>::operator-(Vector4D<T> const& u) const {
                Point4D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector4D<T> Point4D<T>::operator-(Point4D<T> const& p) const {
                return Vector4D<T>(*this, p);
            }

            template <class T>
            Point4D<T> Point4D<T>::operator-() const {
                Point3D<T> tmp(Point3D<T>::operator-(), -getW());
                return tmp;
            }

            template <class T>
            template <class K>
            bool const Point4D<T>::operator==(Point4D<K> const& p) const {
                return Point3D<T>::operator==(p) && this->getW() == p.getW();
            }

            template <>
            template <class K>
            bool const Point4D<NREfloat>::operator==(Point4D<K> const& p) const {
                return Point3D<NREfloat>::operator==(p) && almostEqual(this->getW(), p.getW());
            }

            template <class T>
            template <class K>
            bool const Point4D<T>::operator!=(Point4D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            bool const Point4D<T>::operator<(Point4D<T> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator>(Point4D<T> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator<=(Point4D<T> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator>=(Point4D<T> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
