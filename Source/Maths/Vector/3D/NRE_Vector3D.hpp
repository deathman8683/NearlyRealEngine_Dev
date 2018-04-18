
    /**
     * @file NRE_Vector3D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../2D/NRE_Vector2D.hpp"

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

            template<class> class Point3D;
            template<class> class Vector4D;

            /**
             * @class Vector3D
             * @brief Maths's Object : Cartesian 3D Generic Vector
             */
            template <class T>
            class Vector3D : public Vector2D<T> {
                protected:
                    T z;    /**< z coordinate */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Vector3D();
                        /**
                         * Construct a vector with passed values
                         * @param x new x value
                         * @param y new y value
                         * @param z new z value
                         */
                        Vector3D(T const& x, T const& y, T const& z);
                        /**
                         * Construct a vector with an unique value for all coordinates
                         * @param value new x, y and z values
                         */
                        Vector3D(T const& value);
                        /**
                         * Construct a vector representing the translation between a to b
                         * @param a the vector start point
                         * @param b the vector end point
                         */
                        Vector3D(Point3D<T> const& a, Point3D<T> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * Copy u into this
                         * @param u the vector to copy the content
                         */
                        Vector3D(Vector3D const& u);

                    //## Move-Constructor ##//
                        /**
                         * Move u into this, leaving u empty
                         * @param u the vector to move
                         */
                        Vector3D(Vector3D && u);

                    //## Convertor ##//
                        /**
                         * Convert a K-type vector into a T-type vector
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Vector3D(Vector3D<K> const& u);
                        /**
                         * Convert a K-type point into a T-type vector
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Vector3D(Point3D<K> const& p);
                        /**
                         * Convert a base 2D vector into a 3D vector with a default z value
                         * @param u the 2D vector to convert
                         */
                        Vector3D(Vector2D<T> const& u);
                        /**
                         * Convert a base 2D vector into a 3D point with a passed z value
                         * @param u the 2D vector to convert
                         * @param z the new z value
                         */
                        Vector3D(Vector2D<T> const& u, T const& z);

                    //## Deconstructor ##//
                        /**
                         * Vector3D Deconstructor
                         */
                        ~Vector3D();

                    //## Getter ##//
                        /**
                         * Z getter
                         * @return the z value
                         */
                        T const& getZ() const;
                        /**
                         * X getter, syntax form for color vector
                         * @return the x value
                         */
                        T const& getR() const;
                        /**
                         * Y getter, syntax form for color vector
                         * @return the y value
                         */
                        T const& getG() const;
                        /**
                         * Z getter, syntax form for color vector
                         * @return the z value
                         */
                        T const& getB() const;

                    //## Setter ##//
                        /**
                         * Z setter
                         * @param z the new value for z
                         */
                        template <class K>
                        void setZ(K const& z);
                        /**
                         * X setter, syntax form for color vector
                         * @param r the new value for x
                         */
                        template <class K>
                        void setR(K const& r);
                        /**
                         * Y setter, syntax form for color vector
                         * @param g the new value for y
                         */
                        template <class K>
                        void setG(K const& g);
                        /**
                         * Z setter, syntax form for color vector
                         * @param b the new value for z
                         */
                        template <class K>
                        void setB(K const& b);
                        /**
                         * Set the values for x, y and z
                         * @param x the new value for x
                         * @param y the new value for y
                         * @param z the new value for z
                         */
                        template <class K, class L, class M>
                        void setCoord(K const& x, L const& y, M const& z);
                        /**
                         * Set the values for x, y and z with a base 2D vector
                         * @param u the base 2D vector for x and y values
                         * @param z the new value for z
                         */
                        template <class K, class L>
                        void setCoord(Vector2D<K> const& u, L const& z);
                        /**
                         * Set the values for x, y and z, syntax form for color vector
                         * @param r the new value for x
                         * @param g the new value for y
                         * @param b the new value for z
                         */
                        template <class K, class L, class M>
                        void setIntensities(K const& r, L const& g, M const& b);

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
                        Vector3D<T>& operator=(Vector3D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the vector to move into this
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator=(Vector3D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Add a translation vector to this
                         * @param u the translation vector to add
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator+=(Vector3D<T> const& u);
                        /**
                         * Substract a translation vector to this
                         * @param u the translation vector to substract
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator-=(Vector3D<T> const& u);
                        /**
                         * Multiply vector component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator*=(T const& k);
                        /**
                         * Divide vector component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator/=(T const& k);
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector the for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|=(Vector3D<T> const& u) const;
                        /**
                         * Replace this by the product between this and u
                         * @param u the second vector for the vectorial product
                         * @return the reference of himself
                         */
                        Vector3D<T>& operator^=(Vector3D<T> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the vector resulting in the addition of u into this
                         * @param u the translation vector to add
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator+(Vector3D<T> const& u) const;
                        /**
                         * Compute the vector resulting in the subtraction of u into this
                         * @param u the translation vector to substract
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator-(Vector3D<T> const& u) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite vector of this
                         */
                        Vector3D<T> operator-() const;
                        /**
                         * Compute the vector resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator*(T const& k) const;
                        /**
                         * Compute the vector resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed vector
                         */
                        Vector3D<T> operator/(T const& k) const;
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|(Vector3D<T> const& u) const;
                        /**
                         * Compute the vector resulting in the vectorial product of this and u
                         * @param u the second vector for the vectorial product
                         */
                        Vector3D<T> operator^(Vector3D<T> const& u) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator==(Vector3D<K> const& u) const;
                        /**
                         * Difference test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator!=(Vector3D<K> const& u) const;
                        /**
                         * Inferior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<(Vector3D<T> const& u) const;
                        /**
                         * Superior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>(Vector3D<T> const& u) const;
                        /**
                         * Inferior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<=(Vector3D<T> const& u) const;
                        /**
                         * Superior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>=(Vector3D<T> const& u) const;

                    //## BitWise Operator ##//


                    //## Shift Operator ##//

                protected:
                    static int DEFAULT_Z;   /**< default z value */
            };

            template <class T>
            int Vector3D<T>::DEFAULT_Z = 0;

            /**
             * Outstream operation for 3D vector
             * @param stream the out stream to add the vector u
             * @param u the vector to add in the stream
             * @return the modified outstream
             */
             template <class T>
             std::ostream& operator<<(std::ostream &stream, Vector3D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << "," << u.getZ() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector3D.tpp"
