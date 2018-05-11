
    #include "NRE_SSAOShader.hpp"

    namespace NRE {
        namespace Renderer {

            SSAOShader::SSAOShader() : Shader::Shader(true) {
                addUniformLocation("texDepth");
                addUniformLocation("texNormal");
                addUniformLocation("texNoise");
                addUniformLocation("projection");
                addUniformLocation("invProjection");
                addUniformLocation("gKernel");
                addUniformLocation("gSampleRad");
            }

            SSAOShader::SSAOShader(SSAOShader && s) : Shader::Shader(std::move(s)) {
            }

            SSAOShader::~SSAOShader() {
            }

            std::string const SSAOShader::getPath() const {
                return "SSAO";
            }

            SSAOShader& SSAOShader::operator=(SSAOShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
