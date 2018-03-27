
    namespace NRE {
        namespace Maths {

            template <class T>
            Matrix3x3<T>::Matrix3x3() {
                setIdentity();
            }

            template <class T>
            template <class K, class L, class M,
                      class N, class O, class P,
                      class Q, class R, class S>
            Matrix3x3<T>::Matrix3x3(K const& a, L const& b, M const& c,
                                    N const& d, O const& e, P const& f,
                                    Q const& g, R const& h, S const& i) : data{{a, b, c}, {d, e, f}, {g, h, i}} {
            }

            template <class T>
            template <class K, class L, class M>
            Matrix3x3<T>::Matrix3x3(Vector3D<K> const& l1, Vector3D<L> const& l2, Vector3D<M> const& l3) : data{l1, l2, l3} {
            }

            template <class T>
            template <class K, class L, class M>
            Matrix3x3<T>::Matrix3x3(Point3D<K> const& l1, Point3D<L> const& l2, Point3D<M> const& l3) : data{l1, l2, l3} {
            }

            template <class T>
            Matrix3x3<T>::Matrix3x3(Matrix3x3 const& m) {
                *this = m;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>::Matrix3x3(Matrix3x3<K> const& m) {
                *this = m;
            }

            template <class T>
            Matrix3x3<T>::~Matrix3x3() {
            }

            template <class T>
            Vector3D<T> const& Matrix3x3<T>::getL1() const {
                return data[0];
            }

            template <class T>
            Vector3D<T> const& Matrix3x3<T>::getL2() const {
                return data[1];
            }

            template <class T>
            Vector3D<T> const& Matrix3x3<T>::getL3() const {
                return data[2];
            }

            template <class T>
            Vector3D<T> Matrix3x3<T>::getC1() const {
                return Vector3D<T>(data[0][0], data[1][0], data[2][0]);
            }

            template <class T>
            Vector3D<T> Matrix3x3<T>::getC2() const {
                return Vector3D<T>(data[0][1], data[1][1], data[2][1]);
            }

            template <class T>
            Vector3D<T> Matrix3x3<T>::getC3() const {
                return Vector3D<T>(data[0][2], data[1][2], data[2][2]);
            }

            template <class T>
            NREfloat Matrix3x3<T>::getDeterminant() const {
                return ((data[0][0] * data[1][1] * data[2][2]) + (data[1][0] * data[2][1] * data[0][2]) + (data[2][0] * data[0][1] * data[1][2])) -
                       ((data[2][0] * data[1][1] * data[0][2]) + (data[0][0] * data[2][1] * data[1][2]) + (data[1][0] * data[0][1] * data[2][2]));
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setL1(Vector3D<K> const& l1) {
                data[0] = l1;
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setL2(Vector3D<K> const& l2) {
                data[1] = l2;
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setL3(Vector3D<K> const& l3) {
                data[2] = l3;
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setC1(Vector3D<K> const& c1) {
                data[0][0] = c1.getX();
                data[1][0] = c1.getY();
                data[2][0] = c1.getZ();
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setC2(Vector3D<K> const& c2) {
                data[0][1] = c2.getX();
                data[1][1] = c2.getY();
                data[2][1] = c2.getZ();
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::setC3(Vector3D<K> const& c3) {
                data[0][2] = c3.getX();
                data[1][2] = c3.getY();
                data[2][2] = c3.getZ();
            }

            template <class T>
            void Matrix3x3<T>::setIdentity() {
                setL1(Vector3D<T>(1, 0, 0));
                setL2(Vector3D<T>(0, 1, 0));
                setL3(Vector3D<T>(0, 0, 1));
            }

            template <class T>
            void Matrix3x3<T>::transpose() {
                Matrix3x3<T> tmp;
                tmp[0][0] = data[0][0];
                tmp[0][1] = data[1][0];
                tmp[0][2] = data[2][0];
                tmp[1][0] = data[0][1];
                tmp[1][1] = data[1][1];
                tmp[1][2] = data[2][1];
                tmp[2][0] = data[0][2];
                tmp[2][1] = data[1][2];
                tmp[2][2] = data[2][2];
                *this = tmp;
            }

            template <class T>
            void Matrix3x3<T>::inverse() {
                Matrix3x3<T> tmp;
                NREfloat det = getDeterminant();
                if (std::abs(det) > Global::EPSILON) {
                    tmp[0][0] = (1.0 / det) * (data[1][1] * data[2][2] - data[1][2] * data[2][1]);
                    tmp[0][1] = (1.0 / det) * (data[0][2] * data[2][1] - data[0][1] * data[2][2]);
                    tmp[0][2] = (1.0 / det) * (data[0][1] * data[1][2] - data[0][2] * data[1][1]);
                    tmp[1][0] = (1.0 / det) * (data[1][2] * data[2][0] - data[1][0] * data[2][2]);
                    tmp[1][1] = (1.0 / det) * (data[0][0] * data[2][2] - data[0][2] * data[2][0]);
                    tmp[1][2] = (1.0 / det) * (data[0][2] * data[1][0] - data[0][0] * data[1][2]);
                    tmp[2][0] = (1.0 / det) * (data[1][0] * data[2][1] - data[1][1] * data[2][0]);
                    tmp[2][1] = (1.0 / det) * (data[0][1] * data[2][0] - data[0][0] * data[2][1]);
                    tmp[2][2] = (1.0 / det) * (data[0][0] * data[1][1] - data[0][1] * data[1][0]);
                }

                *this = tmp;
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::translate(Vector2D<K> const& u) {
                setC3(getC1() * u.getX() + getC2() * u.getY() + getC3());
            }

            template <class T>
            template <class K>
            void Matrix3x3<T>::scale(Vector2D<K> const& u) {
                setC1(getC1() * u.getX());
                setC2(getC2() * u.getY());
            }

            template <class T>
            T* const Matrix3x3<T>::value() {
                return &data[0][0];
            }

            template <class T>
            Vector3D<T>& Matrix3x3<T>::operator[](unsigned int const& index) {
                return data[index];
            }
            template <class T>
            const Vector3D<T>& Matrix3x3<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator=(Matrix3x3<K> const& m) {
                for(unsigned int i = 0; i < 3; i = i + 1) {
                    data[i] = m[i];
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator+=(Matrix3x3<K> const& m) {
                for(unsigned int i = 0; i < 3; i = i + 1) {
                    data[i] = data[i] + m[i];
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator-=(Matrix3x3<K> const& m) {
                for(unsigned int i = 0; i < 3; i = i + 1) {
                    data[i] = data[i] - m[i];
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator*=(K const& k) {
                for(unsigned int i = 0; i < 3; i = i + 1) {
                    data[i] = data[i] * k;
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator*=(Matrix3x3<K> const& m) {
                Matrix3x3<T> tmp(*this);
                tmp[0][0] = getL1() | m.getC1(); tmp[0][1] = getL1() | m.getC2(); tmp[0][2] = getL1() | m.getC3();
                tmp[1][0] = getL2() | m.getC1(); tmp[1][1] = getL2() | m.getC2(); tmp[1][2] = getL2() | m.getC3();
                tmp[2][0] = getL3() | m.getC1(); tmp[2][1] = getL3() | m.getC2(); tmp[2][2] = getL3() | m.getC3();
                *this = tmp;
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator/=(K const& k) {
                for(unsigned int i = 0; i < 3; i = i + 1) {
                    data[i] = data[i] / k;
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix3x3<T>& Matrix3x3<T>::operator/=(Matrix3x3<K> const& m) {
                Matrix3x3<K> tmp(m); tmp.inverse();
                return *this *= tmp;
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator+(Matrix3x3<K> const& m) const {
                Matrix3x3<T> tmp(*this);
                return tmp += m;
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator-(Matrix3x3<K> const& m) const {
                Matrix3x3<T> tmp(*this);
                return tmp -= m;
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator*(K const& k)  const {
                Matrix3x3<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator*(Matrix3x3<K> const& m) const {
                Matrix3x3<T> tmp(*this);
                return tmp *= m;
            }

            template <class T>
            template <class K>
            Vector3D<K> Matrix3x3<T>::operator*(Vector3D<K> const& u) const {
                return Vector3D<K>(u | getL1(), u | getL2(), u | getL3());
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator/(K const& k) const {
                Matrix3x3<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            Matrix3x3<T> Matrix3x3<T>::operator/(Matrix3x3<K> const& m) const {
                Matrix3x3<T> tmp(*this);
                return tmp /= m;
            }

            template <class T>
            template <class K>
            bool Matrix3x3<T>::operator==(Matrix3x3<K> const& m) const {
                return getL1() == m.getL1() && getL2() == m.getL2() && getL3() == m.getL3();
            }

            template <class T>
            template <class K>
            bool Matrix3x3<T>::operator!=(Matrix3x3<K> const& m) const {
                return !(*this == m);
            }

        };
    };
