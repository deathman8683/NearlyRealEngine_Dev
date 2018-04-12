
    namespace NRE {
        namespace Maths {

            template <class T>
            Point3D<T>::Point3D() {
            }

            template <class T>
            Point3D<T>::Point3D(T const& x, T const& y, T const& z) : Base3D<T>::Base3D(x, y, z) {
            }

            template <class T>
            Point3D<T>::Point3D(T const& value) : Base3D<T>::Base3D(value) {
            }

            template <class T>
            Point3D<T>::Point3D(Base3D<T> const& p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Base3D<T> && p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Base2D<T> const& p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Base2D<T> const& p, T const &z) : Base3D<T>::Base3D(p, z) {
            }

            template <class T>
            Point3D<T>::~Point3D() {
            }

            template <class T>
            NREfloat const Point3D<T>::distance(Point3D<T> const& p) const {
                return std::sqrt(distanceSquared(p));
            }

            template <class T>
            NREfloat const Point3D<T>::distanceSquared(Point3D<T> const& p) const {
                NREfloat xLenght = this->getX() - p.getX();
                NREfloat yLenght = this->getY() - p.getY();
                NREfloat zLenght = this->getZ() - p.getZ();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght;
            }

            template <class T>
            bool const Point3D<T>::operator<(Point3D<T> const& p) const {
                return distanceSquared() < p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator>(Point3D<T> const& p) const {
                return distanceSquared() > p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator<=(Point3D<T> const& p) const {
                return distanceSquared() <= p.distanceSquared();
            }

            template <class T>
            bool const Point3D<T>::operator>=(Point3D<T> const& p) const {
                return distanceSquared() >= p.distanceSquared();
            }

        };
    };
