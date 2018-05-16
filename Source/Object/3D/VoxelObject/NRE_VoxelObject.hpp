
    /**
     * @file NRE_VoxelObject.hpp
     * @brief Declaration of Engine's Object's Object : VoxelObject
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Object3D.hpp"
    #include "../../VoxelSet/NRE_VoxelSet.hpp"

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
             * @class VoxelObject
             * @brief Object's Object : Manage a voxel type object
             */
            class VoxelObject : public Object3D {
                protected:
                    std::vector<VoxelSet> voxelSets;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VoxelObject();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param o the voxel object to copy the content
                         */
                        VoxelObject(VoxelObject const& o) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the voxel object to move
                         */
                        VoxelObject(VoxelObject && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VoxelObject Deconstructor
                         */
                        ~VoxelObject();

                    //## Getter ##//
                        VoxelSet const& getVoxelSet(GLuint const& index) const;

                    //## Setter ##//
                        void setLeft(GLuint const& index, VoxelSet const& s);
                        void setRight(GLuint const& index, VoxelSet const& s);
                        void setFront(GLuint const& index, VoxelSet const& s);
                        void setBack(GLuint const& index, VoxelSet const& s);
                        void setUp(GLuint const& index, VoxelSet const& s);
                        void setBottom(GLuint const& index, VoxelSet const& s);

                    //## Methods ##//
                        /**
                         * Save the current object's voxelSet into a given file
                         * @param path the file's path
                         */
                        void save(std::string const& path) const;
                        /**
                         * Load the current object's voxelSet from a given file
                         * @param path the file's path
                         */
                        void load(std::string const& path);
                        /**
                         * Process the object's mesh
                         * @param usage the object's rendering usage
                         * @param coord the object's chunk's coordinates
                         */
                        void process(GLenum const& usage, Maths::Point2D<GLint> const& coord);
                        /**
                         * Load a given number of voxels in the file
                         * @param index the voxels set index
                         * @param x     the start x coordinates
                         * @param y     the start y coordinates
                         * @param z     the start z coordinates
                         * @param nb    the number of voxels  to load
                         * @param type  the voxel's type
                         */
                        void loadVoxels(GLuint const& index, GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLubyte const& type);
                        void push_back(Maths::Vector3D<GLuint> const& size);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param o the voxel object to copy into this
                         * @return the reference of himself
                         */
                        VoxelObject& operator=(VoxelObject const& o) = delete;
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the voxel object to move into this
                         * @return the reference of himself
                         */
                        VoxelObject& operator=(VoxelObject && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
