
    /**
     * @file NRE_TangentData.hpp
     * @brief Declaration of Engine's Object's Object : TangentData
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
             * @class TangentData
             * @brief Object's Object : A specialized data object for tangent storing
             */
            class TangentData : public Data<NREfloat> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TangentData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the normal data to copy the content
                         */
                        TangentData(TangentData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the normal data to move
                         */
                        TangentData(TangentData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * TangentData Deconstructor
                         */
                        ~TangentData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the normal data to copy into this
                         * @return the reference of himself
                         */
                        TangentData& operator=(TangentData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the normal data to move into this
                         * @return the reference of himself
                         */
                        TangentData& operator=(TangentData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
