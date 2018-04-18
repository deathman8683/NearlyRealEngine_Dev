
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
             * @brief Renderer's Object : Manage environmental mapping, more advanced form of skybox, used in the PBR pipeline
             */
            class EnvironmentMap {
                private:
                    GL::SkyBox map;
                    GL::SkyBox irradianceMap;
                    GL::SkyBox prefilterMap;
                    GL::Texture2D brdfLUT;
                    GL::IBO buffer;
                    GL::VAO vao;

                public:
                    //## Constructor ##//
                        EnvironmentMap();
                        EnvironmentMap(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader, Shader const& BRDFShader);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                        ~EnvironmentMap();

                    //## Getter ##//
                        GL::SkyBox const& getMap() const;
                        GL::SkyBox const& getIrradianceMap() const;
                        GL::SkyBox const& getPrefilterMap() const;
                        GL::Texture2D const& getBRDFLUT() const;
                        GL::IBO const& getBuffer() const;
                        GL::VAO const& getVAO() const;

                    //## Setter ##//

                    //## Methods ##//
                        void allocate();
                        void fillBuffer();
                        void capture(std::string const& path, Shader const& captureShader, Shader const& irradianceShader, Shader const& prefilterShader, Shader const& BRDFShader);
                        void render(Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview);
                        void renderQuad();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLuint SIZE;
            };

        };
    };
