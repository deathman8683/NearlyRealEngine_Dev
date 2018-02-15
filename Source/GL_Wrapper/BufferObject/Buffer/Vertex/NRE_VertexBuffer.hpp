
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : VertexBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../../../Generic/NRE_Type.hpp"

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
             * @class VertexBuffer
             * @brief GL's Object : A specialized buffer for vertex
             */
            template <class T>
            class VertexBuffer : public Buffer {
                private:
                    GLenum type;

                public:
                    //## Constructor ##//
                    VertexBuffer(GLenum const& type, bool const& generate = false);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VertexBuffer();

                    //## Getter ##//
                    GLenum const& getType() const;

                    //## Setter ##//
                    void setType(GLenum const& type);

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void reload() override;
                    void allocate(unsigned int const& vertices, GLenum const& usage) override;
                    void update(unsigned int const& vertices, GLvoid* const data) override;

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

    #include "NRE_VertexBuffer.tpp"
