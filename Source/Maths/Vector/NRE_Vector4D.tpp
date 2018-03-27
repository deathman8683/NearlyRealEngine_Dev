
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector4D<T>::Vector4D() : Vector4D(DEFAULT_X, DEFAULT_Y, DEFAULT_Z, DEFAULT_W) {
            }

            template <class T>
            template <class K, class L, class M, class N>
            Vector4D<T>::Vector4D(K const& x, L const& y, M const& z, N const& w) : data{x, y, z, w} {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Vector3D<K> const& u, T const& w) : data{u.getX(), u.getY(), u.getZ(), w} {
            }

            template <class T>
            template <class K, class L>
            Vector4D<T>::Vector4D(Point4D<K> const& a, Point4D<L> const& b) : data{b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ(), b.getW() - a.getW()} {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D const& u) : data{u.getX(), u.getY(), u.getZ(), u.getW()} {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Vector4D<K> const& u) : data{u.getX(), u.getY(), u.getZ(), u.getW()} {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Point4D<K> const& p) : data{p.getX(), p.getY(), p.getZ(), p.getW()} {
            }

            template <class T>
            Vector4D<T>::~Vector4D() {
            }

            template <class T>
            T const& Vector4D<T>::getX() const {
                return data[0];
            }

            template <class T>
            T const& Vector4D<T>::getY() const {
                return data[1];
            }

            template <class T>
            T const& Vector4D<T>::getZ() const {
                return data[2];
            }

            template <class T>
            T const& Vector4D<T>::getW() const {
                return data[3];
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setX(K const& x) {
                data[0] = x;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setY(K const& y) {
                data[1] = y;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setZ(K const& z) {
                data[2] = z;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setW(K const& w) {
                data[3] = w;
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Vector4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                setX(x);    setY(y);    setZ(z);    setW(w);
            }

            template <class T>
            template <class K, class L>
            void Vector4D<T>::setCoord(Vector3D<K> const& u, L const& w) {
                setX(u.getX());    setY(u.getY());    setZ(u.getZ());    setW(w);
            }

            template <class T>
            NREfloat Vector4D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector4D<T>::normSquared() const {
                return getX() * getX() + getY() * getY() + getZ() * getZ() + getW() * getW();
            }

            template <class T>
            void Vector4D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator+=(Vector4D<K> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                setZ(getZ() + u.getZ());
                setW(getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator-=(Vector4D<K> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                setZ(getZ() - u.getZ());
                setW(getW() - u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator*=(K const& k) {
                setX(getX() * k);
                setY(getY() * k);
                setZ(getZ() * k);
                setW(getW() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator/=(K const& k) {
                setX(getX() / k);
                setY(getY() / k);
                setZ(getZ() / k);
                setW(getW() / k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector4D<T>::operator|=(Vector4D<K> const& u) const {
                return getX() * u.getX() + getY() * u.getY() + getZ() * u.getZ() + getW() * u.getW();
            }

            template <class T>
            template <class K>
            Vector4D<T> Vector4D<T>::operator+(Vector4D<K> const& u) const {
                Vector4D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Vector4D<T> Vector4D<T>::operator-(Vector4D<K> const& u) const {
                Vector4D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator-() const {
                Vector4D<T> tmp(-this->getX(), -this->getY(), -this->getZ(), -getW());
                return tmp;
            }

            template <class T>
            template <class K>
            Vector4D<T> Vector4D<T>::operator*(K const& k) const {
                Vector4D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Vector4D<T> Vector4D<T>::operator/(K const& k) const {
                Vector4D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator==(Vector4D<K> const& u) const {
                return getX() == u.getX() && getY() == u.getY() && getZ() == u.getZ() && getW() == u.getW();
            }

            template <>
            template <class K>
            bool Vector4D<NREfloat>::operator==(Vector4D<K> const& u) const {
                return almostEqual(getX(), u.getX()) && almostEqual(getY(), u.getY()) && almostEqual(getZ(), u.getZ()) && almostEqual(getW(), u.getW());
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator!=(Vector4D<K> const& u) const {
                return !(*this == u);
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator<(Vector4D<K> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator>(Vector4D<K> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator<=(Vector4D<K> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator>=(Vector4D<K> const& u) const {
                return normSquared() >= u.normSquared();
            }

            template <class T>
            template <class K>
            NREfloat Vector4D<T>::operator|(Vector4D<K> const& u) const {
                return *this |= u;
            }

        };
    };
