
    #include "NRE_Shader.hpp"

    namespace NRE {
        namespace Renderer {

            Shader::Shader() : vertexID(0), fragmentID(0), programID(0), vertexPath(""), fragmentPath("") {
            }

            Shader::Shader(std::string const& vPath, std::string const& fPath, bool const& loadImmediatly) :  vertexID(0), fragmentID(0), programID(0), vertexPath(vPath), fragmentPath(fPath) {
                if (loadImmediatly) {
                    load();
                }
            }

            Shader::Shader(Shader const& s) : vertexID(s.getVertexID()), fragmentID(s.getFragmentID()), programID(s.getProgramID()), vertexPath(s.getVertexPath()), fragmentPath(s.getFragmentPath()) {
            }

            Shader::~Shader() {
                glDeleteShader(getVertexID());
                glDeleteShader(getFragmentID());
                glDeleteProgram(getProgramID());
            }

            GLint const& Shader::getVertexID() const {
                return vertexID;
            }

            GLint const& Shader::getFragmentID() const {
                return fragmentID;
            }

            GLint const& Shader::getProgramID() const {
                return programID;
            }

            std::string const& Shader::getVertexPath() const {
                return vertexPath;
            }

            std::string const& Shader::getFragmentPath() const {
                return fragmentPath;
            }

            void Shader::setVertexID(GLint const& id) {
                vertexID = id;
            }

            void Shader::setFragmentID(GLint const& id) {
                fragmentID = id;
            }

            void Shader::setProgramID(GLint const& id) {
                programID = id;
            }

            void Shader::setVertexPath(std::string const& path) {
                vertexPath = path;
            }

            void Shader::setFragmentPath(std::string const& path) {
                fragmentPath = path;
            }

            void Shader::load() {
                if (glIsShader(getVertexID()) == GL_TRUE) {
                    glDeleteShader(getVertexID());
                }
                if (glIsShader(getFragmentID()) == GL_TRUE) {
                    glDeleteShader(getFragmentID());
                }
                if(glIsProgram(getProgramID()) == GL_TRUE) {
                    glDeleteProgram(getProgramID());
                }

                compile(vertexID, GL_VERTEX_SHADER, getVertexPath());
                compile(fragmentID, GL_FRAGMENT_SHADER, getFragmentPath());

                setProgramID(glCreateProgram());

                glAttachShader(getProgramID(), getVertexID());
                glAttachShader(getProgramID(), getFragmentID());

                glBindAttribLocation(getProgramID(), 0, "in_Vertex");
                glBindAttribLocation(getProgramID(), 1, "in_Color");
                glBindAttribLocation(getProgramID(), 2, "in_Normal");
                glBindAttribLocation(getProgramID(), 3, "in_UV");

                glLinkProgram(getProgramID());

                GLint linkError = 0;
                glGetProgramiv(getProgramID(), GL_LINK_STATUS, &linkError);
                if (linkError != GL_TRUE) {
                    GLint errorSize = 0;
                    char *error = new char[errorSize + 1];

                    glGetShaderInfoLog(getProgramID(), errorSize, &errorSize, error);
                    error[errorSize] = '\0';

                    std::cout << std::string(error) << std::endl;;

                    delete[] error;
                    glDeleteProgram(getProgramID());
                }
            }

            void Shader::compile(GLint & shader, GLenum const& type, std::string const& source) {
                shader = glCreateShader(type);

                std::ifstream shaderFile(source.c_str());

                std::string line, sourceCode;

                while(getline(shaderFile, line)) {
                    sourceCode = sourceCode + line + '\n';
                }

                shaderFile.close();

                const GLchar* sourceCodeChar = sourceCode.c_str();

                glShaderSource(shader, 1, &sourceCodeChar, 0);

                glCompileShader(shader);

                GLint compileError(0);
                glGetShaderiv(shader, GL_COMPILE_STATUS, &compileError);
                if (compileError != GL_TRUE) {
                    GLint errorSize(0);
                    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorSize);

                    char *error = new char[errorSize + 1];

                    glGetShaderInfoLog(shader, errorSize, &errorSize, error);
                    error[errorSize] = '\0';

                    std::cout << std::string(error) << std::endl;

                    delete[] error;
                    glDeleteShader(shader);
                }
            }

        };
    };
