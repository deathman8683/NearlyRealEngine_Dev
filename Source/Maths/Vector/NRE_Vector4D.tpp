
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector4D<T>::Vector4D() : w(DEFAULT_W) {
            }

            template <class T>
            template <class K, class L, class M, class N>
            Vector4D<T>::Vector4D(K const& x, L const& y, M const& z, N const& w) : Vector3D<T>::Vector3D(x, y, z), w(w) {
            }

            template <class T>
            template <class K, class L>
            Vector4D<T>::Vector4D(Vector3D<K> const& u, L const& w) : Vector3D<T>::Vector3D(u), w(w) {
            }

            template <class T>
            template <class K, class L>
            Vector4D<T>::Vector4D(Point4D<K> const& a, Point4D<L> const& b) : Vector3D<T>::Vector3D(a, b), w(b.getW() - a.getW()) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D const& u) : Vector3D<T>::Vector3D(u), w(u.getW()) {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Vector4D<K> const& u) : Vector3D<T>::Vector3D(u), w(u.getW()) {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Point4D<K> const& p) : Vector3D<T>::Vector3D(p), w(p.getW()) {
            }

            template <class T>
            Vector4D<T>::~Vector4D() {
            }

            template <class T>
            T const& Vector4D<T>::getW() const {
                return w;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setW(K const& z) {
                this->w = w;
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Vector4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                Vector3D<T>::setCoord(x, y, z);
                setW(w);
            }

            template <class T>
            template <class K, class L>
            void Vector4D<T>::setCoord(Vector3D<K> const& u, L const& z) {
                Vector3D<T>::setCoord(u.getX(), u.getY(), u.getZ());
                setW(w);
            }

            template <class T>
            NREfloat Vector4D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector4D<T>::normSquared() const {
                return Vector3D<T>::normSquared() + getW() * getW();
            }

            template <class T>
            void Vector4D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator+=(Vector4D<K> const& u) {
                setCoord(this->getX() + u.getX(), this->getY() + u.getY(), this->getZ() + u.getZ(), getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator-=(Vector4D<K> const& u) {
                setCoord(this->getX() - u.getX(), this->getY() - u.getY(), this->getZ() - u.getZ(), getW() - u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator*=(K const& k) {
                setCoord(this->getX() * k, this->getY() * k, this->getZ() * k, getW() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator/=(K const& k) {
                setCoord(this->getX() / k, this->getY() / k, this->getZ() / k, getW() * k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector4D<T>::operator|=(Vector4D<K> const& u) const {
                return this->getX() * u.getX() + this->getY() * u.getY() + this->getZ() * u.getZ() + getW() * u.getW();
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
                return this->getX() == u.getX() && this->getY() == u.getY() && this->getZ() == u.getZ() && this->getW() == u.getW();
            }

            template <class T>
            template <class K>
            bool Vector4D<T>::operator!=(Vector4D<K> const& u) const {
                return !(this == u);
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

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Vector4D<T> const& u) {
                stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << "," << u.getW() << ")";
                return stream;
            }

        };
    };
