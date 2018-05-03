
    /**
     * @file NRE_SSAO.hpp
     * @brief Declaration of Engine's Renderer's Object : SSAO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <random>
    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../../GL_Wrapper/BufferObject/Texture2D/NRE_Texture2D.hpp"

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
             * @class SSAO
             * @brief Renderer's Object : Screen Space Ambient Occlusion manager
             */
            class SSAO {
                private:
                    Maths::Vector3D<NREfloat> *kernel;
                    GL::Texture2D* noise;
                    NREfloat ratio;
                    NREfloat tanHalfFOV;

                public:
                    //## Constructor ##//
                    SSAO();

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~SSAO();

                    //## Getter ##//
                    Maths::Vector3D<NREfloat>* const& getKernel() const;
                    GL::Texture2D* const& getNoise() const;

                    //## Setter ##//
                    void setKernel(Maths::Vector3D<NREfloat>* const& kern);

                    //## Methods ##//
                    void generateKernel();
                    void generateNoise();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                public:
                    static GLuint KERNEL_SIZE;
                private:
                    static GLuint NOISE_SIZE;
            };

        };
    };
