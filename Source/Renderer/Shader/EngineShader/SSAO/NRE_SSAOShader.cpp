
    #include "NRE_SSAOShader.hpp"

    namespace NRE {
        namespace Renderer {

            SSAOShader::SSAOShader() {
                load();
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

            void SSAOShader::sendKernel(SSAO const& ssao) const {
                use3FV("gKernel", SSAO::KERNEL_SIZE, ssao.getKernel()[0].value());
                use1F("gSampleRad", 0.5);
            }

            void SSAOShader::sendTextures() const {
                use1I("texDepth", 0);
                use1I("texNormal", 1);
                use1I("texNoise", 2);
            }

            void SSAOShader::sendProjection(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("projection", 1, &m);
            }
            void SSAOShader::sendInvProjection(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("invProjection", 1, &m);
            }

            SSAOShader& SSAOShader::operator=(SSAOShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
