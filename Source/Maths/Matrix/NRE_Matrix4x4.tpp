
    namespace NRE {
        namespace Maths {

            template <class T>
            Matrix4x4<T>::Matrix4x4() {
                setIdentity();
            }

            template <class T>
            template <class A, class B, class C, class D,
                     class E, class F, class G, class H,
                     class I, class J, class K, class L,
                     class M, class N, class O, class P>
            Matrix4x4<T>::Matrix4x4(A const& a, B const& b, C const& c, D const& d,
                                    D const& e, F const& f, G const& g, H const& h,
                                    I const& i, J const& j, K const& k, L const& l,
                                    M const& m, N const& n, O const& o, P const& p) {
                data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
                data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
                data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
                data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
            }

            template <class T>
            template <class K, class L, class M, class N>
            Matrix4x4<T>::Matrix4x4(Vector4D<K> const& l1, Vector4D<L> const& l2, Vector4D<M> const& l3, Vector4D<N> const& l4) {
                setL1(l1);
                setL2(l2);
                setL3(l3);
                setL4(l4);
            }

            template <class T>
            template <class K, class L, class M, class N>
            Matrix4x4<T>::Matrix4x4(Point4D<K> const& l1, Point4D<L> const& l2, Point4D<M> const& l3, Point4D<N> const& l4) {
                setL1(Vector4D<K>(l1));
                setL2(Vector4D<L>(l2));
                setL3(Vector4D<M>(l3));
                setL4(Vector4D<N>(l4));
            }

            template <class T>
            Matrix4x4<T>::Matrix4x4(Matrix4x4 const& m) {
                *this = m;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>::Matrix4x4(Matrix4x4<K> const& m) {
                *this = m;
            }

            template <class T>
            Matrix4x4<T>::~Matrix4x4() {
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getL1() const {
                return Vector4D<T>(data[0][0], data[0][1], data[0][2], data[0][3]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getL2() const {
                return Vector4D<T>(data[1][0], data[1][1], data[1][2], data[1][3]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getL3() const {
                return Vector4D<T>(data[2][0], data[2][1], data[2][2], data[2][3]);
            }

            template <class T>
            Vector4D<T> Matrix4x4<T>::getL4() const {
                return Vector4D<T>(data[3][0], data[3][1], data[3][2], data[3][3]);
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
            NREfloat Matrix4x4<T>::getDeterminant() const {
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
            template <class K>
            void Matrix4x4<T>::setL1(Vector4D<K> const& l1) {
                data[0][0] = l1.getX();
                data[0][1] = l1.getY();
                data[0][2] = l1.getZ();
                data[0][3] = l1.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setL2(Vector4D<K> const& l2) {
                data[1][0] = l2.getX();
                data[1][1] = l2.getY();
                data[1][2] = l2.getZ();
                data[1][3] = l2.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setL3(Vector4D<K> const& l3) {
                data[2][0] = l3.getX();
                data[2][1] = l3.getY();
                data[2][2] = l3.getZ();
                data[2][3] = l3.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setL4(Vector4D<K> const& l4) {
                data[3][0] = l4.getX();
                data[3][1] = l4.getY();
                data[3][2] = l4.getZ();
                data[3][3] = l4.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setC1(Vector4D<K> const& c1) {
                data[0][0] = c1.getX();
                data[1][0] = c1.getY();
                data[2][0] = c1.getZ();
                data[3][0] = c1.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setC2(Vector4D<K> const& c2) {
                data[0][1] = c2.getX();
                data[1][1] = c2.getY();
                data[2][1] = c2.getZ();
                data[3][1] = c2.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setC3(Vector4D<K> const& c3) {
                data[0][2] = c3.getX();
                data[1][2] = c3.getY();
                data[2][2] = c3.getZ();
                data[3][2] = c3.getW();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::setC4(Vector4D<K> const& c4) {
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
            template <class K>
            void Matrix4x4<T>::translate(Vector3D<K> const& u) {
                data[0][2] = data[0][2] + u.getX();
                data[1][2] = data[1][2] + u.getY();
                data[2][2] = data[2][2] + u.getZ();
            }

            template <class T>
            template <class K>
            void Matrix4x4<T>::scale(Vector3D<K> const& u) {
                data[0][0] = data[0][0] * u.getX();
                data[1][0] = data[1][0] * u.getX();
                data[2][0] = data[2][0] * u.getX();
                data[3][0] = data[3][0] * u.getX();
                data[0][1] = data[0][1] * u.getY();
                data[1][1] = data[1][1] * u.getY();
                data[2][1] = data[2][1] * u.getY();
                data[3][1] = data[3][1] * u.getY();
                data[0][2] = data[0][2] * u.getZ();
                data[1][2] = data[1][2] * u.getZ();
                data[2][2] = data[2][2] * u.getZ();
                data[3][2] = data[3][2] * u.getZ();
            }

            template <class T>
            template <class K, class L>
            void Matrix4x4<T>::rotate(K const& angle, Vector3D<L> const& axis) {
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
            template <class K, class L, class M, class N>
            void Matrix4x4<T>::projection(K const& fov, L const& ratio, M const& zNear, N const& zFar) {
                T f = tan(toRad(fov) / 2.0);
                setL1(Vector4D<T>(1.0 / (ratio * f), 0, 0, 0));
                setL2(Vector4D<T>(0, 1.0 / f, 0, 0));
                setL3(Vector4D<T>(0, 0, (zFar + zNear) / (zNear - zFar), (2 * zFar * zNear) / (zNear - zFar)));
                setL4(Vector4D<T>(0, 0, -1, 1));
            }

            template <class T>
            template <class K, class L, class M>
            void Matrix4x4<T>::lookAt(Point3D<K> const& eye, Point3D<L> const& center, Vector3D<M> const& up) {
                Vector3D<T> f = center - eye;
                f.normalize();
                Vector3D<T> s = f ^ up;
                s.normalize();
                Vector3D<T> u = s ^ f;

                Vector3D<T> vEye(eye);
                setL1(Vector4D<T>(s, -(s | vEye)));
                setL2(Vector4D<T>(u, -(u | vEye)));
                setL3(Vector4D<T>(-f, f | vEye));
                setL4(Vector4D<T>(0, 0, 0, 1));
            }

            template <class T>
            T* const Matrix4x4<T>::value() {
                return &data[0][0];
            }

            template <class T>
            T* Matrix4x4<T>::operator[](unsigned int const& index) {
                return data[index];
            }
            template <class T>
            const T* Matrix4x4<T>::operator[](unsigned int const& index) const {
                return data[index];
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator=(Matrix4x4<K> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    for(unsigned int j = 0; j < 4; j = j + 1) {
                        data[i][j] = m[i][j];
                    }
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator+=(Matrix4x4<K> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    for(unsigned int j = 0; j < 4; j = j + 1) {
                        data[i][j] = data[i][j] + m[i][j];
                    }
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator-=(Matrix4x4<K> const& m) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    for(unsigned int j = 0; j < 4; j = j + 1) {
                        data[i][j] = data[i][j] - m[i][j];
                    }
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator*=(K const& k) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    for(unsigned int j = 0; j < 4; j = j + 1) {
                        data[i][j] = data[i][j] * k;
                    }
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator*=(Matrix4x4<K> const& m) {
                Matrix4x4<T> tmp(*this);
                tmp[0][0] = getL1() | m.getC1(); tmp[0][1] = getL1() | m.getC2(); tmp[0][2] = getL1() | m.getC3(); tmp[0][3] = getL1() | m.getC4();
                tmp[1][0] = getL2() | m.getC1(); tmp[1][1] = getL2() | m.getC2(); tmp[1][2] = getL2() | m.getC3(); tmp[1][3] = getL2() | m.getC4();
                tmp[2][0] = getL3() | m.getC1(); tmp[2][1] = getL3() | m.getC2(); tmp[2][2] = getL3() | m.getC3(); tmp[2][3] = getL3() | m.getC4();
                tmp[3][0] = getL4() | m.getC1(); tmp[3][1] = getL4() | m.getC2(); tmp[3][2] = getL4() | m.getC3(); tmp[3][3] = getL4() | m.getC4();
                *this = tmp;
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator/=(K const& k) {
                for(unsigned int i = 0; i < 4; i = i + 1) {
                    for(unsigned int j = 0; j < 4; j = j + 1) {
                        data[i][j] = data[i][j] / k;
                    }
                }
                return *this;
            }

            template <class T>
            template <class K>
            Matrix4x4<T>& Matrix4x4<T>::operator/=(Matrix4x4<K> const& m) {
                Matrix4x4<K> tmp(m); tmp.inverse();
                return *this *= tmp;
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator+(Matrix4x4<K> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp += m;
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator-(Matrix4x4<K> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp -= m;
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator*(K const& k)  const {
                Matrix4x4<T> tmp(*this);
                return tmp *= k;
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator*(Matrix4x4<K> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp *= m;
            }

            template <class T>
            template <class K>
            Vector4D<K> Matrix4x4<T>::operator*(Vector4D<K> const& u) const {
                return Vector4D<K>(u | getL1(), u | getL2(), u | getL3(), u | getL4());
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator/(K const& k) const {
                Matrix4x4<T> tmp(*this);
                return tmp /= k;
            }

            template <class T>
            template <class K>
            Matrix4x4<T> Matrix4x4<T>::operator/(Matrix4x4<K> const& m) const {
                Matrix4x4<T> tmp(*this);
                return tmp /= m;
            }

            template <class T>
            template <class K>
            bool Matrix4x4<T>::operator==(Matrix4x4<K> const& m) const {
                return getL1() == m.getL1() && getL2() == m.getL2() && getL3() == m.getL3() && getL4() == m.getL4();
            }

            template <class T>
            template <class K>
            bool Matrix4x4<T>::operator!=(Matrix4x4<K> const& m) const {
                return !(*this == m);
            }

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Matrix4x4<T> const& m) {
                stream << "[" << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << "]" << std::endl;
                stream << "[" << m[1][0] << " " << m[1][1] << " " << m[1][2] << " " << m[1][3] << "]" << std::endl;
                stream << "[" << m[2][0] << " " << m[2][1] << " " << m[2][2] << " " << m[2][3] << "]" << std::endl;
                stream << "[" << m[3][0] << " " << m[3][1] << " " << m[3][2] << " " << m[3][3] << "]";
                return stream;
            }

        };
    };
