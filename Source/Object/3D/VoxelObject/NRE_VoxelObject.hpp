
    /**
     * @file NRE_VoxelObject.hpp
     * @brief Declaration of Engine's Object's Object : VoxelObject
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "<Path>/Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief <Module_Desc>
         */
        namespace Object {

            /**
             * @class VoxelObject
             * @brief Object's Object : <Class_Desc>
             */
            class VoxelObject {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VoxelObject();

                    //## Copy-Constructor ##//
                        /**
                         * Copy o into this
                         * @param o the voxel object to copy the content
                         */
                        VoxelObject(VoxelObject const& o);

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

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of o into this
                         * @param o the voxel object to copy into this
                         * @return the reference of himself
                         */
                        VoxelObject& operator=(VoxelObject const& o);
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
