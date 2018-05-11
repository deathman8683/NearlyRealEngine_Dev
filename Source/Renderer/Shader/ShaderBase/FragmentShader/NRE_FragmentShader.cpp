
    #include "NRE_FragmentShader.hpp"

    namespace NRE {
        namespace Renderer {

            FragmentShader::FragmentShader() {
            }

            FragmentShader::FragmentShader(FragmentShader && s) : ShaderBase::ShaderBase(std::move(s)) {
            }

            FragmentShader::~FragmentShader() {
            }

            GLenum const FragmentShader::getType() const {
                return GL_FRAGMENT_SHADER;
            }

            std::string const FragmentShader::getExt() const {
                return "Shader.frag";
            }

            FragmentShader& FragmentShader::operator=(FragmentShader && s) {
                ShaderBase::operator=(std::move(s));
                return *this;
            }
        };
    };
