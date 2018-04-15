
    namespace NRE {
        namespace Maths {

            template <class T>
            Point2D<T>::Point2D() : Point2D(DEFAULT_X, DEFAULT_Y) {
            }

            template <class T>
            Point2D<T>::Point2D(T const& x, T const& y) : x(x), y(y) {
            }

            template <class T>
            Point2D<T>::Point2D(T const& value) : Point2D(value, value) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D<T> const& p, Vector2D<T> const& u) : Point2D(p.getX() + u.getX(), p.getY() + u.getY()) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D const& p) : Point2D(p.getX(), p.getY()) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D && p) : Point2D(std::move(p.getX()), std::move(p.getY())) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Point2D<K> const& p) : Point2D(static_cast <T> (p.getX()), static_cast <T> (p.getY())) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Vector2D<K> const& u) : Point2D(static_cast <T> (u.getX()), static_cast <T> (u.getY())) {
            }

            template <class T>
            Point2D<T>::~Point2D() {
            }

            template <class T>
            T const& Point2D<T>::getX() const {
                return x;
            }

            template <class T>
            T const& Point2D<T>::getY() const {
                return y;
            }

            template <class T>
            template <class K>
            void Point2D<T>::setX(K const& x) {
                this->x = static_cast <T> (x);
            }

            template <class T>
            template <class K>
            void Point2D<T>::setY(K const& y) {
                this->y = static_cast <T> (y);
            }

            template <class T>
            template <class K, class L>
            void Point2D<T>::setCoord(K const& x, L const& y) {
                setX(x);    setY(y);
            }

            template <class T>
            NREfloat const Point2D<T>::distance(Point2D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point2D<T>::distanceSquared(Point2D<T> const& p) const {
                NREfloat xLenght = p.getX() - getX();
                NREfloat yLenght = p.getY() - getY();
                return xLenght * xLenght + yLenght * yLenght;
            }

            template <class T>
            const T* const Point2D<T>::value() const {
                return &x;
            }

            template <class T>
            T& Point2D<T>::operator[](unsigned int const& index) {
                return *(&x + index);
            }

            template <class T>
            const T& Point2D<T>::operator[](unsigned int const& index) const {
                return *(&x + index);
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator=(Point2D<T> const& base) {
                x = base.getX();
                y = base.getY();
                return *this;
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator=(Point2D<T> && base) {
                x = std::move(base.getX());
                y = std::move(base.getY());
                return *this;
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator+=(Vector2D<T> const& u) {
                setX(getX() + u.getX());
                setY(getY() + u.getY());
                return *this;
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator-=(Vector2D<T> const& u) {
                setX(getX() - u.getX());
                setY(getY() - u.getY());
                return *this;
            }

            template <class T>
            Point2D<T> Point2D<T>::operator+(Vector2D<T> const& u) const {
                Point2D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            Point2D<T> Point2D<T>::operator-(Vector2D<T> const& u) const {
                Point2D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Vector2D<T> Point2D<T>::operator-(Point2D<T> const& p) const {
                return Vector2D<T>(*this, p);
            }

            template <class T>
            Point2D<T> Point2D<T>::operator-() const {
                Point2D<T> tmp(-getX(), -getY());
                return tmp;
            }

            template <class T>
            template <class K>
            bool const Point2D<T>::operator==(Point2D<K> const& p) const {
                return getX() == p.getX() && getY() == p.getY();
            }

            template <>
            template <class K>
            bool const Point2D<NREfloat>::operator==(Point2D<K> const& p) const {
                return almostEqual(getX(), p.getX()) && almostEqual(getY(), p.getY());
            }

            template <class T>
            template <class K>
            bool const Point2D<T>::operator!=(Point2D<K> const& p) const {
                return !(*this == p);
            }

            template <class T>
            bool const Point2D<T>::operator<(Point2D<T> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            bool const Point2D<T>::operator>(Point2D<T> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            bool const Point2D<T>::operator<=(Point2D<T> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            bool const Point2D<T>::operator>=(Point2D<T> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
