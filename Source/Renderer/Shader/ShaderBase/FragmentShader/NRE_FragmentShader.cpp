
    #include "NRE_FragmentShader.hpp"

    namespace NRE {
        namespace Renderer {

            FragmentShader::FragmentShader() {
            }

            FragmentShader::FragmentShader(std::string const& path) : ShaderBase::ShaderBase(path) {
            }

            FragmentShader::FragmentShader(FragmentShader const& s) : ShaderBase::ShaderBase(s) {
            }

            FragmentShader::~FragmentShader() {
            }

            GLenum const FragmentShader::getType() const {
                return GL_FRAGMENT_SHADER;
            }
        };
    };
