
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
            template <class K>
            Vector4D<T>::Vector4D(Vector3D<K> const& u, T const& w) : Vector3D<T>::Vector3D(u), w(w) {
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
            void Vector4D<T>::setW(K const& w) {
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
            void Vector4D<T>::setCoord(Vector3D<K> const& u, L const& w) {
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
                Vector3D<T>::operator+=(u);
                setW(getW() + u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator-=(Vector4D<K> const& u) {
                Vector3D<T>::operator-=(u);
                setW(getW() - u.getW());
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator*=(K const& k) {
                Vector3D<T>::operator*=(k);
                setW(getW() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector4D<T>& Vector4D<T>::operator/=(K const& k) {
                Vector3D<T>::operator/=(k);
                setW(getW() / k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector4D<T>::operator|=(Vector4D<K> const& u) const {
                return Vector3D<T>::operator|=(u) + getW() * u.getW();
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
                return Vector3D<T>::operator==(u) && getW() == u.getW();
            }

            template <>
            template <class K>
            bool Vector4D<NREfloat>::operator==(Vector4D<K> const& u) const {
                return Vector3D<NREfloat>::operator==(u) && almostEqual(getW(), u.getW());
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
