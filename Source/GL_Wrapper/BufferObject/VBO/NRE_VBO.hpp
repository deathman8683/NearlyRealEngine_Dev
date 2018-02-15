
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../Buffer/VertexBuffer.hpp"
    #include "../Buffer/ColorBuffer.hpp"
    #include "../Buffer/NormalBuffer.hpp"
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
                    VBO();

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VBO();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

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
