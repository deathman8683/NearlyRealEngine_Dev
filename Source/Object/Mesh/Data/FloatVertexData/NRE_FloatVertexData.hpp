
    /**
     * @file NRE_FloatVertexData.hpp
     * @brief Declaration of Engine's Object's Object : FloatVertexData
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
             * @class FloatVertexData
             * @brief Object's Object : A specialized data object for float vertex storing
             */
            class FloatVertexData : public Data<NREfloat> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FloatVertexData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the float vertex data to copy the content
                         */
                        FloatVertexData(FloatVertexData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the float vertex data to move
                         */
                        FloatVertexData(FloatVertexData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FloatVertexData Deconstructor
                         */
                        ~FloatVertexData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the float vertex data to copy into this
                         * @return the reference of himself
                         */
                        FloatVertexData& operator=(FloatVertexData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the float vertex data to move into this
                         * @return the reference of himself
                         */
                        FloatVertexData& operator=(FloatVertexData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
