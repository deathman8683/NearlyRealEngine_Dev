
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
    #include "../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../../Lighting/NRE_Light.hpp"
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
             * @class DeferredRenderer
             * @brief Renderer's Object : Manage deferred renderding techniques using FBO
             */
            class DeferredRenderer {
                private:
                    GL::FBO gBuffer;
                    Maths::Matrix4x4<NREfloat> modelview;
                    Maths::Matrix4x4<NREfloat> projection;
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
                    Maths::Matrix4x4<NREfloat> const& getModelview() const;
                    Maths::Matrix4x4<NREfloat> const& getProjection() const;
                    GL::VBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;

                    //## Setter ##//
                    void setFrameBuffer(GL::FBO const& buffer);
                    void setModelview(Maths::Matrix4x4<NREfloat> const& mat);
                    void setProjection(Maths::Matrix4x4<NREfloat> const& mat);
                    void setBuffer(GL::VBO const& buffer);
                    void setVAO(GL::VAO const& vao);

                    //## Methods ##//
                    void render(Renderer::Shader const& shader, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light);
                    void startFBO();
                    void endFBO();
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
