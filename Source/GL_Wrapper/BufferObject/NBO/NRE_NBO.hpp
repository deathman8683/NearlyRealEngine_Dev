
    /**
     * @file NRE_NBO.hpp
     * @brief Declaration of Engine's GL's Object : NBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "Buffer/Vertex/NRE_VertexBuffer.hpp"
    #include "Buffer/Normal/NRE_NormalBuffer.hpp"
    #include "../NRE_BufferObject.hpp"

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
             * @class NBO
             * @brief GL's Object : Specialization of an BufferObject for position and normal managing
             */
            class NBO : public BufferObject{
                protected:
                    NRE::Buffer::VertexBuffer vertex;
                    NRE::Buffer::NormalBuffer normal;

                public:
                    //## Constructor ##//
                    NBO();
                    NBO(bool const& generate);

                    //## Copy-Constructor ##//
                    NBO(NBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~NBO();

                    //## Getter ##//
                    NRE::Buffer::VertexBuffer const& getVertexBuffer() const;
                    NRE::Buffer::NormalBuffer const& getNormalBuffer() const;

                    //## Setter ##//
                    void setVertexBuffer(NRE::Buffer::VertexBuffer const& buf);
                    void setNormalBuffer(NRE::Buffer::NormalBuffer const& buf);

                    //## Methods ##//
                    virtual void generateID();
                    virtual void deleteID();
                    virtual void reload();
                    void allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& nData);
                    void allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& nData);
                    virtual void access(GLenum const& vertexType, bool const& enableVAA = true) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, NBO const& buf) {
                stream << "(" << buf.getVertexBuffer() << buf.getNormalBuffer() << ")";
                return stream;
            }

        };
    };
