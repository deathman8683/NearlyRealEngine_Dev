
    /**
     * @file NRE_Object2D.hpp
     * @brief Declaration of Engine's Object's Object : Object2D
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
             * @class Object2D
             * @brief Object's Object : Manage 2D object
             */
            class Object2D : public Object {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object2D();
                        /**
                         * Construt a 2D object with a base vertex data in the mesh
                         * @param type the vertex data type for the mesh
                         */
                        Object2D(GLenum const& type);
                        /**
                         * Construt a 2D object from his data type, rendering usage, position and size
                         * @param type the vertex data type for the mesh
                         * @param usage the object's rendering usage
                         * @param coord the object's position on screen
                         * @param size  the object's size
                         */
                        Object2D(GLenum const& type, GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param o the 2D object to copy the content
                         */
                        Object2D(Object2D const& o) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the 2D object to move
                         */
                        Object2D(Object2D && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Object2D Deconstructor
                         */
                        virtual ~Object2D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        void process(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param o the 2D object to copy into this
                         * @return the reference of himself
                         */
                        Object2D& operator=(Object2D const& o) = delete;
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the 2D object to move into this
                         * @return the reference of himself
                         */
                        Object2D& operator=(Object2D && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
