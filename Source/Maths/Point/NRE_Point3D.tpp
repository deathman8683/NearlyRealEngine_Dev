
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
            Point3D<T>::Point3D(Point3D const& p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Point3D && p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            template <class K>
            Point3D<T>::Point3D(Base3D<K> const& p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Point2D<T> const& p) : Base3D<T>::Base3D(p) {
            }

            template <class T>
            Point3D<T>::Point3D(Point2D<T> const& p, T const& z) : Base3D<T>::Base3D(p, z) {
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
                NREfloat xLenght = p.getX() - this->getX();
                NREfloat yLenght = p.getY() - this->getY();
                NREfloat zLenght = p.getZ() - this->getZ();
                return xLenght * xLenght + yLenght * yLenght + zLenght * zLenght;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator=(Point3D<T> const& p) {
                Base3D<T>::operator=(p);
                return *this;
            }

            template <class T>
            Point3D<T>& Point3D<T>::operator=(Point3D<T> && p) {
                Base3D<T>::operator=(p);
                return *this;
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
