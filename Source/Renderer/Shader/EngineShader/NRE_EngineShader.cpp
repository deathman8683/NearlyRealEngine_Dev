
    #include "NRE_EngineShader.hpp"

    namespace NRE {
        namespace Renderer {

            std::unordered_map<std::string, const Shader*>* EngineShader::programs = 0;

            const Shader* const& EngineShader::getShader(std::string const& name) {
                return programs->find(name)->second;
            }

            void EngineShader::init() {
                programs = new std::unordered_map<std::string, const Shader*>(8);
                (*programs)["BRDF"] = new BRDFShader();
                (*programs)["Capture"] = new CaptureShader();
                (*programs)["GBuffer"] = new GBufferShader();
                (*programs)["Irradiance"] = new IrradianceShader();
                (*programs)["PBR"] = new PBRShader();
                (*programs)["Prefilter"] = new PrefilterShader();
                (*programs)["SkyBox"] = new SkyBoxShader();
                (*programs)["SSAO"] = new SSAOShader();
            }

            void EngineShader::free() {
                for (const auto &it : *programs) {
                    delete it.second;
                }
                delete programs;
            }

        };
    };
