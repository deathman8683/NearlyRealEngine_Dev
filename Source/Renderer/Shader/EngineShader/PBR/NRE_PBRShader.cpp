
    #include "NRE_PBRShader.hpp"

    namespace NRE {
        namespace Renderer {

            GLuint PBRShader::MAX_LIGHTS = 10;

            PBRShader::PBRShader() {
                load();
                addUniformLocation("texDepth");
                addUniformLocation("texDiffuse");
                addUniformLocation("texNormal");
                addUniformLocation("irradianceMap");
                addUniformLocation("prefilterMap");
                addUniformLocation("brdfLUT");
                for (GLuint i = 0; i < MAX_LIGHTS; i = i + 1) {
                    std::ostringstream index;
                    index << i;
                    addUniformLocation("lights[" + index.str() + "].position");
                    addUniformLocation("lights[" + index.str() + "].intensities");
                    addUniformLocation("lights[" + index.str() + "].direction");
                    addUniformLocation("lights[" + index.str() + "].angle");
                }
                for (unsigned int i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
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
            }

            PBRShader::PBRShader(PBRShader && s) : Shader::Shader(std::move(s)) {
            }

            PBRShader::~PBRShader() {
            }

            std::string const PBRShader::getPath() const {
                return "PBR";
            }

            PBRShader& PBRShader::operator=(PBRShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
