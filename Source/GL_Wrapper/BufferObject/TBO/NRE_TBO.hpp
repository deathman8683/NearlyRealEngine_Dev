
    /**
     * @file NRE_TBO.hpp
     * @brief Declaration of Engine's GL's Object : TBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NBO/NRE_NBO.hpp"
    #include "Buffer/UV/NRE_UVBuffer.hpp"

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
             * @class TBO
             * @brief GL's Object : Specialization of an BufferObject for textured vertex managing
             */
            class TBO : public NBO {
                protected:
                    NRE::Buffer::UVBuffer uv;

                public:
                    //## Constructor ##//
                    TBO();
                    TBO(bool const& generate);

                    //## Copy-Constructor ##//
                    TBO(TBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~TBO();

                    //## Getter ##//
                    NRE::Buffer::UVBuffer const& getUVBuffer() const;

                    //## Setter ##//
                    void setUVBuffer(NRE::Buffer::UVBuffer const& buf);

                    //## Methods ##//
                    virtual void generateID();
                    virtual void deleteID();
                    virtual void reload();
                    void allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData);
                    void allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData);
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

            inline std::ostream& operator<<(std::ostream &stream, TBO const& buf) {
                stream << "(" << buf.getVertexBuffer() << buf.getUVBuffer() << buf.getNormalBuffer() << ")";
                return stream;
            }

        };
    };
