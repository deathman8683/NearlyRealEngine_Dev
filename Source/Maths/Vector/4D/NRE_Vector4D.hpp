
    /**
     * @file NRE_Vector4D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../3D/NRE_Vector3D.hpp"

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

            template<class> class Point4D;

            /**
             * @class Vector4D
             * @brief Maths's Object : Homogeneous 3D Generic Vector
             */
            template <class T>
            class Vector4D : public Vector3D<T> {
                private:
                    T w;

                public:
                    //## Constructor ##//
                        Vector4D();
                        Vector4D(T const& x, T const& y, T const& z, T const& w);
                        Vector4D(T const& value);
                        Vector4D(Point4D<T> const& a, Point4D<T> const& b);

                    //## Copy-Constructor ##//
                        Vector4D(Vector4D const& u);

                    //## Move-Constructor ##//
                        Vector4D(Vector4D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector4D(Vector4D<K> const& u);
                        template <class K>
                        Vector4D(Point4D<K> const& p);
                        Vector4D(Vector3D<T> const& u);
                        Vector4D(Vector3D<T> const& u, T const& w);

                    //## Deconstructor ##//
                        ~Vector4D();

                    //## Getter ##//
                        T const& getW() const;
                        T const& getA() const;

                    //## Setter ##//
                        template <class K>
                        void setW(K const& w);
                        template <class K>
                        void setA(K const& a);
                        template <class K, class L, class M, class N>
                        void setCoord(K const& x, L const& y, M const& z, N const& w);
                        template <class K, class L>
                        void setCoord(Vector3D<K> const& u, L const& w);
                        template <class K, class L, class M, class N>
                        void setIntensities(K const& r, L const& g, M const& b, N const& a);

                    //## Methods ##//
                        NREfloat const norm() const;
                        NREfloat const normSquared() const;
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Vector4D<T>& operator=(Vector4D<T> const& base);
                        Vector4D<T>& operator=(Vector4D<T> && base);

                    //## Shortcut Operator ##//
                        Vector4D<T>& operator-=(Vector4D<T> const& u);
                        Vector4D<T>& operator+=(Vector4D<T> const& u);
                        Vector4D<T>& operator*=(T const& k);
                        Vector4D<T>& operator/=(T const& k);
                        NREfloat const operator|=(Vector4D<T> const& u) const;

                    //## Arithmetic Operator ##//
                        Vector4D<T> operator+(Vector4D<T> const& u) const;
                        Vector4D<T> operator-(Vector4D<T> const& u) const;
                        Vector4D<T> operator-() const;
                        Vector4D<T> operator*(T const& k) const;
                        Vector4D<T> operator/(T const& k) const;
                        NREfloat const operator|(Vector4D<T> const& u) const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Vector4D<K> const& u) const;
                        template <class K>
                        bool const operator!=(Vector4D<K> const& u) const;
                        bool const operator<(Vector4D<T> const& u) const;
                        bool const operator>(Vector4D<T> const& u) const;
                        bool const operator<=(Vector4D<T> const& u) const;
                        bool const operator>=(Vector4D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_W;  /**< The default w axis translation */
            };

            template <class T>
            int Vector4D<T>::DEFAULT_W = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y, z, w)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector4D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             std::ostream& operator<<(std::ostream &stream, Vector4D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << "," << u.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector4D.tpp"
