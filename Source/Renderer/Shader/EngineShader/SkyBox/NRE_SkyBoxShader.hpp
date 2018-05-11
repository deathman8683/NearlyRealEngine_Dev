
    /**
     * @file NRE_SkyBoxShader.hpp
     * @brief Declaration of Engine's Renderer's Object : SkyBoxShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../NRE_Shader.hpp"

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
             * @class SkyBoxShader
             * @brief Renderer's Object : Manage the skybox specific shader
             */
            class SkyBoxShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SkyBoxShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the skybox shader to copy the content
                         */
                        SkyBoxShader(SkyBoxShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the skybox shader to move
                         */
                        SkyBoxShader(SkyBoxShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * SkyBoxShader Deconstructor
                         */
                        ~SkyBoxShader();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the shader's specific name path
                         */
                        std::string const getPath() const override;
                        /**
                         * Send the MVP matrix to the shader
                         * @param m the MVP matrix
                         */
                        void sendMVP(Maths::Matrix4x4<NREfloat> const& m) const;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the skybox shader to copy into this
                         * @return the reference of himself
                         */
                        SkyBoxShader& operator=(SkyBoxShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the skybox shader to move into this
                         * @return the reference of himself
                         */
                        SkyBoxShader& operator=(SkyBoxShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
