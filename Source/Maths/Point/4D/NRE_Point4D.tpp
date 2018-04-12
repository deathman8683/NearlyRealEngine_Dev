
    namespace NRE {
        namespace Maths {

            template <class T>
            Point4D<T>::Point4D() {
            }

            template <class T>
            Point4D<T>::Point4D(T const& x, T const& y, T const& z, T const& w) : Base4D<T>::Base4D(x, y, z, w) {
            }

            template <class T>
            Point4D<T>::Point4D(T const& value) : Base4D<T>::Base4D(value) {
            }

            template <class T>
            Point4D<T>::Point4D(Base4D<T> const& p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Base4D<T> && p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Base3D<T> const& p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Base3D<T> const& p, T const &w) : Base4D<T>::Base4D(p, w) {
            }

            template <class T>
            Point4D<T>::~Point4D() {
            }

            template <class T>
            NREfloat const Point4D<T>::distance(Point4D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point4D<T>::distanceSquared(Point4D<T> const& p) const {
                NREfloat xLenght = this->getX() - p.getX();
                NREfloat yLenght = this->getY() - p.getY();
                NREfloat zLenght = this->getZ() - p.getZ();
                NREfloat wLenght = this->getW() - p.getW();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght + wLenght * wLenght;
            }

            template <class T>
            bool const Point4D<T>::operator<(Point4D<T> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator>(Point4D<T> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator<=(Point4D<T> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            bool const Point4D<T>::operator>=(Point4D<T> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
