
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

            void Shader::bind() const {
                glUseProgram(getID());
            }

            void Shader::unbind() const {
                glUseProgram(0);
            }

            void Shader::load() {
                if(glIsProgram(getID()) == GL_TRUE) {
                    glDeleteProgram(getID());
                }

                vShader.compile();
                fShader.compile();

                id = glCreateProgram();

                glAttachShader(getID(), getVertexShader().getID());
                glAttachShader(getID(), getFragmentShader().getID());

                glBindAttribLocation(getID(), 0, "in_Vertex");
                glBindAttribLocation(getID(), 1, "in_Color");
                glBindAttribLocation(getID(), 2, "in_Normal");
                glBindAttribLocation(getID(), 3, "in_UV");
                glBindAttribLocation(getID(), 4, "in_Material");

                glLinkProgram(getID());

                GLint linkError = 0;
                glGetProgramiv(getID(), GL_LINK_STATUS, &linkError);
                if (linkError != GL_TRUE) {
                    GLint errorSize = 0;
                    glGetShaderiv(getID(), GL_INFO_LOG_LENGTH, &errorSize);

                    char *error = new char[errorSize + 1];

                    glGetShaderInfoLog(getID(), errorSize, NULL, error);
                    error[errorSize] = '\0';

                    std::string eError(error);

                    delete[] error;
                    glDeleteProgram(getID());

                    throw (Exception::ShaderException("Linking Error : " + std::string(eError)));
                }
            }

            void Shader::addUniformLocation(std::string const& uniform) {
                uniformsLocations.queryLocation(getID(), uniform);
            }

            void Shader::use1I(std::string const& location, GLint const& v0) const {
                glUniform1i(uniformsLocations.getLocation(location), v0);
            }

            void Shader::use2I(std::string const& location, GLint const& v0, GLint const& v1) const {
                glUniform2i(uniformsLocations.getLocation(location), v0, v1);
            }

            void Shader::use3I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2) const {
                glUniform3i(uniformsLocations.getLocation(location), v0, v1, v2);
            }

            void Shader::use4I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2, GLint const& v3) const {
                glUniform4i(uniformsLocations.getLocation(location), v0, v1, v2, v3);
            }

            void Shader::use1F(std::string const& location, GLfloat const& v0) const {
                glUniform1f(uniformsLocations.getLocation(location), v0);
            }

            void Shader::use2F(std::string const& location, GLfloat const& v0, GLfloat const& v1) const {
                glUniform2f(uniformsLocations.getLocation(location), v0, v1);
            }

            void Shader::use3F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2) const {
                glUniform3f(uniformsLocations.getLocation(location), v0, v1, v2);
            }

            void Shader::use4F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2, GLfloat const& v3) const {
                glUniform4f(uniformsLocations.getLocation(location), v0, v1, v2, v3);
            }

            void Shader::use1UI(std::string const& location, GLuint const& v0) const {
                glUniform1ui(uniformsLocations.getLocation(location), v0);
            }

            void Shader::use2UI(std::string const& location, GLuint const& v0, GLuint const& v1) const {
                glUniform2ui(uniformsLocations.getLocation(location), v0, v1);
            }

            void Shader::use3UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2) const {
                glUniform3ui(uniformsLocations.getLocation(location), v0, v1, v2);
            }

            void Shader::use4UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2, GLuint const& v3) const {
                glUniform4ui(uniformsLocations.getLocation(location), v0, v1, v2, v3);
            }

            void Shader::useMat2(std::string const& location, GLsizei const& count, const Maths::Matrix2x2<NREfloat>* const value) const {
                glUniformMatrix2fv(uniformsLocations.getLocation(location), count, GL_TRUE, value->value());
            }


            void Shader::useMat3(std::string const& location, GLsizei const& count, const Maths::Matrix3x3<NREfloat>* const value) const {
                glUniformMatrix3fv(uniformsLocations.getLocation(location), count, GL_TRUE, value->value());
            }


            void Shader::useMat4(std::string const& location, GLsizei const& count, const Maths::Matrix4x4<NREfloat>* const value) const {
                glUniformMatrix4fv(uniformsLocations.getLocation(location), count, GL_TRUE, value->value());
            }

            void Shader::use1IV(std::string const& location, GLsizei const& count, const GLint* const value) const {
                glUniform1iv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use2IV(std::string const& location, GLsizei const& count, const GLint* const value) const {
                glUniform2iv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use3IV(std::string const& location, GLsizei const& count, const GLint* const value) const {
                glUniform3iv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use4IV(std::string const& location, GLsizei const& count, const GLint* const value) const {
                glUniform4iv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use1FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const {
                glUniform1fv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use2FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const {
                glUniform2fv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use3FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const {
                glUniform3fv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use4FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const {
                glUniform4fv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use1UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const {
                glUniform1uiv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use2UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const {
                glUniform2uiv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use3UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const {
                glUniform3uiv(uniformsLocations.getLocation(location), count, value);
            }

            void Shader::use4UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const {
                glUniform4uiv(uniformsLocations.getLocation(location), count, value);
            }

            Shader& Shader::operator=(Shader && s) {
                id = std::move(s.getID());
                vShader = std::move(s.vShader);
                fShader = std::move(s.fShader);
                uniformsLocations = std::move(s.uniformsLocations);

                return *this;
            }

        };
    };
