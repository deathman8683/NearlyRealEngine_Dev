
    /**
     * @file NRE_SkyBox.hpp
     * @brief Declaration of Engine's GL's Object : SkyBox
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Buffer/CubeMap/NRE_CubeMap.hpp"
    #include "../NRE_BufferObject.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace GL {

            /**
             * @class SkyBox
             * @brief GL's Object : A basic SkyBox with 6 texture using a cube map
             */
            class SkyBox : public CubeMap, public BufferObject {
                private:

                public:
                    //## Constructor ##//
                    SkyBox();

                    //## Copy-Constructor ##//
                    SkyBox(SkyBox const& sb);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~SkyBox();

                    //## Getter ##//
                    GLenum const getType() const;
                    GLenum const getTarget() const;

                    //## Setter ##//

                    //## Methods ##//
                    void allocate(GLsizei const& w, GLsizei const& h, bool const& callFilter);
                    void applyFilter() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE;
            };

        };
    };
