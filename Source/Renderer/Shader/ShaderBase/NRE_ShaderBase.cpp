
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

            void ShaderBase::compile(IO::File const& file) {
                if (glIsShader(getID()) == GL_TRUE) {
                    glDeleteShader(getID());
                }

                id = glCreateShader(getType());

                IO::InputFile shaderFile(file.getPath() + getExt());
                shaderFile.open();

                std::string line, sourceCode;

                while(shaderFile.readLine(line)) {
                    sourceCode = sourceCode + line + '\n';
                }

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

                    throw (Exception::ShaderException((file.getPath() + getExt()) + " : " + std::string(eError)));
                }
            }

            ShaderBase& ShaderBase::operator=(ShaderBase && base) {
                id = std::move(base.id);

                return *this;
            }

        };
    };
