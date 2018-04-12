
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
                    template <class K>
                    Base3D(Base3D<K> const& base);
                    Base3D(Base2D<T> const& base);
                    Base3D(Base2D<T> const& base, T const& z);

                    //## Deconstructor ##//
                    virtual ~Base3D();

                    //## Getter ##//
                    T const& getZ() const;

                    //## Setter ##//
                    template <class K>
                    void setZ(K const& z);
                    template <class K, class L, class M>
                    void setCoord(K const& x, L const& y, M const& z);
                    template <class K, class L>
                    void setCoord(Base2D<K> const& base, L const& z);

                    //## Methods ##//

                    //## Access Operator ##//

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
                    static int DEFAULT_Z;
            };

            template <class T>
            int Base3D<T>::DEFAULT_Z = 0;

            template <class T>
            inline std::ostream& operator<<(std::ostream& stream, Base3D<T> const& base) {
                stream << '(' << base.getX() << ',' << base.getY() << ',' << base.getZ() << ')';
                return stream;
            }

        };
    };

    #include "NRE_Base3D.tpp"
