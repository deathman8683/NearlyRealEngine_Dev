
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

                public:
                    //## Constructor ##//
                    MoveableCamera();
                    MoveableCamera(std::string const& kbPath, std::string const& mPath, NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                   Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, NREfloat const& speed = DEFAULT_SPEED);
                    MoveableCamera(FixedCamera const& camera, Input const& in, NREfloat const& speed);

                    //## Copy-Constructor ##//
                    MoveableCamera(MoveableCamera const& camera);

                    //## Convertor ##//
                    MoveableCamera(FixedCamera const& camera);

                    //## Deconstructor ##//
                    ~MoveableCamera();

                    //## Getter ##//
                    NREfloat const& getSpeed() const;

                    //## Setter ##//
                    void setSpeed(NREfloat const& speed);

                    //## Methods ##//
                    void update();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_SPEED;
            };

        };
    };
