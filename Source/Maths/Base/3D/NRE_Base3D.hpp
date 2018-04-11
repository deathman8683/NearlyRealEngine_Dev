
    /**
     * @file NRE_Base3D.hpp
     * @brief Declaration of Engine's Maths's Object : Base3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../2D/NRE_Base2D.hpp"

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
             * @class Base3D
             * @brief Maths's Object : Base for 3D point and vector
             */
            template <class T>
            class Base3D : public Base2D<T> {
                protected:
                    T z;

                public:
                    //## Constructor ##//
                    Base3D();
                    Base3D(T const& x, T const& y, T const& z);
                    Base3D(T const& value);

                    //## Copy-Constructor ##//
                    Base3D(Base3D const& base);

                    //## Move-Constructor ##//
                    Base3D(Base3D && base);

                    //## Convertor ##//
                    Base3D(Base2D<T> const& )

                    //## Deconstructor ##//
                    virtual ~Base3D();

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
                    Base3D<T>& operator=(Base3D<T> const& base);
                    Base3D<T>& operator=(Base3D<T> && base);

                    //## Shortcut Operator ##//
                    Base3D<T>& operator+=(Base3D<T> const& base);
                    Base3D<T>& operator-=(Base3D<T> const& base);
                    Base3D<T>& operator*=(T const& k);
                    Base3D<T>& operator/=(T const& k);

                    //## Arithmetic Operator ##//
                    Base3D<T> operator+(Base3D<T> const& base) const;
                    Base3D<T> operator-(Base3D<T> const& base) const;
                    Base3D<T> operator-() const;
                    Base3D<T> operator*(T const& k) const;
                    Base3D<T> operator/(T const& k) const;

                    //## Comparison Operator ##//
                    bool const operator==(Base3D<T> const& base) const;
                    bool const operator!=(Base3D<T> const& base) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_X;
                    static int DEFAULT_Y;
            };

            template <class T>
            int Base3D<T>::DEFAULT_X = 0;
            template <class T>
            int Base3D<T>::DEFAULT_Y = 0;

            template <class T>
            inline std::ostream& operator<<(std::ostream& stream, Base3D<T> const& base) {
                stream << '(' << base.getX() << ',' << base.getY() << ')';
                return stream;
            }

        };
    };

    #include "NRE_Base3D.tpp"
