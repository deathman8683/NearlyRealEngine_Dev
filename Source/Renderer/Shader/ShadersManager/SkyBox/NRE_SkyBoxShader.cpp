
    #include "NRE_SkyBoxShader.hpp"

    namespace NRE {
        namespace Renderer {

            SkyBoxShader::SkyBoxShader() {
                load();
                addUniformLocation("MVP");
            }

            SkyBoxShader::SkyBoxShader(SkyBoxShader && s) : Shader::Shader(std::move(s)) {
            }

            SkyBoxShader::~SkyBoxShader() {
            }

            std::string const SkyBoxShader::getPath() const {
                return "SkyBox";
            }

            void SkyBoxShader::sendMVP(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("MVP", 1, &m);
            }

            SkyBoxShader& SkyBoxShader::operator=(SkyBoxShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
