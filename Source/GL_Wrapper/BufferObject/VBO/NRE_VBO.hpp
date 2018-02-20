
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../Buffer/Vertex/NRE_VertexBuffer.hpp"
    #include "../Buffer/Color/NRE_ColorBuffer.hpp"
    #include "../Buffer/Normal/NRE_NormalBuffer.hpp"
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
             * @class VBO
             * @brief GL's Object : Specialization of an BufferObject for vertex managing
             */
            class VBO : public BufferObject{
                private:
                    VertexBuffer vertex;
                    ColorBuffer color;
                    NormalBuffer normal;

                public:
                    //## Constructor ##//
                    VBO(bool const& generate = false);

                    //## Copy-Constructor ##//
                    VBO(VBO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VBO();

                    //## Getter ##//
                    VertexBuffer const& getVertexBuffer() const;
                    ColorBuffer const& getColorBuffer() const;
                    NormalBuffer const& getNormalBuffer() const;

                    //## Setter ##//
                    void setVertexBuffer(VertexBuffer const& buf);
                    void setColorBuffer(ColorBuffer const& buf);
                    void setNormalBuffer(NormalBuffer const& buf);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void reload();
                    void allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage);
                    void update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData);
                    void bind() const;
                    void unbind() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            std::ostream& operator<<(std::ostream &stream, VBO const& buf);

        };
    };
