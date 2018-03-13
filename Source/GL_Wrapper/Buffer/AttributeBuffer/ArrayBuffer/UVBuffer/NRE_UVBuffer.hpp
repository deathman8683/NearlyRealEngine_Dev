
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : UVBuffer
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
             * @class UVBuffer
             * @brief GL's Object : A specialized ArrayBuffer for vertex uv managing
             */
            class UVBuffer : public ArrayBuffer {
                private:

                public:
                    //## Constructor ##//
                    UVBuffer();
                    UVBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    UVBuffer(UVBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~UVBuffer();

                    //## Getter ##//
                    GLint const getTypeSize() const;
                    GLint const getSize() const;
                    GLenum const getType() const;

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
