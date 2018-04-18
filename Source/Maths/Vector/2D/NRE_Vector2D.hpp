
    /**
     * @file NRE_Vector2D.hpp
     * @brief Declaration of Engine's Maths's Object : Vector2D
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

            template<class> class Point2D;

            /**
             * @class Vector2D
             * @brief Maths's Object : Cartesian 2D Generic Vector
             */
            template <class T>
            class Vector2D {
                protected:
                    T x;    /**< x coordinates */
                    T y;    /**< y coordinates */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Vector2D();
                        /**
                         * Construct a vector with passed values
                         * @param x new x value
                         * @param y new y value
                         */
                        Vector2D(T const& x, T const& y);
                        /**
                         * Construct a vector with an unique value for all coordinates
                         * @param value new x and y values
                         */
                        Vector2D(T const& value);
                        /**
                         * Construct a vector representing the translation between a to b
                         * @param a the vector start point
                         * @param b the vector end point
                         */
                        Vector2D(Point2D<T> const& a, Point2D<T> const& b);

                    //## Copy-Constructor ##//
                        /**
                         * Copy u into this
                         * @param u the vector to copy the content
                         */
                        Vector2D(Vector2D const& u);

                    //## Move-Constructor ##//
                        /**
                         * Move u into this, leaving u empty
                         * @param u the vector to move
                         */
                        Vector2D(Vector2D && u);

                    //## Convertor ##//
                        /**
                         * Convert a K-type vector into a T-type vector
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Vector2D(Vector2D<K> const& u);
                        /**
                         * Convert a K-type point into a T-type vector
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Vector2D(Point2D<K> const& p);

                    //## Deconstructor ##//
                        /**
                         * Vector2D Deconstructor
                         */
                        ~Vector2D();

                    //## Getter ##//
                        /**
                         * X getter
                         * @return the x value
                         */
                        T const& getX() const;
                        /**
                         * Y getter
                         * @return the y value
                         */
                        T const& getY() const;
                        /**
                         * X getter, syntax form for size vector
                         * @return the x value
                         */
                        T const& getW() const;
                        /**
                         * Y getter, syntax form for size vector
                         * @return the y value
                         */
                        T const& getH() const;

                    //## Setter ##//
                        /**
                         * X setter
                         * @param x the new value for x
                         */
                        template <class K>
                        void setX(K const& x);
                        /**
                         * Y setter
                         * @param y the new value for y
                         */
                        template <class K>
                        void setY(K const& y);
                        /**
                         * X setter, syntax form for size vector
                         * @param w the new value for x
                         */
                        template <class K>
                        void setW(K const& w);
                        /**
                         * Y setter, syntax form for size vector
                         * @param h the new value for y
                         */
                        template <class K>
                        void setH(K const& h);
                        /**
                         * Set the values for both x and y
                         * @param x the new value for x
                         * @param y the new value for y
                         */
                        template <class K, class L>
                        void setCoord(K const& x, L const& y);
                        /**
                         * Set the values for both x and y, syntax form for size vector
                         * @param w the new value for x
                         * @param h the new value for y
                         */
                        template <class K, class L>
                        void setSize(K const& w, L const& h);

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
                        /**
                         * Return a pointer to the start of the vector's data
                         * @return the vector's data's pointer
                         */
                        const T* const value() const;

                    //## Access Operator ##//
                        /**
                         * Return a reference on the index's object of the vector, don't check the index range
                         * @param index the vector's object index
                         * @return a reference on the index's object of the vector
                         */
                        T& operator[](unsigned int const& index);
                        /**
                         * Return a const-reference on the index's object of the vector, don't check the index range
                         * @param index the vector's object index
                         * @return a const-reference on the index's object of the vector
                         */
                        const T& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of base into this
                         * @param base the vector to copy into this
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator=(Vector2D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the vector to move into this
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator=(Vector2D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Add a translation vector to this
                         * @param u the translation vector to add
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator+=(Vector2D<T> const& u);
                        /**
                         * Substract a translation vector to this
                         * @param u the translation vector to substract
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator-=(Vector2D<T> const& u);
                        /**
                         * Multiply vector component by k
                         * @param k the multiplication factor
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator*=(T const& k);
                        /**
                         * Divide vector component by k
                         * @param k the division factor
                         * @return the reference of himself
                         */
                        Vector2D<T>& operator/=(T const& k);
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector the for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|=(Vector2D<T> const& u) const;

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the vector resulting in the addition of u into this
                         * @param u the translation vector to add
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator+(Vector2D<T> const& u) const;
                        /**
                         * Compute the vector resulting in the subtraction of u into this
                         * @param u the translation vector to substract
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator-(Vector2D<T> const& u) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite vector of this
                         */
                        Vector2D<T> operator-() const;
                        /**
                         * Compute the vector resulting in the multiplication of this by k
                         * @param k the multiplication factor
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator*(T const& k) const;
                        /**
                         * Compute the vector resulting in the division of this by k
                         * @param k the division factor
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator/(T const& k) const;
                        /**
                         * Compute the scalar product between this and u
                         * @param u the second vector for the scalar product
                         * @return the computed scalar product
                         */
                        NREfloat const operator|(Vector2D<T> const& u) const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator==(Vector2D<K> const& u) const;
                        /**
                         * Difference test between this and u
                         * @param u the vector to test with this
                         */
                        template <class K>
                        bool const operator!=(Vector2D<K> const& u) const;
                        /**
                         * Inferior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<(Vector2D<T> const& u) const;
                        /**
                         * Superior test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>(Vector2D<T> const& u) const;
                        /**
                         * Inferior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator<=(Vector2D<T> const& u) const;
                        /**
                         * Superior or Equal test between this and u
                         * @param u the vector to test with this
                         */
                        bool const operator>=(Vector2D<T> const& u) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//


                protected:
                    static int DEFAULT_X;  /**< default x value */
                    static int DEFAULT_Y;  /**< default y value */
            };

            template <class T>
            int Vector2D<T>::DEFAULT_X = 0;
            template <class T>
            int Vector2D<T>::DEFAULT_Y = 0;

            /**
             * Outstream operation for 2D vector
             * @param stream the out stream to add the vector u
             * @param u the vector to add in the stream
             * @return the modified outstream
             */
             template <class T>
             inline std::ostream& operator<<(std::ostream &stream, Vector2D<T> const& u) {
                 stream << "(" << u.getX() << "," << u.getY() << ")";
                 return stream;
             }

        };
    };

    #include "NRE_Vector2D.tpp"
