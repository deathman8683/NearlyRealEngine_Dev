
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
                for (GLuint i = 0; i < MAX_LIGHTS; i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    addUniformLocation("lights[" + index.str() + "].position");
                    addUniformLocation("lights[" + index.str() + "].intensities");
                    addUniformLocation("lights[" + index.str() + "].direction");
                    addUniformLocation("lights[" + index.str() + "].angle");
                }
                for (unsigned int i = 0; i < MaterialManager::getSize(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    addUniformLocation("materials[" + index.str() + "].albedo");
                    addUniformLocation("materials[" + index.str() + "].metallic");
                    addUniformLocation("materials[" + index.str() + "].roughness");
                }
                addUniformLocation("cameraV");
                addUniformLocation("invModelview");
                addUniformLocation("invProjection");
                addUniformLocation("rotation");
                addUniformLocation("numLights");

                bind();
                    sendMaterials();
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

            void PBRShader::sendMaterials() const {
                for (unsigned int i = 0; i < MaterialManager::getSize(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    use3FV("materials[" + index.str() + "].albedo", 1, MaterialManager::getMaterial(i).getAlbedo().value());
                    use1FV("materials[" + index.str() + "].metallic", 1, MaterialManager::getMaterial(i).getMetallicValue());
                    use1FV("materials[" + index.str() + "].roughness", 1, MaterialManager::getMaterial(i).getRoughnessValue());
                }
            }

            void PBRShader::sendLigths(std::vector<Light::Light*> const& lights) const {
                use1I("numLights", lights.size());

                for (unsigned int i = 0; i < lights.size(); i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    use4FV("lights[" + index.str() + "].position", 1, lights.at(i)->getPosition().value());
                    use3FV("lights[" + index.str() + "].intensities", 1, lights.at(i)->getIntensities().value());
                    use3FV("lights[" + index.str() + "].direction", 1, lights.at(i)->getDirection().value());
                    use1FV("lights[" + index.str() + "].angle", 1, lights.at(i)->getAngleValue());
                }
            }

            void PBRShader::sendTextures() const {
                use1I("texDepth", 0);
                use1I("texDiffuseUV", 1);
                use1I("texNormal", 2);
                use1I("irradianceMap", 4);
                use1I("prefilterMap", 5);
                use1I("brdfLUT", 6);
                use1I("texMaterial", 7);
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
