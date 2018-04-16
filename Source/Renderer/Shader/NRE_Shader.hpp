
    /**
     * @file NRE_Shader.hpp
     * @brief Declaration of Engine's Renderer's Object : Shader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "ShaderBase/VertexShader/NRE_VertexShader.hpp"
    #include "ShaderBase/FragmentShader/NRE_FragmentShader.hpp"
    #include "ShaderMap/NRE_ShaderMap.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Renderer
         * @brief Engine's Renderer Module
         */
        namespace Renderer {

            /**
             * @class Shader
             * @brief Renderer's Object : Manage shader transfer and compiling
             */
            class Shader {
                private:
                    GLuint id;
                    VertexShader vShader;
                    FragmentShader fShader;
                    ShaderMap uniformsLocations;

                public:
                    //## Constructor ##//
                        Shader();
                        Shader(std::string const& vPath, std::string const& fPath, bool const& loadImmediatly = false);

                    //## Copy-Constructor ##//
                        Shader(Shader const& s) = delete;

                    //## Move-Constructor ##//
                        Shader(Shader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        ~Shader();

                    //## Getter ##//
                        GLuint const& getID() const;
                        VertexShader const& getVertexShader() const;
                        FragmentShader const& getFragmentShader() const;

                    //## Setter ##//
                        void setID(GLuint const& id);

                    //## Methods ##//
                        void bind() const;
                        void unbind() const;
                        void load();
                        void addUniformLocation(std::string const& uniform);
                        void use1I(std::string const& location, GLint const& v0) const;
                        void use2I(std::string const& location, GLint const& v0, GLint const& v1) const;
                        void use3I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2) const;
                        void use4I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2, GLint const& v3) const;
                        void use1F(std::string const& location, GLfloat const& v0) const;
                        void use2F(std::string const& location, GLfloat const& v0, GLfloat const& v1) const;
                        void use3F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2) const;
                        void use4F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2, GLfloat const& v3) const;
                        void use1UI(std::string const& location, GLuint const& v0) const;
                        void use2UI(std::string const& location, GLuint const& v0, GLuint const& v1) const;
                        void use3UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2) const;
                        void use4UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2, GLuint const& v3) const;
                        void useMat2(std::string const& location, GLsizei const& count, const Maths::Matrix2x2<NREfloat>* const value) const;
                        void useMat3(std::string const& location, GLsizei const& count, const Maths::Matrix3x3<NREfloat>* const value) const;
                        void useMat4(std::string const& location, GLsizei const& count, const Maths::Matrix4x4<NREfloat>* const value) const;
                        void use1IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        void use2IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        void use3IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        void use4IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        void use1FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        void use2FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        void use3FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        void use4FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        void use1UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        void use2UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        void use3UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        void use4UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        Shader& operator=(Shader const& map) = delete;
                        Shader& operator=(Shader && map);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
