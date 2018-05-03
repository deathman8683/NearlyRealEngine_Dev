
    /**
     * @file NRE_FragmentShader.hpp
     * @brief Declaration of Engine's Renderer's Object : FragmentShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ShaderBase.hpp"
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
             * @class FragmentShader
             * @brief Renderer's Object : Manage FragmentShader transfer and compiling
             */
            class FragmentShader : public ShaderBase {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FragmentShader();
                        /**
                         * Construct a fragment shader with his shader path
                         * @param path the path to the shader program
                         */
                        FragmentShader(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the fragment shader to copy
                         */
                        FragmentShader(FragmentShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the fragment shader to move
                         */
                        FragmentShader(FragmentShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FragmentShader Deconstructor
                         */
                        ~FragmentShader();

                    //## Getter ##//
                        /**
                         * Type getter
                         * @return return the shader program type, used to differentiate derived shader
                         */
                        GLenum const getType() const override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##/
                        /**
                         * No copy assigment allowed
                         * @param s the fragment shader to copy
                         */
                        FragmentShader& operator=(FragmentShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the fragment shader to move into this
                         * @return the reference of himself
                         */
                        FragmentShader& operator=(FragmentShader && s);

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
