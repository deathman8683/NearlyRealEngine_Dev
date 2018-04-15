
    /**
     * @file NRE_Vector2D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

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

            template<class> class Point2D;

            /**
             * @class Vector2D
             * @brief Maths's Object : Cartesian 2D Generic Vector
             */
            template <class T>
            class Vector2D {
                protected:
                    T x;
                    T y;

                public:
                    //## Constructor ##//
                        Vector2D();
                        Vector2D(T const& x, T const& y);
                        Vector2D(T const& value);
                        Vector2D(Point2D<T> const& a, Point2D<T> const& b);

                    //## Copy-Constructor ##//
                        Vector2D(Vector2D const& u);

                    //## Move-Constructor ##//
                        Vector2D(Vector2D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector2D(Vector2D<K> const& u);
                        template <class K>
                        Vector2D(Point2D<K> const& p);

                    //## Deconstructor ##//
                        ~Vector2D();

                    //## Getter ##//
                        T const& getX() const;
                        T const& getY() const;
                        T const& getW() const;
                        T const& getH() const;

                    //## Setter ##//
                        template <class K>
                        void setX(K const& x);
                        template <class K>
                        void setY(K const& y);
                        template <class K>
                        void setW(K const& w);
                        template <class K>
                        void setH(K const& h);
                        template <class K, class L>
                        void setCoord(K const& x, L const& y);
                        template <class K, class L>
                        void setSize(K const& w, L const& h);

                    //## Methods ##//
                        NREfloat const norm() const;
                        NREfloat const normSquared() const;
                        void normalize();
                        const T* const value() const;

                    //## Access Operator ##//
                        T& operator[](unsigned int const& index);
                        const T& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        Vector2D<T>& operator=(Vector2D<T> const& base);
                        Vector2D<T>& operator=(Vector2D<T> && base);

                    //## Shortcut Operator ##//
                        Vector2D<T>& operator+=(Vector2D<T> const& u);
                        Vector2D<T>& operator-=(Vector2D<T> const& u);
                        Vector2D<T>& operator*=(T const& k);
                        Vector2D<T>& operator/=(T const& k);
                        NREfloat const operator|=(Vector2D<T> const& u) const;

                    //## Arithmetic Operator ##//
                        Vector2D<T> operator+(Vector2D<T> const& u) const;
                        Vector2D<T> operator-(Vector2D<T> const& u) const;
                        Vector2D<T> operator-() const;
                        Vector2D<T> operator*(T const& k) const;
                        Vector2D<T> operator/(T const& k) const;
                        NREfloat const operator|(Vector2D<T> const& u) const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Vector2D<K> const& u) const;
                        template <class K>
                        bool const operator!=(Vector2D<K> const& u) const;
                        bool const operator<(Vector2D<T> const& u) const;
                        bool const operator>(Vector2D<T> const& u) const;
                        bool const operator<=(Vector2D<T> const& u) const;
                        bool const operator>=(Vector2D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//


                protected:
                    static int DEFAULT_X;  /**< The default x axis translation */
                    static int DEFAULT_Y;  /**< The default y axis translation */
            };

            template <class T>
            int Vector2D<T>::DEFAULT_X = 0.;
            template <class T>
            int Vector2D<T>::DEFAULT_Y = 0.;

            /**
             * @brief Shift Operator <<
             * Add u to an out stream with : (x, y)
             * @param stream : std::ostream, the out stream to add u
             * @param u : Vector2D<T>, the vector to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Vector2D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector2D.tpp"
