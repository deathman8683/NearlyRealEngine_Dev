
    /**
     * @file NRE_IBO.hpp
     * @brief Declaration of Engine's GL's Object : IBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "Buffer/Index/NRE_IndexBuffer.hpp"
    #include "../VBO/NRE_VBO.hpp"

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
                    NRE::Buffer::IndexBuffer index;
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
                    NRE::Buffer::IndexBuffer const& getIndexBuffer() const;
                    GLuint const& getNb() const;

                    //## Setter ##//
                    void setIndexBuffer(NRE::Buffer::IndexBuffer const& buf);
                    void setNb(GLuint const& n);

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void reload() override;
                    void allocate(size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage);
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData);
                    void allocateAndFill(size_t typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData);
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
                stream << "(" << buf.getVertexBuffer() << buf.getColorBuffer() << buf.getNormalBuffer() << buf.getIndexBuffer() << "," << buf.getNb() << ")";
                return stream;
            }

        };
    };
