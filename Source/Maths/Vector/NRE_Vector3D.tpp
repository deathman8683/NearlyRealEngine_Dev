
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector3D<T>::Vector3D() : z(DEFAULT_Z) {
            }

            template <class T>
            template <class K, class L, class M>
            Vector3D<T>::Vector3D(K const& x, L const& y, M const& z) : Vector2D<T>::Vector2D(x, y), z(z) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector2D<K> const& u, T const& z) : Vector2D<T>::Vector2D(u), z(z) {
            }

            template <class T>
            template <class K, class L>
            Vector3D<T>::Vector3D(Point3D<K> const& a, Point3D<L> const& b) : Vector2D<T>::Vector2D(a, b), z(b.getZ() - a.getZ()) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector3D const& u) : Vector2D<T>::Vector2D(u), z(u.getZ()) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector3D<K> const& u) : Vector2D<T>::Vector2D(u), z(u.getZ()) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Point3D<K> const& p) : Vector2D<T>::Vector2D(p), z(p.getZ()) {
            }

            template <class T>
            Vector3D<T>::~Vector3D() {
            }

            template <class T>
            T const& Vector3D<T>::getZ() const {
                return z;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setZ(K const& z) {
                this->z = z;
            }

            template <class T>
            template <class K, class L, class M>
            void Vector3D<T>::setCoord(K const& x, L const& y, M const& z) {
                Vector2D<T>::setCoord(x, y);
                setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Vector3D<T>::setCoord(Vector2D<K> const& u, L const& z) {
                Vector2D<T>::setCoord(u.getX(), u.getY());
                setZ(z);
            }

            template <class T>
            NREfloat Vector3D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector3D<T>::normSquared() const {
                return Vector2D<T>::normSquared() + getZ() * getZ();
            }

            template <class T>
            void Vector3D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator+=(Vector3D<K> const& u) {
                setCoord(this->getX() + u.getX(), this->getY() + u.getY(), getZ() + u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator-=(Vector3D<K> const& u) {
                setCoord(this->getX() - u.getX(), this->getY() - u.getY(), getZ() - u.getZ());
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator*=(K const& k) {
                setCoord(this->getX() * k, this->getY() * k, getZ() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector3D<T>& Vector3D<T>::operator/=(K const& k) {
                setCoord(this->getX() / k, this->getY() / k, getZ() / k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector3D<T>::operator|=(Vector3D<K> const& u) const {
                return this->getX() * u.getX() + this->getY() * u.getY() + getZ() * u.getZ();
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
                return this->getX() == u.getX() && this->getY() == u.getY() && getZ() == u.getZ();
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

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Vector3D<T> const& u) {
                stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << ")";
                return stream;
            }

        };
    };
