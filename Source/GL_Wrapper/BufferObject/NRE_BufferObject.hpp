
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
                    bool allocated; /**< The object allocation state */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BufferObject();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the object to copy
                         */
                        BufferObject(BufferObject const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the object to move
                         */
                        BufferObject(BufferObject && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * BufferObject Deconstructor
                         */
                        virtual ~BufferObject();

                    //## Getter ##//
                        /**
                         * Return the allocation's state of this
                         * @return the allocation state
                         */
                        bool const& isAllocated() const;

                    //## Setter ##//
                        /**
                         * Allocate setter
                         * @param state the new allocation state
                         */
                        void setAllocated(bool const& state);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the object to copy
                         */
                        BufferObject& operator=(BufferObject const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the object to move into this
                         * @return the reference of himself
                         */
                        BufferObject& operator=(BufferObject && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
