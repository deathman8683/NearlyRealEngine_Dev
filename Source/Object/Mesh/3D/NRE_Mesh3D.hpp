
    /**
     * @file NRE_Mesh3D.hpp
     * @brief Declaration of Engine's Object's Object : Mesh3D
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
         * @brief The Engine's Object's managing system
         */
        namespace Object {

            /**
             * @class Mesh3D
             * @brief Object's Object : A 3D mesh used in 3D object rendering
             */
            class Mesh3D : public Mesh {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh3D() = delete;
                        /**
                         * Construct a 3D mesh with a given vertex data type
                         * @param type the vertex data type
                         */
                        Mesh3D(GLenum const& type);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param m the 3D mesh to copy the content
                         */
                        Mesh3D(Mesh3D const& m) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the 3D mesh to move
                         */
                        Mesh3D(Mesh3D && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh3D Deconstructor
                         */
                        ~Mesh3D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Process a sphere with given parameters
                         * @param usage   the buffer's usage
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
                         * @param m the 3D mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh3D& operator=(Mesh3D const& m) = delete;
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the 3D mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh3D& operator=(Mesh3D && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
