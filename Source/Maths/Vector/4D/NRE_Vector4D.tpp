
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector4D<T>::Vector4D() : w(DEFAULT_W) {
            }

            template <class T>
            Vector4D<T>::Vector4D(T const& x, T const& y, T const& z, T const& w) : Vector3D<T>::Vector3D(x, y, z), w(w) {
            }

            template <class T>
            Vector4D<T>::Vector4D(T const& value) : Vector3D<T>::Vector3D(value), w(value) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Point4D<T> const& a, Point4D<T> const& b) : Vector3D<T>::Vector3D(a, b), w(b.getW() - a.getW()) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D const& u) : Vector3D<T>::Vector3D(u), w(u.getW()) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D && u) : Vector3D<T>::Vector3D(u), w(std::move(u.getW())) {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Vector4D<K> const& u) : Vector3D<T>::Vector3D(u), w(static_cast <T> (u.getW())) {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Point4D<K> const& p) : Vector3D<T>::Vector3D(p), w(static_cast <T> (p.getW())) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector3D<T> const& u) : Vector4D(u, DEFAULT_W) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector3D<T> const& u, T const& w) : Vector3D<T>::Vector3D(u), w(w) {
            }

            template <class T>
            Vector4D<T>::~Vector4D() {
            }

            template <class T>
            T const& Vector4D<T>::getW() const {
                return w;
            }

            template <class T>
            T const& Vector4D<T>::getA() const {
                return w;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setW(K const& w) {
                this->w = static_cast <T> (w);
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setA(K const& a) {
                this->w = static_cast <T> (a);
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Vector4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                Vector3D<T>::setCoord(x, y, z);   setW(w);
            }

            template <class T>
            template <class K, class L>
            void Vector4D<T>::setCoord(Vector3D<K> const& u, L const& w) {
                Vector3D<T>::setCoord(u, u.getZ());    setW(w);
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Vector4D<T>::setIntensities(K const& r, L const& g, M const& b, N const& a) {
                setR(r);    setG(g);    setB(b);    setA(a);
            }

            template <class T>
            NREfloat const Vector4D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat const Vector4D<T>::normSquared() const {
                return Vector3D<T>::normSquared() + this->getW() * this->getW();
            }

            template <class T>
            void Vector4D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator=(Vector4D<T> const& base) {
                Vector3D<T>::operator=(base);
                this->w = base.getW();
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator=(Vector4D<T> && base) {
                Vector3D<T>::operator=(base);
                this->w = std::move(base.getW());
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator+=(Vector4D<T> const& u) {
                Vector3D<T>::operator+=(u);
                this->setW(this->getW() + u.getW());
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator-=(Vector4D<T> const& u) {
                Vector3D<T>::operator-=(u);
                this->setW(this->getW() - u.getW());
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator*=(T const& k) {
                Vector3D<T>::operator*=(k);
                this->setW(this->getW() * k);
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator/=(T const& k) {
                Vector3D<T>::operator/=(k);
                this->setW(this->getW() / k);
                return *this;
            }

            template <class T>
            NREfloat const Vector4D<T>::operator|=(Vector4D<T> const& u) const {
                return Vector3D<T>::operator|=(u) + this->getW() * u.getW();
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator+(Vector4D<T> const& u) const {
                Vector4D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator-(Vector4D<T> const& u) const {
                Vector4D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator-() const {
                Vector4D<T> tmp(Vector3D<T>::operator-(), -getW());
                return tmp;
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator*(T const& k) const {
                Vector4D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Vector4D<T> Vector4D<T>::operator/(T const& k) const {
                Vector4D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            NREfloat const Vector4D<T>::operator|(Vector4D<T> const& u) const {
                return *this |= u;
            }

            template <class T>
            template <class K>
            bool const Vector4D<T>::operator==(Vector4D<K> const& u) const {
                return Vector3D<T>::operator==(u) && this->getW() == u.getW();
            }

            template <>
            template <class K>
            bool const Vector4D<NREfloat>::operator==(Vector4D<K> const& u) const {
                return Vector3D<NREfloat>::operator==(u) && almostEqual(this->getW(), u.getW());
            }

            template <class T>
            template <class K>
            bool const Vector4D<T>::operator!=(Vector4D<K> const& u) const {
                return !(*this == u);
            }

            template <class T>
            bool const Vector4D<T>::operator<(Vector4D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator>(Vector4D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator<=(Vector4D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator>=(Vector4D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }


        };
    };
