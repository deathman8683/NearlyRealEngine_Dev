
    namespace NRE {
        namespace Maths {

            template <class T>
            Point2D<T>::Point2D() {
            }

            template <class T>
            Point2D<T>::Point2D(T const& x, T const& y) : Base2D<T>::Base2D(x, y) {
            }

            template <class T>
            Point2D<T>::Point2D(T const& value) : Base2D<T>::Base2D(value) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D const& p) : Base2D<T>::Base2D(p) {
            }

            template <class T>
            Point2D<T>::Point2D(Point2D && p) : Base2D<T>::Base2D(p) {
            }

            template <class T>
            template <class K>
            Point2D<T>::Point2D(Base2D<K> const& p) : Base2D<T>::Base2D(p) {
            }

            template <class T>
            Point2D<T>::~Point2D() {
            }

            template <class T>
            NREfloat const Point2D<T>::distance(Point2D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point2D<T>::distanceSquared(Point2D<T> const& p) const {
                NREfloat xLenght = p.getX() - this->getX();
                NREfloat yLenght = p.getY() - this->getY();
                return xLenght * xLenght + yLenght * yLenght;
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator=(Point2D<T> const& p) {
                Base2D<T>::operator=(p);
                return *this;
            }

            template <class T>
            Point2D<T>& Point2D<T>::operator=(Point2D<T> && p) {
                Base2D<T>::operator=(p);
                return *this;
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
