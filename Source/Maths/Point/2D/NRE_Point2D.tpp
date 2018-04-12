
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
            Point2D<T>::Point2D(Base2D<T> const& p) : Base2D<T>::Base2D(p) {
            }

            template <class T>
            Point2D<T>::Point2D(Base2D<T> && p) : Base2D<T>::Base2D(p) {
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
                NREfloat xLenght = this->getX() - p.getX();
                NREfloat yLenght = this->getY() - p.getY();
                return xLenght * xLenght + yLenght * yLenght;
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
