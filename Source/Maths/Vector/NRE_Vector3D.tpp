
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector3D<T>::Vector3D() {
            }

            template <class T>
            Vector3D<T>::Vector3D(T const& x, T const& y, T const& z) : Base3D<T>::Base3D(x, y, z) {
            }

            template <class T>
            Vector3D<T>::Vector3D(T const& value) : Base3D<T>::Base3D(value) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector3D const& u) : Base3D<T>::Base3D(u) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector3D && u) : Base3D<T>::Base3D(u) {
            }

            template <class T>
            template <class K>
            Vector3D<T>::Vector3D(Base3D<K> const& u) : Base3D<T>::Base3D(u) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector2D<T> const& u) : Base3D<T>::Base3D(u) {
            }

            template <class T>
            Vector3D<T>::Vector3D(Vector2D<T> const& u, T const& z) : Base3D<T>::Base3D(u, z) {
            }

            template <class T>
            Vector3D<T>::~Vector3D() {
            }

            template <class T>
            T const& Vector3D<T>::getR() const {
                return this->x;
            }

            template <class T>
            T const& Vector3D<T>::getG() const {
                return this->y;
            }

            template <class T>
            T const& Vector3D<T>::getB() const {
                return this->z;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setR(K const& r) {
                this->x = r;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setG(K const& g) {
                this->y = g;
            }

            template <class T>
            template <class K>
            void Vector3D<T>::setB(K const& b) {
                this->z = b;
            }

            template <class T>
            template <class K, class L, class M>
            void Vector3D<T>::setIntensities(K const& r, L const& g, M const& b) {
                setR(r);    setG(g);    setB(b);
            }

            template <class T>
            NREfloat const Vector3D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat const Vector3D<T>::normSquared() const {
                return this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ();
            }

            template <class T>
            void Vector3D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator=(Vector3D<T> const& u) {
                Base3D<T>::operator=(u);
                return *this;
            }

            template <class T>
            Vector3D<T>& Vector3D<T>::operator=(Vector3D<T> && u) {
                Base3D<T>::operator=(u);
                return *this;
            }

            template <class T>
            bool const Vector3D<T>::operator<(Vector3D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator>(Vector3D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator<=(Vector3D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector3D<T>::operator>=(Vector3D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }

        };
    };
