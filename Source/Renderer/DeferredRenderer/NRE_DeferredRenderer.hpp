
    /**
     * @file NRE_DeferredRenderer.hpp
     * @brief Declaration of Engine's Renderer's Object : DeferredRenderer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include "../../GL_Wrapper/BufferObject/FBO/NRE_FBO.hpp"
    #include "../../GL_Wrapper/Buffer/VAO/NRE_VAO.hpp"
    #include "../../GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "../../GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.hpp"
    #include "../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../../Lighting/NRE_Light.hpp"
    #include "../Shader/NRE_Shader.hpp"
    #include "../SSAO/NRE_SSAO.hpp"

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
             * @class DeferredRenderer
             * @brief Renderer's Object : Manage deferred renderding techniques using FBO
             */
            class DeferredRenderer {
                private:
                    GL::FBO gBuffer;
                    GL::FBO shadowMap;
                    SSAO ssao;
                    GL::VBO buffer;
                    GL::VAO vao;

                public:
                    //## Constructor ##//
                    DeferredRenderer();
                    DeferredRenderer(Maths::Vector2D<GLushort> const& size);

                    //## Copy-Constructor ##//
                    DeferredRenderer(DeferredRenderer const& renderer);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~DeferredRenderer();

                    //## Getter ##//
                    GL::FBO const& getFrameBuffer() const;
                    GL::FBO const& getShadowMap() const;
                    SSAO const& getSSAO() const;
                    GL::VBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;

                    //## Setter ##//
                    void setFrameBuffer(GL::FBO const& buffer);
                    void setShadowMap(GL::FBO const& buffer);
                    void setSSAO(SSAO const& ssao);
                    void setBuffer(GL::VBO const& buffer);
                    void setVAO(GL::VAO const& vao);

                    //## Methods ##//
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &invModelview, Maths::Matrix4x4<NREfloat> &invProjection, Maths::Matrix4x4<NREfloat> &lightModelview, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light, GL::SkyBox const& skyBox);
                    void startGBufferPass();
                    void endGBufferPass();
                    void SSAOPass(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &invProjection);
                    void startShadowPass();
                    void endShadowPass();
                    void fillBuffer();

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
