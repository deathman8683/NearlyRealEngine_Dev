
    /**
     * @file NRE_Point3D.hpp
     * @brief Declaration of Engine's Maths's Object : Point3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

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
                protected:
                    T z;

                public:
                    //## Constructor ##//
                        Point3D();
                        Point3D(T const& x, T const& y, T const& z);
                        Point3D(T const& value);
                        Point3D(Point3D<T> const& p, Vector3D<T> const& u);

                    //## Copy-Constructor ##//
                        Point3D(Point3D const& p);

                    //## Move-Constructor ##//
                        Point3D(Point3D && p);

                    //## Convertor ##//
                        template <class K>
                        Point3D(Point3D<K> const& p);
                        template <class K>
                        Point3D(Vector3D<K> const& u);
                        Point3D(Point2D<T> const& p);
                        Point3D(Point2D<T> const& p, T const& z);

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
                        NREfloat const distance(Point3D<T> const& p = Point3D()) const;
                        NREfloat const distanceSquared(Point3D<T> const& p = Point3D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Point3D<T>& operator=(Point3D<T> const& base);
                        Point3D<T>& operator=(Point3D<T> && base);

                    //## Shortcut Operator ##//
                        Point3D<T>& operator+=(Vector3D<T> const& u);
                        Point3D<T>& operator-=(Vector3D<T> const& u);

                    //## Arithmetic Operator ##//
                        Point3D<T> operator+(Vector3D<T> const& u) const;
                        Point3D<T> operator-(Vector3D<T> const& u) const;
                        Vector3D<T> operator-(Point3D<T> const& p) const;
                        Point3D<T> operator-() const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Point3D<K> const& p) const;
                        template <class K>
                        bool const operator!=(Point3D<K> const& p) const;
                        bool const operator<(Point3D<T> const& p) const;
                        bool const operator>(Point3D<T> const& p) const;
                        bool const operator<=(Point3D<T> const& p) const;
                        bool const operator>=(Point3D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_Z;  /**< The default applicate */
            };

            template <class T>
            int Point3D<T>::DEFAULT_Z = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y, z)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point3D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point3D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Point3D.tpp"
