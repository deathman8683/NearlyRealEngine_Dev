
    namespace NRE {
        namespace Physics {

            template <class T>
            AABB<T>::AABB() {
            }

            template <class T>
            AABB<T>::AABB(Maths::Point3D<T> const& p, Maths::Vector3D<T> const& u) : center(p), hExtent(u) {
            }

            template <class T>
            AABB<T>::AABB(Maths::Point3D<T> const& p1, Maths::Point3D<T> const& p2) {
                setHExtent((p2 - p1) / 2);
                setCenter(p1 + getHExtent());
            }

            template <class T>
            AABB<T>::AABB(AABB const& box) : center(box.getCenter()), hExtent(box.getHExtent()) {
            }

            template <class T>
            AABB<T>::AABB(AABB && box) : center(std::move(box.getCenter())), hExtent(std::move(box.getHExtent())) {
            }

            template <class T>
            template <class K>
            AABB<T>::AABB(AABB<K> const& box) : center(static_cast <Maths::Point3D<T>> (box.getCenter())), hExtent(static_cast <Maths::Vector3D<T>> (box.getHExtent())) {
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
            Maths::Point3D<T> const AABB<T>::getMin() const {
                return getCenter() - getHExtent();
            }

            template <class T>
            Maths::Point3D<T> const AABB<T>::getMax() const {
                return getCenter() + getHExtent();
            }

            template <class T>
            Maths::Point3D<T> const AABB<T>::getPVertex(Maths::Vector3D<T> const& n) const {
                Maths::Point3D<T> p(getMin());
                Maths::Point3D<T> pMax(getMax());

                if (n.getX() >= 0) {
                    p.setX(pMax.getX());
                }
                if (n.getY() >= 0) {
                    p.setY(pMax.getY());
                }
                if (n.getZ() >= 0) {
                    p.setZ(pMax.getZ());
                }

                return p;
            }
            template <class T>
            Maths::Point3D<T> const AABB<T>::getNVertex(Maths::Vector3D<T> const& n) const {
                Maths::Point3D<T> p(getMax());
                Maths::Point3D<T> pMin(getMin());

                if (n.getX() >= 0) {
                    p.setX(pMin.getX());
                }
                if (n.getY() >= 0) {
                    p.setY(pMin.getY());
                }
                if (n.getZ() >= 0) {
                    p.setZ(pMin.getZ());
                }

                return p;
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

            template <class T>
            AABB<T>& AABB<T>::operator=(AABB<T> const& box) {
                center = box.getCenter();
                hExtent = box.getHExtent();
                return *this;
            }

            template <class T>
            AABB<T>& AABB<T>::operator=(AABB<T> && box) {
                center = std::move(box.getCenter());
                hExtent = std::move(box.getHExtent());
                return *this;
            }

        };
    };
