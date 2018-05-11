
    #include "NRE_PrefilterShader.hpp"

    namespace NRE {
        namespace Renderer {

            PrefilterShader::PrefilterShader() : Shader::Shader(true) {
                addUniformLocation("skyBox");
                addUniformLocation("modelview");
                addUniformLocation("roughness");
            }

            PrefilterShader::PrefilterShader(PrefilterShader && s) : Shader::Shader(std::move(s)) {
            }

            PrefilterShader::~PrefilterShader() {
            }

            std::string const PrefilterShader::getPath() const {
                return "Prefilter";
            }

            PrefilterShader& PrefilterShader::operator=(PrefilterShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
