
    /**
     * @file NRE_Mesh.hpp
     * @brief Declaration of Engine's World's Object : Mesh
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Chunk/NRE_Chunk.hpp"
    #include "../NRE_World.hpp"
    #include <vector>
    #include <unordered_map>

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Module
         */
        namespace World {

            /**
             * @class Mesh
             * @brief World's Object : Manage object's rendering while creating their mesh with optimization
             */
            class Mesh {
                private:
                    Chunk* target;              /**< The chunk to build the mesh */
                    std::vector<GLint> vData;   /**< The vertex buffer */
                    std::vector<GLubyte> mData; /**< The material id buffer */
                    std::vector<GLbyte> nData;  /**< The normal buffer */
                    std::vector<GLuint> iData;  /**< The index buffer */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh();
                        /**
                         * Construct a mesh with a given target
                         * @param target the chunk to build the mesh
                         */
                        Mesh(Chunk* const& target);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param mesh the mesh to copy the content
                         */
                         Mesh(Mesh const& mesh) = delete;

                     //## Move-Constructor ##//
                         /**
                          * Move mesh into this, leaving reg empty
                          * @param mesh the mesh to move
                          */
                         Mesh(Mesh && mesh);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh Deconstructor
                         */
                        ~Mesh();

                    //## Getter ##//
                        /**
                         * Target getter
                         * @return the mesh target
                         */
                        Chunk* const& getTarget() const;
                        /**
                         * Vertex buffer getter
                         * @return the vertex data buffer
                         */
                        std::vector<GLint> const& getVData() const;
                        /**
                         * Material buffer getter
                         * @return the material data buffer
                         */
                        std::vector<GLubyte> const& getMData() const;
                        /**
                         * Normal buffer getter
                         * @return the normal data buffer
                         */
                        std::vector<GLbyte> const& getNData() const;
                        /**
                         * Index buffer getter
                         * @return the index data buffer
                         */
                        std::vector<GLuint> const& getIData() const;
                        /**
                         * Vertex buffer pointer getter
                         * @return a pointer to the first element from the vertex buffer
                         */
                        GLint* getVPointer();
                        /**
                         * Material buffer pointer getter
                         * @return a pointer to the first element from the material buffer
                         */
                        GLubyte* getMPointer();
                        /**
                         * Normal buffer pointer getter
                         * @return a pointer to the first element from the normal buffer
                         */
                        GLbyte* getNPointer();
                        /**
                         * Index buffer pointer getter
                         * @return a pointer to the first element from the index buffer
                         */
                        GLuint* getIPointer();

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Add a vertex into the vertex data buffer
                         * @param v the vertex to add
                         */
                        void addVertex(Maths::Point3D<GLint> const& v);
                        /**
                         * Add a material id into the material data buffer
                         * @param id the material id to add
                         */
                        void addMaterialID(GLubyte const& id);
                        /**
                         * Add a normal into the normal data buffer
                         * @param n the normal to add
                         */
                        void addNormal(Maths::Vector3D<GLbyte> const& n);
                        /**
                         * Add an index into the index data buffer
                         * @param index the index to add
                         */
                        void addIndex(GLuint const& index);
                        /**
                         * Construct the whole optimized chunk mesh
                         * @param w the world used to compute chunk border
                         */
                        void constructMesh(World* w);
                        /**
                         * Add a voxel into the mesh, compute several optimization like merging and culling
                         * @param w    the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @param rX   the voxel x coordinates in world referencial
                         * @param rY   the voxel y coordinates in world referencial
                         * @param rZ   the voxel z coordinates in world referencial
                         * @param face tell if each face of the voxel is visible or not
                         */
                        void addVoxel(World* w, GLuint const& x, GLuint const& y, GLuint const& z, GLint const& rX, GLint const& rY, GLint const& rZ, bool const (&face)[6]);
                        /**
                         * Merge a voxel face with direct neighboor, merge in line and then in column
                         * @param w    the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @param type the voxel type
                         * @param p    an array of point designating the 4 point of the mesh for the current voxel face
                         */
                        void mergeVoxels(World* w, GLuint x, GLuint y, GLuint z, GLint const& type, Maths::Point3D<GLint> (&p)[4], int const& face);
                        /**
                         * Add a vertex, a material id, an index and a normal into respective buffer
                         * @param p an array of point designating the 4 point of the mesh for the current voxel face
                         * @param face tell which face is added
                         * @param cCode tell the material id
                         */
                        void addPackedVertex(Maths::Point3D<GLint> const (&p)[4], GLuint const& face, size_t const& cCode);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param mesh the mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh const& mesh) = delete;
                        /**
                         * Move assigment of mesh into this, leaving mesh empty
                         * @param mesh the mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh && mesh);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    /**
                     * Check if the XNegative face is visible or not
                     * @param w the world used to compute chunk border
                     * @param x    the voxel x coordinates in chunk referencial
                     * @param y    the voxel y coordinates in chunk referencial
                     * @param z    the voxel z coordinates in chunk referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool checkVoxelXNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
                        /**
                         * Check if the XPositive face is visible or not
                         * @param w the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @return     if the voxel face is visible or not
                         */
                    bool checkVoxelXPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
                        /**
                         * Check if the YNegative face is visible or not
                         * @param w the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @return     if the voxel face is visible or not
                         */
                    bool checkVoxelYNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
                        /**
                         * Check if the YPositive face is visible or not
                         * @param w the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @return     if the voxel face is visible or not
                         */
                    bool checkVoxelYPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
                        /**
                         * Check if the ZNegative face is visible or not
                         * @param w the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @return     if the voxel face is visible or not
                         */
                    bool checkVoxelZNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
                        /**
                         * Check if the ZPositive face is visible or not
                         * @param w the world used to compute chunk border
                         * @param x    the voxel x coordinates in chunk referencial
                         * @param y    the voxel y coordinates in chunk referencial
                         * @param z    the voxel z coordinates in chunk referencial
                         * @return     if the voxel face is visible or not
                         */
                    bool checkVoxelZPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z);
            };

        };
    };
