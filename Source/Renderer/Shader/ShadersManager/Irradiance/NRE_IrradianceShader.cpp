
    #include "NRE_IrradianceShader.hpp"

    namespace NRE {
        namespace Renderer {

            IrradianceShader::IrradianceShader() {
                load();
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

            void IrradianceShader::sendModelview(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("modelview", 1, &m);
            }

            IrradianceShader& IrradianceShader::operator=(IrradianceShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
