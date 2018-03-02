
    /**
     * @file NRE_Voxel.hpp
     * @brief Declaration of Engine's World's Object : Voxel
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Renderer/Color/NRE_Color.hpp"

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
                    bool active;

                public:
                    //## Constructor ##//
                    Voxel();
                    Voxel(bool const& state);

                    //## Copy-Constructor ##//
                    Voxel(Voxel const& vox);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Voxel();

                    //## Getter ##//
                    bool const& isActive() const;

                    //## Setter ##//
                    void setActive(bool const& state);

                    //## Methods ##//
                    size_t getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf);
                    virtual GLint const getType() const = 0;
                    virtual Color::RGB const getColor() const = 0;

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
                    static size_t NB_INDEX;
            };

            inline std::ostream& operator<<(std::ostream &stream, Voxel const& vox) {
                stream << "(" << vox.getType() << ")";
                return stream;
            }

        };
    };
