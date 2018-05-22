
    #include "NRE_BRDFShader.hpp"

    namespace NRE {
        namespace Renderer {

            BRDFShader::BRDFShader() {
                load();
            }

            BRDFShader::BRDFShader(BRDFShader && s) : Shader::Shader(std::move(s)) {
            }

            BRDFShader::~BRDFShader() {
            }

            std::string const BRDFShader::getPath() const {
                return "BRDF";
            }

            BRDFShader& BRDFShader::operator=(BRDFShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
