
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
                        FragmentShader();
                        FragmentShader(std::string const& path);

                    //## Copy-Constructor ##//
                        FragmentShader(FragmentShader const& s) = delete;

                    //## Move-Constructor ##//
                        FragmentShader(FragmentShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        ~FragmentShader();

                    //## Getter ##//
                        GLenum const getType() const override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##/
                        FragmentShader& operator=(FragmentShader const& s) = delete;
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
