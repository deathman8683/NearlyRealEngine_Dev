
    #include "NRE_VertexShader.hpp"

    namespace NRE {
        namespace Renderer {

            VertexShader::VertexShader() {
            }

            VertexShader::VertexShader(std::string const& path) : ShaderBase::ShaderBase(path) {
            }

            VertexShader::VertexShader(VertexShader const& s) : ShaderBase::ShaderBase(s) {
            }

            VertexShader::~VertexShader() {
            }

            GLenum const VertexShader::getType() const {
                return GL_VERTEX_SHADER;
            }
        };
    };
