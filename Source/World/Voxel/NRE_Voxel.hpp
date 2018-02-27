
    /**
     * @file NRE_Voxel.hpp
     * @brief Declaration of Engine's World's Object : Voxel
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

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
                private:
                    bool active;

                public:
                    //## Constructor ##//
                    Voxel();
                    Voxel(bool const& state);

                    //## Copy-Constructor ##//
                    Voxel(Voxel const& vox);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Voxel();

                    //## Getter ##//
                    bool const& isActive() const;

                    //## Setter ##//
                    void setActive(bool const& state);

                    //## Methods ##//
                    void getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static bool DEFAULT_STATE;
                    static int NB_VERTICES;
            };

        };
    };
