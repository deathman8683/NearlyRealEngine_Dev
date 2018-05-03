
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
                    GLuint id;                  /**< OpenGL Program ID */
                    VertexShader vShader;       /**< The vertex shader program */
                    FragmentShader fShader;     /**< The fragment shader program */
                    ShaderMap uniformsLocations;/**< The Shader map to store all uniforms */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Shader();
                        /**
                         * Construct a shader from the vertex/fragment shader path
                         * @param vPath          the path to the vertex shader
                         * @param fPath          the path to the fragment shader
                         * @param loadImmediatly tell if the constructor has to load the shader on fly
                         */
                        Shader(std::string const& vPath, std::string const& fPath, bool const& loadImmediatly = false);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the shader to copy
                         */
                        Shader(Shader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the shader to move
                         */
                        Shader(Shader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Shader Deconstructor
                         */
                        ~Shader();

                    //## Getter ##//
                        /**
                         * ID getter
                         * @return the program id
                         */
                        GLuint const& getID() const;
                        /**
                         * Vertex Shader getter
                         * @return the vertex shader object
                         */
                        VertexShader const& getVertexShader() const;
                        /**
                         * Fragment Shader getter
                         * @return the fragment shader object
                         */
                        FragmentShader const& getFragmentShader() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Bind the current shader program
                         */
                        void bind() const;
                        /**
                         * Unbind the current shader program
                         */
                        void unbind() const;
                        /**
                         * Load the shader program and compile the vertex/fragment shader on fly
                         */
                        void load();
                        /**
                         * Add an uniform location into the shader map
                         * @param uniform the uniform to add the location
                         */
                        void addUniformLocation(std::string const& uniform);
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the value to pass
                         */
                        void use1I(std::string const& location, GLint const& v0) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         */
                        void use2I(std::string const& location, GLint const& v0, GLint const& v1) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         */
                        void use3I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         * @param v3       the fourth value to pass
                         */
                        void use4I(std::string const& location, GLint const& v0, GLint const& v1, GLint const& v2, GLint const& v3) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the value to pass
                         */
                        void use1F(std::string const& location, GLfloat const& v0) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         */
                        void use2F(std::string const& location, GLfloat const& v0, GLfloat const& v1) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         */
                        void use3F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         * @param v3       the fourth value to pass
                         */
                        void use4F(std::string const& location, GLfloat const& v0, GLfloat const& v1, GLfloat const& v2, GLfloat const& v3) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the value to pass
                         */
                        void use1UI(std::string const& location, GLuint const& v0) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         */
                        void use2UI(std::string const& location, GLuint const& v0, GLuint const& v1) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         */
                        void use3UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value
                         * @param location the uniform to query the location
                         * @param v0       the first value to pass
                         * @param v1       the second value to pass
                         * @param v2       the third value to pass
                         * @param v3       the fourth value to pass
                         */
                        void use4UI(std::string const& location, GLuint const& v0, GLuint const& v1, GLuint const& v2, GLuint const& v3) const;
                        /**
                         * Call the OpengGL command to bind 2x2 matrix
                         * @param location the uniform to query the location
                         * @param count    the number of matrix passed
                         * @param value    the pointer to the first matrix to passed
                         */
                        void useMat2(std::string const& location, GLsizei const& count, const Maths::Matrix2x2<NREfloat>* const value) const;
                        /**
                         * Call the OpengGL command to bind 3x3 matrix
                         * @param location the uniform to query the location
                         * @param count    the number of matrix passed
                         * @param value    the pointer to the first matrix to passed
                         */
                        void useMat3(std::string const& location, GLsizei const& count, const Maths::Matrix3x3<NREfloat>* const value) const;
                        /**
                         * Call the OpengGL command to bind 4x4 matrix
                         * @param location the uniform to query the location
                         * @param count    the number of matrix passed
                         * @param value    the pointer to the first matrix to passed
                         */
                        void useMat4(std::string const& location, GLsizei const& count, const Maths::Matrix4x4<NREfloat>* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 1 value by 1 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use1IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 2 value by 2 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use2IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 3 value by 3 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use3IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 4 value by 4 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use4IV(std::string const& location, GLsizei const& count, const GLint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 1 value by 1 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use1FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 2 value by 2 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use2FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 3 value by 3 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use3FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 4 value by 4 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use4FV(std::string const& location, GLsizei const& count, const GLfloat* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 1 value by 1 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use1UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 2 value by 2 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use2UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 3 value by 3 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use3UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;
                        /**
                         * Call the OpenGL command to bind specific uniform value from a pointer, 4 value by 4 value
                         * @param location the uniform to query the location
                         * @param count    the number of values passed
                         * @param value    the pointer to the first value to passed
                         */
                        void use4UIV(std::string const& location, GLsizei const& count, const GLuint* const value) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param s the shader to copy
                         */
                        Shader& operator=(Shader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the shader to move into this
                         * @return the reference of himself
                         */
                        Shader& operator=(Shader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
