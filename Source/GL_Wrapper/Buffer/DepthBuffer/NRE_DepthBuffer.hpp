
    /**
     * @file NRE_DepthBuffer.hpp
     * @brief Declaration of Engine's GL's Object : DepthBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace GL {

            /**
             * @class DepthBuffer
             * @brief GL's Object : An interface for DepthBuffer specialization used in FBO
             */
            class DepthBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        DepthBuffer();

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * DepthBuffer Deconstructor
                         */
                        virtual ~DepthBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        virtual void bind() const = 0;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        virtual void unbind() const = 0;
                        /**
                         * Attach the current buffer to a specific attachment point
                         * @param attachment the frame buffer specific attachment point
                         */
                        virtual void attach(GLenum const& attachment) const = 0;
                        /**
                         * Apply a specific filter to clamp the depth buffer to a border with a given color
                         * @param borderColor the border color
                         */
                        void clampToBorder(Maths::Vector4D<NREfloat> const& borderColor) const;

                    //## Access Operator ##//

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
