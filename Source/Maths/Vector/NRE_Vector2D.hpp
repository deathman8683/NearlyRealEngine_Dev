
    #pragma once

    namespace NRE {
        namespace Maths {

            template <class T>
            class Vector2D {
                private:
                    T x;
                    T y;

                public:
                    Vector2D();
                    Vector2D(T const& x, T const& y);
                    Vector2D(Vector2D const& u);
                    template <class K>
                    Vector2D(Vector2D<K> const& u);
                    ~Vector2D();

                    T const& getX() const;
                    T const& getY() const;

                    void setX(T const& x);
                    void setY(T const& y);
                    void setCoord(T const& x, T const& y);

                    template <class K>
                    Vector2D<T> operator+(Vector2D<K> const& u);

                private:
                    static int DEFAULT_X;
                    static int DEFAULT_Y;
            };

            template <class T>
            int Vector2D<T>::DEFAULT_X = 0;

            template <class T>
            int Vector2D<T>::DEFAULT_Y = 0;

        };
    };

    #include "NRE_Vector2D.tpp"
