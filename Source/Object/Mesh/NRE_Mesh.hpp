
    /**
     * @file NRE_Mesh.hpp
     * @brief Declaration of Engine's Object's Object : Mesh
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "Data/NRE_Data.hpp"
    #include "Data/IntVertexData/NRE_IntVertexData.hpp"
    #include "Data/FloatVertexData/NRE_FloatVertexData.hpp"
    #include "Data/MaterialData/NRE_MaterialData.hpp"
    #include "Data/NormalData/NRE_NormalData.hpp"
    #include "Data/TangentData/NRE_TangentData.hpp"
    #include "Data/IndexData/NRE_IndexData.hpp"
    #include "Data/UVData/NRE_UVData.hpp"
    #include "Data/ColorData/NRE_ColorData.hpp"
    #include "../../GL_Wrapper/BufferObject/IBO/NRE_IBO.hpp"
    #include "../../GL_Wrapper/Buffer/VAO/NRE_VAO.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system
         */
        namespace Object {

            /**
             * @class Mesh
             * @brief Object's Object : Base class for 2D and 3D mesh specialization
             */
            class Mesh {
                protected:
                    GL::VBO* buffer;                /**< The mesh's rendering buffer */
                    GL::VAO vao;                    /**< The mesh's rendering VAO */
                    std::vector<DataSet*> data;     /**< The mesh's array of data set fill with a model information */
                    GLenum type;                    /**< The mesh's vertex data type */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh() = delete;
                        /**
                         * Construct a mesh with a base vertex data
                         * @param type the vertex data type
                         */
                        Mesh(GLenum const& type);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param m the mesh to copy the content
                         */
                        Mesh(Mesh const& m) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the mesh to move
                         */
                        Mesh(Mesh && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh Deconstructor
                         */
                        virtual ~Mesh();

                    //## Getter ##//
                        /**
                         * DataSet getter
                         * @param  index the data set index
                         * @return       the corresponding data set
                         */
                        const DataSet* const getDataSet(GLuint const& index) const;
                        /**
                         * Type getter
                         * @return the mesh's vertex data type enum
                         */
                        GLenum const& getType() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Push back a dataset into the mesh
                         * @param d the dateset to add into the mesh
                         */
                        void push_back(DataSet* const& d);
                        /**
                         * Add a set of value into a specific DataSet
                         * @param index   the dataSet's index in the mesh
                         * @param value   the pointer to the set of value
                         * @param nbValue the number of value to add
                         */
                        void add(GLuint const& index, const GLvoid* const value, GLuint const& nbValue = 1) const;
                        /**
                         * Update the VBO with mesh's data
                         * @param offset a set of offset to pass to VBO's update
                         */
                        void update(std::vector<GLintptr> const& offset);
                        /**
                         * Update the VBO with mesh's data and null offset
                         */
                        void update();
                        /**
                         * Allocate and fill the VBO with mesh's data
                         * @param usage  the buffer's usage
                         */
                        void allocateAndFill(GLenum const& usage);
                        /**
                         * Clear all data set
                         */
                        void clear();
                        /**
                         * Draw the current mesh, need to be call from a rendering context (Shader bind)
                         */
                        void draw() const;
                        /**
                         * Bind the VAO to the object Buffer using the mesh data type
                         */
                        void access();
                        /**
                         * Reload the mesh
                         */
                        void reload();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param m the mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh const& m) = delete;
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    /**
                     * Update the VBO with mesh's data
                     * @param offset a set of offset to pass to VBO's update
                     */
                    void updateVBO(std::vector<GLintptr> const& offset) const;
                    /**
                     * Update the IBO with mesh's data
                     * @param offset a set of offset to pass to VBO's update
                     */
                    void updateIBO(std::vector<GLintptr> const& offset) const;
                    /**
                     * @param buffer the buffer to allocate and fill
                     * @param usage  the buffer's usage
                     */
                    void allocateAndFillVBO(GLenum const& usage) const;
                    /**
                     * @param buffer the buffer to allocate and fill
                     * @param usage  the buffer's usage
                     */
                    void allocateAndFillIBO(GLenum const& usage) const;
            };

        };
    };
