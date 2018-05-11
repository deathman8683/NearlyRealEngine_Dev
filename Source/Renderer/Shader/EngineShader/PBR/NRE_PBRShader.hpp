
    /**
     * @file NRE_PBRShader.hpp
     * @brief Declaration of Engine's Renderer's Object : PBRShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include "../../NRE_Shader.hpp"
    #include "../../../../Light/NRE_Light.hpp"
    #include "../../../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../../../../World/Voxel/Type/VoxelTypes/NRE_VoxelTypes.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Renderer
         * @brief Engine's Renderer Module
         */
        namespace Renderer {

            /**
             * @class PBRShader
             * @brief Renderer's Object : Manage the pbr specific shader
             */
            class PBRShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        PBRShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the pbr shader to copy the content
                         */
                        PBRShader(PBRShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the pbr shader to move
                         */
                        PBRShader(PBRShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * PBRShader Deconstructor
                         */
                        ~PBRShader();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the shader's specific name path
                         */
                        std::string const getPath() const override;

                    //## Setter ##//

                    //## Methods ##//
                        void sendMaterials() const;
                        void sendLigths(std::vector<Light::Light*> const& lights) const;
                        void sendTextures() const;
                        void sendInvProjection(Maths::Matrix4x4<NREfloat> const& m) const;
                        void sendInvModelview(Maths::Matrix4x4<NREfloat> const& m) const;
                        void sendRotation(Maths::Matrix4x4<NREfloat> const& m) const;
                        void sendCamera(Camera::FixedCamera const& c) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the pbr shader to copy into this
                         * @return the reference of himself
                         */
                        PBRShader& operator=(PBRShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the pbr shader to move into this
                         * @return the reference of himself
                         */
                        PBRShader& operator=(PBRShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLuint MAX_LIGHTS;
            };

        };
    };
