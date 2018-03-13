
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ColorBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ArrayBuffer.hpp"

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
             * @class ColorBuffer
             * @brief GL's Object : A specialized ArrayBuffer for vertex color managing
             */
            class ColorBuffer : public ArrayBuffer {
                private:

                public:
                    //## Constructor ##//
                    ColorBuffer();
                    ColorBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    ColorBuffer(ColorBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~ColorBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void access(bool const& enableVAA);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLint INDEX;
                    static GLenum TYPE;
                    static GLint TYPESIZE;
                    static GLint SIZE;
            };

        };
    };
