
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector2D<T>::Vector2D() {
            }

            template <class T>
            Vector2D<T>::Vector2D(T const& x, T const& y) : Base2D<T>::Base2D(x, y) {
            }

            template <class T>
            Vector2D<T>::Vector2D(T const& value) : Base2D<T>::Base2D(value) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D const& u) : Base2D<T>::Base2D(u) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D && u) : Base2D<T>::Base2D(u) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Base2D<K> const& u) : Base2D<T>::Base2D(u) {
            }

            template <class T>
            Vector2D<T>::~Vector2D(){
            }

            template <class T>
            T const& Vector2D<T>::getW() const {
                return this->x;
            }

            template <class T>
            T const& Vector2D<T>::getH() const {
                return this->y;
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setW(K const& w) {
                this->x = static_cast <T> (w);
            }

            template <class T>
            template <class K>
            void Vector2D<T>::setH(K const& h) {
                this->y = static_cast <T> (h);
            }

            template <class T>
            template <class K, class L>
            void Vector2D<T>::setSize(K const& w, L const& h) {
                setW(w);    setH(h);
            }

            template <class T>
            NREfloat Vector2D<T>::norm() const {
                return std::sqrt(normSquared());
            }

            template <class T>
            NREfloat Vector2D<T>::normSquared() const {
                return this->getX() * this->getX() + this->getY() * this->getY();
            }

            template <class T>
            void Vector2D<T>::normalize() {
                *this = *this / norm();
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator=(Vector2D<T> const& u) {
                Base2D<T>::operator=(u);
                return *this;
            }

            template <class T>
            Vector2D<T>& Vector2D<T>::operator=(Vector2D<T> && u) {
                Base2D<T>::operator=(u);
                return *this;
            }

            template <class T>
            bool const Vector2D<T>::operator<(Vector2D<T> const& u) const {
                return normSquared() < u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator>(Vector2D<T> const& u) const {
                return normSquared() > u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator<=(Vector2D<T> const& u) const {
                return normSquared() <= u.normSquared();
            }

            template <class T>
            bool const Vector2D<T>::operator>=(Vector2D<T> const& u) const {
                return normSquared() >= u.normSquared();
            }

        };
    };
