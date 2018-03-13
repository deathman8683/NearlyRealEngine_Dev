
    /**
     * @file NRE_IBO.hpp
     * @brief Declaration of Engine's GL's Object : IBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../VBO/NRE_VBO.hpp"
    #include "../../Buffer/AttributeBuffer/IndexBuffer/NRE_IndexBuffer.hpp"

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
             * @class IBO
             * @brief GL's Object : Specialization of an BufferObject for vertex managing with indexing
             */
            class IBO : public VBO {
                private:
                    IndexBuffer index;
                    GLuint nb;

                public:
                    //## Constructor ##//
                    IBO();
                    IBO(bool const& generate);

                    //## Copy-Constructor ##//
                    IBO(IBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~IBO();

                    //## Getter ##//
                    IndexBuffer const& getIndexBuffer() const;
                    GLuint const& getNb() const;

                    //## Setter ##//
                    void setIndexBuffer(IndexBuffer const buf);
                    void setNb(GLuint const& n);

                    //## Methods ##//
                    void allocate(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage);
                    void update(GLintptr const& offset, GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, std::vector<GLvoid*> const& data, GLvoid* const& iData);
                    void allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, std::vector<GLvoid*> const& data, GLvoid* const& iData);
                    void access(GLenum const& vertexType, bool const& enableVAA = true) const override;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, IBO const& buf) {
                stream << "(";
                for (GLuint i = 0; i < buf.getAttributes().size(); i = i + 1) {
                    stream << *(buf.getAttribute(i)) << ",";
                }
                stream << buf.getIndexBuffer() << ")";
                return stream;
            }

        };
    };
