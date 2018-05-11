
    #include "NRE_GBufferShader.hpp"

    namespace NRE {
        namespace Renderer {

            GBufferShader::GBufferShader() {
                load();
                addUniformLocation("modelview");
                addUniformLocation("projection");
            }

            GBufferShader::GBufferShader(GBufferShader && s) : Shader::Shader(std::move(s)) {
            }

            GBufferShader::~GBufferShader() {
            }

            std::string const GBufferShader::getPath() const {
                return "GBuffer";
            }

            GBufferShader& GBufferShader::operator=(GBufferShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
