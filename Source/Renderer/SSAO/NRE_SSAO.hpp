
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
                    Maths::Vector3D<NREfloat> *kernel;  /**< SSAO kernel with random sample */
                    GL::Texture2D* noise;               /**< SSAO texture with a random noise to reduce the kernel size */
                    NREfloat ratio;                     /**< SSAO ratio, the window radio */
                    NREfloat tanHalfFOV;                /**< Half tan FOV stored to reduce computation */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SSAO();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param ssao the SSAO to copy
                         */
                        SSAO(SSAO const& ssao) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move ssao into this, leaving ssao empty
                         * @param ssao the SSAO to move
                         */
                        SSAO(SSAO && ssao);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * SSAO Deconstructor
                         */
                        ~SSAO();

                    //## Getter ##//
                        /**
                         * Kernel getter
                         * @return the pointer to the first vector of the kernel
                         */
                        Maths::Vector3D<NREfloat>* const& getKernel() const;
                        /**
                         * Noise getter
                         * @return the noise texture
                         */
                        GL::Texture2D* const& getNoise() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the SSAO kernel
                         */
                        void generateKernel();
                        /**
                         * Generate the noise texture
                         */
                        void generateNoise();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param ssao the SSAO to copy
                         */
                        SSAO& operator=(SSAO const& ssao) = delete;
                        /**
                         * Move assigment of ssao into this, leaving ssao empty
                         * @param ssao the SSAO to move into this
                         * @return the reference of himself
                         */
                        SSAO& operator=(SSAO && ssao);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                public:
                    static GLuint KERNEL_SIZE;  /**< The SSSAO kernel size */
                private:
                    static GLuint NOISE_SIZE;   /**< The SSAO noise texture size */
            };

        };
    };
