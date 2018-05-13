
    /**
     * @file NRE_Mesh2D.hpp
     * @brief Declaration of Engine's Object's Object : Mesh2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Mesh.hpp"
    #include "../../../Maths/NRE_Maths.hpp"

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
             * @class Mesh2D
             * @brief Object's Object : A 2D mesh used in 2D object rendering
             */
            class Mesh2D : public Mesh {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh2D();
                        /**
                         * Construct a 2D mesh with a given vertex data type
                         * @param type the vertex data type
                         */
                        Mesh2D(GLenum const& type);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the 2D mesh to copy the content
                         */
                        Mesh2D(Mesh2D const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the 2D mesh to move
                         */
                        Mesh2D(Mesh2D && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh2D Deconstructor
                         */
                        ~Mesh2D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Process the mesh and create the graphical model from the object coordinates and size
                         * @param buffer the buffer to fill
                         * @param usage  the buffer's usage
                         * @param coord  the object's coordinates
                         * @param size   the object's size
                         */
                        void process(GL::VBO& buffer, GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> const& size);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the 2D mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh2D& operator=(Mesh2D const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the 2D mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh2D& operator=(Mesh2D && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
