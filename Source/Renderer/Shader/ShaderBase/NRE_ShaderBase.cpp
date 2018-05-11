
    #include "NRE_ShaderBase.hpp"

    namespace NRE {
        namespace Renderer {

            ShaderBase::ShaderBase() : id(0) {
            }

            ShaderBase::ShaderBase(ShaderBase && base) : id(std::move(base.getID())) {
            }

            ShaderBase::~ShaderBase() {
                glDeleteShader(getID());
            }

            GLuint const& ShaderBase::getID() const {
                return id;
            }

            void ShaderBase::compile(std::string const& name) {
                if (glIsShader(getID()) == GL_TRUE) {
                    glDeleteShader(getID());
                }

                id = glCreateShader(getType());

                std::ifstream shaderFile((name + getExt()).c_str());

                std::string line, sourceCode;

                while(getline(shaderFile, line)) {
                    sourceCode = sourceCode + line + '\n';
                }

                shaderFile.close();

                const GLchar* sourceCodeChar = sourceCode.c_str();

                glShaderSource(getID(), 1, &sourceCodeChar, 0);

                glCompileShader(getID());

                GLint compileError(0);
                glGetShaderiv(getID(), GL_COMPILE_STATUS, &compileError);
                if (compileError != GL_TRUE) {
                    GLint errorSize = 0;
                    glGetShaderiv(getID(), GL_INFO_LOG_LENGTH, &errorSize);

                    char *error = new char[errorSize + 1];

                    glGetShaderInfoLog(getID(), errorSize, &errorSize, error);
                    std::string eError(error);

                    delete[] error;
                    glDeleteShader(getID());

                    throw (Exception::ShaderException((name + getExt()) + " : " + std::string(eError)));
                }
            }

            ShaderBase& ShaderBase::operator=(ShaderBase && base) {
                id = std::move(base.id);

                return *this;
            }

        };
    };
