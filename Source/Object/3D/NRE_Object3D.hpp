
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
                private:
                    Model model;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object3D();
                        /**
                         * Construt a 3D object from his size
                         * @param size  the object's size
                         */
                        Object3D(Maths::Vector3D<GLuint> size);

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
                        void process(GLenum const& usage, Maths::Point2D<GLint> const& coord);
                        void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type);

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
