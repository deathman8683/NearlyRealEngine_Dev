
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector3D<T>::Vector3D() : z(DEFAULT_Z) {
            }

            template <class T>
            Vector3D<T>::Vector3D(T const& x, T const& y, T const& z) : Vector2D<T>::Vector2D(x, y), z(z) {
            }

            template <class T>
            Vector3D<T>::Vector3D(T const& value) : Vector2D<T>::Vector2D(value), z(z) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Point3D<T> const& a, Point3D<T> const& b) : Vector2D<T>::Vector2D(a, b), z(b.getZ() - a.getZ()) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector3D const& u) : Vector2D<T>::Vector2D(u), z(u.getZ()) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector3D<K> const& u) : Vector2D<T>::Vector2D(u), z(static_cast <T> (u.getZ())) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Point3D<K> const& p) : Vector2D<T>::Vector2D(p), z(static_cast <T> (p.getZ())) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Vector4D<K> const& u) : Vector3D(static_cast <T> (u.getX()), static_cast <T> (u.getY()), static_cast <T> (u.getZ())) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector2D<T> const& u) : Vector3D(u, DEFAULT_Z) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector2D<T> const& u, T const& z) : Vector2D<T>::Vector2D(u), z(z) {
            }

            template <class T>
            Vector3D<T>::~Vector3D() {
            }

            template <class T>
            T const& Vector3D<T>::getZ() const {
                return z;
            }

            template <class T>
            T const& Vector3D<T>::getR() const {
                return this->x;
            }

            template <class T>
            T const& Vector3D<T>::getG() const {
                return this->y;
            }

            template <class T>
            T const& Vector3D<T>::getB() const {
                return z;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setZ(K const& z) {
                this->z = static_cast <T> (z);
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setR(K const& r) {
                this->x = static_cast <T> (r);
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setG(K const& g) {
                this->y = static_cast <T> (g);
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setB(K const& b) {
                this->z = static_cast <T> (b);
            }

            template <class T>
            template <class K, class L, class M>
            void Vector3D<T>::setCoord(K const& x, L const& y, M const& z) {
                Vector2D<T>::setCoord(x, y);    setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Vector3D<T>::setCoord(Vector2D<K> const& u, L const& z) {
                Vector2D<T>::setCoord(u.getX(), u.getY());    setZ(z);
            }

            template <class T>
            template <class K, class L, class M>
            void Vector3D<T>::setIntensities(K const& r, L const& g, M const& b) {
                setR(r);    setG(g);    setB(b);
            }

            template <class T>
            NREfloat const Vector3D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat const Vector3D<T>::normSquared() const {
                return this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ();
            }

            template <class T>
            void Vector3D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator=(Vector3D<T> const& base) {
                this->x = base.getX();
                this->y = base.getY();
                this->z = base.getZ();
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator=(Vector3D<T> && base) {
                this->x = std::move(base.getX());
                this->y = std::move(base.getY());
                this->z = std::move(base.getZ());
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator+=(Vector3D<T> const& u) {
                this->setX(this->getX() + u.getX());
                this->setY(this->getY() + u.getY());
                this->setZ(this->getZ() + u.getZ());
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator-=(Vector3D<T> const& u) {
                this->setX(this->getX() - u.getX());
                this->setY(this->getY() - u.getY());
                this->setZ(this->getZ() - u.getZ());
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator*=(T const& k) {
                this->setX(this->getX() * k);
                this->setY(this->getY() * k);
                this->setZ(this->getZ() * k);
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator/=(T const& k) {
                this->setX(this->getX() / k);
                this->setY(this->getY() / k);
                this->setZ(this->getZ() / k);
                return *this;
            }

            template <class T>
            NREfloat const Vector3D<T>::operator|=(Vector3D<T> const& u) const {
                return this->getX() * u.getX() + this->getY() * u.getY() + this->getZ() * u.getZ();
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator^=(Vector3D<T> const& u) {
                Vector3D<T> tmp(this->getY() * u.getZ() - this->getZ() * u.getY(),
                                this->getZ() * u.getX() - this->getX() * u.getZ(),
                                this->getX() * u.getY() - this->getY() * u.getX());
                *this = tmp;
                return *this;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator+(Vector3D<T> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator-(Vector3D<T> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator-() const {
                Vector3D<T> tmp(-this->getX(), -this->getY(), -getZ());
                return tmp;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator*(T const& k) const {
                Vector3D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator/(T const& k) const {
                Vector3D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            NREfloat const Vector3D<T>::operator|(Vector3D<T> const& u) const {
                return *this |= u;
            }

            template <class T>
            Vector3D<T> Vector3D<T>::operator^(Vector3D<T> const& u) const {
                Vector3D<T> tmp(*this);
                return tmp ^= u;
            }

            template <class T>
            template <class K>
            bool const Vector3D<T>::operator==(Vector3D<K> const& u) const {
                return this->getX() == u.getX() && this->getY() == u.getY() && this->getZ() == u.getZ();
            }

            template <>
            template <class K>
            bool const Vector3D<NREfloat>::operator==(Vector3D<K> const& u) const {
                return almostEqual(this->getX(), u.getX()) && almostEqual(this->getY(), u.getY()) && almostEqual(this->getZ(), u.getZ());
            }

            template <class T>
            template <class K>
            bool const Vector3D<T>::operator!=(Vector3D<K> const& u) const {
                return !(*this == u);
            }

            template <class T>
            bool const Vector3D<T>::operator<(Vector3D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator>(Vector3D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator<=(Vector3D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator>=(Vector3D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }

        };
    };
