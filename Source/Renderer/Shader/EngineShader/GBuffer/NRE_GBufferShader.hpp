
    /**
     * @file NRE_GBufferShader.hpp
     * @brief Declaration of Engine's Renderer's Object : GBufferShader
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
             * @class GBufferShader
             * @brief Renderer's Object : Manage the GBuffer specific shader
             */
            class GBufferShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        GBufferShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the GBuffer shader to copy the content
                         */
                        GBufferShader(GBufferShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the GBuffer shader to move
                         */
                        GBufferShader(GBufferShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * GBufferShader Deconstructor
                         */
                        ~GBufferShader();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the shader's specific name path
                         */
                        std::string const getPath() const override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the GBuffer shader to copy into this
                         * @return the reference of himself
                         */
                        GBufferShader& operator=(GBufferShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the GBuffer shader to move into this
                         * @return the reference of himself
                         */
                        GBufferShader& operator=(GBufferShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
