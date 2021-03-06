
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
                        /**
                         * Default Constructor
                         */
                        VertexShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the vertex shader to copy
                         */
                        VertexShader(VertexShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the vertex shader to move
                         */
                        VertexShader(VertexShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VertexShader Deconstructor
                         */
                        ~VertexShader();

                    //## Getter ##//
                        /**
                         * Type getter
                         * @return return the shader program type, used to differentiate derived shader
                         */
                        GLenum const getType() const override;
                        /**
                         * Extension getter
                         * @return the shader program extension, used to compile derived shader
                         */
                        std::string const getExt() const override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param s the vertex shader to copy
                         */
                        VertexShader& operator=(VertexShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the vertex shader to move into this
                         * @return the reference of himself
                         */
                        VertexShader& operator=(VertexShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
