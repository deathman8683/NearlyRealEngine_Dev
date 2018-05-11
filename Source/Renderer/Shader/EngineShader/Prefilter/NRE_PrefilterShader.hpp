
    /**
     * @file NRE_PrefilterShader.hpp
     * @brief Declaration of Engine's Renderer's Object : PrefilterShader
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
             * @class PrefilterShader
             * @brief Renderer's Object : Manage the prefilter specific shader
             */
            class PrefilterShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        PrefilterShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the prefilter shader to copy the content
                         */
                        PrefilterShader(PrefilterShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the prefilter shader to move
                         */
                        PrefilterShader(PrefilterShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * PrefilterShader Deconstructor
                         */
                        ~PrefilterShader();

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
                         * @param s the prefilter shader to copy into this
                         * @return the reference of himself
                         */
                        PrefilterShader& operator=(PrefilterShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the prefilter shader to move into this
                         * @return the reference of himself
                         */
                        PrefilterShader& operator=(PrefilterShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
