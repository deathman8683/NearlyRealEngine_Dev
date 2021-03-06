
    /**
     * @file NRE_IntVertexData.hpp
     * @brief Declaration of Engine's Object's Object : IntVertexData
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
             * @class IntVertexData
             * @brief Object's Object : A specialized data object for integer vertex storing
             */
            class IntVertexData : public Data<GLint> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IntVertexData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the integer vertex data to copy the content
                         */
                        IntVertexData(IntVertexData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the integer vertex data to move
                         */
                        IntVertexData(IntVertexData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IntVertexData Deconstructor
                         */
                        ~IntVertexData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the integer vertex data to copy into this
                         * @return the reference of himself
                         */
                        IntVertexData& operator=(IntVertexData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the integer vertex data to move into this
                         * @return the reference of himself
                         */
                        IntVertexData& operator=(IntVertexData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
