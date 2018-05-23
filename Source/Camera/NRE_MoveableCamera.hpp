
    /**
     * @file NRE_MoveableCamera.hpp
     * @brief Declaration of Engine's Camera's Object : MoveableCamera
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Generic/NRE_Type.hpp"
    #include "FixedCamera/NRE_FixedCamera.hpp"
    #include "Input/NRE_Input.hpp"
    #include "../World/NRE_World.hpp"
    #include "../World/Voxel/VoxelPoint/NRE_VoxelPoint.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Camera
         * @brief Engine's Camera Module
         */
        namespace Camera {

            /**
             * @class MoveableCamera
             * @brief Camera's Object : An advanced camera linked to input system
             */
            class MoveableCamera : public FixedCamera, public Input {
                private:
                    NREfloat speed;
                    World::World *world;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        MoveableCamera() = delete;
                        /**
                         * Construct a moveable camera from all needed parameters for base class
                         * @param fov    the fixed camera's fov
                         * @param ratio  the fixed camera's ratio
                         * @param dist   the fixed camera's near and far distance
                         * @param eye    the fixed camera's position
                         * @param center the fixed camera's fixed point
                         * @param world  the camera's world
                         * @param speed  the camera's speed
                         */
                        MoveableCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                       Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, World::World* world, NREfloat const& speed = DEFAULT_SPEED);
                        /**
                         * Construct a moveable camera from base part
                         * @param camera the fixed camera
                         * @param in     the input system
                         * @param world  the camera's world
                         * @param speed  the camera's speed
                         */
                        MoveableCamera(FixedCamera const& camera, Input const& in, World::World* world, NREfloat const& speed);

                    //## Copy-Constructor ##//
                        /**
                         * Copy camera into this
                         * @param camera the moveable camera to copy the content
                         */
                        MoveableCamera(MoveableCamera const& camera);

                    //## Move-Constructor ##//
                        /**
                         * Move camera into this, leaving camera empty
                         * @param camera the moveable camera to move
                         */
                        MoveableCamera(MoveableCamera && camera);

                    //## Convertor ##//
                        /**
                         * Convert a not moveable camera into a moveable one, attaching an input system to it
                         * @param camera the camera to convert
                         */
                        MoveableCamera(FixedCamera const& camera);

                    //## Deconstructor ##//
                        /**
                         * MoveableCamera Deconstructor
                         */
                        ~MoveableCamera();

                    //## Getter ##//
                        /**
                         * Speed getter
                         * @return the camera's speed value
                         */
                        NREfloat const& getSpeed() const;

                    //## Setter ##//
                        /**
                         * Speed setter
                         * @param speed the new speed value
                         */
                        void setSpeed(NREfloat const& speed);

                    //## Methods ##//
                        /**
                         * Update the input system and compute new camera's value after
                         */
                        void update();
                        /**
                         * Bind key system to their command
                         */
                        void bindKey();
                        /**
                         * Move the camera forward
                         */
                        void moveFront();
                        /**
                         * Move the camera backward
                         */
                        void moveBack();
                        /**
                         * Move the camera downward
                         */
                        void moveDown();
                        /**
                         * Move the camera upward
                         */
                        void moveUp();
                        /**
                         * Move the camera to the left
                         */
                        void moveLeft();
                        /**
                         * Move the camera to the right
                         */
                        void moveRight();
                        /**
                         * Move the center of the fixed camera
                         */
                        void moveCenter();
                        /**
                         * Interact with the world
                         */
                        void interact();
                        /**
                         * Cast a ray to the first solid bloc in vicinity
                         * @return the Voxel point corresponding to the end of the ray
                         */
                        World::VoxelPoint const rayCast() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of camera into this
                         * @param camera the moveable camera to copy into this
                         * @return the reference of himself
                         */
                        MoveableCamera& operator=(MoveableCamera const& camera);
                        /**
                         * Move assigment of camera into this, leaving camera empty
                         * @param camera the moveable camera to move into this
                         * @return the reference of himself
                         */
                        MoveableCamera& operator=(MoveableCamera && camera);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_SPEED;  /**< The default camera's speed */
            };

        };
    };
