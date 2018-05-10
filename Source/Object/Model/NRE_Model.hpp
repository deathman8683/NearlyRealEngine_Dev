
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

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Model();

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
                        Maths::Vector3D<GLuint> const& getSize() const;

                    //## Setter ##//

                    //## Methods ##//

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
