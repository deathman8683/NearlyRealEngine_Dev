
    /**
     * @file NRE_ArrayBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ArrayBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"

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
             * @class ArrayBuffer
             * @brief GL's Object : A specialized buffer for VAO managing
             */
            class ArrayBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                    ArrayBuffer();
                    ArrayBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    ArrayBuffer(ArrayBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~ArrayBuffer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                    void generateID() override;
                    void deleteID() override;
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

        };
    };
