
    /**
     * @file NRE_AABB.hpp
     * @brief Declaration of Engine's Physics's Object : AABB
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Physics
         * @brief Engine's Physics Module
         */
        namespace Physics {

            /**
             * @enum regroup constant for collision's test signification
             */
            enum CollisionResult {
                OUTSIDE,    /**< The tested object isn't in collision */
                INTERSECT,  /**< The tested object is intersecting */
                INSIDE      /**< The tested object is in collision */
            };

            /**
             * @class AABB
             * @brief Physics's Object : Axis-Aligned Bounding Box, with center + half extent
             */
            template <class T>
            class AABB {
                private:
                    Maths::Point3D<T> center;       /**< The AABB center */
                    Maths::Vector3D<T> hExtent;     /**< The AABB half extent */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        AABB();
                        /**
                         * Construct an AABB with a center and his half extent
                         * @param p the AABB center
                         * @param u the AABB half extent
                         */
                        AABB(Maths::Point3D<T> const& p, Maths::Vector3D<T> const& u);
                        /**
                         * Construct an AABB from to extrem point
                         * @param p1 the bottom far left point
                         * @param p2 the top near right point
                         */
                        AABB(Maths::Point3D<T> const& p1, Maths::Point3D<T> const& p2);

                    //## Copy-Constructor ##//
                        /**
                         * Copy box into this
                         * @param box the AABB to copy the content
                         */
                        AABB(AABB const& box);

                    //## Move-Constructor ##//
                        /**
                         * Move box into this, leaving box empty
                         * @param box the AABB to move
                         */
                        AABB(AABB && box);

                    //## Convertor ##//
                        /**
                         * Convert a K-type AABB into a T-type AABB
                         * @param box the K-type AABB to convert
                         */
                        template <class K>
                        AABB(AABB<K> const& box);

                    //## Deconstructor ##//
                        /**
                         * AABB Deconstructor
                         */
                        ~AABB();

                    //## Getter ##//
                        /**
                         * Center getter
                         * @return the center value
                         */
                        Maths::Point3D<T> const& getCenter() const;
                        /**
                         * Half Extent getter
                         * @return the hExtent value
                         */
                        Maths::Vector3D<T> const& getHExtent() const;
                        /**
                         * Compute the Bottom Far Left point getter
                         * @return the computed point
                         */
                        Maths::Point3D<T> const getMin() const;
                        /**
                         * Compute the Top Near Right point getter
                         * @return the computed point
                         */
                        Maths::Point3D<T> const getMax() const;
                        /**
                         * Compute the positive point (coordinate) from min and max and a normal
                         * @param  n the normal to compute the positive point
                         * @return   the computed point
                         */
                        Maths::Point3D<T> const getPVertex(Maths::Vector3D<T> const& n) const;
                        /**
                         * Compute the negative point (coordinate) from min and max and a normal
                         * @param  n the normal to compute the negative point
                         * @return   the computed point
                         */
                        Maths::Point3D<T> const getNVertex(Maths::Vector3D<T> const& n) const;

                    //## Setter ##//
                        /**
                         * Center setter
                         * @param p the new value for center
                         */
                        template <class K>
                        void setCenter(Maths::Point3D<K> const& p);
                        /**
                         * Half Extent setter
                         * @param u the new value for half extent
                         */
                        template <class K>
                        void setHExtent(Maths::Vector3D<K> const& u);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of box into this
                         * @param box the AABB to copy into this
                         * @return the reference of himself
                         */
                        AABB<T>& operator=(AABB<T> const& box);
                        /**
                         * Move assigment of box into this, leaving box empty
                         * @param box the AABB to move into this
                         * @return the reference of himself
                         */
                        AABB<T>& operator=(AABB<T> && box);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for AABB
             * @param stream the out stream to add the AABB box
             * @param box the AABB to add in the stream
             * @return the modified outstream
             */
            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, AABB<T> const& box) {
                stream << "(" << box.getCenter() << "," << box.getHExtent() << ")";
                return stream;
            }

        };
    };

    #include "NRE_AABB.tpp"
