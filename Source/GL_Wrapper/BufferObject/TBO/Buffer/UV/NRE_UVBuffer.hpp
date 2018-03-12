
    /**
     * @file NRE_UVBuffer.hpp
     * @brief Declaration of Engine's GL's Object : UVBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../../Generic/NRE_Type.hpp"
    #include "../../../NBO/Buffer/NRE_Buffer.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace Buffer {

            /**
             * @class UVBuffer
             * @brief GL's Object : A specialized buffer for UV coord
             */
            class UVBuffer : public GL::Buffer {
                private:

                public:
                    //## Constructor ##//
                    UVBuffer();
                    UVBuffer(bool const& generate);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~UVBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target = GL_ARRAY_BUFFER) override;
                    void update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target = GL_ARRAY_BUFFER) override;
                    void allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target = GL_ARRAY_BUFFER) override;
                    void bind(GLenum const& target = GL_ARRAY_BUFFER) const override;
                    void unbind(GLenum const& target = GL_ARRAY_BUFFER) const override;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                public:
                    static GLenum TYPE;
                    static int SIZE;
            };

        };
    };
