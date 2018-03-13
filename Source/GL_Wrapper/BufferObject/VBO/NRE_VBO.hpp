
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer/NRE_VertexBuffer.hpp"

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
             * @class VBO
             * @brief GL's Object : Specialization of an BufferObject for vertex managing
             */
            class VBO : public BufferObject {
                private:
                    std::vector<ArrayBuffer*> attributes;

                public:
                    //## Constructor ##//
                    VBO();
                    VBO(bool const& generate);

                    //## Copy-Constructor ##//
                    VBO(VBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VBO();

                    //## Getter ##//
                    std::vector<ArrayBuffer*> const& getAttributes() const;
                    ArrayBuffer* const& getAttribute(GLuint const& index) const;

                    //## Setter ##//
                    void setAttributes(std::vector<ArrayBuffer*> const& attr);
                    void setAttribute(GLuint const& index, ArrayBuffer* const& attr);

                    //## Methods ##//
                    void allocate(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, GLuint const& typeSize, size_t const& nbVertex, std::vector<GLvoid*> const& data);
                    void allocateAndFill(GLuint typeSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data);
                    void access(GLenum const& vertexType, bool const& enableVAA = true) const;

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
