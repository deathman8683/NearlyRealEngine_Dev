
    /**
     * @file NRE_SSAOShader.hpp
     * @brief Declaration of Engine's Renderer's Object : SSAOShader
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
             * @class SSAOShader
             * @brief Renderer's Object : Manage the SSAO specific shader
             */
            class SSAOShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SSAOShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the SSAO shader to copy the content
                         */
                        SSAOShader(SSAOShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the SSAO shader to move
                         */
                        SSAOShader(SSAOShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * SSAOShader Deconstructor
                         */
                        ~SSAOShader();

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
                         * @param s the SSAO shader to copy into this
                         * @return the reference of himself
                         */
                        SSAOShader& operator=(SSAOShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the SSAO shader to move into this
                         * @return the reference of himself
                         */
                        SSAOShader& operator=(SSAOShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
