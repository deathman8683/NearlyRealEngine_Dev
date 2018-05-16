
    /**
     * @file NRE_MeshLoader.hpp
     * @brief Declaration of Engine's Object's Object : MeshLoader
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include <algorithm>
    #include "../3D/NRE_Mesh3D.hpp"
    #include "../../../Exception/IOException/NRE_IOException.hpp"

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
             * @class MeshLoader
             * @brief Object's Object : Manage the loading system for 3D mesh, manage obj file
             */
            class MeshLoader {
                private:
                    Mesh3D* target;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        MeshLoader();
                        /**
                         * Construct a mesh loader with the mesh target and mesh's file's path
                         * @param mesh the loading target
                         * @param path  the mesh's file's path
                         */
                        MeshLoader(Mesh3D* mesh, std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * Copy ml into this
                         * @param ml the mesh loader to copy the content
                         */
                        MeshLoader(MeshLoader const& ml);

                    //## Move-Constructor ##//
                        /**
                         * Move ml into this, leaving ml empty
                         * @param ml the mesh loader to move
                         */
                        MeshLoader(MeshLoader && ml);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * MeshLoader Deconstructor
                         */
                        ~MeshLoader();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Load the mesh from a given file
                         * @param path the mesh's file's path
                         */
                        void load(std::string const& path);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of ml into this
                         * @param ml the mesh loader to copy into this
                         * @return the reference of himself
                         */
                        MeshLoader& operator=(MeshLoader const& ml);
                        /**
                         * Move assigment of ml into this, leaving ml empty
                         * @param ml the mesh loader to move into this
                         * @return the reference of himself
                         */
                        MeshLoader& operator=(MeshLoader && ml);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
