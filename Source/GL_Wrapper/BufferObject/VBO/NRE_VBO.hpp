
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer/NRE_VertexBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/ColorBuffer/NRE_ColorBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer/NRE_NormalBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/MaterialBuffer/NRE_MaterialBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/UVBuffer/NRE_UVBuffer.hpp"

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
                    virtual ~VBO();

                    //## Getter ##//
                    std::vector<ArrayBuffer*> const& getAttributes() const;
                    ArrayBuffer* const& getAttribute(GLuint const& index) const;

                    //## Setter ##//
                    void setAttributes(std::vector<ArrayBuffer*> const& attr);
                    void setAttribute(GLuint const& index, ArrayBuffer* const& attr);

                    //## Methods ##//
                    void reload();
                    void allocate(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, GLuint const& vertexSize, size_t const& nbVertex, std::vector<GLvoid*> const& data);
                    void allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data);
                    virtual void access(GLenum const& vertexType, bool const& enableVAA = true) const;
                    void push_back(ArrayBuffer* const& attr);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, VBO const& buf) {
                stream << "(";
                for (GLuint i = 0; i < buf.getAttributes().size() - 1; i = i + 1) {
                    stream << *(buf.getAttribute(i)) << ",";
                }
                stream << *(buf.getAttribute(buf.getAttributes().size() - 1)) << ")";
                return stream;
            }

        };
    };
