
    namespace NRE {
        namespace Maths {

            template <class T>
            Quaternion<T>::Quaternion() {
            }

            template <class T>
            Quaternion<T>::Quaternion(T const& x, T const& y, T const& z, T const& w) : Vector4D<T>::Vector4D(x, y, z, w) {
            }

            template <class T>
            Quaternion<T>::Quaternion(T const& value) : Vector4D<T>::Vector4D(value) {
            }

            template <class T>
            Quaternion<T>::Quaternion(Vector3D<T> const& axis, T const& theta) : Vector4D<T>::Vector4D(axis * std::sin(toRad(theta) / 2), std::cos(toRad(theta) / 2)) {
            }

            template <class T>
            Quaternion<T>::Quaternion(Quaternion const& q) : Vector4D<T>::Vector4D(q) {
            }

            template <class T>
            Quaternion<T>::Quaternion(Quaternion && q) : Vector4D<T>::Vector4D(std::move(q)) {
            }

            template <class T>
            Quaternion<T>::~Quaternion() {
            }

            template <class T>
            Quaternion<T>& Quaternion<T>::operator=(Quaternion<T> const& q) {
                Vector4D<T>::operator=(q);
                return *this;
            }

            template <class T>
            Quaternion<T>& Quaternion<T>::operator=(Quaternion<T> && q) {
                Vector4D<T>::operator=(std::move(q));
                return *this;
            }

            template <class T>
            Quaternion<T>& Quaternion<T>::operator*=(Quaternion<T> const& q) {
                Quaternion<T> tmp(this->getW() * q.getW() - this->getX() * q.getX() - this->getY() * q.getY() - this->getZ() * q.getZ(),
                                  this->getW() * q.getX() + this->getX() * q.getW() + this->getY() * q.getZ() - this->getZ() * q.getY(),
                                  this->getW() * q.getY() + this->getY() * q.getW() + this->getX() * q.getZ() - this->getZ() * q.getX(),
                                  this->getW() * q.getZ() + this->getZ() * q.getW() + this->getX() * q.getY() - this->getY() * q.getX()
                              );
                *this = tmp;
                return *this;
            }

            template <class T>
            Quaternion<T> Quaternion<T>::operator*(Quaternion<T> const& q) const {
                Quaternion<T> tmp(*this);
                return tmp *= q;
            }

        };
    };
