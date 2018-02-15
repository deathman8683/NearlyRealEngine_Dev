
    /**
     * @file NRE_ColorBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ColorBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../../Generic/NRE_Type.hpp"

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
                    ColorBuffer(bool const& generate = false);

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
