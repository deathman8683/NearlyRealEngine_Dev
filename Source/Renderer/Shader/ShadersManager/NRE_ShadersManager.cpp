
    #include "NRE_ShadersManager.hpp"

    namespace NRE {
        namespace Renderer {

            std::unordered_map<std::string, const Shader*>* ShadersManager::programs = 0;

            const Shader* const& ShadersManager::getShader(std::string const& name) {
                return programs->find(name)->second;
            }

            void ShadersManager::init() {
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

            void ShadersManager::sendProjection(Maths::Matrix4x4<NREfloat> const& m) {
                Maths::Matrix4x4<NREfloat> inv(m);
                inv.inverse();

                const PBRShader* pbr = static_cast<const PBRShader*> (getShader("PBR"));
                pbr->bind();
                    pbr->sendInvProjection(inv);
                pbr->unbind();

                const SSAOShader* ssao = static_cast<const SSAOShader*> (getShader("SSAO"));
                ssao->bind();
                    ssao->sendInvProjection(inv);
                    ssao->sendProjection(m);
                ssao->unbind();

                const GBufferShader* gBuffer = static_cast<const GBufferShader*> (getShader("GBuffer"));
                gBuffer->bind();
                    gBuffer->sendProjection(m);
                gBuffer->unbind();
            }

            void ShadersManager::sendKernel(SSAO const& ssao) {
                const SSAOShader* s = static_cast<const SSAOShader*> (getShader("SSAO"));
                s->bind();
                    s->sendKernel(ssao);
                s->unbind();
            }

            void ShadersManager::free() {
                for (const auto &it : *programs) {
                    delete it.second;
                }
                delete programs;
            }

        };
    };
