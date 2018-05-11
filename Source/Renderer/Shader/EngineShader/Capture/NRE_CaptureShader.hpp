
    /**
     * @file NRE_CaptureShader.hpp
     * @brief Declaration of Engine's Renderer's Object : CaptureShader
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
             * @class CaptureShader
             * @brief Renderer's Object : Manage the capture specific shader
             */
            class CaptureShader : public Shader {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        CaptureShader();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the capture shader to copy the content
                         */
                        CaptureShader(CaptureShader const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the capture shader to move
                         */
                        CaptureShader(CaptureShader && s);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * CaptureShader Deconstructor
                         */
                        ~CaptureShader();

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
                         * @param s the capture shader to copy into this
                         * @return the reference of himself
                         */
                        CaptureShader& operator=(CaptureShader const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the capture shader to move into this
                         * @return the reference of himself
                         */
                        CaptureShader& operator=(CaptureShader && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
