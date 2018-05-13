
    /**
     * @file NRE_Object3D.hpp
     * @brief Declaration of Engine's Object's Object : Object3D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Object.hpp"

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
             * @class Object3D
             * @brief Object's Object : Manage 3D object
             */
            class Object3D : public Object {
                protected:
                    Model model;    /**< The object's model, used only for voxel type model */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object3D();
                        /**
                         * Construt a 3D object from his data type and size
                         * @param type the vertex data type for the mesh
                         * @param size  the object's size
                         */
                        Object3D(GLenum const& type, Maths::Vector3D<GLuint> size);

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
                        /**
                         * Model getter
                         * @return the object's model
                         */
                        Model const& getModel() const;

                    //## Setter ##//
                        /**
                         * Left's Model setter
                         * @param o the new left's model taken from the object
                         */
                        void setLeft(Object3D const& o);
                        /**
                         * Right's Model setter
                         * @param o the new right's model taken from the object
                         */
                        void setRight(Object3D const& o);
                        /**
                         * Front's Model setter
                         * @param o the new front's model taken from the object
                         */
                        void setFront(Object3D const& o);
                        /**
                         * Back's Model setter
                         * @param o the new back's model taken from the object
                         */
                        void setBack(Object3D const& o);
                        /**
                         * Up's Model setter
                         * @param o the new up's model taken from the object
                         */
                        void setUp(Object3D const& o);
                        /**
                         * Bottom's Model setter
                         * @param o the new bottom's model taken from the object
                         */
                        void setBottom(Object3D const& o);

                    //## Methods ##//
                        /**
                         * Save the current object's model into a given file
                         * @param path the file's path
                         */
                        void save(std::string const& path) const;
                        /**
                         * Load the current object's model from a given file
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
                         * Process a sphere into the current object
                         * @param usage the object's rendering usage
                         * @param radius  the sphere's radius
                         * @param rings   the sphere's number of rings
                         * @param sectors the sphere's number of sectors
                         * @param type    the sphere's material's type
                         */
                        void processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type);
                        /**
                         * Load a given number of voxels in the file
                         * @param x    the start x coordinates
                         * @param y    the start y coordinates
                         * @param z    the start z coordinates
                         * @param nb   the number of voxels  to load
                         * @param type the voxel's type
                         */
                        void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLubyte const& type);

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
