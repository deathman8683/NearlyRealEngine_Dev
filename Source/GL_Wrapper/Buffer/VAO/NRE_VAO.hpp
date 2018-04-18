
    /**
     * @file NRE_ArrayBuffer.hpp
     * @brief Declaration of Engine's GL's Object : VAO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../BufferObject/VBO/NRE_VBO.hpp"

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
             * @class VAO
             * @brief GL's Object : A specialized buffer for VAO managing
             */
            class VAO : public Buffer {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VAO();
                        /**
                         * Construct the vao and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        VAO(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the vao to copy
                         */
                        VAO(VAO const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the vao to move
                         */
                        VAO(VAO && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VAO Deconstructor
                         */
                        ~VAO();

                    //## Getter ##//

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
                         * Access all VBO's buffer to bind the vao with all buffers
                         * @param buffer     the VBO to access and bind
                         * @param vertexType the vertex type inside the VBO
                         * @param enableVAA tell if the function has to call glEnableVertexAttribArray
                         */
                        void access(VBO const& buffer, GLenum const& vertexType, bool const& enableVAA = true) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the vao to copy
                         */
                        VAO& operator=(VAO const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the vao to move into this
                         * @return the reference of himself
                         */
                        VAO& operator=(VAO && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
