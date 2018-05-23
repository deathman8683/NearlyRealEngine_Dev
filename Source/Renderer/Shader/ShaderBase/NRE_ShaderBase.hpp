
    /**
     * @file NRE_ShaderBase.hpp
     * @brief Declaration of Engine's Renderer's Object : ShaderBase
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <fstream>
    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Exception/NRE_Exception.hpp"
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

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ShaderBase();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param base the shader base to copy
                         */
                        ShaderBase(ShaderBase const& base) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move base into this, leaving base empty
                         * @param base the shader base to move
                         */
                        ShaderBase(ShaderBase && base);

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
                         * Type getter
                         * @return the shader program type, used to differentiate derived shader
                         */
                        virtual GLenum const getType() const = 0;
                        /**
                         * Extension getter
                         * @return the shader program extension, used to compile derived shader
                         */
                        virtual std::string const getExt() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Compile the current shader
                         * @param name  the shader's name (And with the base path added)
                         */
                        void compile(std::string const& name);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param base the shader base to copy
                         */
                        ShaderBase& operator=(ShaderBase const& base) = delete;
                        /**
                         * Move assigment of base into this, leaving base empty
                         * @param base the shader base to move into this
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
