
    /**
     * @file NRE_DepthBuffer.hpp
     * @brief Declaration of Engine's GL's Object : DepthBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

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
                    DepthBuffer();

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    virtual void bind() const = 0;
                    virtual void unbind() const = 0;
                    virtual void attach(GLenum const& attachment) const = 0;

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
