
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
            Point4D<T>::Point4D(Point4D const& p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Point4D && p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            template <class K>
            Point4D<T>::Point4D(Base4D<K> const& p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Point3D<T> const& p) : Base4D<T>::Base4D(p) {
            }

            template <class T>
            Point4D<T>::Point4D(Point3D<T> const& p, T const& w) : Base4D<T>::Base4D(p, w) {
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
                NREfloat xLenght = p.getX() - this->getX();
                NREfloat yLenght = p.getY() - this->getY();
                NREfloat zLenght = p.getZ() - this->getZ();
                NREfloat wLenght = p.getW() - this->getW();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght + wLenght * wLenght;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator=(Point4D<T> const& p) {
                Base4D<T>::operator=(p);
                return *this;
            }

            template <class T>
            Point4D<T>& Point4D<T>::operator=(Point4D<T> && p) {
                Base4D<T>::operator=(p);
                return *this;
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
