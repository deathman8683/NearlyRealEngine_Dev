
    namespace NRE {
        namespace Maths {

            template <class T>
            Matrix4x4<T>::Matrix4x4() {
                setIdentity();
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(T const& a, T const& b, T const& c, T const& d,
                                    T const& e, T const& f, T const& g, T const& h,
                                    T const& i, T const& j, T const& k, T const& l,
                                    T const& m, T const& n, T const& o, T const& p)
                                    : data{{a, b, c, d}, {e, f, g, h}, {i, j, k, l}, {m, n, o, p}} {
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(T const& value) : Matrix4x4(value, value, value, value,
                                                                value, value, value, value,
                                                                value, value, value, value,
                                                                value, value, value, value) {
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(Vector4D<T> const& l1, Vector4D<T> const& l2, Vector4D<T> const& l3, Vector4D<T> const& l4)
                                    : data{l1, l2, l3, l4} {
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(Point4D<T> const& l1, Point4D<T> const& l2, Point4D<T> const& l3, Point4D<T> const& l4)
                                    : data{l1, l2, l3, l4} {
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(Matrix4x4 const& m) : data{m.getL1(), m.getL2(), m.getL3(), m.getL4()} {
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(Matrix4x4 && m) : data{std::move(m.getL1()), std::move(m.getL2()), std::move(m.getL3()), std::move(m.getL4())} {
            }

            template <class T>
            template <class K>
            Matrix4x4<T>::Matrix4x4(Matrix4x4<K> const& m) : data{static_cast <Vector4D<T>> (m.getL1()), static_cast <Vector4D<T>> (m.getL2()), static_cast <Vector4D<T>> (m.getL3()), static_cast <Vector4D<T>> (m.getL4())} {
            }

            template <class T>
            template <class K>
            Matrix4x4<T>::Matrix4x4(Matrix3x3<K> const& m) : data{Vector4D<T>(m.getL1(), 0.0), Vector4D<T>(m.getL2(), 0.0), Vector4D<T>(m.getL3(), 0.0), Vector4D<T>(0.0, 0.0, 0.0, 1.0)} {
            }

            template <class T>
            Matrix4x4<T>::~Matrix4x4() {
            }

            template <class T>
            Vector4D<T> const& Matrix4x4<T>::getL1() const {
                return data[0];
            }

            template <class T>
            Vector4D<T> const& Matrix4x4<T>::getL2() const {
                return data[1];
            }

            template <class T>
            Vector4D<T> const& Matrix4x4<T>::getL3() const {
                return data[2];
            }

            template <class T>
            Vector4D<T> const& Matrix4x4<T>::getL4() const {
                return data[3];
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getC1() const {
                return Vector4D<T>(data[0][0], data[1][0], data[2][0], data[3][0]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getC2() const {
                return Vector4D<T>(data[0][1], data[1][1], data[2][1], data[3][1]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getC3() const {
                return Vector4D<T>(data[0][2], data[1][2], data[2][2], data[3][2]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getC4() const {
                return Vector4D<T>(data[0][3], data[1][3], data[2][3], data[3][3]);
            }

            template <class T>
            NREfloat const Matrix4x4<T>::getDeterminant() const {
                return (data[0][0] * data[1][1] * data[2][2] * data[3][3]) + (data[0][0] * data[1][2] * data[2][3] * data[3][1]) + (data[0][0] * data[1][3] * data[2][1] * data[3][2])
                     + (data[0][1] * data[1][0] * data[2][3] * data[3][2]) + (data[0][1] * data[1][2] * data[2][0] * data[3][3]) + (data[0][1] * data[1][3] * data[2][2] * data[3][0])
                     + (data[0][2] * data[1][0] * data[2][1] * data[3][3]) + (data[0][2] * data[1][1] * data[2][3] * data[3][0]) + (data[0][2] * data[1][3] * data[2][0] * data[3][1])
                     + (data[0][3] * data[1][0] * data[2][2] * data[3][1]) + (data[0][3] * data[1][1] * data[2][0] * data[3][2]) + (data[0][3] * data[1][2] * data[2][1] * data[3][0])
                     - (data[0][0] * data[1][1] * data[2][3] * data[3][2]) - (data[0][0] * data[1][2] * data[2][1] * data[3][3]) - (data[0][0] * data[1][3] * data[2][2] * data[3][1])
                     - (data[0][1] * data[1][0] * data[2][2] * data[3][3]) - (data[0][1] * data[1][2] * data[2][3] * data[3][0]) - (data[0][1] * data[1][3] * data[2][0] * data[3][2])
                     - (data[0][2] * data[1][0] * data[2][3] * data[3][1]) - (data[0][2] * data[1][1] * data[2][0] * data[3][3]) - (data[0][2] * data[1][3] * data[2][1] * data[3][0])
                     - (data[0][3] * data[1][0] * data[2][1] * data[3][2]) - (data[0][3] * data[1][1] * data[2][2] * data[3][0]) - (data[0][3] * data[1][2] * data[2][0] * data[3][1]);
            }

            template <class T>
            void Matrix4x4<T>::setL1(Vector4D<T> const& l1) {
                data[0] = l1;
            }

            template <class T>
            void Matrix4x4<T>::setL2(Vector4D<T> const& l2) {
                data[1] = l2;
            }

            template <class T>
            void Matrix4x4<T>::setL3(Vector4D<T> const& l3) {
                data[2] = l3;
            }

            template <class T>
            void Matrix4x4<T>::setL4(Vector4D<T> const& l4) {
                data[3] = l4;
            }

            template <class T>
            void Matrix4x4<T>::setC1(Vector4D<T> const& c1) {
                data[0][0] = c1.getX();
                data[1][0] = c1.getY();
                data[2][0] = c1.getZ();
                data[3][0] = c1.getW();
            }

            template <class T>
            void Matrix4x4<T>::setC2(Vector4D<T> const& c2) {
                data[0][1] = c2.getX();
                data[1][1] = c2.getY();
                data[2][1] = c2.getZ();
                data[3][1] = c2.getW();
            }

            template <class T>
            void Matrix4x4<T>::setC3(Vector4D<T> const& c3) {
                data[0][2] = c3.getX();
                data[1][2] = c3.getY();
                data[2][2] = c3.getZ();
                data[3][2] = c3.getW();
            }

            template <class T>
            void Matrix4x4<T>::setC4(Vector4D<T> const& c4) {
                data[0][3] = c4.getX();
                data[1][3] = c4.getY();
                data[2][3] = c4.getZ();
                data[3][3] = c4.getW();
            }

            template <class T>
            void Matrix4x4<T>::setIdentity() {
                setL1(Vector4D<T>(1, 0, 0, 0));
                setL2(Vector4D<T>(0, 1, 0, 0));
                setL3(Vector4D<T>(0, 0, 1, 0));
                setL4(Vector4D<T>(0, 0, 0, 1));
            }

            template <class T>
            void Matrix4x4<T>::transpose() {
                Matrix4x4<T> tmp;
                tmp[0][0] = data[0][0];
                tmp[0][1] = data[1][0];
                tmp[0][2] = data[2][0];
                tmp[0][3] = data[3][0];
                tmp[1][0] = data[0][1];
                tmp[1][1] = data[1][1];
                tmp[1][2] = data[2][1];
                tmp[1][3] = data[3][1];
                tmp[2][0] = data[0][2];
                tmp[2][1] = data[1][2];
                tmp[2][2] = data[2][2];
                tmp[2][3] = data[3][2];
                tmp[3][0] = data[0][3];
                tmp[3][1] = data[1][3];
                tmp[3][2] = data[2][3];
                tmp[3][3] = data[3][3];
                *this = tmp;
            }

            template <class T>
            void Matrix4x4<T>::inverse() {
                Matrix4x4<T> tmp;
                NREfloat det = getDeterminant();
                if (std::abs(det) > Global::EPSILON) {
                    tmp[0][0] = (1.0 / det) * ((data[1][1] * data[2][2] * data[3][3]) + (data[1][2] * data[2][3] * data[3][1]) + (data[1][3] * data[2][1] * data[3][2])
                                            - (data[1][1] * data[2][3] * data[3][2]) - (data[1][2] * data[2][1] * data[3][3]) - (data[1][3] * data[2][2] * data[3][1]));
                    tmp[0][1] = (1.0 / det) * ((data[0][1] * data[2][3] * data[3][2]) + (data[0][2] * data[2][1] * data[3][3]) + (data[0][3] * data[2][2] * data[3][1])
                                            - (data[0][1] * data[2][2] * data[3][3]) - (data[0][2] * data[2][3] * data[3][1]) - (data[0][3] * data[2][1] * data[3][2]));
                    tmp[0][2] = (1.0 / det) * ((data[0][1] * data[1][2] * data[3][3]) + (data[0][2] * data[1][3] * data[3][1]) + (data[0][3] * data[1][1] * data[3][2])
                                            - (data[0][1] * data[1][3] * data[3][2]) - (data[0][2] * data[1][1] * data[3][3]) - (data[0][3] * data[1][2] * data[3][1]));
                    tmp[0][3] = (1.0 / det) * ((data[0][1] * data[1][3] * data[2][2]) + (data[0][2] * data[1][1] * data[2][3]) + (data[0][3] * data[1][2] * data[2][1])
                                            - (data[0][1] * data[1][2] * data[2][3]) - (data[0][2] * data[1][3] * data[2][1]) - (data[0][3] * data[1][1] * data[2][2]));
                    tmp[1][0] = (1.0 / det) * ((data[1][0] * data[2][3] * data[3][2]) + (data[1][2] * data[2][0] * data[3][3]) + (data[1][3] * data[2][2] * data[3][0])
                                            - (data[1][0] * data[2][2] * data[3][3]) - (data[1][2] * data[2][3] * data[3][0]) - (data[1][3] * data[2][0] * data[3][2]));
                    tmp[1][1] = (1.0 / det) * ((data[0][0] * data[2][2] * data[3][3]) + (data[0][2] * data[2][3] * data[3][0]) + (data[0][3] * data[2][0] * data[3][2])
                                            - (data[0][0] * data[2][3] * data[3][2]) - (data[0][2] * data[2][0] * data[3][3]) - (data[0][3] * data[2][2] * data[3][0]));
                    tmp[1][2] = (1.0 / det) * ((data[0][0] * data[1][3] * data[3][2]) + (data[0][2] * data[1][0] * data[3][3]) + (data[0][3] * data[1][2] * data[3][0])
                                            - (data[0][0] * data[1][2] * data[3][3]) - (data[0][2] * data[1][3] * data[3][0]) - (data[0][3] * data[1][0] * data[3][2]));
                    tmp[1][3] = (1.0 / det) * ((data[0][0] * data[1][2] * data[2][3]) + (data[0][2] * data[1][3] * data[2][0]) + (data[0][3] * data[1][0] * data[2][2])
                                            - (data[0][0] * data[1][3] * data[2][2]) - (data[0][2] * data[1][0] * data[2][3]) - (data[0][3] * data[1][2] * data[2][0]));
                    tmp[2][0] = (1.0 / det) * ((data[1][0] * data[2][1] * data[3][3]) + (data[1][1] * data[2][3] * data[3][0]) + (data[1][3] * data[2][0] * data[3][1])
                                            - (data[1][0] * data[2][3] * data[3][1]) - (data[1][1] * data[2][0] * data[3][3]) - (data[1][3] * data[2][1] * data[3][0]));
                    tmp[2][1] = (1.0 / det) * ((data[0][0] * data[2][3] * data[3][1]) + (data[0][1] * data[2][0] * data[3][3]) + (data[0][3] * data[2][1] * data[3][0])
                                            - (data[0][0] * data[2][1] * data[3][3]) - (data[0][1] * data[2][3] * data[3][0]) - (data[0][3] * data[2][0] * data[3][1]));
                    tmp[2][2] = (1.0 / det) * ((data[0][0] * data[1][1] * data[3][3]) + (data[0][1] * data[1][3] * data[3][0]) + (data[0][3] * data[1][0] * data[3][1])
                                            - (data[0][0] * data[1][3] * data[3][1]) - (data[0][1] * data[1][0] * data[3][3]) - (data[0][3] * data[1][1] * data[3][0]));
                    tmp[2][3] = (1.0 / det) * ((data[0][0] * data[1][3] * data[2][1]) + (data[0][1] * data[1][0] * data[2][3]) + (data[0][3] * data[1][1] * data[2][0])
                                            - (data[0][0] * data[1][1] * data[2][3]) - (data[0][1] * data[1][3] * data[2][0]) - (data[0][3] * data[1][0] * data[2][1]));
                    tmp[3][0] = (1.0 / det) * ((data[1][0] * data[2][2] * data[3][1]) + (data[1][1] * data[2][0] * data[3][2]) + (data[1][2] * data[2][1] * data[3][0])
                                            - (data[1][0] * data[2][1] * data[3][2]) - (data[1][1] * data[2][2] * data[3][0]) - (data[1][2] * data[2][0] * data[3][1]));
                    tmp[3][1] = (1.0 / det) * ((data[0][0] * data[2][1] * data[3][2]) + (data[0][1] * data[2][2] * data[3][0]) + (data[0][2] * data[2][0] * data[3][1])
                                            - (data[0][0] * data[2][2] * data[3][1]) - (data[0][1] * data[2][0] * data[3][2]) - (data[0][2] * data[2][1] * data[3][0]));
                    tmp[3][2] = (1.0 / det) * ((data[0][0] * data[1][2] * data[3][1]) + (data[0][1] * data[1][0] * data[3][2]) + (data[0][2] * data[1][1] * data[3][0])
                                            - (data[0][0] * data[1][1] * data[3][2]) - (data[0][1] * data[1][2] * data[3][0]) - (data[0][2] * data[1][0] * data[3][1]));
                    tmp[3][3] = (1.0 / det) * ((data[0][0] * data[1][1] * data[2][2]) + (data[0][1] * data[1][2] * data[2][0]) + (data[0][2] * data[1][0] * data[2][1])
                                            - (data[0][0] * data[1][2] * data[2][1]) - (data[0][1] * data[1][0] * data[2][2]) - (data[0][2] * data[1][1] * data[2][0]));
                }

                *this = tmp;
            }

            template <class T>
            void Matrix4x4<T>::translate(Vector3D<T> const& u) {
                setC4(getC1() * u.getX() + getC2() * u.getY() + getC3() * u.getZ() + getC4());
            }

            template <class T>
            void Matrix4x4<T>::scale(Vector3D<T> const& u) {
                setC1(getC1() * u.getX());
                setC2(getC2() * u.getY());
                setC3(getC3() * u.getZ());
            }

            template <class T>
            void Matrix4x4<T>::rotate(T const& angle, Vector3D<T> const& axis) {
                NREfloat c = cos(toRad(angle));
                NREfloat s = sin(toRad(angle));

                Vector3D<T> vec(axis);
                vec.normalize();
                Vector3D<T> temp(vec * (1.0 - c));
                Matrix4x4<T> tmp(Vector4D<T>(c + temp.getX() * vec.getX(), temp.getY() * vec.getX() - s * vec.getZ(), temp.getZ() * vec.getX() + s * vec.getY(), 0),
                                 Vector4D<T>(temp.getX() * vec.getY() + s * vec.getZ(), c + temp.getY() * vec.getY(), temp.getZ() * vec.getY() - s * vec.getX(), 0),
                                 Vector4D<T>(temp.getX() * vec.getZ() - s * vec.getY(), temp.getY() * vec.getZ() + s * vec.getX(), c + temp.getZ() * vec.getZ(), 0),
                                 Vector4D<T>(0, 0, 0, 1));

                *this *= tmp;
            }

            template <class T>
            void Matrix4x4<T>::projection(T const& fov, T const& ratio, T const& zNear, T const& zFar) {
                T f = tan(fov / 2.0);
                setL1(Vector4D<T>(1.0 / (ratio * f), 0, 0, 0));
                setL2(Vector4D<T>(0, 1.0 / f, 0, 0));
                setL3(Vector4D<T>(0, 0, (zFar + zNear) / (zNear - zFar), (2 * zFar * zNear) / (zNear - zFar)));
                setL4(Vector4D<T>(0, 0, -1, 0));
            }

            template <class T>
            void Matrix4x4<T>::ortho(T const& left, T const& right, T const& bottom, T const& top, T const& zNear, T const& zFar) {
                setL1(Vector4D<T>(2.0 / (right - left), 0, 0, -((right + left) / (right - left))));
                setL2(Vector4D<T>(0, 2.0 / (top - bottom), 0, -((top + bottom) / (top - bottom))));
                setL3(Vector4D<T>(0, 0, -2.0 / (zFar - zNear), -((zFar + zNear) / (zFar - zNear))));
                setL4(Vector4D<T>(0, 0, 0, 1));
            }

            template <class T>
            void Matrix4x4<T>::lookAt(Point3D<T> const& eye, Point3D<T> const& center, Vector3D<T> const& up) {
                Vector3D<T> f = eye - center;
                f.normalize();
                Vector3D<T> s = f ^ up;
                Vector3D<T> u = s ^ f;
                s.normalize();
                u.normalize();

                Vector3D<T> vEye(eye);
                setL1(Vector4D<T>(s, -(s | vEye)));
                setL2(Vector4D<T>(u, -(u | vEye)));
                setL3(Vector4D<T>(-f, (f | vEye)));
                setL4(Vector4D<T>(0, 0, 0, 1));
            }

            template <class T>
            const T* const Matrix4x4<T>::value() const {
                return data[0].value();
            }

            template <class T>
            Vector4D<T>& Matrix4x4<T>::operator[](unsigned int const& index) {
                return data[index];
            }
            template <class T>
            const Vector4D<T>& Matrix4x4<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator=(Matrix4x4<T> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = m[i];
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator=(Matrix4x4<T> && m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = std::move(m[i]);
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator+=(Matrix4x4<T> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = data[i] + m[i];
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator-=(Matrix4x4<T> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = data[i] - m[i];
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator*=(T const& k) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = data[i] * k;
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator*=(Matrix4x4<T> const& m) {
                Matrix4x4<T> tmp(*this);
                tmp[0][0] = getL1() | m.getC1(); tmp[0][1] = getL1() | m.getC2(); tmp[0][2] = getL1() | m.getC3(); tmp[0][3] = getL1() | m.getC4();
                tmp[1][0] = getL2() | m.getC1(); tmp[1][1] = getL2() | m.getC2(); tmp[1][2] = getL2() | m.getC3(); tmp[1][3] = getL2() | m.getC4();
                tmp[2][0] = getL3() | m.getC1(); tmp[2][1] = getL3() | m.getC2(); tmp[2][2] = getL3() | m.getC3(); tmp[2][3] = getL3() | m.getC4();
                tmp[3][0] = getL4() | m.getC1(); tmp[3][1] = getL4() | m.getC2(); tmp[3][2] = getL4() | m.getC3(); tmp[3][3] = getL4() | m.getC4();
                *this = tmp;
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator/=(T const& k) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    data[i] = data[i] / k;
                }
                return *this;
            }

            template <class T>
            Matrix4x4<T>& Matrix4x4<T>::operator/=(Matrix4x4<T> const& m) {
                Matrix4x4<T> tmp(m); tmp.inverse();
                return *this *= tmp;
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator+(Matrix4x4<T> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp += m;
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator-(Matrix4x4<T> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp -= m;
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator*(T const& k)  const {
                Matrix4x4<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator*(Matrix4x4<T> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp *= m;
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::operator*(Vector4D<T> const& u) const {
                return Vector4D<T>(u | getL1(), u | getL2(), u | getL3(), u | getL4());
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator/(T const& k) const {
                Matrix4x4<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            Matrix4x4<T> Matrix4x4<T>::operator/(Matrix4x4<T> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp /= m;
            }

            template <class T>
            bool Matrix4x4<T>::operator==(Matrix4x4<T> const& m) const {
                return getL1() == m.getL1() && getL2() == m.getL2() && getL3() == m.getL3() && getL4() == m.getL4();
            }

            template <class T>
            bool Matrix4x4<T>::operator!=(Matrix4x4<T> const& m) const {
                return !(*this == m);
            }

        };
    };
