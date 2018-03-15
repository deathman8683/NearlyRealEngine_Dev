
    /**
     * @file NRE_DeferredRenderer.hpp
     * @brief Declaration of Engine's Renderer's Object : DeferredRenderer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../GL_Wrapper/BufferObject/FBO/NRE_FBO.hpp"
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

                public:
                    //## Constructor ##//

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

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
