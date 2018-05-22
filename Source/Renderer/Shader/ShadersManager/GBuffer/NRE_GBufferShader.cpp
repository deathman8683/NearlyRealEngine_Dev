
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

            void GBufferShader::sendProjection(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("projection", 1, &m);
            }

            void GBufferShader::sendModelview(Maths::Matrix4x4<NREfloat> const& m) const {
                useMat4("modelview", 1, &m);
            }

            GBufferShader& GBufferShader::operator=(GBufferShader && s) {
                Shader::operator=(std::move(s));
                return *this;
            }

        };
    };
