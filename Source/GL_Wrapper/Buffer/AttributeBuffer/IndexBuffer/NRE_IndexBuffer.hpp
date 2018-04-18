
    /**
     * @file NRE_VertexBuffer.hpp
     * @brief Declaration of Engine's GL's Object : IndexBuffer
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
             * @class IndexBuffer
             * @brief GL's Object : A specialized AttributeBuffer for vertex index managing
             */
            class IndexBuffer : public AttributeBuffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IndexBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        IndexBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        IndexBuffer(IndexBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        IndexBuffer(IndexBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IndexBuffer Deconstructor
                         */
                        ~IndexBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute type size, used with derived class
                         * @return the attribute type size
                         */
                        GLint const getTypeSize() const;
                        /**
                         * Return the attribute type enum, used with derived class
                         * @return the attribute type enum
                         */
                        GLenum const getType() const;
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        GLenum const getTarget() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Store calls for VAO managing
                         */
                        void access() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        IndexBuffer& operator=(IndexBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        IndexBuffer& operator=(IndexBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE;     /**< Index's type enum */
                    static GLint TYPESIZE;  /**< Index's type size */
            };

        };
    };
