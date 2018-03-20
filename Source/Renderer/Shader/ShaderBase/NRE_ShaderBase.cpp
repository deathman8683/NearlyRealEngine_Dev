
    #include "NRE_ShaderBase.hpp"

    namespace NRE {
        namespace Renderer {

            ShaderBase::ShaderBase() : id(0), path("") {
            }

            ShaderBase::ShaderBase(std::string const& path) :  id(0), path(path) {
            }

            ShaderBase::ShaderBase(ShaderBase const& s) : id(s.getID()), path(s.getPath()) {
            }

            ShaderBase::~ShaderBase() {
                glDeleteShader(getID());
            }

            GLuint const& ShaderBase::getID() const {
                return id;
            }

            std::string const& ShaderBase::getPath() const {
                return path;
            }

            void ShaderBase::setID(GLuint const& id) {
                this->id = id;
            }

            void ShaderBase::setPath(std::string const& path) {
                this->path = path;
            }

            void ShaderBase::compile() {
                if (glIsShader(getID()) == GL_TRUE) {
                    glDeleteShader(getID());
                }

                id = glCreateShader(getType());

                std::ifstream shaderFile(getPath().c_str());

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

                    throw (Exception::ShaderException(getPath() + " : " + std::string(eError)));
                }
            }


        };
    };
