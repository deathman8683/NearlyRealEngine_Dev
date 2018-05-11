
    /**
     * @file NRE_EngineShader.hpp
     * @brief Declaration of Engine's Renderer's Object : EngineShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <unordered_map>
    #include "BRDF/NRE_BRDFShader.hpp"
    #include "Capture/NRE_CaptureShader.hpp"
    #include "GBuffer/NRE_GBufferShader.hpp"
    #include "Irradiance/NRE_IrradianceShader.hpp"
    #include "PBR/NRE_PBRShader.hpp"
    #include "Prefilter/NRE_PrefilterShader.hpp"
    #include "SkyBox/NRE_SkyBoxShader.hpp"
    #include "SSAO/NRE_SSAOShader.hpp"

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
             * @class EngineShader
             * @brief Renderer's Object : A singleton used to regroup all engine's specific shader
             */
            class EngineShader {
                public:
                    //## Getter ##//
                        /**
                         * Specific Shader getter
                         * @param  name the shader's name
                         * @return      the corresponding shader
                         */
                        static const Shader* const& getShader(std::string const& name);

                    //## Methods ##//
                        /**
                         * Allocate all engine's shader
                         */
                        static void init();
                        /**
                         * Free all engine's shader
                         */
                        static void free();
                        /**
                         * Send the projection matrix and it's inverse to all shader which need it
                         * @param m the projection matrix
                         */
                        static void sendProjection(Maths::Matrix4x4<NREfloat> const& m);
                        /**
                         * Send the SSAO's kernel to the corresponding shader
                         * @param ssao the SSAo to send the kernel
                         */
                        static void sendKernel(SSAO const& ssao);

                private:
                    static std::unordered_map<std::string, const Shader*>* programs;    /**< The map storing all shader by their name */
            };

        };
    };
