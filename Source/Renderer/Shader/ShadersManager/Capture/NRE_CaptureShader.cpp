
    #include "NRE_CaptureShader.hpp"

    namespace NRE {
        namespace Renderer {

            CaptureShader::CaptureShader() {
                load();
                addUniformLocation("skyBox");
                addUniformLocation("modelview");
            }

            CaptureShader::CaptureShader(CaptureShader && s) : Shader::Shader(std::move(s)) {
            }

            CaptureShader::~CaptureShader() {
            }

            std::string const CaptureShader::getPath() const {
                return "Capture";
            }

            void CaptureShader::sendModelview(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("modelview", 1, &m);
            }

            CaptureShader& CaptureShader::operator=(CaptureShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
