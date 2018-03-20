
    #include "NRE_Shader.hpp"

    namespace NRE {
        namespace Renderer {

            Shader::Shader() : id(0) {
            }

            Shader::Shader(std::string const& vPath, std::string const& fPath, bool const& loadImmediatly) :  id(0), vShader(vPath), fShader(fPath) {
                if (loadImmediatly) {
                    load();
                }
            }

            Shader::Shader(Shader const& s) : id(s.getID()), vShader(s.getVertexShader()), fShader(s.getFragmentShader()) {
            }

            Shader::~Shader() {
                glDeleteProgram(getID());
            }

            GLuint const& Shader::getID() const {
                return id;
            }

            VertexShader const& Shader::getVertexShader() const {
                return vShader;
            }

            FragmentShader const& Shader::getFragmentShader() const {
                return fShader;
            }

            void Shader::setID(GLuint const& id) {
                this->id = id;
            }

            void Shader::setVertexShader(VertexShader const& s) {
                vShader = s;
            }

            void Shader::setFragmentShader(FragmentShader const& s) {
                fShader = s;
            }

            void Shader::load() {
                if(glIsProgram(getID()) == GL_TRUE) {
                    glDeleteProgram(getID());
                }

                vShader.compile();
                fShader.compile();

                setID(glCreateProgram());

                glAttachShader(getID(), getVertexShader().getID());
                glAttachShader(getID(), getFragmentShader().getID());

                glBindAttribLocation(getID(), 0, "in_Vertex");
                glBindAttribLocation(getID(), 1, "in_Color");
                glBindAttribLocation(getID(), 2, "in_Normal");
                glBindAttribLocation(getID(), 3, "in_UV");

                glLinkProgram(getID());

                GLint linkError = 0;
                glGetProgramiv(getID(), GL_LINK_STATUS, &linkError);
                if (linkError != GL_TRUE) {
                    GLint errorSize = 0;
                    glGetShaderiv(getID(), GL_INFO_LOG_LENGTH, &errorSize);

                    char *error = new char[errorSize + 1];

                    glGetShaderInfoLog(getID(), errorSize, NULL, error);
                    error[errorSize] = '\0';

                    std::cout << std::string(error) << std::endl;;

                    delete[] error;
                    glDeleteProgram(getID());
                }
            }

        };
    };
