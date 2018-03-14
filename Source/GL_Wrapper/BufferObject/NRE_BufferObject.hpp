
    /**
     * @file NRE_BufferObject.hpp
     * @brief Declaration of Engine's GL's Object : BufferObject
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

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
             * @class BufferObject
             * @brief GL's Object : Base for openGL advanced buffer object
             */
            class BufferObject {
                private:
                    bool allocated;

                public:
                    //## Constructor ##//
                    BufferObject();

                    //## Copy-Constructor ##//
                    BufferObject(BufferObject const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~BufferObject();

                    //## Getter ##//
                    bool const& isAllocated() const;

                    //## Setter ##//
                    void setAllocated(bool const& state);

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
