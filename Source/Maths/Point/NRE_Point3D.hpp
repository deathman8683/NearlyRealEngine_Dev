
    /**
     * @file NRE_Point3D.hpp
     * @brief Declaration of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

     #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "NRE_Point2D.hpp"

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

            template<class> class Vector3D;

            /**
             * @class Point3D
             * @brief Maths's Object : Cartesian 3D Generic Point
             */
            template <class T>
            class Point3D : public Point2D<T> {
                private:
                    T z;

                public:
                    //## Constructor ##//
                    Point3D();
                    template <class K, class L, class M>
                    Point3D(K const& x, L const& y, M const& z);
                    template <class K, class L>
                    Point3D(Point2D<K> const& p, L const& z);
                    template <class K, class L>
                    Point3D(Point3D<K> const& p, Vector3D<L> const& u);

                    //## Copy-Constructor ##//
                    Point3D(Point3D const& p);

                    //## Convertor ##//
                    template <class K>
                    Point3D(Point3D<K> const& p);
                    template <class K>
                    Point3D(Vector3D<K> const& u);

                    //## Deconstructor ##//
                    ~Point3D();

                    //## Getter ##//
                    T const& getZ() const;

                    //## Setter ##//
                    template <class K>
                    void setZ(K const& z);
                    template <class K, class L, class M>
                    void setCoord(K const& x, L const& y, M const& z);
                    template <class K, class L>
                    void setCoord(Point2D<K> const& p, L const& z);

                    //## Methods ##//
                    NREfloat distance(Point3D<T> const& p = {DEFAULT_X, DEFAULT_Y, DEFAULT_Z}) const;
                    NREfloat distanceSquared(Point3D<T> const& p = {DEFAULT_X, DEFAULT_Y, DEFAULT_Z}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    template <class K>
                    Point3D<T>& operator+=(Vector3D<K> const& u);
                    template <class K>
                    Point3D<T>& operator-=(Vector3D<K> const& u);

                    //## Arithmetic Operator ##//
                    template <class K>
                    Point3D<T> operator+(Vector3D<K> const& u);
                    template <class K>
                    Point3D<T> operator-(Vector3D<K> const& u);
                    Point3D<T> operator-();

                    //## Comparison Operator ##//
                    template <class K>
                    bool operator==(Point3D<K> const& p);
                    template <class K>
                    bool operator!=(Point3D<K> const& p);
                    template <class K>
                    bool operator<(Point3D<K> const& p);
                    template <class K>
                    bool operator>(Point3D<K> const& p);
                    template <class K>
                    bool operator<=(Point3D<K> const& p);
                    template <class K>
                    bool operator>=(Point3D<K> const& p);

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_Z;
            };

            template <class T>
            NREfloat Point3D<T>::DEFAULT_Z = 0.;

            template <class T>
            std::ostream& operator<<(std::ostream &stream, Point3D<T> const& p);

        };
    };
