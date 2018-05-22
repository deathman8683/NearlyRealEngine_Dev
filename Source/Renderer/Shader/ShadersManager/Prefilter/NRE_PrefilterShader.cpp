
    #include "NRE_PrefilterShader.hpp"

    namespace NRE {
        namespace Renderer {

            PrefilterShader::PrefilterShader() {
                load();
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

            void PrefilterShader::sendRoughness(NREfloat const& value) const {
                use1F("roughness", value);
            }

            void PrefilterShader::sendModelview(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("modelview", 1, &m);
            }

            PrefilterShader& PrefilterShader::operator=(PrefilterShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
