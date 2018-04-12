
    /**
     * @file NRE_Vector3D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Base/3D/NRE_Base3D.hpp"

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
             * @class Vector3D
             * @brief Maths's Object : Cartesian 3D Generic Vector
             */
            template <class T>
            class Vector3D : public Base3D<T> {
                private:

                public:
                    //## Constructor ##//
                        Vector3D();
                        Vector3D(T const& x, T const& y, T const& z);
                        Vector3D(T const& value);

                    //## Copy-Constructor ##//
                        Vector3D(Vector3D const& u);

                    //## Move-Constructor ##//
                        Vector3D(Vector3D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector3D(Base3D<K> const& u);
                        Vector3D(Vector2D<T> const& u);
                        Vector3D(Vector2D<T> const& u, T const& z);

                    //## Deconstructor ##//
                        ~Vector3D();

                    //## Getter ##//
                        T const& getR() const;
                        T const& getG() const;
                        T const& getB() const;

                    //## Setter ##//
                        template <class K>
                        void setR(K const& r);
                        template <class K>
                        void setG(K const& g);
                        template <class K>
                        void setB(K const& b);
                        template <class K, class L, class M>
                        void setIntensities(K const& r, L const& g, M const& b);

                    //## Methods ##//
                        NREfloat const norm() const;
                        NREfloat const normSquared() const;
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Vector3D<T>& operator=(Vector3D<T> const& u);
                        Vector3D<T>& operator=(Vector3D<T> && u);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                        bool const operator<(Vector3D<T> const& u) const;
                        bool const operator>(Vector3D<T> const& u) const;
                        bool const operator<=(Vector3D<T> const& u) const;
                        bool const operator>=(Vector3D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
            };

        };
    };

    #include "NRE_Vector3D.tpp"
