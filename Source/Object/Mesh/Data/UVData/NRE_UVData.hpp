
    /**
     * @file NRE_VertexData.hpp
     * @brief Declaration of Engine's Object's Object : UVData
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Data.hpp"

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
             * @class UVData
             * @brief Object's Object : A specialized data object for uv storing
             */
            class UVData : public Data<GLshort> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        UVData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the uv data to copy the content
                         */
                        UVData(UVData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the uv data to move
                         */
                        UVData(UVData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * UVData Deconstructor
                         */
                        ~UVData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the uv data to copy into this
                         * @return the reference of himself
                         */
                        UVData& operator=(UVData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the uv data to move into this
                         * @return the reference of himself
                         */
                        UVData& operator=(UVData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
