
    /**
     * @file NRE_Mesh.hpp
     * @brief Declaration of Engine's Object's Object : Mesh
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
         * @brief The Engine's Object's managing system
         */
        namespace Object {

            /**
             * @class Mesh
             * @brief Object's Object : Base class for 2D and 3D mesh specialization
             */
            class Mesh {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mesh();

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the mesh to copy the content
                         */
                        Mesh(Mesh const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the mesh to move
                         */
                        Mesh(Mesh && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mesh Deconstructor
                         */
                        ~Mesh();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the mesh to copy into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the mesh to move into this
                         * @return the reference of himself
                         */
                        Mesh& operator=(Mesh && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
