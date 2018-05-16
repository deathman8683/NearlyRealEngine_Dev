
    /**
     * @file NRE_Object.hpp
     * @brief Declaration of Engine's Object's Object : Object
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Generic/NRE_Type.hpp"
    #include "../Maths/NRE_Maths.hpp"
    #include "Mesh/NRE_Mesh.hpp"
    #include "Mesh/2D/NRE_Mesh2D.hpp"
    #include "Mesh/3D/NRE_Mesh3D.hpp"

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
             * @class Object
             * @brief Object's Object : Manage a simple object with a VBO (or IBO) and a VAO
             */
            class Object {
                protected:
                    Mesh* mesh;         /**< The object's mesh */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object();
                        /**
                         * Construct an object with his mesh
                         * @param mesh  the object mesh, containing (or not yet) the object's model
                         */
                        Object(Mesh* mesh);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param o the object to copy the content
                         */
                        Object(Object const& o) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the object to move
                         */
                        Object(Object && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Object Deconstructor
                         */
                        ~Object();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Add a set of value into in the mesh
                         * @param index   the dataSet's index in the mesh
                         * @param value   the pointer to the set of value
                         * @param nbValue the number of value to add
                         */
                        void add(GLuint const& index, void* value, GLuint const& nbValue = 1) const;
                        /**
                         * Update the current object from his mesh
                         */
                        void update();
                        /**
                         * Allocate and fill the current object's buffer from his mesh
                         * @param usage the object's rendering usage
                         */
                        void allocateAndFill(GLenum const& usage);
                        /**
                         * Draw the current object, need to be call from a rendering context (Shader bind)
                         */
                        void draw() const;
                        void reload();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param o the object to copy into this
                         * @return the reference of himself
                         */
                        Object& operator=(Object const& o) = delete;
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the object to move into this
                         * @return the reference of himself
                         */
                        Object& operator=(Object && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
