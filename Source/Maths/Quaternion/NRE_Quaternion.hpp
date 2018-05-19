
    /**
     * @file NRE_Quaternion.hpp
     * @brief Declaration of Engine's Maths's Object : Quaternion
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Vector/4D/NRE_Vector4D.hpp"

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
             * @class Quaternion
             * @brief Maths's Object : A generic quaternion with 4D coordinates to represent the axis and the factor [x, y, z, w]
             */
            template <class T>
            class Quaternion : public Vector4D<T> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Quaternion();
                        /**
                         * Construct a quaternion with passed values
                         * @param x new x value
                         * @param y new y value
                         * @param z new z value
                         * @param w new w value
                         */
                        Quaternion(T const& x, T const& y, T const& z, T const& w);
                        /**
                         * Construct a quaternion with an unique value for all coordinates
                         * @param value new x, y, z and w values
                         */
                        Quaternion(T const& value);
                        Quaternion(Vector3D<T> const& axis, T const& theta);

                    //## Copy-Constructor ##//
                        /**
                         * Copy q into this
                         * @param q the quaternion to copy the content
                         */
                        Quaternion(Quaternion const& q);

                    //## Move-Constructor ##//
                        /**
                         * Move q into this, leaving q empty
                         * @param q the quaternion to move
                         */
                        Quaternion(Quaternion && q);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Quaternion Deconstructor
                         */
                        ~Quaternion();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of q into this
                         * @param q the quaternion to copy into this
                         * @return the reference of himself
                         */
                        Quaternion<T>& operator=(Quaternion<T> const& q);
                        /**
                         * Move assigment of q into this, leaving q empty
                         * @param q the quaternion to move into this
                         * @return the reference of himself
                         */
                        Quaternion<T>& operator=(Quaternion<T> && q);

                    //## Shortcut Operator ##//
                        /**
                         * Multiply this by a quaternion k
                         * @param k the multiplication quaternion
                         * @return the reference of himself
                         */
                        Quaternion<T>& operator*=(Quaternion<T> const& k);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the quaternion resulting in the multiplication of this and q
                         * @param q the multiplication quaternion
                         * @return the newly computed quaternion
                         */
                        Quaternion<T> operator*(Quaternion<T> const& q) const;

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    #include "NRE_Quaternion.tpp"
