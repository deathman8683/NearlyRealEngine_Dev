
    /**
     * @file NRE_VoxelMesh.hpp
     * @brief Declaration of Engine's Object's Object : VoxelMesh
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Mesh3D.hpp"
    #include "../../../VoxelSet/NRE_VoxelSet.hpp"
    #include "../../../MergingCache/NRE_MergingCache.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system>
         */
        namespace Object {

            /**
             * @class VoxelMesh
             * @brief Object's Object : A 3D voxel mesh used in voxel object rendering
             */
            class VoxelMesh : public Mesh3D {
                private:
                    const VoxelSet* target;    /**< The mesh's set */
                    const VoxelSet* left;      /**< The mesh's set left neighbor */
                    const VoxelSet* right;     /**< The mesh's set right neighbor */
                    const VoxelSet* front;     /**< The mesh's set front neighbor */
                    const VoxelSet* back;      /**< The mesh's set back neighbor */
                    const VoxelSet* up;        /**< The mesh's set up neighbor */
                    const VoxelSet* bottom;    /**< The mesh's set bottom neighbor */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VoxelMesh();
                        VoxelMesh(const VoxelSet* const set);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param m the voxel mesh to copy the content
                         */
                        VoxelMesh(VoxelMesh const& m) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the voxel mesh to move
                         */
                        VoxelMesh(VoxelMesh && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VoxelMesh Deconstructor
                         */
                        ~VoxelMesh();

                    //## Getter ##//

                    //## Setter ##//
                        /**
                         * Left setter
                         * @param set the new left's set
                         */
                        void setLeft(const VoxelSet* const set);
                        /**
                         * Right setter
                         * @param set the new right's set
                         */
                        void setRight(const VoxelSet* const set);
                        /**
                         * Front setter
                         * @param set the new front's set
                         */
                        void setFront(const VoxelSet* const set);
                        /**
                         * Back setter
                         * @param set the new back's set
                         */
                        void setBack(const VoxelSet* const set);
                        /**
                         * Up setter
                         * @param set the new up's set
                         */
                        void setUp(const VoxelSet* const set);
                        /**
                         * Bottom setter
                         * @param set the new bottom's set
                         */
                        void setBottom(const VoxelSet* const set);

                    //## Methods ##//
                        /**
                         * Construct the mesh and create the graphical model from the target's model
                         * @param usage  the buffer's usage
                         * @param coord  the model's coordinates
                         */
                        void process(GLenum const& usage, Maths::Point2D<GLint> const& coord);
                        /**
                         * Add a voxel into the mesh, compute several optimization like merging and culling
                         * @param x    the voxel x coordinates in model referencial
                         * @param y    the voxel y coordinates in model referencial
                         * @param z    the voxel z coordinates in model referencial
                         * @param rX   the voxel x coordinates in world referencial
                         * @param rY   the voxel y coordinates in world referencial
                         * @param rZ   the voxel z coordinates in world referencial
                         * @param face tell if each face of the voxel is visible or not
                         */
                        void addVoxel(GLuint const& x, GLuint const& y, GLuint const& z, GLint const& rX, GLint const& rY, GLint const& rZ, bool const (&face)[6]);
                        /**
                         * Merge a voxel face with direct neighbor, merge in line and then in column
                         * @param x    the voxel x coordinates in model referencial
                         * @param y    the voxel y coordinates in model referencial
                         * @param z    the voxel z coordinates in model referencial
                         * @param type the voxel type
                         * @param p    an array of point designating the 4 point of the mesh for the current voxel face
                         * @param face tell which face is being merged
                         */
                        void mergeVoxels(GLuint x, GLuint y, GLuint z, GLint const& type, Maths::Point3D<GLint> (&p)[4], int const& face);
                        /**
                         * Add a vertex, a material id, an index and a normal into respective buffer
                         * @param p     an array of point designating the 4 point of the mesh for the current voxel face
                         * @param face  tell which face is added
                         * @param cCode tell the material id
                         */
                        void addPackedVertex(Maths::Point3D<GLint> const (&p)[4], GLuint const& face, size_t const& cCode);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param m the voxel mesh to copy into this
                         * @return the reference of himself
                         */
                        VoxelMesh& operator=(VoxelMesh const& m) = delete;
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the voxel mesh to move into this
                         * @return the reference of himself
                         */
                        VoxelMesh& operator=(VoxelMesh && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    /**
                     * Check if the XNegative face is visible or not
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelXNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z);
                    /**
                     * Check if the XPositive face is visible or not
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelXPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z);
                    /**
                     * Check if the YNegative face is visible or not
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelYNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z);
                    /**
                     * Check if the YPositive face is visible or not
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelYPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z);
                    /**
                     * Check if the ZNegative face is visible or not
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelZNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z);
                    /**
                     * Check if the ZPositive face is visible or not²
                     * @param x    the voxel x coordinates in model referencial
                     * @param y    the voxel y coordinates in model referencial
                     * @param z    the voxel z coordinates in model referencial
                     * @return     if the voxel face is visible or not
                     */
                    bool const checkVoxelZPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z);
            };

        };
    };
