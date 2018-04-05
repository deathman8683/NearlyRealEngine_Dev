
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
                    GL::IBO buffer;
                    GL::VAO vao;

                public:
                    //## Constructor ##//
                    EnvironmentMap();
                    EnvironmentMap(std::string const& path, Shader const& captureShader, Shader const& irradianceShader);

                    //## Copy-Constructor ##//
                    EnvironmentMap(EnvironmentMap const& map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~EnvironmentMap();

                    //## Getter ##//
                    GL::SkyBox const& getMap() const;
                    GL::SkyBox const& getIrradienceMap() const;
                    GL::IBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;

                    //## Setter ##//
                    void setMap(GL::SkyBox const& map);
                    void setIrradience(GL::SkyBox const& map);
                    void setBuffer(GL::IBO const& buf);
                    void setVAO(GL::VAO const& vao);

                    //## Methods ##//
                    void allocate();
                    void fillBuffer();
                    void capture(std::string const& path, Shader const& captureShader, Shader const& irradianceShader);
                    void render(Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
