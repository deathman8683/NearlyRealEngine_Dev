
    /**
     * @file NRE_ShaderBase.hpp
     * @brief Declaration of Engine's Renderer's Object : ShaderBase
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <fstream>
    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Exception/ShaderException/NRE_ShaderException.hpp"
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
                    GLuint id;          /**< The shader base OpenGL id */
                    std::string path;   /**< The shade base path */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ShaderBase();
                        /**
                         * Construct a shader base with his shader path
                         * @param path the path to the shader program
                         */
                        ShaderBase(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the shader base to copy
                         */
                        ShaderBase(ShaderBase const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the shader base to move
                         */
                        ShaderBase(ShaderBase && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ShaderBase Deconstructor
                         */
                        virtual ~ShaderBase();

                    //## Getter ##//
                        /**
                         * ID getter
                         * @return the program id
                         */
                        GLuint const& getID() const;
                        /**
                         * Path getter
                         * @return the shader path
                         */
                        std::string const& getPath() const;
                        /**
                         * Type getter
                         * @return return the shader program type, used to differentiate derived shader
                         */
                        virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Compile the current shader
                         */
                        void compile();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param s the shader base to copy
                         */
                        ShaderBase& operator=(ShaderBase const& base) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the shader base to move into this
                         * @return the reference of himself
                         */
                        ShaderBase& operator=(ShaderBase && base);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
