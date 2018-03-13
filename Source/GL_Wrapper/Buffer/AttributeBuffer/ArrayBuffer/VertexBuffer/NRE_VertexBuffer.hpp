
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : VertexBuffer
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
             * @class VertexBuffer
             * @brief GL's Object : A specialized ArrayBuffer for vertex position managing
             */
            class VertexBuffer : public ArrayBuffer {
                private:

                public:
                    //## Constructor ##//
                    VertexBuffer();
                    VertexBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    VertexBuffer(VertexBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VertexBuffer();

                    //## Getter ##//
                    GLint const getTypeSize() const;
                    GLint const getSize() const;
                    GLenum const getType() const;
                    GLint const getIndex() const;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLint INDEX;
                    static GLint SIZE;
            };

        };
    };
