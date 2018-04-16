
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
                        GLint const getLocation(std::string const& var);

                    //## Setter ##//
                        void setID(GLuint const& id);

                    //## Methods ##//
                        void bind();
                        void unbind();
                        void load();
                        void use1i(std::string const& location, GLint const& v0);
                        void use2i(std::string const& location, GLint const& v0, GLint const& v1);

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
