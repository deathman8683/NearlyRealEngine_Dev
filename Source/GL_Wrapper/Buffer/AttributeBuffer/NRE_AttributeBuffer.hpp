
    /**
     * @file NRE_AttributeBuffer.hpp
     * @brief Declaration of Engine's GL's Object : AttributeBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"

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
             * @class AttributeBuffer
             * @brief GL's Object : A specialized buffer for vertex attribute managing
             */
            class AttributeBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                    AttributeBuffer();
                    AttributeBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    AttributeBuffer(AttributeBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~AttributeBuffer();

                    //## Getter ##//
                    virtual GLint const getTypeSize() const = 0;
                    virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void bind(GLenum const& target) const override;
                    void unbind(GLenum const& target) const override;
                    void allocate(GLenum const& target, GLsizeiptr const& size, GLenum const& usage) const;
                    void update(GLenum const& target, GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data) const;
                    void allocateAndFill(GLenum const& target, GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data) const;

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
