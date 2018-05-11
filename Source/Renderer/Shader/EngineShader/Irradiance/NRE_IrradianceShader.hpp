
    /**
     * @file NRE_IrradianceShader.hpp
     * @brief Declaration of Engine's Renderer's Object : IrradianceShader
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
             * @class IrradianceShader
             * @brief Renderer's Object : Manage the irradiance specific shader
             */
            class IrradianceShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IrradianceShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the irradiance shader to copy the content
                         */
                        IrradianceShader(IrradianceShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the irradiance shader to move
                         */
                        IrradianceShader(IrradianceShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IrradianceShader Deconstructor
                         */
                        ~IrradianceShader();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the shader's specific name path
                         */
                        std::string const getPath() const override;

                    //## Setter ##//

                    //## Methods ##//
                        void sendModelview(Maths::Matrix4x4<NREfloat> const& m) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the irradiance shader to copy into this
                         * @return the reference of himself
                         */
                        IrradianceShader& operator=(IrradianceShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the irradiance shader to move into this
                         * @return the reference of himself
                         */
                        IrradianceShader& operator=(IrradianceShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
