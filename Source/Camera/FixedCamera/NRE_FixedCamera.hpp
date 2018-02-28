
    /**
     * @file NRE_FixedCamera.hpp
     * @brief Declaration of Engine's Camera's Object : FixedCamera
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
         * @namespace Camera
         * @brief Engine's Camera Module
         */
        namespace Camera {

            /**
             * @class FixedCamera
             * @brief Camera's Object : A basic fixed camera
             */
            class FixedCamera {
                protected:
                    Maths::Point3D<NREfloat> eye;
                    Maths::Point3D<NREfloat> center;
                    Maths::Vector3D<NREfloat> up;
                    Maths::Vector3D<NREfloat> forward;
                    Maths::Vector3D<NREfloat> left;
                    Maths::Vector2D<NREfloat> angle;

                public:
                    //## Constructor ##//
                    FixedCamera();
                    FixedCamera(Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle, bool const& calculate = false);
                    FixedCamera(Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center, Maths::Vector2D<NREfloat> const& angle,
                                Maths::Vector3D<NREfloat> const& up, Maths::Vector3D<NREfloat> const& forward, Maths::Vector3D<NREfloat> const& left);

                    //## Copy-Constructor ##//
                    FixedCamera(FixedCamera const& camera);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~FixedCamera();

                    //## Getter ##//
                    Maths::Point3D<NREfloat> const& getEye() const;
                    Maths::Point3D<NREfloat> const& getCenter() const;
                    Maths::Vector3D<NREfloat> const& getUp() const;
                    Maths::Vector3D<NREfloat> const& getForward() const;
                    Maths::Vector3D<NREfloat> const& getLeft() const;
                    Maths::Vector2D<NREfloat> const& getAngle() const;

                    //## Setter ##//
                    void setEye(Maths::Point3D<NREfloat> const& p);
                    void setCenter(Maths::Point3D<NREfloat> const& p);
                    void setUp(Maths::Vector3D<NREfloat> const& u);
                    void setForward(Maths::Vector3D<NREfloat> const& u);
                    void setLeft(Maths::Vector3D<NREfloat> const& u);
                    void setAngle(Maths::Vector2D<NREfloat> const& u);

                    //## Methods ##//
                    void setView(Maths::Matrix4x4<NREfloat>& modelview) const;
                    void calculateVector();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat MAX_PHI;
                    static NREfloat MIN_PHI;
            };

            std::ostream& operator<<(std::ostream &stream, FixedCamera const& camera);

        };
    };
