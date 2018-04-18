
    /**
     * @file NRE_IBO.hpp
     * @brief Declaration of Engine's GL's Object : IBO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../VBO/NRE_VBO.hpp"
    #include "../../Buffer/AttributeBuffer/IndexBuffer/NRE_IndexBuffer.hpp"

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
             * @class IBO
             * @brief GL's Object : Specialization of an BufferObject for vertex managing with indexing
             */
            class IBO : public VBO {
                private:
                    IndexBuffer index;  /**< The IBO's indexBuffer */
                    GLuint nb;          /**< The IBO's indexBuffer's size */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IBO();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        IBO(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        IBO(IBO const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        IBO(IBO && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IBO Deconstructor
                         */
                        ~IBO();

                    //## Getter ##//
                        /**
                         * IndexBuffer getter
                         * @return the indexBuffer object
                         */
                        IndexBuffer const& getIndexBuffer() const;
                        /**
                         * Nb getter
                         * @return return the indexBuffer size
                         */
                        GLuint const& getNb() const;

                    //## Setter ##//
                        /**
                         * Nb setter
                         * @param n the new indexBuffer size
                         */
                        void setNb(GLuint const& n);

                    //## Methods ##//
                        /**
                         * Reload all buffer stored in the IBO
                         */
                        void reload();
                        /**
                         * Allocate the storage for all buffer stored in the IBO
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param nbIndex    the number of index to store
                         * @param usage      the ibo's usage
                         */
                        void allocate(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage);
                        /**
                         * Update the ibo's storage
                         * @param offset     the offset in the buffer
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param nbIndex    the number of index to store
                         * @param data       arrays of data for all buffer
                         * @param iData      the index data
                         */
                        void update(GLintptr const& offset, GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, std::vector<GLvoid*> const& data, GLvoid* const& iData);
                        /**
                         * ALlocate the storage and fill all buffer in the IBO
                         * @param vertexSize the vertex type size
                         * @param nbVertex   the number of vertex to store
                         * @param nbIndex    the number of index to store
                         * @param usage      the ibo's usage
                         * @param data       arrays of data for all buffer
                         * @param iData      the index data
                         */
                        void allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, std::vector<GLvoid*> const& data, GLvoid* const& iData);
                        /**
                         * Store calls for VAO managing
                         * @param vertexType the vertex buffer type size
                         * @param enableVAA  tell if the function has to call glEnableVertexAttribArray
                         */
                        void access(GLenum const& vertexType, bool const& enableVAA = true) const override;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the IBO to copy
                         */
                        IBO& operator=(IBO const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the IBO to move into this
                         * @return the reference of himself
                         */
                        IBO& operator=(IBO && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for IBO
             * @param stream the out stream to add the IBO buf
             * @param buf the IBO to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, IBO const& buf) {
                stream << "(";
                for (GLuint i = 0; i < buf.getAttributes().size(); i = i + 1) {
                    stream << *(buf.getAttribute(i)) << ",";
                }
                stream << buf.getIndexBuffer() << ")";
                return stream;
            }

        };
    };
