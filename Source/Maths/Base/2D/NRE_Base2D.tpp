
    namespace NRE {
        namespace Maths {

            template <class T>
            Base2D<T>::Base2D() : Base2D(DEFAULT_X, DEFAULT_Y) {
            }

            template <class T>
            Base2D<T>::Base2D(T const& x, T const& y) : x(x), y(y) {
            }

            template <class T>
            Base2D<T>::Base2D(T const& value) : x(value), y(value) {
            }

            template <class T>
            Base2D<T>::Base2D(Base2D const& base) : Base2D(base.x, base.y) {
            }

            template <class T>
            Base2D<T>::Base2D(Base2D && base) : Base2D(std::move(base.x), std::move(base.y)) {
            }

            template <class T>
            Base2D<T>::~Base2D() {
            }

            template <class T>
            T const& Base2D<T>::getX() const {
                return x;
            }

            template <class T>
            T const& Base2D<T>::getY() const {
                return y;
            }

            template <class T>
            template <class K>
            void Base2D<T>::setX(K const& x) {
                this->x = static_cast <T> (x);
            }

            template <class T>
            template <class K>
            void Base2D<T>::setY(K const& y) {
                this->y = static_cast <T> (y);
            }

            template <class T>
            template <class K, class L>
            void Base2D<T>::setCoord(K const& x, L const& y) {
                setX(x);    setY(y);
            }

            template <class T>
            const T* const Base2D<T>::value() const {
                return &x;
            }

            template <class T>
            T& Base2D<T>::operator[](GLuint const& index) {
                return *(value() + index);
            }

            template <class T>
            const T& Base2D<T>::operator[](GLuint const& index) const {
                return *(value() + index);
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator=(Base2D<T> const& base) {
                this->x = base.x;
                this->y = base.y;
                return *this;
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator=(Base2D<T> && base) {
                this->x = std::move(base.x);
                this->y = std::move(base.y);
                return *this;
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator+=(Base2D<T> const& base) {
                setX(getX() + base.getX());
                setY(getY() + base.getY());
                return *this;
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator-=(Base2D<T> const& base) {
                setX(getX() - base.getX());
                setY(getY() - base.getY());
                return *this;
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator*=(T const& k) {
                setX(getX() * k);
                setY(getY() * k);
                return *this;
            }

            template <class T>
            Base2D<T>& Base2D<T>::operator/=(T const& k) {
                setX(getX() / k);
                setY(getY() / k);
                return *this;
            }

            template <class T>
            Base2D<T> Base2D<T>::operator+(Base2D<T> const& base) const {
                Base2D<T> tmp(*this);
                return tmp += base;
            }

            template <class T>
            Base2D<T> Base2D<T>::operator-(Base2D<T> const& base) const {
                Base2D<T> tmp(*this);
                return tmp -= base;
            }

            template <class T>
            Base2D<T> Base2D<T>::operator-() const {
                Base2D<T> tmp(-getX(), -getY());
                return tmp;
            }

            template <class T>
            Base2D<T> Base2D<T>::operator*(T const& k) const {
                Base2D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Base2D<T> Base2D<T>::operator/(T const& k) const {
                Base2D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            bool const Base2D<T>::operator==(Base2D<T> const& base) const {
                return getX() == base.getX() && getY() == base.getY();
            }

            template <>
            bool const Base2D<NREfloat>::operator==(Base2D<NREfloat> const& base) const {
                return almostEqual(getX(), base.getX()) && almostEqual(getY(), base.getY());
            }

            template <class T>
            bool const Base2D<T>::operator!=(Base2D<T> const& base) const {
                return !(*this == base);
            }

        };
    };
