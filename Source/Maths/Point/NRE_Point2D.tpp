
    namespace NRE {
        namespace Maths {

            template <class T>
            Point2D<T>::Point2D() : Point2D(DEFAULT_X, DEFAULT_Y) {
            }

            template <class T>
            Point2D<T>::Point2D(T const& x, T const& y) : data{x, y} {
            }

            template <class T>
            Point2D<T>::Point2D(T const& value) : Point2D(value, value) {
            }

            template <class T>
            template <class K, class L>
            Point2D<T>::Point2D(Point2D<K> const& p, Vector2D<L> const& u) : Point2D(p.getX() + u.getX(), p.getY() + u.getY()) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D const& p) : Point2D(p.getX(), p.getY()) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Point2D<K> const& p) : Point2D(p.getX(), p.getY()) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Vector2D<K> const& u) : Point2D(u.getX(), u.getY()) {
            }

            template <class T>
            Point2D<T>::~Point2D() {
            }

            template <class T>
            T const& Point2D<T>::getX() const {
                return data[0];
            }

            template <class T>
            T const& Point2D<T>::getY() const {
                return data[1];
            }

            template <class T>
            template <class K>
            void Point2D<T>::setX(K const& x) {
                data[0] = x;
            }

            template <class T>
            template <class K>
            void Point2D<T>::setY(K const& y) {
                data[1] = y;
            }

            template <class T>
            template <class K, class L>
            void Point2D<T>::setCoord(K const& x, L const& y) {
                setX(x);    setY(y);
            }

            template <class T>
            NREfloat Point2D<T>::distance(Point2D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point2D<T>::distanceSquared(Point2D<T> const& p) const {
                NREfloat xLenght = p.getX() - getX();
                NREfloat yLenght = p.getY() - getY();
                return xLenght * xLenght + yLenght * yLenght;
            }

            template <class T>
            const T* const Point2D<T>::value() const {
                return &data[0];
            }

            template <class T>
            template <class K>
            Point2D<T>& Point2D<T>::operator+=(Vector2D<K> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Point2D<T>& Point2D<T>::operator-=(Vector2D<K> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Point2D<T> Point2D<T>::operator+(Vector2D<K> const& u) const {
                Point2D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Point2D<T> Point2D<T>::operator-(Vector2D<K> const& u) const {
                Point2D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            template <class K>
            Vector2D<T> Point2D<T>::operator-(Point2D<K> const& p) const {
                return Vector2D<T>(*this, p);
            }

            template <class T>
            Point2D<T> Point2D<T>::operator-() const {
                Point2D<T> tmp(-getX(), -getY());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator==(Point2D<K> const& p) const {
                return getX() == p.getX() && getY() == p.getY();
            }

            template <>
            template <class K>
            bool Point2D<NREfloat>::operator==(Point2D<K> const& p) const {
                return almostEqual(getX(), p.getX()) && almostEqual(getY(), p.getY());
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator!=(Point2D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator<(Point2D<K> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator>(Point2D<K> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator<=(Point2D<K> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator>=(Point2D<K> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
