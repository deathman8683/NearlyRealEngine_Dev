
    /**
     * @file NRE_Voxel.hpp
     * @brief Declaration of Engine's World's Object : Voxel
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "Type/VoxelTypes/NRE_VoxelTypes.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Managment Module
         */
        namespace World {

            /**
             * @class Voxel
             * @brief World's Object : A basic voxel
             */
            class Voxel {
                protected:
                    GLubyte type;   /**< The voxel type */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Voxel();
                        /**
                         * Construct a voxel with a given type
                         * @param type the voxel type
                         */
                        Voxel(GLubyte const& type);

                    //## Copy-Constructor ##//
                        /**
                         * Copy vox into this
                         * @param vox the voxel to copy the content
                         */
                        Voxel(Voxel const& vox);

                    //## Move-Constructor ##//
                        /**
                         * Move vox into this, leaving vox empty
                         * @param vox the voxel to move
                         */
                        Voxel(Voxel && vox);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Voxel Deconstructor
                         */
                        ~Voxel();

                    //## Getter ##//
                        /**
                         * Type getter
                         * @return the voxel type value
                         */
                        GLubyte const& getType() const;
                        /**
                         * Voxel color getter
                         * @return the voxel volor using the voxel type lookup table
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Voxel solid state getter
                         * @return the voxel solid state using the voxel type lookup table
                         */
                        bool const isSolid() const;

                    //## Setter ##//
                        /**
                         * Type setter
                         * @param type the new type value
                         */
                        void setType(GLubyte const& type);

                    //## Methods ##//
                        /**
                         * Fill different passed buffer with a voxel frame, used for debug purpose
                         * @param  vBuf vertices buffers
                         * @param  cBuf color buffer
                         * @param  nBuf normal buffer
                         * @param  iBuf index buffer
                         * @return      the number of vertex added in buffer
                         */
                        size_t getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of vox into this
                         * @param vox the voxel to copy into this
                         * @return the reference of himself
                         */
                        Voxel& operator=(Voxel const& vox);
                        /**
                         * Move assigment of vox into this, leaving vox empty
                         * @param vox the voxel to move into this
                         * @return the reference of himself
                         */
                        Voxel& operator=(Voxel && vox);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static int NB_VERTICES; /**< The number of vertices in a single voxel frame */
                    static size_t NB_INDEX; /**< The number of index in a single voxel frame */
            };

            /**
             * Outstream operation for voxel
             * @param stream the out stream to add the voxel vox
             * @param vox the voxel to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, Voxel const& vox) {
                stream << "(" << vox.getType() << ")";
                return stream;
            }

        };
    };
