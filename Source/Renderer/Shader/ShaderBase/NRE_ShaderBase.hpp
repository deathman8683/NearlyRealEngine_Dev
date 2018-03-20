
    /**
     * @file NRE_ShaderBase.hpp
     * @brief Declaration of Engine's Renderer's Object : ShaderBase
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <fstream>
    #include "../../../Generic/NRE_Type.hpp"
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
             * @class ShaderBase
             * @brief Renderer's Object : A base shader for vertex and fragment specialization
             */
            class ShaderBase {
                private:
                    GLuint id;
                    std::string path;

                public:
                    //## Constructor ##//
                    ShaderBase();
                    ShaderBase(std::string const& path);

                    //## Copy-Constructor ##//
                    ShaderBase(ShaderBase const& s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~ShaderBase();

                    //## Getter ##//
                    GLuint const& getID() const;
                    std::string const& getPath() const;
                    virtual GLenum const getType() const = 0;

                    //## Setter ##//
                    void setID(GLuint const& id);
                    void setPath(std::string const& path);

                    //## Methods ##//
                    void compile();

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
