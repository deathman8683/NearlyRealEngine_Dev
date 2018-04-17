
    /**
     * @file NRE_Point2D.hpp
     * @brief Declaration of Engine's Maths's Object : Point2D
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

            template<class> class Vector2D;

            /**
             * @class Point2D
             * @brief Maths's Object : Cartesian 2D Generic Point
             */
            template <class T>
            class Point2D {
                protected:
                    T x;    /**< x coordinates */
                    T y;    /**< y coordinates */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Point2D();
                        /**
                         * Construct a point with passed value
                         * @param x new x value
                         * @param y new y value
                         */
                        Point2D(T const& x, T const& y);
                        /**
                         * Construct a point with a unique value for all coordinates
                         * @param value new x and y values
                         */
                        Point2D(T const& value);
                        /**
                         * Construct a point with the translation on another on
                         * @param p the base point
                         * @param u the translation vector applied to p
                         */
                        Point2D(Point2D<T> const& p, Vector2D<T> const& u);

                    //## Copy-Constructor ##//
                        /**
                         * Copy p into this
                         * @param p the point to copy the content
                         */
                        Point2D(Point2D const& p);

                    //## Move-Constructor ##//
                        /**
                         * Move p into this, leaving p empty
                         * @param p the point to move
                         */
                        Point2D(Point2D && p);

                    //## Convertor ##//
                        /**
                         * Convert a K-type point into a T-type point
                         * @param p the K-type point to convert
                         */
                        template <class K>
                        Point2D(Point2D<K> const& p);
                        /**
                         * Convert a K-type vector into a T-type point
                         * @param u the K-type vector to convert
                         */
                        template <class K>
                        Point2D(Vector2D<K> const& u);

                    //## Deconstructor ##//
                        /**
                         * Point2D Deconstructor
                         */
                        ~Point2D();

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
                         * Set the values for both x and y
                         * @param x the new value for x
                         * @param y the new value for y
                         */
                        template <class K, class L>
                        void setCoord(K const& x, L const& y);

                    //## Methods ##//
                        /**
                         * Compute the distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the distance with this
                         * @return the computed distance
                         */
                        NREfloat const distance(Point2D<T> const& p = Point2D()) const;
                        /**
                         * Compute the squared distance between this and p, if p is not specified the distance is computed with the origin
                         * @param  p the point to measure the square distance with this
                         * @return the computed squared distance
                         */
                        NREfloat const distanceSquared(Point2D<T> const& p = Point2D()) const;
                        /**
                         * Return a pointer to the start of the point's data
                         * @return the point's data's pointer
                         */
                        const T* const value() const;

                    //## Access Operator ##//
                        /**
                         * Return a reference on the index's object of the point, don't check the index range
                         * @param index the point's object index
                         * @return a reference on the index's object of the point
                         */
                        T& operator[](unsigned int const& index);
                        /**
                         * Return a const-reference on the index's object of the point, don't check the index range
                         * @param index the point's object index
                         * @return a const-reference on the index's object of the point
                         */
                        const T& operator[](unsigned int const& index) const;

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of base into this
                         * @param base the point to copy into this
                         * @return the reference of himself
                         */
                        Point2D<T>& operator=(Point2D<T> const& base);
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the point to move into this
                         * @return the reference of himself
                         */
                        Point2D<T>& operator=(Point2D<T> && base);

                    //## Shortcut Operator ##//
                        /**
                         * Perform a translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point2D<T>& operator+=(Vector2D<T> const& u);
                        /**
                         * Perform an opposite translation of this by u
                         * @param u the translation vector
                         * @return the reference of himself
                         */
                        Point2D<T>& operator-=(Vector2D<T> const& u);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point2D<T> operator+(Vector2D<T> const& u) const;
                        /**
                         * Compute the opposite translated version of this by u
                         * @param u the translation vector
                         * @return the newly translated point
                         */
                        Point2D<T> operator-(Vector2D<T> const& u) const;
                        /**
                         * Compute the vector measure the translation needed to go from this to p
                         * @param p the second point to compute the vector
                         * @return the newly computed vector
                         */
                        Vector2D<T> operator-(Point2D<T> const& p) const;
                        /**
                         * Compute the opposite version of this
                         * @return the newly opposite point
                         */
                        Point2D<T> operator-() const;

                    //## Comparison Operator ##//
                        /**
                         * Equality test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator==(Point2D<K> const& p) const;
                        /**
                         * Difference test between this and p
                         * @param p the point to test with this
                         */
                        template <class K>
                        bool const operator!=(Point2D<K> const& p) const;
                        /**
                         * Inferior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<(Point2D<T> const& p) const;
                        /**
                         * Superior test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>(Point2D<T> const& p) const;
                        /**
                         * Inferior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator<=(Point2D<T> const& p) const;
                        /**
                         * Superior or Equal test between this and p
                         * @param p the point to test with this
                         */
                        bool const operator>=(Point2D<T> const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//;

                protected:
                    static int DEFAULT_X;  /**< default x value */
                    static int DEFAULT_Y;  /**< default y value */
            };

            template <class T>
            int Point2D<T>::DEFAULT_X = 0.;
            template <class T>
            int Point2D<T>::DEFAULT_Y = 0.;

            /**
             * Outstream operation for 2D point
             * @param stream the out stream to add the point p
             * @param p the point to add in the stream
             * @return the modified outstream
             */
            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Point2D<T> const& p) {
                stream << "(" << p.getX() << "," << p.getY() << ")";
                return stream;
            }

        };
    };

    namespace std {
        template <>
        class hash<NRE::Maths::Point2D<GLint>> {
            public:
                size_t operator()(NRE::Maths::Point2D<GLint> const& p) const
                {
                    size_t h1 = p.getX();
                    size_t h2 = p.getY();

                    size_t hV = h2 * 100'000'000 + h1;
                    return hV;
                }
        };
    };

    #include "NRE_Point2D.tpp"
