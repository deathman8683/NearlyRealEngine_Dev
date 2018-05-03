
    /**
     * @file NRE_EnvironmentMap.hpp
     * @brief Declaration of Engine's Renderer's Object : EnvironmentMap
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
    #include "../../GL_Wrapper/BufferObject/FBO/NRE_FBO.hpp"
    #include "../../GL_Wrapper/BufferObject/IBO/NRE_IBO.hpp"
    #include "../../GL_Wrapper/Buffer/VAO/NRE_VAO.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../Shader/NRE_Shader.hpp"

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
             * @class EnvironmentMap
             * @brief Renderer's Object : Manage environment mapping, more advanced form of skybox, used in the PBR pipeline
             */
            class EnvironmentMap {
                private:
                    GL::SkyBox map;             /**< The normal skybox */
                    GL::SkyBox irradianceMap;   /**< The irradiance map computed from the map */
                    GL::SkyBox prefilterMap;    /**< The prefiltered map computed from the map */
                    GL::Texture2D brdfLUT;      /**< The BRDF texture computed on fly */
                    GL::IBO buffer;             /**< The rendering buffer */
                    GL::VAO vao;                /**< The rendering VAO */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        EnvironmentMap();
                        /**
                         * Construct an environment map with a specific file, several shader for capture and computation
                         * @param path             the path to the main skybox
                         * @param captureShader    the shader used to capture the Cube Map faces
                         * @param irradianceShader the shader used to compute the irradiance map
                         * @param prefilterShader  the shader used to compute the prefiltered map
                         * @param BRDFShader       the shader used to computed the BRDF texture
                         */
                        EnvironmentMap(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader, Shader const& BRDFShader);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param map the environment map to copy
                         */
                        EnvironmentMap(EnvironmentMap const& map) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move map into this, leaving map empty
                         * @param buf the environment map to move
                         */
                        EnvironmentMap(EnvironmentMap && map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * EnvironmentMap Deconstructor
                         */
                        ~EnvironmentMap();

                    //## Getter ##//
                        /**
                         * Map getter
                         * @return the base skybox
                         */
                        GL::SkyBox const& getMap() const;
                        /**
                         * Irradiance map getter
                         * @return the irradiance map
                         */
                        GL::SkyBox const& getIrradianceMap() const;
                        /**
                         * Prefiltered map getter
                         * @return the prefiltered map
                         */
                        GL::SkyBox const& getPrefilterMap() const;
                        /**
                         * BRDF Texture getter
                         * @return the BRDF texture
                         */
                        GL::Texture2D const& getBRDFLUT() const;
                        /**
                         * Rendering Buffer getter
                         * @return the buffer used to render the map
                         */
                        GL::IBO const& getBuffer() const;
                        /**
                         * Rendering VAO getter
                         * @return the VAO used to render the map
                         */
                        GL::VAO const& getVAO() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Allocate all map storage and configure them
                         */
                        void allocate();
                        /**
                         * Fill the rendering buffer for later rendering
                         */
                        void fillBuffer();
                        /**
                         * Capture all map for later rendering
                         * @param path             the path to the main skybox
                         * @param captureShader    the shader used to capture the Cube Map faces
                         * @param irradianceShader the shader used to compute the irradiance map
                         * @param prefilterShader  the shader used to compute the prefiltered map
                         * @param BRDFShader       the shader used to computed the BRDF texture
                         */
                        void capture(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader, Shader const& BRDFShader);
                        /**
                         * Render the base skybox
                         * @param shader     the rendering shader
                         * @param projection the proection matrix
                         * @param modelview  the modelview matrix
                         */
                        void render(Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview);
                        /**
                         * Render a quad, used to capture CubeMap faces
                         */
                        void renderQuad();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param map the environment map to copy
                         */
                        EnvironmentMap& operator=(EnvironmentMap const& map) = delete;
                        /**
                         * Move assigment of map into this, leaving map empty
                         * @param map the environment map to move into this
                         * @return the reference of himself
                         */
                        EnvironmentMap& operator=(EnvironmentMap && map);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLuint SIZE; /**< The main Skybox size */
            };

        };
    };
