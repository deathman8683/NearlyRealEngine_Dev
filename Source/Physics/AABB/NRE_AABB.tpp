
    namespace NRE {
        namespace Physics {

            template <class T>
            AABB<T>::AABB() {
            }

            template <class T>
            template <class K, class L>
            AABB<T>::AABB(Maths::Point3D<K> const& p, Maths::Vector3D<L> const& u) : center(p), hExtent(u) {
            }

            template <class T>
            template <class K, class L>
            AABB<T>::AABB(Maths::Point3D<K> const& p1, Maths::Point3D<L> const& p2) {
                setHExtent((p2 - p1) / 2);
                setCenter(p1 + getHExtent());
            }

            template <class T>
            AABB<T>::AABB(AABB const& box) : center(box.getCenter()), hExtent(box.getHExtent()) {
            }

            template <class T>
            template <class K>
            AABB<T>::AABB(AABB<K> const& box) : center(box.getCenter()), hExtent(box.getHExtent()) {
            }

            template <class T>
            AABB<T>::~AABB() {
            }

            template <class T>
            Maths::Point3D<T> const& AABB<T>::getCenter() const {
                return center;
            }

            template <class T>
            Maths::Vector3D<T> const& AABB<T>::getHExtent() const {
                return hExtent;
            }

            template <class T>
            template <class K>
            void AABB<T>::setCenter(Maths::Point3D<K> const& p) {
                center = p;
            }

            template <class T>
            template <class K>
            void AABB<T>::setHExtent(Maths::Vector3D<K> const& u) {
                hExtent = u;
            }

        };
    };
