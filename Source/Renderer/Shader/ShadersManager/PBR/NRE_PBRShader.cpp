
    #include "NRE_PBRShader.hpp"

    namespace NRE {
        namespace Renderer {

            GLuint PBRShader::MAX_LIGHTS = 10;

            PBRShader::PBRShader() {
                load();
                addUniformLocation("texDepth");
                addUniformLocation("texDiffuseUV");
                addUniformLocation("texNormal");
                addUniformLocation("irradianceMap");
                addUniformLocation("prefilterMap");
                addUniformLocation("brdfLUT");
                addUniformLocation("texMaterial");
                addUniformLocation("texRoughness");
                addUniformLocation("texMetallic");
                for (GLuint i = 0; i < MAX_LIGHTS; i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    addUniformLocation("lights[" + index.str() + "].position");
                    addUniformLocation("lights[" + index.str() + "].intensities");
                    addUniformLocation("lights[" + index.str() + "].direction");
                    addUniformLocation("lights[" + index.str() + "].angle");
                }
                addUniformLocation("cameraV");
                addUniformLocation("invModelview");
                addUniformLocation("invProjection");
                addUniformLocation("rotation");
                addUniformLocation("numLights");

                bind();
                    sendTextures();
                unbind();
            }

            PBRShader::PBRShader(PBRShader && s) : Shader::Shader(std::move(s)) {
            }

            PBRShader::~PBRShader() {
            }

            std::string const PBRShader::getPath() const {
                return "PBR";
            }

            void PBRShader::sendLigths() const {
                use1I("numLights", Light::LightsManager::getSize());

                for (unsigned int i = 0; i < Light::LightsManager::getSize(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    use4FV("lights[" + index.str() + "].position", 1, Light::LightsManager::getLight(i).getPosition().value());
                    use3FV("lights[" + index.str() + "].intensities", 1, Light::LightsManager::getLight(i).getIntensities().value());
                    use3FV("lights[" + index.str() + "].direction", 1, Light::LightsManager::getLight(i).getDirection().value());
                    use1FV("lights[" + index.str() + "].angle", 1, Light::LightsManager::getLight(i).getAngleValue());
                }
            }

            void PBRShader::sendTextures() const {
                use1I("texDepth", 0);
                use1I("texDiffuseUV", 1);
                use1I("texNormal", 2);
                use1I("irradianceMap", 3);
                use1I("prefilterMap", 4);
                use1I("brdfLUT", 5);
                use1I("texMaterial", 6);
                use1I("texRoughness", 7);
                use1I("texMetallic", 8);
            }

            void PBRShader::sendInvProjection(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("invProjection", 1, &m);
            }

            void PBRShader::sendInvModelview(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("invModelview", 1, &m);
            }

            void PBRShader::sendRotation(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("rotation", 1, &m);
            }

            void PBRShader::sendCamera(Camera::FixedCamera const& c) const {
                use3FV("cameraV", 1, c.getEye().value());
            }

            PBRShader& PBRShader::operator=(PBRShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
