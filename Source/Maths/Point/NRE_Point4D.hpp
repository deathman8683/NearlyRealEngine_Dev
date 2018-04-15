
    /**
     * @file NRE_Point4D.hpp
     * @brief Declaration of Engine's Maths's Object : Point4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "NRE_Point3D.hpp"

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

            template<class> class Vector4D;

            /**
             * @class Point4D
             * @brief Maths's Object : Homogeneous 3D Generic Point
             */
            template <class T>
            class Point4D : public Point3D<T> {
                private:
                    T w;

                public:
                    //## Constructor ##//
                        Point4D();
                        Point4D(T const& x, T const& y, T const& z, T const& w);
                        Point4D(T const& value);
                        Point4D(Point4D<T> const& p, Vector4D<T> const& u);

                    //## Copy-Constructor ##//
                        Point4D(Point4D const& p);

                    //## Move-Constructor ##//
                        Point4D(Point4D && p);

                    //## Convertor ##//
                        template <class K>
                        Point4D(Point4D<K> const& p);
                        template <class K>
                        Point4D(Vector4D<K> const& u);
                        Point4D(Point3D<T> const& p);
                        Point4D(Point3D<T> const& p, T const& w);

                    //## Deconstructor ##//
                        ~Point4D();

                    //## Getter ##//
                        T const& getW() const;

                    //## Setter ##//
                        template <class K>
                        void setW(K const& w);
                        template <class K, class L, class M, class N>
                        void setCoord(K const& x, L const& y, M const& z, N const& w);
                        template <class K, class L>
                        void setCoord(Point3D<K> const& p, L const& w);

                    //## Methods ##//
                        NREfloat const distance(Point4D<T> const& p = Point4D()) const;
                        NREfloat const distanceSquared(Point4D<T> const& p = Point4D()) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Point4D<T>& operator=(Point4D<T> const& base);
                        Point4D<T>& operator=(Point4D<T> && base);

                    //## Shortcut Operator ##//
                        Point4D<T>& operator+=(Vector4D<T> const& u);
                        Point4D<T>& operator-=(Vector4D<T> const& u);

                    //## Arithmetic Operator ##//
                        Point4D<T> operator+(Vector4D<T> const& u) const;
                        Point4D<T> operator-(Vector4D<T> const& u) const;
                        Vector4D<T> operator-(Point4D<T> const& p) const;
                        Point4D<T> operator-() const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Point4D<K> const& p) const;
                        template <class K>
                        bool const operator!=(Point4D<K> const& p) const;
                        bool const operator<(Point4D<T> const& p) const;
                        bool const operator>(Point4D<T> const& p) const;
                        bool const operator<=(Point4D<T> const& p) const;
                        bool const operator>=(Point4D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static int DEFAULT_W;  /**< The default homogeneous coordinate */
            };

            template <class T>
            int Point4D<T>::DEFAULT_W = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y, z, w)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point4D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point4D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << "," << p.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Point4D.tpp"
