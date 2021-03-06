
    /**
     * @file NRE_Object3D.hpp
     * @brief Declaration of Engine's Object's Object : Object3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <assimp/Importer.hpp>
    #include <assimp/scene.h>
    #include <assimp/postprocess.h>
    #include "../NRE_Object.hpp"
    #include "../../IO/NRE_IO.hpp"
    #include "../../Exception/NRE_Exception.hpp"

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
             * @class Object3D
             * @brief Object's Object : Manage 3D object
             */
            class Object3D : public Object {
                protected:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object3D();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param o the 3D object to copy the content
                         */
                        Object3D(Object3D const& o) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the 3D object to move
                         */
                        Object3D(Object3D && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Object3D Deconstructor
                         */
                        virtual ~Object3D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Load the object from a given file
                         * @param usage the object's rendering usage
                         * @param file  the object's file path
                         */
                        void load(GLenum const& usage, IO::File const& file);
                        /**
                         * Process an Assimp node
                         * @param node  the assimp's node to process
                         * @param scene the assimp's scene (main node);
                         */
                        void processNode(aiNode *node, const aiScene *scene);
                        /**
                         * Process a NRE mesh from an Assimp mesh
                         * @param  mesh  the assimp's mesh to process
                         * @param  scene the assimp's scene (main node)
                         * @return       the resulting NRE mesh
                         */
                        Mesh3D* processMesh(aiMesh *mesh, const aiScene *scene);
                        /**
                         * Process a sphere into the current object
                         * @param usage the object's rendering usage
                         * @param radius  the sphere's radius
                         * @param rings   the sphere's number of rings
                         * @param sectors the sphere's number of sectors
                         * @param type    the sphere's material's type
                         */
                        void processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param o the 3D object to copy into this
                         * @return the reference of himself
                         */
                        Object3D& operator=(Object3D const& o) = delete;
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the 3D object to move into this
                         * @return the reference of himself
                         */
                        Object3D& operator=(Object3D && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
