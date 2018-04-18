
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
                        /**
                         * Default Constructor
                         */
                        SkyBox();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the skyBox to copy
                         */
                        SkyBox(SkyBox const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the skyBox to move
                         */
                        SkyBox(SkyBox && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * SkyBox Deconstructor
                         */
                        ~SkyBox();

                    //## Getter ##//
                        /**
                         * Return the skyBox type enum, used with derived class
                         * @return the skyBox type enum
                         */
                        GLenum const getType() const;
                        /**
                         * Return the skyBox target, used with derived class
                         * @return the skyBox target
                         */
                        GLenum const getTarget() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Allocate the skyBox cubemap with given parameter
                         * @param w          skyBox's width
                         * @param h          skyBox's height
                         * @param callFilter tell if the function has to apply filter or not for the given binding
                         */
                        void allocate(GLsizei const& w, GLsizei const& h, bool const& callFilter);
                        /**
                         * SkyBox specific filter
                         */
                        void applyFilter() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the skyBox to copy
                         */
                        SkyBox& operator=(SkyBox const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the skyBox to move into this
                         * @return the reference of himself
                         */
                        SkyBox& operator=(SkyBox && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE; /**< The SkyBox's type enum */
            };

        };
    };
