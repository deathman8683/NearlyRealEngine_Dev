
    /**
     * @file NRE_Vector3D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../2D/NRE_Vector2D.hpp"

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
            template<class> class Vector4D;

            /**
             * @class Vector3D
             * @brief Maths's Object : Cartesian 3D Generic Vector
             */
            template <class T>
            class Vector3D : public Vector2D<T> {
                protected:
                    T z;

                public:
                    //## Constructor ##//
                        Vector3D();
                        Vector3D(T const& x, T const& y, T const& z);
                        Vector3D(T const& value);
                        Vector3D(Point3D<T> const& a, Point3D<T> const& b);

                    //## Copy-Constructor ##//
                        Vector3D(Vector3D const& u);

                    //## Move-Constructor ##//
                        Vector3D(Vector3D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector3D(Vector3D<K> const& u);
                        template <class K>
                        Vector3D(Point3D<K> const& p);
                        Vector3D(Vector2D<T> const& u);
                        Vector3D(Vector2D<T> const& u, T const& z);

                    //## Deconstructor ##//
                        ~Vector3D();

                    //## Getter ##//
                        T const& getZ() const;
                        T const& getR() const;
                        T const& getG() const;
                        T const& getB() const;

                    //## Setter ##//
                        template <class K>
                        void setZ(K const& z);
                        template <class K>
                        void setR(K const& r);
                        template <class K>
                        void setG(K const& g);
                        template <class K>
                        void setB(K const& b);
                        template <class K, class L, class M>
                        void setCoord(K const& x, L const& y, M const& z);
                        template <class K, class L>
                        void setCoord(Vector2D<K> const& u, L const& z);
                        template <class K, class L, class M>
                        void setIntensities(K const& r, L const& g, M const& b);

                    //## Methods ##//
                        NREfloat const norm() const;
                        NREfloat const normSquared() const;
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Vector3D<T>& operator=(Vector3D<T> const& base);
                        Vector3D<T>& operator=(Vector3D<T> && base);

                    //## Shortcut Operator ##//
                        Vector3D<T>& operator+=(Vector3D<T> const& u);
                        Vector3D<T>& operator-=(Vector3D<T> const& u);
                        Vector3D<T>& operator*=(T const& k);
                        Vector3D<T>& operator/=(T const& k);
                        NREfloat const operator|=(Vector3D<T> const& u) const;
                        Vector3D<T>& operator^=(Vector3D<T> const& u);

                    //## Arithmetic Operator ##//
                        Vector3D<T> operator+(Vector3D<T> const& u) const;
                        Vector3D<T> operator-(Vector3D<T> const& u) const;
                        Vector3D<T> operator-() const;
                        Vector3D<T> operator*(T const& k) const;
                        Vector3D<T> operator/(T const& k) const;
                        NREfloat const operator|(Vector3D<T> const& u) const;
                        Vector3D<T> operator^(Vector3D<T> const& u) const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Vector3D<K> const& u) const;
                        template <class K>
                        bool const operator!=(Vector3D<K> const& u) const;
                        bool const operator<(Vector3D<T> const& u) const;
                        bool const operator>(Vector3D<T> const& u) const;
                        bool const operator<=(Vector3D<T> const& u) const;
                        bool const operator>=(Vector3D<T> const& u) const;

                    //## BitWise Operator ##//


                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_Z;  /**< The default z axis translation */
            };

            template <class T>
            int Vector3D<T>::DEFAULT_Z = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y, z)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector3D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             std::ostream& operator<<(std::ostream &stream, Vector3D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector3D.tpp"
