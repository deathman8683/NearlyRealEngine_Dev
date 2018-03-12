
    /**
     * @file NRE_ITBO.hpp
     * @brief Declaration of Engine's GL's Object : ITBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../TBO/NRE_TBO.hpp"
    #include "../Buffer/Index/NRE_IndexBuffer.hpp"

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
             * @class ITBO
             * @brief GL's Object : Specialization of an BufferObject for textured vertex managing with indexing
             */
            class ITBO : public TBO {
                private:
                    NRE::Buffer::IndexBuffer index;
                    GLuint nb;

                public:
                    //## Constructor ##//
                    ITBO();
                    ITBO(bool const& generate);

                    //## Copy-Constructor ##//
                    ITBO(ITBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~ITBO();

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
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLvoid* const& vData, GLvoid* const& uvata, GLvoid* const& nData, GLvoid* const& iData);
                    void allocateAndFill(size_t typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& uvata, GLvoid* const& nData, GLvoid* const& iData);
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

            inline std::ostream& operator<<(std::ostream &stream, ITBO const& buf) {
                stream << "(" << buf.getVertexBuffer() << buf.getUVBuffer() << buf.getNormalBuffer() << buf.getIndexBuffer() << "," << buf.getNb() << ")";
                return stream;
            }

        };
    };
