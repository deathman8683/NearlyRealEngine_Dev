
    namespace NRE {
        namespace Maths {

            template <class T>
            Vector2D<T>::Vector2D() : x(DEFAULT_X), y(DEFAULT_Y) {
            }

            template <class T>
            Vector2D<T>::Vector2D(T const& x, T const& y) : x(x), y(y) {
            }

            template <class T>
            Vector2D<T>::Vector2D(Vector2D const& u) : x(u.x), y(u.y) {
            }

            template <class T>
            template <class K>
            Vector2D<T>::Vector2D(Vector2D<K> const& u) : x(u.getX()), y(u.getY()) {
            }

            template <class T>
            Vector2D<T>::~Vector2D(){
            }

            template <class T>
            T const& Vector2D<T>::getX() const {
                return x;
            }

            template <class T>
            T const& Vector2D<T>::getY() const {
                return y;
            }

            template <class T>
            void Vector2D<T>::setX(T const& x) {
                this->x = x;
            }

            template <class T>
            void Vector2D<T>::setY(T const& y) {
                this->y = x;
            }

            template <class T>
            void Vector2D<T>::setCoord(T const& x, T const& y) {
                setX(x); setY(y);
            }

            template <class T>
            template <class K>
            Vector2D<T> Vector2D<T>::operator+(Vector2D<K> const& u) {
                Vector2D<T> tmp(this->getX() + u.getX(), this->getY() + u.getY());
                return tmp;
            }

        };
    };
