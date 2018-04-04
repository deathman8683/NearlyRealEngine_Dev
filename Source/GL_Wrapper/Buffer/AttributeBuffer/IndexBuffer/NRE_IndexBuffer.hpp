
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : IndexBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_AttributeBuffer.hpp"

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
             * @class IndexBuffer
             * @brief GL's Object : A specialized AttributeBuffer for vertex index managing
             */
            class IndexBuffer : public AttributeBuffer {
                private:

                public:
                    //## Constructor ##//
                    IndexBuffer();
                    IndexBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    IndexBuffer(IndexBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~IndexBuffer();

                    //## Getter ##//
                    GLint const getTypeSize() const;
                    GLenum const getType() const;
                    GLenum const getTarget() const;

                    //## Setter ##//

                    //## Methods ##//
                    void access() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE;
                    static GLint TYPESIZE;
            };

        };
    };
