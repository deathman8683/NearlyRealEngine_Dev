
    /**
     * @file NRE_Vector2D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Base/2D/NRE_Base2D.hpp"

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
             * @class Vector2D
             * @brief Maths's Object : Cartesian 2D Generic Vector
             */
            template <class T>
            class Vector2D : public Base2D<T> {
                private:

                public:
                    //## Constructor ##//
                        Vector2D();
                        Vector2D(T const& x, T const& y);
                        Vector2D(T const& value);

                    //## Copy-Constructor ##//
                        Vector2D(Vector2D const& u);

                    //## Move-Constructor ##//
                        Vector2D(Vector2D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector2D(Base2D<K> const& u);

                    //## Deconstructor ##//
                        ~Vector2D();

                    //## Getter ##//
                        T const& getW() const;
                        T const& getH() const;

                    //## Setter ##//
                        template <class K>
                        void setW(K const& w);
                        template <class K>
                        void setH(K const& h);
                        template <class K, class L>
                        void setSize(K const& w, L const& h);

                    //## Methods ##//
                        NREfloat norm() const;
                        NREfloat normSquared() const;
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Vector2D<T>& operator=(Vector2D<T> const& u);
                        Vector2D<T>& operator=(Vector2D<T> && u);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                        bool const operator<(Vector2D<T> const& u) const;
                        bool const operator>(Vector2D<T> const& u) const;
                        bool const operator<=(Vector2D<T> const& u) const;
                        bool const operator>=(Vector2D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift (Usually for printing methods) Operator ##//


                protected:
            };

        };
    };

    #include "NRE_Vector2D.tpp"
