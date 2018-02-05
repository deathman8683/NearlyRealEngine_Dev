
    template <class T>
    Vector3D<T>::Vector3D() : z(DEFAULT_Z) {
    }

    template <class T>
    template <class K, class L, class M>
    Vector3D<T>::Vector3D(K const& x, L const& y, M const& z) : Vector2D(x, y), z(z) {
    }

    template <class T>
    template <class K, class L>
    Vector3D<T>::Vector3D(Vector2D<K> const& u, L const& z) Vector2D(u), z(z) {
    }

    template <class T>
    template <class K, class L>
    Vector3D<T>::Vector3D(Point3D<K> const& a, Point3D<L> const& b) : Vector2D(a, b), z(b.getZ() - a.getZ()) {
    }

    template <class T>
    Vector3D<T>::Vector3D(Vector3D const& u) : Vector2D(u), z(u.getZ()) {
    }

    template <class T>
    template <class K>
    Vector3D<T>::Vector3D(Vector3D<K> const& u) : Vector2D(u), z(u.getZ()) {
    }

    template <class T>
    template <class K>
    Vector3D<T>::Vector3D(Point3D<K> const& p) : Vector2D(p), z(p.getZ()) {
    }

    template <class T>
    Vector3D<T>::~Vector3D() {
    }

    template <class T>
    const& T Vector3D<T>::getZ() const {
        return z;
    }

    template <class T>
    template <class K>
    void Vector3D<T>::setZ(K const& z) {
        this.z = z;
    }

    template <class T>
    template <class K, class L, class M>
    void Vector3D<T>::setCoord(K const& x, L const& y, M const& z) {
        Vector2D::setCoord(x, y);
        setZ(z);
    }

    template <class T>
    template <class K, class L>
    void Vector3D<T>::setCoord(Vector2D<K> const& u, L const& z) {
        Vector2D::setCoord(u.getX(), u.getY());
        setZ(z);
    }

    template <class T>
    NREfloat Vector3D<T>::norm() const {
        return std::sqrt(normSquared());
    }

    template <class T>
    NREfloat Vector3D<T>::normSquared() const {
        return Vector2D::normSquared() + getZ() * getZ();
    }

    template <class T>
    void Vector3D<T>::normalize() {
        *this = *this / norm();
    }

    template <class T>
    template <class K>
    Vector3D<T>& Vector3D<T>::operator+=(Vector3D<K> const& u) {
        setCoord(getX() + u.getX(), getY() + u.getY(), getZ() + u.getZ());
        return *this;
    }

    template <class T>
    template <class K>
    Vector3D<T>& Vector3D<T>::operator-=(Vector3D<K> const& u) {
        setCoord(getX() - u.getX(), getY() - u.getY(), getZ() - u.getZ());
        return *this;
    }

    template <class T>
    template <class K>
    Vector3D<T>& Vector3D<T>::operator*=(K const& k) {
        setCoord(getX() * k, getY() * k, getZ() * k);
        return *this;
    }

    template <class T>
    template <class K>
    Vector3D<T>& Vector3D<T>::operator/=(K const& k) {
        setCoord(getX() / k, getY() / k, getZ() / k);
        return *this;
    }

    template <class T>
    template <class K>
    NREfloat Vector3D<T>::operator|=(Vector3D<K> const& u) const {
        return getX() * u.getX() + getY() * u.getY() + getZ() * u.getZ();
    }

    template <class T>
    template <class K>
    Vector3D<T>& Vector3D<T>::operator^=(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    Vector3D<T> Vector3D<T>::operator+(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    Vector3D<T> Vector3D<T>::operator-(Vector3D<K> const& u) {

    }

    template <class T>
    Vector3D<T> Vector3D<T>::operator-() {

    }

    template <class T>
    template <class K>
    Vector3D<T> Vector3D<T>::operator*(K const& k) {

    }

    template <class T>
    template <class K>
    Vector3D<T> Vector3D<T>::operator/(K const& k) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator==(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator!=(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator<(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator>(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator<=(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    bool Vector3D<T>::operator>=(Vector3D<K> const& u) {

    }

    template <class T>
    template <class K>
    NREfloat Vector3D<T>::operator|(Vector3D<K> const& u) const {

    }

    template <class T>
    template <class K>
    Vector3D<T> Vector3D<T>::operator^(Vector3D<K> const& u) {

    }

    template <class T>
    std::ostream& operator<<(std::ostream &stream, Vector3D<T> const& u) {

    }
