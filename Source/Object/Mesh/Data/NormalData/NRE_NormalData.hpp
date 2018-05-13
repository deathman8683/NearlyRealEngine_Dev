
    /**
     * @file NRE_NormalData.hpp
     * @brief Declaration of Engine's Object's Object : NormalData
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
             * @class NormalData
             * @brief Object's Object : A specialized data object for normal storing
             */
            class NormalData : public Data<NREfloat> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        NormalData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the normal data to copy the content
                         */
                        NormalData(NormalData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the normal data to move
                         */
                        NormalData(NormalData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * NormalData Deconstructor
                         */
                        ~NormalData();

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
                        NormalData& operator=(NormalData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the normal data to move into this
                         * @return the reference of himself
                         */
                        NormalData& operator=(NormalData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
