
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

            enum BoxFace {
                TOP,
                BOTTOM,
                LEFT,
                RIGHT,
                NEAR,
                FAR,

                FACE_NUM
            };

            /**
             * @class Frustum
             * @brief Maths's Object : A view frustum used in camera
             */
            template <class T>
            class Frustum {
                protected:
                    Plane<T> *plane;
                    Vector2D<T> near;
                    Vector2D<T> far;
                    Vector2D<T> dist;
                    T fov;
                    T ratio;

                public:
                    //## Constructor ##//
                    Frustum();
                    template <class K, class L, class M>
                    Frustum(K const& fov, L const& ratio, Vector2D<M> const& dist);

                    //## Copy-Constructor ##//
                    Frustum(Frustum const& f);

                    //## Convertor ##//
                    template <class K>
                    Frustum(Frustum<K> const& f);

                    //## Deconstructor ##//
                    virtual ~Frustum();

                    //## Getter ##//
                    Plane<T>* const& getPlanes() const;
                    Plane<T> const& getPlane(unsigned int const& index) const;
                    Vector2D<T> const& getNear() const;
                    Vector2D<T> const& getFar() const;
                    Vector2D<T> const& getDist() const;
                    T const& getFov() const;
                    T const& getRatio() const;

                    //## Setter ##//
                    void setPlanes(Plane<T>* const& p);
                    template <class K>
                    void setPlane(Plane<K> const& p, unsigned int const& index);
                    template <class K>
                    void setNear(Vector2D<K> const& size);
                    template <class K>
                    void setFar(Vector2D<K> const& size);
                    template <class K>
                    void setDist(Vector2D<K> const& size);
                    template <class K>
                    void setFov(K const& f);
                    template <class K>
                    void setRatio(K const& r);

                    //## Methods ##//
                    void computeNearAndFar();
                    template <class K>
                    Physics::CollisionResult const& pointCollision(Point3D<K> const& p) const;
                    template <class K, class L>
                    Physics::CollisionResult const& sphereCollision(Point3D<K> const& p, L const& radius);
                    template <class K>
                    void computeProjectionMatrix(Matrix4x4<K> &m);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                    protected:
                    static NREfloat DEFAULT_FOV;
                    static NREfloat DEFAULT_RATIO;
            };

            template <class T>
            NREfloat Frustum<T>::DEFAULT_FOV = 70.0;
            template <class T>
            NREfloat Frustum<T>::DEFAULT_RATIO = 800.0 / 600.0;

        };
    };

    #include "NRE_Frustum.tpp"
