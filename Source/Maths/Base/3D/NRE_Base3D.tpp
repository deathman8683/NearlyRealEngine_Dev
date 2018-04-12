
    namespace NRE {
        namespace Maths {

            template <class T>
            Base3D<T>::Base3D() : z(DEFAULT_Z) {
            }

            template <class T>
            Base3D<T>::Base3D(T const& x, T const& y, T const& z) : Base2D<T>::Base2D(x, y), z(z) {
            }

            template <class T>
            Base3D<T>::Base3D(T const& value) : Base2D<T>::Base2D(value), z(value) {
            }

            template <class T>
            Base3D<T>::Base3D(Base3D const& base) : Base2D<T>::Base2D(base), z(base.z) {
            }

            template <class T>
            Base3D<T>::Base3D(Base3D && base) : Base2D<T>::Base2D(base), z(std::move(base.z)) {
            }

            template <class T>
            template <class K>
            Base3D<T>::Base3D(Base3D<K> const& base) : Base2D<T>::Base2D(base), z(static_cast <T> (base.getZ())) {
            }

            template <class T>
            Base3D<T>::Base3D(Base2D<T> const& base) : Base3D(base, DEFAULT_Z) {
            }

            template <class T>
            Base3D<T>::Base3D(Base2D<T> const& base, T const& z) : Base2D<T>::Base2D(base), z(z) {
            }

            template <class T>
            Base3D<T>::~Base3D() {
            }

            template <class T>
            T const& Base3D<T>::getZ() const {
                return z;
            }

            template <class T>
            template <class K>
            void Base3D<T>::setZ(K const& z) {
                this->z = static_cast <T> (z);
            }

            template <class T>
            template <class K, class L, class M>
            void Base3D<T>::setCoord(K const& x, L const& y, M const& z) {
                Base2D<T>::setCoord(x, y);  setZ(z);
            }

            template <class T>
            template <class K, class L>
            void Base3D<T>::setCoord(Base2D<K> const& base, L const& z) {
                setCoord(base.getX(), base.getY(), z);
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator=(Base3D<T> const& base) {
                Base2D<T>::operator=(base);
                this->z = base.z;
                return *this;
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator=(Base3D<T> && base) {
                Base2D<T>::operator=(base);
                this->z = std::move(base.z);
                return *this;
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator+=(Base3D<T> const& base) {
                Base2D<T>::operator+=(base);
                setZ(getZ() + base.getZ());
                return *this;
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator-=(Base3D<T> const& base) {
                Base2D<T>::operator-=(base);
                setZ(getZ() - base.getZ());
                return *this;
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator*=(T const& k) {
                Base2D<T>::operator*=(k);
                setZ(getZ() * k);
                return *this;
            }

            template <class T>
            Base3D<T>& Base3D<T>::operator/=(T const& k) {
                Base2D<T>::operator/=(k);
                setZ(getZ() / k);
                return *this;
            }

            template <class T>
            Base3D<T> Base3D<T>::operator+(Base3D<T> const& base) const {
                Base3D<T> tmp(*this);
                return tmp += base;
            }

            template <class T>
            Base3D<T> Base3D<T>::operator-(Base3D<T> const& base) const {
                Base3D<T> tmp(*this);
                return tmp -= base;
            }

            template <class T>
            Base3D<T> Base3D<T>::operator-() const {
                Base3D<T> tmp(Base2D<T>::operator-(), -getZ());
                return tmp;
            }

            template <class T>
            Base3D<T> Base3D<T>::operator*(T const& k) const {
                Base3D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Base3D<T> Base3D<T>::operator/(T const& k) const {
                Base3D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            bool const Base3D<T>::operator==(Base3D<T> const& base) const {
                return Base2D<T>::operator==(base) && getZ() == base.getZ();
            }

            template <class T>
            bool const Base3D<T>::operator!=(Base3D<T> const& base) const {
                return !(*this == base);
            }
        };
    };
