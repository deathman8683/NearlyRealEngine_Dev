
    /**
     * @file NRE_AABB.hpp
     * @brief Declaration of Engine's Physics's Object : AABB
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Physics
         * @brief Engine's Physics Module
         */
        namespace Physics {

            enum CollisionResult {
                OUTSIDE,
                INTERSECT,
                INSIDE
            };

            /**
             * @class AABB
             * @brief Physics's Object : Axis-Aligned Bounding Box, with center + half extent
             */
            template <class T>
            class AABB {
                private:
                    Maths::Point3D<T> center;
                    Maths::Vector3D<T> hExtent;

                public:
                    //## Constructor ##//
                    AABB();
                    template <class K, class L>
                    AABB(Maths::Point3D<K> const& p, Maths::Vector3D<L> const& u);
                    template <class K, class L>
                    AABB(Maths::Point3D<K> const& p1, Maths::Point3D<L> const& p2);

                    //## Copy-Constructor ##//
                    AABB(AABB const& box);

                    //## Convertor ##//
                    template <class K>
                    AABB(AABB<K> const& box);

                    //## Deconstructor ##//
                    ~AABB();

                    //## Getter ##//
                    Maths::Point3D<T> const& getCenter() const;
                    Maths::Vector3D<T> const& getHExtent() const;
                    Maths::Point3D<T> const getMin() const;
                    Maths::Point3D<T> const getMax() const;
                    template <class K>
                    Maths::Point3D<T> const getPVertex(Maths::Vector3D<K> const& n) const;
                    template <class K>
                    Maths::Point3D<T> const getNVertex(Maths::Vector3D<K> const& n) const;
                    template <class K>
                    void getCorner(Maths::Point3D<K> *&corner) const;

                    //## Setter ##//
                    template <class K>
                    void setCenter(Maths::Point3D<K> const& p);
                    template <class K>
                    void setHExtent(Maths::Vector3D<K> const& u);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, AABB<T> const& box) {
                stream << "(" << box.getCenter() << "," << box.getHExtent() << ")";
                return stream;
            }

        };
    };

    #include "NRE_AABB.tpp"
