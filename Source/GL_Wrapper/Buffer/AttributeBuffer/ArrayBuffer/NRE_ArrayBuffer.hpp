
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ArrayBuffer
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
             * @class ArrayBuffer
             * @brief GL's Object : A specialized AttributeBuffer for vertex array attribute managing
             */
            class ArrayBuffer : public AttributeBuffer {
                private:

                public:
                    //## Constructor ##//
                    ArrayBuffer();
                    ArrayBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    ArrayBuffer(ArrayBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~ArrayBuffer();

                    //## Getter ##//
                    virtual GLint const getTypeSize() const = 0;
                    virtual GLint const getSize() const = 0;
                    virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                    void bind() const;
                    void unbind() const;
                    void allocate(GLsizeiptr const& size, GLenum const& usage) const;
                    void update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const;
                    void allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const;
                    void access(GLenum const& type, GLint const& index, GLint const& size, bool const& enableVAA);

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
