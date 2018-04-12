
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector4D<T>::Vector4D() {
            }

            template <class T>
            Vector4D<T>::Vector4D(T const& x, T const& y, T const& z, T const& w) : Base4D<T>::Base4D(x, y, z, w) {
            }

            template <class T>
            Vector4D<T>::Vector4D(T const& value) : Base4D<T>::Base4D(value) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D const& u) : Base4D<T>::Base4D(u) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector4D && u) : Base4D<T>::Base4D(u) {
            }

            template <class T>
            template <class K>
            Vector4D<T>::Vector4D(Base4D<K> const& u) : Base4D<T>::Base4D(u) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector3D<T> const& u) : Base4D<T>::Base4D(u) {
            }

            template <class T>
            Vector4D<T>::Vector4D(Vector3D<T> const& u, T const& w) : Base4D<T>::Base4D(u, w) {
            }

            template <class T>
            Vector4D<T>::~Vector4D() {
            }

            template <class T>
            T const& Vector4D<T>::getR() const {
                return this->x;
            }

            template <class T>
            T const& Vector4D<T>::getG() const {
                return this->y;
            }

            template <class T>
            T const& Vector4D<T>::getB() const {
                return this->z;
            }

            template <class T>
            T const& Vector4D<T>::getA() const {
                return this->w;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setR(K const& r) {
                this->x = r;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setG(K const& g) {
                this->y = g;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setB(K const& b) {
                this->z = b;
            }

            template <class T>
            template <class K>
            void Vector4D<T>::setA(K const& a) {
                this->w = a;
            }

            template <class T>
            template <class K, class L, class M, class N>
            void Vector4D<T>::setIntensities(K const& r, L const& g, M const& b, N const& a) {
                setR(r);    setG(g);    setB(b);    setA(a);
            }

            template <class T>
            NREfloat const Vector4D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat const Vector4D<T>::normSquared() const {
                return this->getX() * this->getX() + this->getY() * this->getY() + this->getZ() * this->getZ() + this->getW() * this->getW();
            }

            template <class T>
            void Vector4D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator=(Vector4D<T> const& u) {
                Base4D<T>::operator=(u);
                return *this;
            }

            template <class T>
            Vector4D<T>& Vector4D<T>::operator=(Vector4D<T> && u) {
                Base4D<T>::operator=(u);
                return *this;
            }

            template <class T>
            bool const Vector4D<T>::operator<(Vector4D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator>(Vector4D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator<=(Vector4D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector4D<T>::operator>=(Vector4D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }

        };
    };
