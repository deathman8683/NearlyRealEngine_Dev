
    /**
     * @file NRE_Frustum.hpp
     * @brief Declaration of Engine's Maths's Object : Frustum
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../Plane/NRE_Plane.hpp"
    #include "../../Physics/AABB/NRE_AABB.hpp"

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
             * @enum regroup constant for box's faces managing
             */
            enum BoxFace {
                TOP,        /**< The top face */
                BOTTOM,     /**< The bottom face */
                LEFT,       /**< The left face */
                RIGHT,      /**< The right face */
                NEAR,       /**< The near face */
                FAR,        /**< The far face */

                FACE_NUM    /**< The number of face in a box */
            };

            /**
             * @class Frustum
             * @brief Maths's Object : A view frustum used in camera
             */
            template <class T>
            class Frustum {
                protected:
                    Plane<T> *planes;    /**< The frustum' six planes */
                    Vector2D<T> near;   /**< The near size vector */
                    Vector2D<T> far;    /**< The far size vector */
                    Vector2D<T> dist;   /**< The dist size vector */
                    T fov;              /**< The frustum's fov */
                    T ratio;            /**< The frustum's ratio */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Frustum();
                        /**
                         * Construct a frustum with his fov, his ratio and the distance vector
                         * @param fov   the frustum's fov
                         * @param ratio the frustum's ratio
                         * @param dist  the frustum's distance
                         */
                        Frustum(T const& fov, T const& ratio, Vector2D<T> const& dist);

                    //## Copy-Constructor ##//
                        /**
                         * Copy f into this
                         * @param f the frustum to copy the content
                         */
                        Frustum(Frustum const& f);

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the frustum to move
                         */
                        Frustum(Frustum && f);

                    //## Convertor ##//
                        /**
                         * Convert a K-type frustum into a T-type frustum
                         * @param f the K-type frustum to convert
                         */
                        template <class K>
                        Frustum(Frustum<K> const& f);

                    //## Deconstructor ##//
                        /**
                         * Frustum Deconstructor
                         */
                        virtual ~Frustum();

                    //## Getter ##//
                        /**
                         * Return a specific plane
                         * @param  index the desired planes index
                         * @return       the reference of the plane
                         */
                        Plane<T> const& getPlane(unsigned int const& index) const;
                        /**
                         * Near getter
                         * @return the near value
                         */
                        Vector2D<T> const& getNear() const;
                        /**
                         * Far getter
                         * @return the far value
                         */
                        Vector2D<T> const& getFar() const;
                        /**
                         * Dist getter
                         * @return the dist value
                         */
                        Vector2D<T> const& getDist() const;
                        /**
                         * Fov getter
                         * @return the fov value
                         */
                        T const& getFov() const;
                        /**
                         * Ratio getter
                         * @return the ratio value
                         */
                        T const& getRatio() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Compute the near and far vector from the frustum members
                         */
                        void computeNearAndFar();
                        /**
                         * Test if a point is in the frustum
                         * @param  p the point to test
                         * @return   the test result
                         */
                        Physics::CollisionResult const pointCollision(Point3D<T> const& p) const;
                        /**
                         * Test if a sphere defined by the center p and it's radius is in the frustum
                         * @param  p      the sphere's center
                         * @param  radius the sphere's radiu
                         * @return        the test result
                         */
                        Physics::CollisionResult const sphereCollision(Point3D<T> const& p, T const& radius) const;
                        /**
                         * Test if an AABB is in the frustum
                         * @param  box the bounding box to test
                         * @return     the test result
                         */
                        Physics::CollisionResult const AABBCollision(Physics::AABB<T> const& box) const;
                        /**
                         * Perform a perspective projection on m
                         * @param m the matrix to transform
                         */
                        void computeProjectionMatrix(Matrix4x4<T> &m);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of f into this
                         * @param f the frustum to copy into this
                         * @return the reference of himself
                         */
                        Frustum<T>& operator=(Frustum<T> const& f);
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the frustum to move into this
                         * @return the reference of himself
                         */
                        Frustum<T>& operator=(Frustum<T> && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                    protected:
                        static NREfloat DEFAULT_FOV;    /**< default fov value */
                        static NREfloat DEFAULT_RATIO;  /**< default ratio value */
            };

            template <class T>
            NREfloat Frustum<T>::DEFAULT_FOV = 70.0;
            template <class T>
            NREfloat Frustum<T>::DEFAULT_RATIO = 800.0 / 600.0;

            /**
             * Outstream operation for frustum
             * @param stream the out stream to add the frustum f
             * @param f the frustum to add in the stream
             * @return the modified outstream
             */
            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Frustum<T> const& f) {
                stream << "TOP[" << f.getPlane(TOP) << "]" << std::endl;
                stream << "BOTTOM[" << f.getPlane(BOTTOM) << "]" << std::endl;
                stream << "RIGHT[" << f.getPlane(RIGHT) << "]" << std::endl;
                stream << "LEFT[" << f.getPlane(LEFT) << "]" << std::endl;
                stream << "NEAR[" << f.getPlane(NEAR) << "]" << std::endl;
                stream << "FAR[" << f.getPlane(FAR) << "]" << std::endl;
                stream << "(" << f.getNear() << "," << f.getFar() << "," << f.getDist() << "," << f.getFov() << "," << f.getRatio() << ")";
                return stream;
            }

        };
    };

    #include "NRE_Frustum.tpp"
