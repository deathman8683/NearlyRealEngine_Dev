
    /**
     * @file NRE_Point2D.hpp
     * @brief Declaration of Engine's Maths's Object : Point2D
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

            template<class> class Vector2D;

            /**
             * @class Point2D
             * @brief Maths's Object : Cartesian 2D Generic Point
             */
            template <class T>
            class Point2D {
                protected:
                    T x;
                    T y;

                public:
                    //## Constructor ##//
                        Point2D();
                        Point2D(T const& x, T const& y);
                        Point2D(T const& value);
                        Point2D(Point2D<T> const& p, Vector2D<T> const& u);

                    //## Copy-Constructor ##//
                        Point2D(Point2D const& p);

                    //## Move-Constructor ##//
                        Point2D(Point2D && p);

                    //## Convertor ##//
                        template <class K>
                        Point2D(Point2D<K> const& p);
                        template <class K>
                        Point2D(Vector2D<K> const& u);

                    //## Deconstructor ##//
                        ~Point2D();

                    //## Getter ##//
                        T const& getX() const;
                        T const& getY() const;

                    //## Setter ##//
                        template <class K>
                        void setX(K const& x);
                        template <class K>
                        void setY(K const& y);
                        template <class K, class L>
                        void setCoord(K const& x, L const& y);

                    //## Methods ##//
                        NREfloat const distance(Point2D<T> const& p = Point2D()) const;
                        NREfloat const distanceSquared(Point2D<T> const& p = Point2D()) const;
                        const T* const value() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Point2D<T>& operator=(Point2D<T> const& base);
                        Point2D<T>& operator=(Point2D<T> && base);

                    //## Shortcut Operator ##//
                        Point2D<T>& operator+=(Vector2D<T> const& u);
                        Point2D<T>& operator-=(Vector2D<T> const& u);

                    //## Arithmetic Operator ##//
                        Point2D<T> operator+(Vector2D<T> const& u) const;
                        Point2D<T> operator-(Vector2D<T> const& u) const;
                        Vector2D<T> operator-(Point2D<T> const& p) const;
                        Point2D<T> operator-() const;

                    //## Comparison Operator ##//
                        template <class K>
                        bool const operator==(Point2D<K> const& p) const;
                        template <class K>
                        bool const operator!=(Point2D<K> const& p) const;
                        bool const operator<(Point2D<T> const& p) const;
                        bool const operator>(Point2D<T> const& p) const;
                        bool const operator<=(Point2D<T> const& p) const;
                        bool const operator>=(Point2D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//;

                protected:
                    static int DEFAULT_X;  /**< The default abscissa */
                    static int DEFAULT_Y;  /**< The default ordinate */
            };

            template <class T>
            int Point2D<T>::DEFAULT_X = 0.;
            template <class T>
            int Point2D<T>::DEFAULT_Y = 0.;

            /**
             * @brief Shift Operator <<
             * Add p to an out stream with : (x, y)
             * @param stream : std::ostream, the out stream to add p
             * @param p : Point2D<T>, the point to add
             * @return std::ostream, the modified out stream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Point2D<T> const& p) {
                 stream << "(" << p.getX() << "," << p.getY() << ")";
                 return stream;
             }

        };
    };

    namespace std {
        template <>
        class hash<NRE::Maths::Point2D<GLint>> {
            public:
                size_t operator()(NRE::Maths::Point2D<GLint> const& p) const
                {
                    size_t h1 = p.getX();
                    size_t h2 = p.getY();

                    size_t hV = h2 * 100'000'000 + h1;
                    return hV;
                }
        };
    };

    #include "NRE_Point2D.tpp"
