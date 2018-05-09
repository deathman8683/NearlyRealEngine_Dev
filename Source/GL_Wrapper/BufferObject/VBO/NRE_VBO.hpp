
    /**
     * @file NRE_VBO.hpp
     * @brief Declaration of Engine's GL's Object : VBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer/NRE_VertexBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/ColorBuffer/NRE_ColorBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer/NRE_NormalBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/MaterialBuffer/NRE_MaterialBuffer.hpp"
    #include "../../Buffer/AttributeBuffer/ArrayBuffer/UVBuffer/NRE_UVBuffer.hpp"

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
             * @enum VBOType
             * Describe the type of the current buffer (VBO or IBO)
             */
            enum VBOType {
                VERTEXBUFFEROBJECT,     /**< The Buffer is a VBO */
                INDEXBUFFEROBJECT       /**< The Buffer is an IBO */
            };

            /**
             * @class VBO
             * @brief GL's Object : Specialization of an BufferObject for vertex managing
             */
            class VBO : public BufferObject {
                private:
                    std::vector<ArrayBuffer*> attributes;   /**< The VBO's attributes array to store all needed buffer */
                    GLuint nb;                              /**< The VBO's number of vertex */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VBO();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        VBO(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        VBO(VBO const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        VBO(VBO && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VBO Deconstructor
                         */
                        virtual ~VBO();

                    //## Getter ##//
                        /**
                         * Return a specific arrayBuffer
                         * @param  index the arrayBuffer's index
                         * @return       the specific arrayBuffer
                         */
                        ArrayBuffer* const& getAttribute(GLuint const& index) const;
                        /**
                         * Nb getter
                         * @return return the vertexBuffer size
                         */
                        GLuint const& getNb() const;
                        /**
                         * Type getter
                         * @return if the current object is a VBO or an IBO
                         */
                        virtual VBOType const getType() const;

                    //## Setter ##//
                        /**
                         * Nb setter
                         * @param n the new vertexBuffer size
                         */
                        void setNb(GLuint const& n);

                    //## Methods ##//
                        /**
                         * Reload all buffer stored in the VBO
                         */
                        void reload();
                        /**
                         * Allocate the storage for all buffer stored in the VO
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param usage      the vbo's usage
                         */
                        void allocate(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage);
                        /**
                         * Update the vbo's storage
                         * @param offset     arrays of offset for all buffer
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param data       arrays of data for all buffer, vertex data must be in first
                         */
                        void update(std::vector<GLintptr> const& offset, GLuint const& vertexSize, size_t const& nbVertex, std::vector<GLvoid*> const& data);
                        /**
                         * ALlocate the storage and fill all buffer in the VBO
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param usage      the ibo's usage
                         * @param data       arrays of data for all buffer, vertex data must be in first
                         */
                        void allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data);
                        /**
                         * Store calls for VAO managing
                         * @param vertexType the vertex buffer type size
                         * @param enableVAA  tell if the function has to call glEnableVertexAttribArray
                         */
                        virtual void access(GLenum const& vertexType, bool const& enableVAA = true) const;
                        /**
                         * Push back an arrayBuffer into the VBO
                         * @param attr the arrayBuffer to add into the VBO
                         */
                        void push_back(ArrayBuffer* const& attr);
                        /**
                         * Return the size of the attributes vector
                         * @return the size of the VBO
                         */
                        GLuint const size() const;
                        /**
                         * Calls the OpenGL command to draw the buffer
                         */
                        virtual void draw() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the VBO to copy
                         */
                        VBO& operator=(VBO const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the VBO to move into this
                         * @return the reference of himself
                         */
                        VBO& operator=(VBO && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for VBO
             * @param stream the out stream to add the VBO buf
             * @param buf the VBO to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, VBO const& buf) {
                stream << "(";
                for (GLuint i = 0; i < buf.size() - 1; i = i + 1) {
                    stream << *(buf.getAttribute(i)) << ",";
                }
                stream << *(buf.getAttribute(buf.size() - 1)) << ")";
                return stream;
            }

        };
    };
