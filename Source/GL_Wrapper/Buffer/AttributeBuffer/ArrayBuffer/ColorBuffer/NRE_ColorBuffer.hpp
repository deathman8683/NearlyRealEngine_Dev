
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : ColorBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ArrayBuffer.hpp"

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
             * @brief GL's Object : A specialized ArrayBuffer for vertex color managing
             */
            class ColorBuffer : public ArrayBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ColorBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        ColorBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        ColorBuffer(ColorBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        ColorBuffer(ColorBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ColorBuffer Deconstructor
                         */
                        ~ColorBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute type size, used with derived class
                         * @return the attribute type size
                         */
                        GLint const getTypeSize() const;
                        /**
                         * Return the attribute number of component, used with derived class
                         * @return the attribute number of component
                         */
                        GLint const getSize() const;
                        /**
                         * Return the attribute type enum, used with derived class
                         * @return the attribute type enum
                         */
                        GLenum const getType() const;
                        /**
                         * Return the attribute shader's index, used with derived class
                         * @return the attribute shader's index
                         */
                        GLint const getIndex() const;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        ColorBuffer& operator=(ColorBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        ColorBuffer& operator=(ColorBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLint INDEX;     /**< Color's shader's index */
                    static GLenum TYPE;     /**< Color's type enum */
                    static GLint TYPESIZE;  /**< Color's type size */
                    static GLint SIZE;      /**< Color's number of component */
            };

        };
    };
