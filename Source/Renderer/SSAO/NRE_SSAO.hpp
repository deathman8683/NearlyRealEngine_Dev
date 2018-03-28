
    /**
     * @file NRE_SSAO.hpp
     * @brief Declaration of Engine's Renderer's Object : SSAO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

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

                public:
                    //## Constructor ##//
                    SSAO();

                    //## Copy-Constructor ##//
                    SSAO(SSAO const& ao);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~SSAO();

                    //## Getter ##//
                    Maths::Vector3D<NREfloat>* const& getKernel() const;

                    //## Setter ##//
                    void setKernel(Maths::Vector3D<NREfloat>* const& kern);

                    //## Methods ##//
                    void generateKernel();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLuint KERNEL_SIZE;
            };

        };
    };
