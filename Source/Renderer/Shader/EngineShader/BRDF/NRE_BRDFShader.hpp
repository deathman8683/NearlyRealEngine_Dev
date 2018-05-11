
    /**
     * @file NRE_BRDFShader.hpp
     * @brief Declaration of Engine's Renderer's Object : BRDFShader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../NRE_Shader.hpp"

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
             * @class BRDFShader
             * @brief Renderer's Object : Manage the BRDF specific shader
             */
            class BRDFShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BRDFShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the BRDF shader to copy the content
                         */
                        BRDFShader(BRDFShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the BRDF shader to move
                         */
                        BRDFShader(BRDFShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * BRDFShader Deconstructor
                         */
                        ~BRDFShader();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the shader's specific name path
                         */
                        std::string const getPath() const override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the BRDF shader to copy into this
                         * @return the reference of himself
                         */
                        BRDFShader& operator=(BRDFShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the BRDF shader to move into this
                         * @return the reference of himself
                         */
                        BRDFShader& operator=(BRDFShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
