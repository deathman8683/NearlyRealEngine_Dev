
    /**
     * @file NRE_VertexShader.hpp
     * @brief Declaration of Engine's Renderer's Object : VertexShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ShaderBase.hpp"
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
             * @class VertexShader
             * @brief Renderer's Object : Manage VertexShader transfer and compiling
             */
            class VertexShader : public ShaderBase {
                private:

                public:
                    //## Constructor ##//
                    VertexShader();
                    VertexShader(std::string const& path);

                    //## Copy-Constructor ##//
                    VertexShader(VertexShader const& s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VertexShader();

                    //## Getter ##//
                    GLenum const getType() const override;

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
