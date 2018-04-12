
    /**
     * @file NRE_Base4D.hpp
     * @brief Declaration of Engine's Maths's Object : Base4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../3D/NRE_Base3D.hpp"

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
             * @class Base4D
             * @brief Maths's Object : Base for 4D point and vector
             */
            template <class T>
            class Base4D : public Base3D<T> {
                protected:
                    T w;

                public:
                    //## Constructor ##//
                    Base4D();
                    Base4D(T const& x, T const& y, T const& z, T const& w);
                    Base4D(T const& value);

                    //## Copy-Constructor ##//
                    Base4D(Base4D const& base);

                    //## Move-Constructor ##//
                    Base4D(Base4D && base);

                    //## Convertor ##//
                    template <class K>
                    Base4D(Base4D<K> const& base);
                    Base4D(Base3D<T> const& base);
                    Base4D(Base3D<T> const& base, T const& w);

                    //## Deconstructor ##//
                    virtual ~Base4D();

                    //## Getter ##//
                    T const& getW() const;

                    //## Setter ##//
                    template <class K>
                    void setW(K const& w);
                    template <class K, class L, class M, class N>
                    void setCoord(K const& x, L const& y, M const& z, N const& w);
                    template <class K, class L>
                    void setCoord(Base3D<K> const& base, L const& w);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                    Base4D<T>& operator=(Base4D<T> const& base);
                    Base4D<T>& operator=(Base4D<T> && base);

                    //## Shortcut Operator ##//
                    Base4D<T>& operator+=(Base4D<T> const& base);
                    Base4D<T>& operator-=(Base4D<T> const& base);
                    Base4D<T>& operator*=(T const& k);
                    Base4D<T>& operator/=(T const& k);

                    //## Arithmetic Operator ##//
                    Base4D<T> operator+(Base4D<T> const& base) const;
                    Base4D<T> operator-(Base4D<T> const& base) const;
                    Base4D<T> operator-() const;
                    Base4D<T> operator*(T const& k) const;
                    Base4D<T> operator/(T const& k) const;

                    //## Comparison Operator ##//
                    bool const operator==(Base4D<T> const& base) const;
                    bool const operator!=(Base4D<T> const& base) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_W;
            };

            template <class T>
            int Base4D<T>::DEFAULT_W = 0;

            template <class T>
            inline std::ostream& operator<<(std::ostream& stream, Base4D<T> const& base) {
                stream << '(' << base.getX() << ',' << base.getY() << ',' << base.getZ() << ',' << base.getW() << ')';
                return stream;
            }

        };
    };

    #include "NRE_Base4D.tpp"
