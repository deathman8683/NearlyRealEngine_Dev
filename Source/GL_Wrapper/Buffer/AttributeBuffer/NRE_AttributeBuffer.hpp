
    /**
     * @file NRE_AttributeBuffer.hpp
     * @brief Declaration of Engine's GL's Object : AttributeBuffer
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
             * @class AttributeBuffer
             * @brief GL's Object : A specialized buffer for vertex attribute managing
             */
            class AttributeBuffer : public Buffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        AttributeBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        AttributeBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        AttributeBuffer(AttributeBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        AttributeBuffer(AttributeBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * AttributeBuffer Deconstructor
                         */
                        virtual ~AttributeBuffer();

                    //## Getter ##//
                        /**
                         * Return the attribute type size, used with derived class
                         * @return the attribute type size
                         */
                        virtual GLint const getTypeSize() const = 0;
                        /**
                         * Return the attribute type enum, used with derived class
                         * @return the attribute type enum
                         */
                        virtual GLenum const getType() const = 0;
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        virtual GLenum const getTarget() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        void generateID() override;
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        void deleteID() override;
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        void bind() const override;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        void unbind() const override;
                        /**
                         * Allocate the buffer with a given size and a specific usage
                         * @param size  the buffer's size
                         * @param usage the buffer's usage
                         */
                        void allocate(GLsizeiptr const& size, GLenum const& usage) const;
                        /**
                         * Update the buffer's data with a possible offset, the data's size, and a pointer to the data
                         * @param offset the data's offset
                         * @param size   the data's size
                         * @param data   the pointer to the data
                         */
                        void update(GLintptr const& offset, GLsizeiptr const& size, const GLvoid* const& data) const;
                        /**
                         * Allocate the buffer and send all data in the same time, need the data's size, the specific usage and a pointer to the data
                         * @param size  the buffer's size
                         * @param usage the buffer's usage
                         * @param data  the pointer to the data
                         */
                        void allocateAndFill(GLsizeiptr const& size, GLenum const& usage, const GLvoid* const& data) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        AttributeBuffer& operator=(AttributeBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        AttributeBuffer& operator=(AttributeBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
