
    /**
     * @file NRE_Texture2DArray.hpp
     * @brief Declaration of Engine's GL's Object : Texture2DArray
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/TextureBuffer/3D/NRE_Texture3DBuffer.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief <Module_Desc>
         */
        namespace GL {

            /**
             * @class Texture2DArray
             * @brief GL's Object : <Class_Desc>
             */
            class Texture2DArray : public Texture3DBuffer, public BufferObject {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Texture2DArray();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param tex the 2D texture array to copy the content
                         */
                        Texture2DArray(Texture2DArray const& tex) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move tex into this, leaving tex empty
                         * @param tex the 2D texture array to move
                         */
                        Texture2DArray(Texture2DArray && tex);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Texture2DArray Deconstructor
                         */
                        ~Texture2DArray();

                    //## Getter ##//
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        GLenum const getTarget() const override;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Texture2DArray specific filter
                         */
                        void applyFilter() const override;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param tex the 2D texture array to copy into this
                         * @return the reference of himself
                         */
                        Texture2DArray& operator=(Texture2DArray const& tex) = delete;
                        /**
                         * Move assigment of tex into this, leaving tex empty
                         * @param tex the 2D texture array to move into this
                         * @return the reference of himself
                         */
                        Texture2DArray& operator=(Texture2DArray && tex);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum DEFAULT_TYPE; /**< The 3D texture default type enum */
            };

        };
    };
