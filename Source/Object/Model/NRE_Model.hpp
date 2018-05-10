
    /**
     * @file NRE_Model.hpp
     * @brief Declaration of Engine's Object's Object : Model
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../World/Voxel/NRE_Voxel.hpp"
    #include "../../Generic/Array/NRE_ArrayOperation.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../../lib/FastNoise/FastNoise.h"

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
             * @class Model
             * @brief Object's Object : Manage voxels storing for an object 3D model
             */
            class Model {
                private:
                    World::Voxel* voxels;           /**< The model's voxels */
                    Maths::Vector3D<GLuint> size;   /**< The model's size */
                    GLuint maxSolidHeight;          /**< The maximum height with solid voxel */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Model();
                        /**
                         * Construct a model with a given size
                         * @param size the model's size
                         */
                        Model(Maths::Vector3D<GLuint> const& size);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the model to copy the content
                         */
                        Model(Model const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the model to move
                         */
                        Model(Model && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Model Deconstructor
                         */
                        ~Model();

                    //## Getter ##//
                        /**
                         * Specific Voxel getter
                         * @param  p the voxel's coordinates
                         * @return   the corresponding voxel
                         */
                        World::Voxel const& getVoxel(Maths::Point3D<GLuint> const& p) const;
                        /**
                         * Specific Voxel getter
                         * @param  x the voxel's x coordinate
                         * @param  y the voxel's y coordinate
                         * @param  z the voxel's z coordinate
                         * @return   the corresponding voxel
                         */
                        World::Voxel const& getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
                        /**
                         * Specific Voxel getter
                         * @param  index the already computed voxel index (3D to 1D)
                         * @return       the corresponding voxel
                         */
                        World::Voxel const& getVoxel(GLuint const& index) const;
                        /**
                         * Compute the voxel 1D index from 3D coordinates
                         * @param  x the voxel's x coordinate
                         * @param  y the voxel's y coordinate
                         * @param  z the voxel's z coordinate
                         * @return   the computed index using array operation function
                         */
                        GLuint const getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) const;
                        /**
                         * Size getter
                         * @return the model's size
                         */
                        Maths::Vector3D<GLuint> const& getSize() const;
                        /**
                         * Maximum solid voxel height getter
                         * @return the model's maximum height of solid voxel
                         */
                        GLuint const& getMaxSolidHeight() const;

                    //## Setter ##//
                        /**
                         * Maximum solid voxel height setter
                         * @param height the new maximum solid voxel height value
                         */
                        void setMaxSolidHeight(GLuint const& height);

                    //## Methods ##//
                        /**
                         * Load a number of voxel with a based coordinate and a type
                         * @param x    the first voxel x coordinate
                         * @param y    the first voxel y coordinate
                         * @param z    the first voxel z coordinate
                         * @param nb   the number of voxel to add, used to increment through coordinates
                         * @param type the voxel's type to add
                         */
                        void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type);
                        /**
                         * Construct a procedural terrain from a custom generator using FastNoise library
                         * @param soilGenerator     the soil generator
                         * @param moistureGenerator the moisture generator
                         * @param coord             the model's coordinate
                         */
                        void createProceduralTerrain(FastNoise const& soilGenerator, FastNoise const& moistureGenerator, Maths::Point2D<GLint> const& coord);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the model to copy into this
                         * @return the reference of himself
                         */
                        Model& operator=(Model const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the model to move into this
                         * @return the reference of himself
                         */
                        Model& operator=(Model && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
