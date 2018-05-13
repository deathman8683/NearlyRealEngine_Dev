
    /**
     * @file NRE_Mesh3D.hpp
     * @brief Declaration of Engine's Object's Object : Mesh3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Mesh.hpp"
    #include "../../../Maths/NRE_Maths.hpp"
    #include "../../Model/NRE_Model.hpp"
    #include "../../MergingCache/NRE_MergingCache.hpp"

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
             * @class Mesh3D
             * @brief Object's Object : A 3D mesh used in 3D object rendering
             */
            class Mesh3D : public Mesh {
                private:
                    const Model* target;    /**< The mesh's model */
                    const Model* left;      /**< The mesh's model left neighbor */
                    const Model* right;     /**< The mesh's model right neighbor */
                    const Model* front;     /**< The mesh's model front neighbor */
                    const Model* back;      /**< The mesh's model back neighbor */
                    const Model* up;        /**< The mesh's model up neighbor */
                    const Model* bottom;    /**< The mesh's model bottom neighbor */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh3D();
                        /**
                         * Construct a 3D mesh with a given vertex data type
                         * @param type the vertex data type
                         */
                        Mesh3D(GLenum const& type);
                        /**
                         * Construct a 3D mesh with a given target and his neighboors
                         * @param type the vertex data type
                         * @param target the mesh's model to manage
                         * @param left   the mesh's model left neighbor
                         * @param right  the mesh's model right neighbor
                         * @param front  the mesh's model front neighbor
                         * @param back   the mesh's model back neighbor
                         * @param up     the mesh's model up neighbor
                         * @param bottom the mesh's model bottom neighbor
                         */
                        Mesh3D(GLenum const& type, const Model* target, const Model* left, const Model* right, const Model* front, const Model* back, const Model* up, const Model* bottom);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the 3D mesh to copy the content
                         */
                        Mesh3D(Mesh3D const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the 3D mesh to move
                         */
                        Mesh3D(Mesh3D && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh3D Deconstructor
                         */
                        ~Mesh3D();

                    //## Getter ##//

                    //## Setter ##//
                        /**
                         * Left setter
                         * @param model the new left's model
                         */
                        void setLeft(const Model* const model);
                        /**
                         * Right setter
                         * @param model the new right's model
                         */
                        void setRight(const Model* const model);
                        /**
                         * Front setter
                         * @param model the new front's model
                         */
                        void setFront(const Model* const model);
                        /**
                         * Back setter
                         * @param model the new back's model
                         */
                        void setBack(const Model* const model);
                        /**
                         * Up setter
                         * @param model the new up's model
                         */
                        void setUp(const Model* const model);
                        /**
                         * Bottom setter
                         * @param model the new bottom's model
                         */
                        void setBottom(const Model* const model);

                    //## Methods ##//
                        /**
                         * Construct the mesh and create the graphical model from the target's model
                         * @param buffer the buffer to fill
                         * @param usage  the buffer's usage
                         * @param coord  the model's coordinates
                         */
                        void process(GL::IBO& buffer, GLenum const& usage, Maths::Point2D<GLint> const& coord);
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
                        /**
                         * Process a sphere with given parameters
                         * @param buffer  the buffer to fill
                         * @param usage   the buffer's usage
                         * @param radius  the sphere's radius
                         * @param rings   the sphere's number of rings
                         * @param sectors the sphere's number of sectors
                         * @param type    the sphere's material's type
                         */
                        void processSphere(GL::IBO& buffer, GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the 3D mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh3D& operator=(Mesh3D const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the 3D mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh3D& operator=(Mesh3D && m);

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
