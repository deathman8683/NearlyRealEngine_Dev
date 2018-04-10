
    /**
     * @file NRE_Shader.hpp
     * @brief Declaration of Engine's Renderer's Object : Shader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "ShaderBase/VertexShader/NRE_VertexShader.hpp"
    #include "ShaderBase/FragmentShader/NRE_FragmentShader.hpp"
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

                public:
                    //## Constructor ##//
                    Shader();
                    Shader(std::string const& vPath, std::string const& fPath, bool const& loadImmediatly = false);

                    //## Copy-Constructor ##//
                    Shader(Shader const& s);

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
                    void setVertexShader(VertexShader const& s);
                    void setFragmentShader(FragmentShader const& s);

                    //## Methods ##//
                    void bind();
                    void unbind();
                    void load();
                    void use(GLint const& i);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
