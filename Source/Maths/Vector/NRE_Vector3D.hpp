
    /**
     * @file NRE_Vector3D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector3D
     * @author Louis ABEL
     * @version 1.0
     */

     #pragma once

    #include "../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Maths
         * @brief Engine's Mathematicals Module
         */
        namespace Maths {

            template<class> class Point3D;

            /**
             * @class Vector3D
             * @brief Maths's Object : Cartesian 3D Generic Vector
             */
            template <class T>
            class Vector3D : public Vector2D<T> {
                private:
                    T z;

                public:
                    //## Constructor ##//
                    Vector3D();
                    template <class K, class L, class M>
                    Vector3D(K const& x, L const& y, M const& z);
                    template <class K, class L>
                    Vector3D(Vector2D<K> const& u, L const& z);
                    template <class K, class L>
                    Vector3D(Point3D<K> const& a, Point3D<L> const& b);

                    //## Copy-Constructor ##//
                    Vector3D(Vector3D const& u);

                    //## Convertor ##//
                    template <class K>
                    Vector3D(Vector3D<K> const& u);
                    template <class K>
                    Vector3D(Point3D<K> const& p);

                    //## Deconstructor ##//
                    ~Vector3D();

                    //## Getter ##//
                    const& T getZ() const;

                    //## Setter ##//
                    template <class K>
                    void setZ(K const& z);
                    template <class K, class L, class M>
                    void setCoord(K const& x, L const& y, M const& z);
                    template <class K, class L>
                    void setCoord(Vector2D<K> const& u, L const& z);

                    //## Methods ##//
                    NREfloat norm() const;
                    NREfloat normSquared() const;
                    void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
