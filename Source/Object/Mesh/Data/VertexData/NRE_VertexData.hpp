
    /**
     * @file NRE_VertexData.hpp
     * @brief Declaration of Engine's Object's Object : VertexData
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
             * @class VertexData
             * @brief Object's Object : A specialized data object for vertex storing
             */
            class VertexData : public Data<GLint> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VertexData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the vertex data to copy the content
                         */
                        VertexData(VertexData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the vertex data to move
                         */
                        VertexData(VertexData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VertexData Deconstructor
                         */
                        ~VertexData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the vertex data to copy into this
                         * @return the reference of himself
                         */
                        VertexData& operator=(VertexData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the vertex data to move into this
                         * @return the reference of himself
                         */
                        VertexData& operator=(VertexData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
