
    #pragma once

    #include <cmath>
    #include "../../Generic/NRE_Type.hpp"

    namespace NRE {
        namespace Maths {

            template<class> class Vector2D;

            template <class T>
            class Point2D {
                private:
                    T x;
                    T y;

                public:
                    //## Constructor | Copy-Constructor | Convertor | Deconstructor ##//
                    Point2D();
                    Point2D(T const& x, T const& y);
                    Point2D(Point2D const& p);
                    template <class K>
                    Point2D(Point2D<K> const& p);
                    template <class K>
                    Point2D(Vector2D<K> const& u);
                    template <class K, class L>
                    Point2D(Point2D<K> const& p, Vector2D<L> const& u);
                    ~Point2D();

                    //## Getter ##//
                    T const& getX() const;
                    T const& getY() const;

                    //## Setter ##//
                    void setX(T const& x);
                    void setY(T const& y);
                    void setCoord(T const& x, T const& y);

                    //## Methods ##//
                    NREfloat distance(Point2D<T> const& p = {DEFAULT_X, DEFAULT_Y}) const;
                    NREfloat distanceSquared(Point2D<T> const& p = {DEFAULT_X, DEFAULT_Y}) const;

                    //## Shortcut Operator ##//
                    template <class K>
                    Point2D<T>& operator+=(Vector2D<K> const& u);
                    template <class K>
                    Point2D<T>& operator-=(Vector2D<K> const& u);

                    //## Arithmetic Operator ##//
                    template <class K>
                    Point2D<T> operator+(Vector2D<K> const& u);
                    template <class K>
                    Point2D<T> operator-(Vector2D<K> const& u);
                    Point2D<T> operator-();

                    //## Comparison Operator ##//
                    template <class K>
                    bool operator==(Point2D<K> const& p);

                    //## BitWise Operator ##//

                    //## Shift (Usually for printing methods) Operator ##//

                private:
                    static NREfloat DEFAULT_X;
                    static NREfloat DEFAULT_Y;
            };

            template <class T>
            NREfloat Point2D<T>::DEFAULT_X = 0.;

            template <class T>
            NREfloat Point2D<T>::DEFAULT_Y = 0.;

        };
    };

    #include "NRE_Point2D.tpp"
