
    /**
     * @file NRE_Base2D.hpp
     * @brief Declaration of Engine's Maths's Object : Base2D
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

            /**
             * @class Base2D
             * @brief Maths's Object : Base for 2D point and vector
             */
            template <class T>
            class Base2D {
                protected:
                    T x;
                    T y;

                public:
                    //## Constructor ##//
                    Base2D();
                    Base2D(T const& x, T const& y);
                    Base2D(T const& value);

                    //## Copy-Constructor ##//
                    Base2D(Base2D const& base);

                    //## Move-Constructor ##//
                    Base2D(Base2D && base);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Base2D();

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
                    const T* const value() const;

                    //## Access Operator ##//
                    T& operator[](GLuint const& index);
                    const T& operator[](GLuint const& index) const;

                    //## Assignment Operator ##//
                    Base2D<T>& operator=(Base2D<T> const& base);
                    Base2D<T>& operator=(Base2D<T> && base);

                    //## Shortcut Operator ##//
                    Base2D<T>& operator+=(Base2D<T> const& base);
                    Base2D<T>& operator-=(Base2D<T> const& base);
                    Base2D<T>& operator*=(T const& k);
                    Base2D<T>& operator/=(T const& k);

                    //## Arithmetic Operator ##//
                    Base2D<T> operator+(Base2D<T> const& base) const;
                    Base2D<T> operator-(Base2D<T> const& base) const;
                    Base2D<T> operator-() const;
                    Base2D<T> operator*(T const& k) const;
                    Base2D<T> operator/(T const& k) const;

                    //## Comparison Operator ##//
                    bool const operator==(Base2D<T> const& base) const;
                    bool const operator!=(Base2D<T> const& base) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_X;
                    static int DEFAULT_Y;
            };

            template <class T>
            int Base2D<T>::DEFAULT_X = 0;
            template <class T>
            int Base2D<T>::DEFAULT_Y = 0;

            template <class T>
            inline std::ostream& operator<<(std::ostream& stream, Base2D<T> const& base) {
                stream << '(' << base.getX() << ',' << base.getY() << ')';
                return stream;
            }

        };
    };

    #include "NRE_Base2D.tpp"
