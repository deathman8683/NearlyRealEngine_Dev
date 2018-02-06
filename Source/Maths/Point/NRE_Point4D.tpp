
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
            template <class K, class L>
            Point4D<T>::Point4D(Point3D<K> const& p, L const& w) : Point3D<T>::Point3D(p), w(w) {
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
            void Point4D<T>::setCoord(Point3D<K> const& p, L const& z) {
                Point3D<T>::setCoord(p.getX(), p.getY(), p.getZ());
                setW(w);
            }

            template <class T>
            NREfloat Point4D<T>::distance(Point4D<T> const& p) const {
                return sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point4D<T>::distanceSquared(Point4D<T> const& p) const {
                NREfloat w_lenght = p.getW() - getW();
                return Point3D<T>::distanceSquared(p) + w_lenght * w_lenght;
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator+=(Vector4D<K> const& u) {
                setCoord(this->getX() + u.getX(), this->getY() + u.getY(), this->getZ() + u.getZ(), getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Point4D<T>& Point4D<T>::operator-=(Vector4D<K> const& u) {
                setCoord(this->getX() - u.getX(), this->getY() - u.getY(), this->getZ() - u.getZ(), getW() - u.getW());
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
                return Vector4D<T>(p, *this);
            }

            template <class T>
            Point4D<T> Point4D<T>::operator-() const {
                Point4D<T> tmp(-this->getX(), -this->getY(), -this->getZ(), -getW());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point4D<T>::operator==(Point4D<K> const& p) const {
                return this->getX() == p.getX() && this->getY() == p.getY() && this->getZ() == p.getZ() && getW() == p.getW();
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

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Point4D<T> const& p) {
                stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << "," << p.getW() << ")";
                return stream;
            }

        };
    };
