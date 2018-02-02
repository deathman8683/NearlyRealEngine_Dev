
    template <class T>
    Point3D<T>::Point3D() : z(DEFAULT_Z ){
    }

    template <class T>
    template <class K, class L, class M>
    Point3D<T>::Point3D(K const& x, L const& y, M const& z) : Point2D<T>::(x, y), z(z) {
    }

    template <class T>
    template <class K, class L>
    Point3D<T>::Point3D(Point2D<K> const& p, L const& z) : Point2D<T>::(p), z(z) {
    }

    template <class T>
    template <class K, class L>
    Point3D<T>::Point3D(Point3D<K> const& p, Vector3D<L> const& u) : x(p.getX() + u.getX()), y(p.getX() + u.getX()), z(p.getZ() + u.getZ()) {
    }

    template <class T>
    Point3D<T>::Point3D(Point3D const& p) : x(p.getX()), y(p.getY()), z(p.getZ()) {
    }

    template <class T>
    template <class K>
    Point3D<T>::Point3D(Point3D<K> const& p) : x(p.getX()), y(p.getY()), z(p.getZ()) {
    }

    template <class T>
    template <class K>
    Point3D<T>::Point3D(Vector3D<K> const& u) : x(u.getX()), y(u.getY()), z(u.getZ()) {
    }

    template <class T>
    Point3D<T>::~Point3D() {
    }
