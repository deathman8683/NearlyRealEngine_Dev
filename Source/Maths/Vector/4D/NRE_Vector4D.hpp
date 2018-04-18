
    /**
     * @file NRE_Vector4D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector4D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../3D/NRE_Vector3D.hpp"

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

            template<class> class Point4D;

            /**
             * @class Vector4D
             * @brief Maths's Object : Homogeneous 3D Generic Vector
             */
            template <class T>
            class Vector4D : public Vector3D<T> {
                private:
                    T w;    /**< w coordinate */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Vector4D();
                        /**
                         * Construct a vector with passed values
                         * @param x new x value
                         * @param y new y value
                         * @param z new z value
                         * @param w new w value
                         */
                        Vector4D(T const& x, T const& y, T const& z, T const& w);
                        /**
                         * Construct a vector with an unique value for all coordinates
                         * @param value new x, y, z and w values
                         */
                        Vector4D(T const& value);
                        /**
                         * Construct a vector representing the translation between a to b
                         * @param a the vector start point
                         * @param b the vector end point
                         */
                        Vector4D(Point4D<T> const& a, Point4D<T> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * Copy u into this
                         * @param u the vector to copy the content
                         */
                        Vector4D(Vector4D const& u);

                    //## Move-Constructor ##//
                        /**
                         * Move u into this, leaving u empty
                         * @param u the vector to move
                         */
                        Vector4D(Vector4D && u);

                    //## Convertor ##//
                        /**
                         * Convert a K-type vector into a T-type vector
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Vector4D(Vector4D<K> const& u);
                        /**
                         * Convert a K-type point into a T-type vector
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Vector4D(Point4D<K> const& p);
                        /**
                         * Convert a base 3D vector into a 4D vector with a default w value
                         * @param u the 3D vector to convert
                         */
                        Vector4D(Vector3D<T> const& u);
                        /**
                         * Convert a base 3D vector into a 4D point with a passed w value
                         * @param u the 3D vector to convert
                         * @param w the new w value
                         */
                        Vector4D(Vector3D<T> const& u, T const& w);

                    //## Deconstructor ##//
                        /**
                         * Vector4D Deconstructor
                         */
                        ~Vector4D();

                    //## Getter ##//
                        /**
                         * W getter
                         * @return the w value
                         */
                        T const& getW() const;
                        /**
                         * W getter, syntax form for color vector
                         * @return the w value
                         */
                        T const& getA() const;

                    //## Setter ##//
                        /**
                         * W setter
                         * @param w the new value for w
                         */
                        template <class K>
                        void setW(K const& w);
                        /**
                         * W setter, syntax form for color vector
                         * @param a the new value for w
                         */
                        template <class K>
                        void setA(K const& a);
                        /**
                         * Set the values for x, y, z and w
                         * @param x the new value for x
                         * @param y the new value for y
                         * @param z the new value for z
                         * @param w the new value for w
                         */
                        template <class K, class L, class M, class N>
                        void setCoord(K const& x, L const& y, M const& z, N const& w);
                        /**
                         * Set the values for x, y, z and w with a base 3D vector
                         * @param u the base 3D vector for x, y and z values
                         * @param w the new value for w
                         */
                        template <class K, class L>
                        void setCoord(Vector3D<K> const& u, L const& w);
                        /**
                         * Set the values for x, y, z and w, syntax form for color vector
                         * @param r the new value for x
                         * @param g the new value for y
                         * @param b the new value for z
                         * @param a the new value for w
                         */
                        template <class K, class L, class M, class N>
                        void setIntensities(K const& r, L const& g, M const& b, N const& a);

                    //## Methods ##//
                        /**
                         * Compute the vector's norm
                         * @return the computed norm
                         */
                        NREfloat const norm() const;
                        /**
                         * Compute the squared vector's norm
                         * @return the computed squared norm
                         */
                        NREfloat const normSquared() const;
                        /**
                         * Normalize the vector
                         */
                        void normalize();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of base into this
                         * @param base the vector to copy into this
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator=(Vector4D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the vector to move into this
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator=(Vector4D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Add a translation vector to this
                         * @param u the translation vector to add
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator-=(Vector4D<T> const& u);
                        /**
                         * Subtract a translation vector to this
                         * @param u the translation vector to subtract
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator+=(Vector4D<T> const& u);
                        /**
                         * Multiply vector component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator*=(T const& k);
                        /**
                         * Divide vector component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Vector4D<T>& operator/=(T const& k);
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector the for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|=(Vector4D<T> const& u) const;

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the vector resulting in the addition of u into this
                         * @param u the translation vector to add
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator+(Vector4D<T> const& u) const;
                        /**
                         * Compute the vector resulting in the subtraction of u into this
                         * @param u the translation vector to subtract
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator-(Vector4D<T> const& u) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite vector of this
                         */
                        Vector4D<T> operator-() const;
                        /**
                         * Compute the vector resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator*(T const& k) const;
                        /**
                         * Compute the vector resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed vector
                         */
                        Vector4D<T> operator/(T const& k) const;
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|(Vector4D<T> const& u) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator==(Vector4D<K> const& u) const;
                        /**
                         * Difference test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator!=(Vector4D<K> const& u) const;
                        /**
                         * Inferior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<(Vector4D<T> const& u) const;
                        /**
                         * Superior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>(Vector4D<T> const& u) const;
                        /**
                         * Inferior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<=(Vector4D<T> const& u) const;
                        /**
                         * Superior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>=(Vector4D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_W;   /**< default z value */
            };

            template <class T>
            int Vector4D<T>::DEFAULT_W = 0;

            /**
             * Outstream operation for 4D vector
             * @param stream the out stream to add the vector u
             * @param u the vector to add in the stream
             * @return the modified outstream
             */
             template <class T>
             std::ostream& operator<<(std::ostream &stream, Vector4D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << "," << u.getW() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector4D.tpp"
