
    namespace NRE {
        namespace Maths {

            template <class T>
            Base4D<T>::Base4D() : w(DEFAULT_W) {
            }

            template <class T>
            Base4D<T>::Base4D(T const& x, T const& y, T const& z, T const& w) : Base3D<T>::Base3D(x, y, z), w(w) {
            }

            template <class T>
            Base4D<T>::Base4D(T const& value) : Base3D<T>::Base3D(value), w(value) {
            }

            template <class T>
            Base4D<T>::Base4D(Base4D const& base) : Base3D<T>::Base3D(base), w(base.getW()) {
            }

            template <class T>
            Base4D<T>::Base4D(Base4D && base) : Base3D<T>::Base3D(base), w(std::move(base.getW())) {
            }

            template <class T>
            template <class K>
            Base4D<T>::Base4D(Base4D<K> const& base) : Base3D<T>::Base3D(base), w(static_cast <T> (base.getW())) {
            }

            template <class T>
            Base4D<T>::Base4D(Base3D<T> const& base) : Base4D(base, DEFAULT_W) {
            }

            template <class T>
            Base4D<T>::Base4D(Base3D<T> const& base, T const& w) : Base3D<T>::Base3D(base), w(w) {
            }

            template <class T>
            Base4D<T>::~Base4D() {
            }

            template <class T>
            T const& Base4D<T>::getW() const {
                return w;
            }

            template <class T>
            template <class K>
            void Base4D<T>::setW(K const& w) {
                this->w = static_cast <T> (w);
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Base4D<T>::setCoord(K const& x, L const& y, M const& z, N const& w) {
                Base3D<T>::setCoord(x, y, z);  setW(w);
            }

            template <class T>
            template <class K, class L>
            void Base4D<T>::setCoord(Base3D<K> const& base, L const& W) {
                setCoord(base.getX(), base.getY(), base.getZ(), w);
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator=(Base4D<T> const& base) {
                Base3D<T>::operator=(base);
                this->w = base.w;
                return *this;
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator=(Base4D<T> && base) {
                Base3D<T>::operator=(base);
                this->w = std::move(base.w);
                return *this;
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator+=(Base4D<T> const& base) {
                Base3D<T>::operator+=(base);
                setZ(getW() + base.getW());
                return *this;
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator-=(Base4D<T> const& base) {
                Base3D<T>::operator-=(base);
                setW(getW() - base.getW());
                return *this;
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator*=(T const& k) {
                Base3D<T>::operator*=(k);
                setW(getW() * k);
                return *this;
            }

            template <class T>
            Base4D<T>& Base4D<T>::operator/=(T const& k) {
                Base3D<T>::operator/=(k);
                setW(getW() / k);
                return *this;
            }

            template <class T>
            NREfloat const Base4D<T>::operator|=(Base4D<T> const& base) const {
                return this->getX() * base.getX() + this->getY() * base.getY() + this->getZ() * base.getZ() + this->getW() * base.getW();
            }

            template <class T>
            Base4D<T> Base4D<T>::operator+(Base4D<T> const& base) const {
                Base4D<T> tmp(*this);
                return tmp += base;
            }

            template <class T>
            Base4D<T> Base4D<T>::operator-(Base4D<T> const& base) const {
                Base4D<T> tmp(*this);
                return tmp -= base;
            }

            template <class T>
            Base4D<T> Base4D<T>::operator-() const {
                Base4D<T> tmp(Base3D<T>::operator-(), -getW());
                return tmp;
            }

            template <class T>
            Base4D<T> Base4D<T>::operator*(T const& k) const {
                Base4D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Base4D<T> Base4D<T>::operator/(T const& k) const {
                Base4D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            NREfloat const Base4D<T>::operator|(Base4D<T> const& base) const {
                return *this |= base;
            }

            template <class T>
            bool const Base4D<T>::operator==(Base4D<T> const& base) const {
                return Base3D<T>::operator==(base) && getW() == base.getW();
            }

            template <class T>
            bool const Base4D<T>::operator!=(Base4D<T> const& base) const {
                return !(*this == base);
            }
        };
    };
