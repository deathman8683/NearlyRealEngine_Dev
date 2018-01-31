
    namespace NRE {
        namespace Maths {

            template <class T>
            Matrix2x2<T>::Matrix2x2() {
                setIdentity();
            }

            template <class T>
            template <class K, class L, class M, class N>
            Matrix2x2<T>::Matrix2x2(K const& a, L const& b,
                                    M const& c, N const& d) {
                data[0] = {a, b};
                data[1] = {c, d};
            }

            template <class T>
            template <class K, class L>
            Matrix2x2<T>::Matrix2x2(Vector2D<K> const& l1, Vector2D<L> const& l2) {
                data[0][0] = l1.getX(); data[0][1] = l1.getY();
                data[1][0] = l2.getX(); data[1][1] = l2.getY();
            }

            template <class T>
            template <class K, class L>
            Matrix2x2<T>::Matrix2x2(Point2D<K> const& l1, Point2D<L> const& l2) {
                data[0][0] = l1.getX(); data[0][1] = l1.getY();
                data[1][0] = l2.getX(); data[1][1] = l2.getY();
            }

            template <class T>
            Matrix2x2<T>::Matrix2x2(Matrix2x2 const& m) {
                *this = m;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>::Matrix2x2(Matrix2x2<K> const& m) {
                *this = m;
            }

            template <class T>
            Matrix2x2<T>::~Matrix2x2() {
            }

            template <class T>
            Vector2D<T> Matrix2x2<T>::getL1() const {
                return Vector2D<T>(data[0][0], data[0][1]);
            }

            template <class T>
            Vector2D<T> Matrix2x2<T>::getL2() const {
                return Vector2D<T>(data[1][0], data[1][1]);
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
            NREfloat Matrix2x2<T>::getDeterminant() const {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setL1(Vector2D<K> const& l1) {
                data[0][0] = l1.getX();
                data[0][1] = l1.getY();
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::setL2(Vector2D<K> const& l2) {
                data[1][0] = l2.getX();
                data[1][1] = l2.getY();
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
                T det = getDeterminant();
                if (std::abs(det) > Global::EPSILON) {
                    tmp[0][0] = (1.0 / det) * data[1][1];
                    tmp[0][1] = (1.0 / det) * -data[0][1];
                    tmp[1][0] = (1.0 / det) * -data[1][0];
                    tmp[1][1] = (1.0 / det) * data[0][0];
                }

                *this = tmp;
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::translate(K const& u) {
                data[0][1] = data[0][1] + u;
            }

            template <class T>
            template <class K>
            void Matrix2x2<T>::scale(K const& u) {
                data[0][0] = data[0][0] + u;
            }

            template <class T>
            T* Matrix2x2<T>::operator[](unsigned int const& index) {
                return data[index];
            }
            template <class T>
            const T* Matrix2x2<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator=(Matrix2x2<K> const& m) {
                data[0][0] = m[0][0]; data[0][1] = m[0][1];
                data[1][0] = m[1][0]; data[1][1] = m[1][1];
                return *this;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator+=(Matrix2x2<K> const& m) {
                data[0][0] = data[0][0] + m[0][0]; data[0][1] = data[0][1] + m[0][1];
                data[1][0] = data[1][0] + m[1][0]; data[1][1] = data[1][1] + m[1][1];
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator-=(Matrix2x2<K> const& m) {
                data[0][0] = data[0][0] - m[0][0]; data[0][1] = data[0][1] - m[0][1];
                data[1][0] = data[1][0] - m[1][0]; data[1][1] = data[1][1] - m[1][1];
                return *this;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator*=(K const& k) {
                data[0][0] = data[0][0] * k; data[0][1] = data[0][1] * k;
                data[1][0] = data[1][0] * k; data[1][1] = data[1][1] * k;
                return *this;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator*=(Matrix2x2<K> const& m) {
                data[0][0] = getL1() | getC1(); data[0][1] = getL1() | getC2();
                data[1][0] = getL2() | getC1(); data[1][1] = getL2() | getC2();
                return *this;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator/=(K const& k) {
                data[0][0] = data[0][0] / k; data[0][1] = data[0][1] / k;
                data[1][0] = data[1][0] / k; data[1][1] = data[1][1] / k;
                return *this;
            }

            template <class T>
            template <class K>
            Matrix2x2<T>& Matrix2x2<T>::operator/=(Matrix2x2<K> const& m) {
                Matrix2x2<K> tmp(m); tmp.inverse();
                return *this * tmp;
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator+(Matrix2x2<K> const& m) {
                Matrix2x2<T> tmp(*this);
                return tmp += m;
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator-(Matrix2x2<K> const& m) {
                Matrix2x2<T> tmp(*this);
                return tmp -= m;
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator*(K const& k)  {
                Matrix2x2<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator*(Matrix2x2<K> const& m) {
                Matrix2x2<T> tmp(*this);
                return tmp *= m;
            }

            template <class T>
            template <class K>
            Vector2D<K> Matrix2x2<T>::operator*(Vector2D<K> const& u) {
                return Vector2D<K>(u | getL1(), u | getL2());
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator/(K const& k) {
                Matrix2x2<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            Matrix2x2<T> Matrix2x2<T>::operator/(Matrix2x2<K> const& m) {
                Matrix2x2<T> tmp(*this);
                return tmp /= m;
            }

            template <class T>
            template <class K>
            bool Matrix2x2<T>::operator==(Matrix2x2<K> const& m) {
                return getL1() == m.getL1() && getL2() == m.getL2();
            }

            template <class T>
            template <class K>
            bool Matrix2x2<T>::operator!=(Matrix2x2<K> const& m) {
                return !(*this == m);
            }

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Matrix2x2<T> const& m) {
                stream << "[" << m[0][0] << " " << m[0][1] << "]" << std::endl;
                stream << "[" << m[1][0] << " " << m[1][1] << "]";
                return stream;
            }

        };
    };
