
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : NormalBuffer
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
             * @class NormalBuffer
             * @brief GL's Object : A specialized ArrayBuffer for vertex normal managing
             */
            class NormalBuffer : public ArrayBuffer {
                private:

                public:
                    //## Constructor ##//
                    NormalBuffer();
                    NormalBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    NormalBuffer(NormalBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~NormalBuffer();

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
