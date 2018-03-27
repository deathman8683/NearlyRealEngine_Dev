
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector3D<T>::Vector3D() : Vector3D(DEFAULT_X, DEFAULT_Y, DEFAULT_Z) {
            }

            template <class T>
            template <class K, class L, class M>
            Vector3D<T>::Vector3D(K const& x, L const& y, M const& z) : data{static_cast <T> (x), static_cast <T> (y), static_cast <T> (z)} {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector2D<K> const& u, T const& z) : Vector3D(u.getX(), u.getY(), z) {
            }

            template <class T>
            template <class K, class L>
            Vector3D<T>::Vector3D(Point3D<K> const& a, Point3D<L> const& b) : Vector3D(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ()) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector3D const& u) : Vector3D(u.getX(), u.getY(), u.getZ()) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector3D<K> const& u) : Vector3D(u.getX(), u.getY(), u.getZ()) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Point3D<K> const& p) : Vector3D(p.getX(), p.getY(), p.getZ()) {
            }

            template <class T>
            Vector3D<T>::~Vector3D() {
            }

            template <class T>
            T const& Vector3D<T>::getX() const {
                return data[0];
            }

            template <class T>
            T const& Vector3D<T>::getY() const {
                return data[1];
            }

            template <class T>
            T const& Vector3D<T>::getZ() const {
                return data[2];
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setX(K const& x) {
                data[0] = x;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setY(K const& y) {
                data[1] = y;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setZ(K const& z) {
                data[2] = z;
            }

            template <class T>
            template <class K, class L, class M>
            void Vector3D<T>::setCoord(K const& x, L const& y, M const& z) {
                setX(x);    setY(y);    setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Vector3D<T>::setCoord(Vector2D<K> const& u, L const& z) {
                setX(u.getX());    setY(u.getY());    setZ(z);
            }

            template <class T>
            NREfloat Vector3D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector3D<T>::normSquared() const {
                return getX() * getX() + getY() * getY() + getZ() * getZ();
            }

            template <class T>
            void Vector3D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            T* const Vector3D<T>::value() {
                return &data[0];
            }

            template <class T>
            T& Vector3D<T>::operator[](unsigned int const& index) {
                return data[index];
            }

            template <class T>
            const T& Vector3D<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator+=(Vector3D<K> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                setZ(getZ() + u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator-=(Vector3D<K> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                setZ(getZ() - u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator*=(K const& k) {
                setX(getX() * k);
                setY(getY() * k);
                setZ(getZ() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator/=(K const& k) {
                setX(getX() / k);
                setY(getY() / k);
                setZ(getZ() / k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector3D<T>::operator|=(Vector3D<K> const& u) const {
                return getX() * u.getX() + getY() * u.getY() + getZ() * u.getZ();
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator^=(Vector3D<K> const& u) {
                Vector3D<T> tmp(this->getY() * u.getZ() - this->getZ() * u.getY(),
                                this->getZ() * u.getX() - this->getX() * u.getZ(),
                                this->getX() * u.getY() - this->getY() * u.getX());
                *this = tmp;
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T> Vector3D<T>::operator+(Vector3D<K> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Vector3D<T> Vector3D<T>::operator-(Vector3D<K> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator-() const {
                Vector3D<T> tmp(-this->getX(), -this->getY(), -getZ());
                return tmp;
            }

            template <class T>
            template <class K>
            Vector3D<T> Vector3D<T>::operator*(K const& k) const {
                Vector3D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Vector3D<T> Vector3D<T>::operator/(K const& k) const {
                Vector3D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator==(Vector3D<K> const& u) const {
                return getX() == u.getX() && getY() == u.getY() && getZ() == u.getZ();
            }

            template <>
            template <class K>
            bool Vector3D<NREfloat>::operator==(Vector3D<K> const& u) const {
                return almostEqual(getX(), u.getX()) && almostEqual(getY(), u.getY()) && almostEqual(getZ(), u.getZ());
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator!=(Vector3D<K> const& u) const {
                return !(*this == u);
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator<(Vector3D<K> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator>(Vector3D<K> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator<=(Vector3D<K> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector3D<T>::operator>=(Vector3D<K> const& u) const {
                return normSquared() >= u.normSquared();
            }

            template <class T>
            template <class K>
            NREfloat Vector3D<T>::operator|(Vector3D<K> const& u) const {
                return *this |= u;
            }

            template <class T>
            template <class K>
            Vector3D<T> Vector3D<T>::operator^(Vector3D<K> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp ^= u;
            }

        };
    };
