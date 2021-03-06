
    namespace NRE {
        namespace Maths {

            template <class T>
            Matrix2x2<T>::Matrix2x2() {
                setIdentity();
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(T const& a, T const& b,
                                    T const& c, T const& d) : data{{a, b}, {c, d}} {
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(T const& value) : Matrix2x2(value, value, value, value) {
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(Vector2D<T> const& l1, Vector2D<T> const& l2) : data{l1, l2} {
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(Point2D<T> const& l1, Point2D<T> const& l2) : data{l1, l2} {
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(Matrix2x2 const& m) : data{m.getL1(), m.getL2()} {
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(Matrix2x2 && m) : data{std::move(m.getL1()), std::move(m.getL2())} {
            }

            template <class T>
            template <class K>
            Matrix2x2<T>::Matrix2x2(Matrix2x2<K> const& m) : data{static_cast <Vector2D<T>> (m.getL1()), static_cast <Vector2D<T>> (m.getL2())} {
            }

            template <class T>
            Matrix2x2<T>::~Matrix2x2() {
            }

            template <class T>
            Vector2D<T> const& Matrix2x2<T>::getL1() const {
                return data[0];
            }

            template <class T>
            Vector2D<T> const& Matrix2x2<T>::getL2() const {
                return data[1];
            }

            template <class T>
            Vector2D<T> Matrix2x2<T>::getC1() const {
                return Vector2D<T>(data[0][0], data[1][0]);
            }

            template <class T>
            Vector2D<T> Matrix2x2<T>::getC2() const {
                return Vector2D<T>(data[0][1], data[1][1]);
            }

            template <class T>
            NREfloat const Matrix2x2<T>::getDeterminant() const {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setL1(Vector2D<K> const& l1) {
                data[0] = l1;
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setL2(Vector2D<K> const& l2) {
                data[1] = l2;
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setC1(Vector2D<K> const& c1) {
                data[0][0] = c1.getX();
                data[1][0] = c1.getY();
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setC2(Vector2D<K> const& c2) {
                data[0][1] = c2.getX();
                data[1][1] = c2.getY();
            }

            template <class T>
            void Matrix2x2<T>::setIdentity() {
                setL1(Vector2D<T>(1, 0));
                setL2(Vector2D<T>(0, 1));
            }

            template <class T>
            void Matrix2x2<T>::transpose() {
                Matrix2x2<T> tmp;
                tmp[0][0] = data[0][0];
                tmp[0][1] = data[1][0];
                tmp[1][0] = data[0][1];
                tmp[1][1] = data[1][1];
                *this = tmp;
            }

            template <class T>
            void Matrix2x2<T>::inverse() {
                Matrix2x2<T> tmp;
                NREfloat det = getDeterminant();
                if (std::abs(det) > Global::EPSILON) {
                    tmp[0][0] = (1.0 / det) * data[1][1];
                    tmp[0][1] = (1.0 / det) * -data[0][1];
                    tmp[1][0] = (1.0 / det) * -data[1][0];
                    tmp[1][1] = (1.0 / det) * data[0][0];
                }

                *this = tmp;
            }

            template <class T>
            void Matrix2x2<T>::translate(T const& u) {
                setC2(getC1() * u + getC2());
            }

            template <class T>
            void Matrix2x2<T>::scale(T const& u) {
                setC1(getC1() * u);
            }

            template <class T>
            const T* const Matrix2x2<T>::value() const {
                return data[0].value();
            }

            template <class T>
            Vector2D<T>& Matrix2x2<T>::operator[](unsigned int const& index) {
                return data[index];
            }
            template <class T>
            const Vector2D<T>& Matrix2x2<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator=(Matrix2x2<T> const& m) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = m[i];
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator=(Matrix2x2<T> && m) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = std::move(m[i]);
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator+=(Matrix2x2<T> const& m) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = data[i] + m[i];
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator-=(Matrix2x2<T> const& m) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = data[i] - m[i];
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator*=(T const& k) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = data[i] * k;
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator*=(Matrix2x2<T> const& m) {
                Matrix2x2<T> tmp(*this);
                tmp[0][0] = getL1() | m.getC1(); tmp[0][1] = getL1() | m.getC2();
                tmp[1][0] = getL2() | m.getC1(); tmp[1][1] = getL2() | m.getC2();
                *this = tmp;
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator/=(T const& k) {
                for(unsigned int i = 0; i < 2; i = i + 1) {
                    data[i] = data[i] / k;
                }
                return *this;
            }

            template <class T>
            Matrix2x2<T>& Matrix2x2<T>::operator/=(Matrix2x2<T> const& m) {
                Matrix2x2<T> tmp(m); tmp.inverse();
                return *this *= tmp;
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator+(Matrix2x2<T> const& m) const {
                Matrix2x2<T> tmp(*this);
                return tmp += m;
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator-(Matrix2x2<T> const& m) const {
                Matrix2x2<T> tmp(*this);
                return tmp -= m;
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator*(T const& k)  const {
                Matrix2x2<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator*(Matrix2x2<T> const& m) const {
                Matrix2x2<T> tmp(*this);
                return tmp *= m;
            }

            template <class T>
            Vector2D<T> Matrix2x2<T>::operator*(Vector2D<T> const& u) const {
                return Vector2D<T>(u | getL1(), u | getL2());
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator/(T const& k) const {
                Matrix2x2<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            Matrix2x2<T> Matrix2x2<T>::operator/(Matrix2x2<T> const& m) const {
                Matrix2x2<T> tmp(*this);
                return tmp /= m;
            }

            template <class T>
            bool Matrix2x2<T>::operator==(Matrix2x2<T> const& m) const {
                return getL1() == m.getL1() && getL2() == m.getL2();
            }

            template <class T>
            bool Matrix2x2<T>::operator!=(Matrix2x2<T> const& m) const {
                return !(*this == m);
            }

        };
    };
