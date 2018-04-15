
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector2D<T>::Vector2D() : Vector2D(DEFAULT_X, DEFAULT_Y) {
            }

            template <class T>
            Vector2D<T>::Vector2D(T const& x, T const& y) : x(x), y(y) {
            }

            template <class T>
            Vector2D<T>::Vector2D(T const& value) : Vector2D(value, value) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Point2D<T> const& a, Point2D<T> const& b) : Vector2D(b.getX() - a.getX(), b.getY() - a.getY()) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D const& u) : Vector2D(u.getX(), u.getY()) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D && u) : Vector2D(std::move(u.getX()), std::move(u.getY())) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Vector2D<K> const& u) : Vector2D(static_cast <T> (u.getX()), static_cast <T> (u.getY())) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Point2D<K> const& p) : Vector2D(static_cast <T> (p.getX()), static_cast <T> (p.getY())) {
            }

            template <class T>
            Vector2D<T>::~Vector2D(){
            }

            template <class T>
            T const& Vector2D<T>::getX() const {
                return x;
            }

            template <class T>
            T const& Vector2D<T>::getY() const {
                return y;
            }

            template <class T>
            T const& Vector2D<T>::getW() const {
                return x;
            }

            template <class T>
            T const& Vector2D<T>::getH() const {
                return y;
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setX(K const& x) {
                this->x = static_cast <T> (x);
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setY(K const& y) {
                this->y = static_cast <T> (y);
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setW(K const& w) {
                this->x = static_cast <T> (w);
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setH(K const& h) {
                this->y = static_cast <T> (h);
            }

            template <class T>
            template <class K, class L>
            void Vector2D<T>::setCoord(K const& x, L const& y) {
                setX(x);    setY(y);
            }

            template <class T>
            template <class K, class L>
            void Vector2D<T>::setSize(K const& w, L const& h) {
                setW(w);    setH(h);
            }

            template <class T>
            NREfloat const Vector2D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat const Vector2D<T>::normSquared() const {
                return getX() * getX() + getY() * getY();
            }

            template <class T>
            void Vector2D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            const T* const Vector2D<T>::value() const {
                return &x;
            }

            template <class T>
            T& Vector2D<T>::operator[](unsigned int const& index) {
                return *(&x + index);
            }

            template <class T>
            const T& Vector2D<T>::operator[](unsigned int const& index) const {
                return *(&x + index);
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator=(Vector2D<T> const& base) {
                x = base.getX();
                y = base.getY();
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator=(Vector2D<T> && base) {
                x = std::move(base.getX());
                y = std::move(base.getY());
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator+=(Vector2D<T> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator-=(Vector2D<T> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator*=(T const& k) {
                setX(getX() * k);
                setY(getY() * k);
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator/=(T const& k) {
                setX(getX() / k);
                setY(getY() / k);
                return *this;
            }

            template <class T>
            NREfloat const Vector2D<T>::operator|=(Vector2D<T> const& u) const {
                return getX() * u.getX() + getY() * u.getY();
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator+(Vector2D<T> const& u) const {
                Vector2D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator-(Vector2D<T> const& u) const {
                Vector2D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator-() const {
                Vector2D<T> tmp(-getX(), -getY());
                return tmp;
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator*(T const& k) const {
                Vector2D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator/(T const& k) const {
                Vector2D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            NREfloat const Vector2D<T>::operator|(Vector2D<T> const& u) const {
                return *this |= u;
            }

            template <class T>
            template <class K>
            bool const Vector2D<T>::operator==(Vector2D<K> const& u) const {
                return getX() == u.getX() && getY() == u.getY();
            }

            template <>
            template <class K>
            bool const Vector2D<NREfloat>::operator==(Vector2D<K> const& u) const {
                return almostEqual(getX(), u.getX()) && almostEqual(getY(), u.getY());
            }

            template <class T>
            template <class K>
            bool const Vector2D<T>::operator!=(Vector2D<K> const& u) const {
                return !(*this == u);
            }

            template <class T>
            bool const Vector2D<T>::operator<(Vector2D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator>(Vector2D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator<=(Vector2D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator>=(Vector2D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }

        };
    };
