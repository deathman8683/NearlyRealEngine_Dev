
    /**
     * @file NRE_Mesh.hpp
     * @brief Declaration of Engine's Object's Object : Mesh
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "Data/NRE_Data.hpp"
    #include "Data/VertexData/NRE_VertexData.hpp"
    #include "Data/MaterialData/NRE_MaterialData.hpp"
    #include "Data/NormalData/NRE_NormalData.hpp"
    #include "Data/IndexData/NRE_IndexData.hpp"
    #include "../../GL_Wrapper/BufferObject/IBO/NRE_IBO.hpp"

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
                    std::vector<DataSet*> data;

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
                        /**
                         * Push back a dataset into the mesh
                         * @param d the dateset to add into the mesh
                         */
                        void push_back(DataSet* const& d);
                        void add(GLuint const& index, void* value, GLuint const& nbValue = 1) const;
                        void updateVBO(GL::VBO const& buffer, std::vector<GLintptr> const& offset) const;
                        void updateIBO(GL::IBO const& buffer, std::vector<GLintptr> const& offset) const;
                        void allocateAndFillVBO(GL::VBO const& buffer, GLenum const& usage) const;
                        void allocateAndFillIBO(GL::IBO const& buffer, GLenum const& usage) const;

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
