
    #include "NRE_SkyBoxShader.hpp"

    namespace NRE {
        namespace Renderer {

            SkyBoxShader::SkyBoxShader() : Shader::Shader(true) {
                addUniformLocation("MVP");
            }

            SkyBoxShader::SkyBoxShader(SkyBoxShader && s) : Shader::Shader(std::move(s)) {
            }

            SkyBoxShader::~SkyBoxShader() {
            }

            std::string const SkyBoxShader::getPath() const {
                return "SkyBox";
            }

            SkyBoxShader& SkyBoxShader::operator=(SkyBoxShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };