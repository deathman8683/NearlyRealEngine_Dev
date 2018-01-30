
    namespace NRE {
        namespace Maths {

            template <class T>
            Point2D<T>::Point2D() : x(DEFAULT_X), y(DEFAULT_Y) {
            }

            template <class T>
            Point2D<T>::Point2D(T const& x, T const& y) : x(x), y(y) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D const& p) : x(p.x), y(p.y) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Point2D<K> const& p) : x(p.getX()), y(p.getY()) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Vector2D<K> const& u) : x(u.getX()), y(u.getY()) {
            }

            template <class T>
            template <class K, class L>
            Point2D<T>::Point2D(Point2D<K> const& p, Vector2D<L> const& u) : x(p.getX() + u.getX()), y(p.getX() + u.getX()) {
            }

            template <class T>
            Point2D<T>::~Point2D(){
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
            void Point2D<T>::setX(T const& x) {
                this->x = x;
            }

            template <class T>
            void Point2D<T>::setY(T const& y) {
                this->y = x;
            }

            template <class T>
            void Point2D<T>::setCoord(T const& x, T const& y) {
                setX(x); setY(y);
            }

            template <class T>
            NREfloat Point2D<T>::distance(Point2D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat Point2D<T>::distanceSquared(Point2D<T> const& p) const {
                NREfloat x_lenght, y_lenght;
                x_lenght = p.getX() - getX();
                y_lenght = p.getY() - getY();
                return x_lenght * x_lenght + y_lenght * y_lenght;
            }

            template <class T>
            template <class K>
            Point2D<T>& Point2D<T>::operator+=(Vector2D<K> const& u) {
                setCoord(this->getX() + u.getX(), this->getY() + u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Point2D<T>& Point2D<T>::operator-=(Vector2D<K> const& u) {
                setCoord(this->getX() - u.getX(), this->getY() - u.getY());
                return *this;
            }

            template <class T>
            template <class K>
            Point2D<T> Point2D<T>::operator+(Vector2D<K> const& u) {
                Point2D<T> tmp(*this);
                return tmp += u;
            }

            template <class T>
            template <class K>
            Point2D<T> Point2D<T>::operator-(Vector2D<K> const& u) {
                Point2D<T> tmp(*this);
                return tmp -= u;
            }

            template <class T>
            Point2D<T> Point2D<T>::operator-() {
                Point2D<T> tmp(-this->getX(), -this->getY());
                return tmp;
            }

            template <class T>
            template <class K>
            bool Point2D<T>::operator==(Point2D<K> const& p) {
                return this->getX() == p.getX() && this->getY() == p.getY();
            }

        };
    };
