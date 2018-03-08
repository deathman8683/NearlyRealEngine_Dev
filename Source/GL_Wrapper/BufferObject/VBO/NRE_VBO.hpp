
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NBO/NRE_NBO.hpp"
    #include "Buffer/Color/NRE_ColorBuffer.hpp"

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
             * @brief GL's Object : Specialization of an BufferObject for colored vertex managing
             */
            class VBO : public NBO {
                protected:
                    NRE::Buffer::ColorBuffer color;

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
                    NRE::Buffer::ColorBuffer const& getColorBuffer() const;

                    //## Setter ##//
                    void setColorBuffer(NRE::Buffer::ColorBuffer const& buf);

                    //## Methods ##//
                    virtual void generateID();
                    virtual void deleteID();
                    virtual void reload();
                    void allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData);
                    void allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData);
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

            inline std::ostream& operator<<(std::ostream &stream, VBO const& buf) {
                stream << "(" << buf.getVertexBuffer() << buf.getColorBuffer() << buf.getNormalBuffer() << ")";
                return stream;
            }

        };
    };
