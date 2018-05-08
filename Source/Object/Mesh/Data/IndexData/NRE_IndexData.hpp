
    /**
     * @file NRE_VertexData.hpp
     * @brief Declaration of Engine's Object's Object : IndexData
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
             * @class IndexData
             * @brief Object's Object : A specialized data object for index storing
             */
            class IndexData : public Data<GLuint> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IndexData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the index data to copy the content
                         */
                        IndexData(IndexData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the index data to move
                         */
                        IndexData(IndexData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IndexData Deconstructor
                         */
                        ~IndexData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the index data to copy into this
                         * @return the reference of himself
                         */
                        IndexData& operator=(IndexData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the index data to move into this
                         * @return the reference of himself
                         */
                        IndexData& operator=(IndexData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
