
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ArrayBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_AttributeBuffer.hpp"

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
             * @brief GL's Object : A specialized AttributeBuffer for vertex array attribute managing
             */
            class ArrayBuffer : public AttributeBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ArrayBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        ArrayBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        ArrayBuffer(ArrayBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        ArrayBuffer(ArrayBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ArrayBuffer Deconstructor
                         */
                        virtual ~ArrayBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute number of component, used with derived class
                         * @return the attribute number of component
                         */
                        virtual GLint const getSize() const = 0;
                        /**
                         * Return the attribute shader's index, used with derived class
                         * @return the attribute shader's index
                         */
                        virtual GLint const getIndex() const = 0;
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        GLenum const getTarget() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Store calls for VAO managing
                         * @param type the attribute type enum
                         * @param index the attribute shader's index
                         * @param size the attribute type size
                         * @param enableVAA tell if the function has to call glEnableVertexAttribArray
                         */
                        void access(GLenum const& type, GLint const& index, GLint const& size, bool const& enableVAA);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        ArrayBuffer& operator=(ArrayBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        ArrayBuffer& operator=(ArrayBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
