
    /**
     * @file NRE_ColorBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ColorBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../../../Generic/NRE_Type.hpp"

    #define COLOR_BUFFER_SIZE sizeof(GLubyte)

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
             * @class ColorBuffer
             * @brief GL's Object : A specialized buffer for color
             */
            class ColorBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                    ColorBuffer();
                    ColorBuffer(bool const& generate);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~ColorBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
                    void reload() override;
                    void allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target = GL_ARRAY_BUFFER) override;
                    void update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target = GL_ARRAY_BUFFER) override;
                    void bind(GLenum const& target = GL_ARRAY_BUFFER) const override;
                    void unbind(GLenum const& target = GL_ARRAY_BUFFER) const override;

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
