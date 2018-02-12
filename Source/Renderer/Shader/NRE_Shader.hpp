
    /**
     * @file NRE_Shader.hpp
     * @brief Declaration of Engine's Renderer's Object : Shader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <fstream>
    #include "../../Generic/NRE_Type.hpp"
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
                    GLint vertexID;
                    GLint fragmentID;
                    GLint programID;
                    std::string vertexPath;
                    std::string fragmentPath;

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
                    GLint const& getVertexID() const;
                    GLint const& getFragmentID() const;
                    GLint const& getProgramID() const;
                    std::string const& getVertexPath() const;
                    std::string const& getFragmentPath() const;

                    //## Setter ##//
                    void setVertexID(GLint const& id);
                    void setFragmentID(GLint const& id);
                    void setProgramID(GLint const& id);
                    void setVertexPath(std::string const& path);
                    void setFragmentPath(std::string const& path);

                    //## Methods ##//
                    void load();
                    void compile(GLint & shader, GLenum const& type, std::string const& source);

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
