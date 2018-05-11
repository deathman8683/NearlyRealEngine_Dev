
    #include "NRE_VertexShader.hpp"

    namespace NRE {
        namespace Renderer {

            VertexShader::VertexShader() {
            }

            VertexShader::VertexShader(VertexShader && s) : ShaderBase::ShaderBase(std::move(s)) {
            }

            VertexShader::~VertexShader() {
            }

            GLenum const VertexShader::getType() const {
                return GL_VERTEX_SHADER;
            }

            std::string const VertexShader::getExt() const {
                return "Shader.vert";
            }

            VertexShader& VertexShader::operator=(VertexShader && s) {
                ShaderBase::operator=(std::move(s));
                return *this;
            }
        };
    };
