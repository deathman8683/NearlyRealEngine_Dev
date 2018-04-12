
    /**
     * @file NRE_Vector4D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector4D
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
            /**
             * @class Vector4D
             * @brief Maths's Object : Homogeneous 4D Generic Vector
             */
            template <class T>
            class Vector4D : public Base4D<T> {
                private:

                public:
                    //## Constructor ##//
                        Vector4D();
                        Vector4D(T const& x, T const& y, T const& z, T const& w);
                        Vector4D(T const& value);

                    //## Copy-Constructor ##//
                        Vector4D(Vector4D const& u);

                    //## Move-Constructor ##//
                        Vector4D(Vector4D && u);

                    //## Convertor ##//
                        template <class K>
                        Vector4D(Base4D<K> const& u);
                        Vector4D(Vector3D<T> const& u);
                        Vector4D(Vector3D<T> const& u, T const& z);

                    //## Deconstructor ##//
                        ~Vector4D();

                    //## Getter ##//
                        T const& getR() const;
                        T const& getG() const;
                        T const& getB() const;
                        T const& getA() const;

                    //## Setter ##//
                        template <class K>
                        void setR(K const& r);
                        template <class K>
                        void setG(K const& g);
                        template <class K>
                        void setB(K const& b);
                        template <class K>
                        void setA(K const& a);
                        template <class K, class L, class M, class N>
                        void setIntensities(K const& r, L const& g, M const& b, N const& a);

                    //## Methods ##//
                        NREfloat const norm() const;
                        NREfloat const normSquared() const;
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Vector4D<T>& operator=(Vector4D<T> const& u);
                        Vector4D<T>& operator=(Vector4D<T> && u);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                        bool const operator<(Vector4D<T> const& u) const;
                        bool const operator>(Vector4D<T> const& u) const;
                        bool const operator<=(Vector4D<T> const& u) const;
                        bool const operator>=(Vector4D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
            };

        };
    };

    #include "NRE_Vector4D.tpp"
