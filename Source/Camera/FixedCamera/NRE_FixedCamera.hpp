
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
            class FixedCamera  : public Maths::Frustum<NREfloat> {
                protected:
                    Maths::Point3D<NREfloat> eye;       /**< The camera's position */
                    Maths::Point3D<NREfloat> center;    /**< The camera's fixed point */
                    Maths::Vector3D<NREfloat> up;       /**< The camera's up vector */
                    Maths::Vector3D<NREfloat> forward;  /**< The camera's forward vector */
                    Maths::Vector3D<NREfloat> left;     /**< The camera's left vector */
                    Maths::Vector2D<NREfloat> angle;    /**< The camera's angle, used to compute view vector and frustum */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FixedCamera();
                        /**
                         * Construct a fixed camera with different passed attributes
                         * @param fov    the camera's frustum's fov
                         * @param ratio  the camera's frustum's ratio
                         * @param dist   the camera's frustum's near and far distance
                         * @param eye    the camera's position
                         * @param center the camera's fixed point
                         */
                        FixedCamera(NREfloat const& fov, NREfloat const& ratio, Maths::Vector2D<NREfloat> const& dist,
                                    Maths::Point3D<NREfloat> const& eye, Maths::Point3D<NREfloat> const& center);

                    //## Copy-Constructor ##//
                        /**
                         * Copy camera into this
                         * @param camera the fixed camera to copy the content
                         */
                        FixedCamera(FixedCamera const& camera);

                    //## Move-Constructor ##//
                        /**
                         * Move camera into this, leaving camera empty
                         * @param camera the fixed camera to move
                         */
                        FixedCamera(FixedCamera && camera);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FixedCamera Deconstructor
                         */
                        virtual ~FixedCamera();

                    //## Getter ##//
                        /**
                         * Eye getter
                         * @return the camera's position value
                         */
                        Maths::Point3D<NREfloat> const& getEye() const;
                        /**
                         * Center getter
                         * @return the camera's fixed point value
                         */
                        Maths::Point3D<NREfloat> const& getCenter() const;
                        /**
                         * Up getter
                         * @return the camera's up vector
                         */
                        Maths::Vector3D<NREfloat> const& getUp() const;
                        /**
                         * Forward getter
                         * @return the camera's forward vector
                         */
                        Maths::Vector3D<NREfloat> const& getForward() const;
                        /**
                         * Left getter
                         * @return the camera's left vector
                         */
                        Maths::Vector3D<NREfloat> const& getLeft() const;
                        /**
                         * Angle getter
                         * @return the camera's angle vector
                         */
                        Maths::Vector2D<NREfloat> const& getAngle() const;

                    //## Setter ##//
                        /**
                         * Eye setter
                         * @param p the new camera's position value
                         */
                        void setEye(Maths::Point3D<NREfloat> const& p);
                        /**
                         * Center setter
                         * @param p the new camera's fixed point value
                         */
                        void setCenter(Maths::Point3D<NREfloat> const& p);
                        /**
                         * Up setter
                         * @param u the new camera's up vector
                         */
                        void setUp(Maths::Vector3D<NREfloat> const& u);
                        /**
                         * Forward setter
                         * @param u the new camera's forward vector
                         */
                        void setForward(Maths::Vector3D<NREfloat> const& u);
                        /**
                         * Left setter
                         * @param u the new camera's left vector
                         */
                        void setLeft(Maths::Vector3D<NREfloat> const& u);
                        /**
                         * Angle setter
                         * @param u the new camera's angle vector
                         */
                        void setAngle(Maths::Vector2D<NREfloat> const& u);

                    //## Methods ##//
                        /**
                         * Compute the new modelview matrix from camera's vector
                         * @param modelview the matrix to modify
                         */
                        void setView(Maths::Matrix4x4<NREfloat>& modelview) const;
                        /**
                         * Initialize angle from the position and fixed point value
                         */
                        void initAngle();
                        /**
                         * Compute angle, just test for phi to be in the min, max range
                         */
                        void computeAngle();
                        /**
                         * Compute the camera's vector from the camera's angle
                         */
                        void computeVector();
                        /**
                         * Compute the frustum planes from the camera's vector
                         */
                        void computePlane();
                        /**
                         * Create a wire frame frustum into passed buffer
                         * @param  vBuf the vertices buffer
                         * @param  cBuf the color buffer
                         * @param  nBuf the normal buffer
                         * @param  iBuf the index buffer
                         * @return      the number of index added in the index buffer
                         */
                        size_t getVertices(GLfloat* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of camera into this
                         * @param camera the fixed camera to copy into this
                         * @return the reference of himself
                         */
                        FixedCamera& operator=(FixedCamera const& camera);
                        /**
                         * Move assigment of camera into this, leaving camera empty
                         * @param camera the fixed camera to move into this
                         * @return the reference of himself
                         */
                        FixedCamera& operator=(FixedCamera && camera);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat MAX_PHI;    /**< Maximum Phi angle for the camera's angle */
                    static NREfloat MIN_PHI;    /**< Minimum Phi angle for the camera's angle */
            };

            /**
             * Outstream operation for FixedCamera
             * @param stream the out stream to add the fixed camera camera
             * @param camera the fixed camera to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, FixedCamera const& camera) {
                stream << "(" << camera.getEye() << "," << camera.getCenter() << "," << camera.getAngle() << ")" << std::endl;
                stream << "(" << camera.getForward() << "," << camera.getLeft() << "," << camera.getUp() << ")";
                return stream;
            }

        };
    };
