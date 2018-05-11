
    #include "NRE_IrradianceShader.hpp"

    namespace NRE {
        namespace Renderer {

            IrradianceShader::IrradianceShader() : Shader::Shader(true) {
                addUniformLocation("skyBox");
                addUniformLocation("modelview");
            }

            IrradianceShader::IrradianceShader(IrradianceShader && s) : Shader::Shader(std::move(s)) {
            }

            IrradianceShader::~IrradianceShader() {
            }

            std::string const IrradianceShader::getPath() const {
                return "Irradiance";
            }

            IrradianceShader& IrradianceShader::operator=(IrradianceShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
