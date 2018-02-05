
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector2D<T>::Vector2D() : x(DEFAULT_X), y(DEFAULT_Y) {
            }

            template <class T>
            template <class K, class L>
            Vector2D<T>::Vector2D(K const& x, L const& y) : x(x), y(y) {
            }

            template <class T>
            template <class K, class L>
            Vector2D<T>::Vector2D(Point2D<K> const& a, Point2D<L> const& b) : x(b.getX() - a.getX()), y(b.getY() - a.getY()) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D const& u) : x(u.x), y(u.y) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Vector2D<K> const& u) : x(u.getX()), y(u.getY()) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Point2D<K> const& p) : x(p.getX()), y(p.getY()) {
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
            template <class K>
            void Vector2D<T>::setX(K const& x) {
                this->x = x;
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setY(K const& y) {
                this->y = x;
            }

            template <class T>
            template <class K, class L>
            void Vector2D<T>::setCoord(K const& x, L const& y) {
                setX(x); setY(y);
            }

            template <class T>
            NREfloat Vector2D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector2D<T>::normSquared() const {
                return getX() * getX() + getY() * getY();
            }

            template <class T>
            void Vector2D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            template <class K>
            void Vector2D<T>::rotate(K const& theta) {
                T tmpX = getX(); T tmpY = getY(); T angle = toRad(theta);
                T tmpCos = std::cos(angle); T tmpSin = std::sin(angle);
                setX(tmpX * tmpCos - tmpY * tmpSin);
                setY(tmpX * tmpSin + tmpY * tmpCos);
            }

            template <class T>
            template <class K>
            Vector2D<T>& Vector2D<T>::operator+=(Vector2D<K> const& u) {
                setCoord(getX() + u.getX(), getY() + u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Vector2D<T>& Vector2D<T>::operator-=(Vector2D<K> const& u) {
                setCoord(getX() - u.getX(), getY() - u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Vector2D<T>& Vector2D<T>::operator*=(K const& k) {
                setCoord(getX() * k, getY() * k);
                return *this;
            }

            template <class T>
            template <class K>
            Vector2D<T>& Vector2D<T>::operator/=(K const& k) {
                setCoord(getX() / k, getY() / k);
                return *this;
            }

            template <class T>
            template <class K>
            NREfloat Vector2D<T>::operator|=(Vector2D<K> const& u) const {
                return getX() * u.getX() + getY() * u.getY();
            }

            template <class T>
            template <class K>
            Vector2D<T> Vector2D<T>::operator+(Vector2D<K> const& u) {
                Vector2D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Vector2D<T> Vector2D<T>::operator-(Vector2D<K> const& u) {
                Vector2D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector2D<T> Vector2D<T>::operator-() {
                Vector2D<T> tmp(-getX(), -getY());
                return tmp;
            }

            template <class T>
            template <class K>
            Vector2D<T> Vector2D<T>::operator*(K const& k) {
                Vector2D<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Vector2D<T> Vector2D<T>::operator/(K const& k) {
                Vector2D<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator==(Vector2D<K> const& u) {
                return getX() == u.getX() && getY() == u.getY();
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator!=(Vector2D<K> const& u) {
                return !(*this == u);
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator<(Vector2D<K> const& u) {
                return normSquared() < u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator>(Vector2D<K> const& u) {
                return normSquared() > u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator<=(Vector2D<K> const& u) {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            template <class K>
            bool Vector2D<T>::operator>=(Vector2D<K> const& u) {
                return normSquared() >= u.normSquared();
            }

            template <class T>
            template <class K>
            NREfloat Vector2D<T>::operator|(Vector2D<K> const& u) const {
                return *this |= u;
            }

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Vector2D<T> const& u) {
                stream << "(" << u.getX() << "," << u.getY() << ")";
                return stream;
            }

        };
    };
