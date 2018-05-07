
    /**
     * @file NRE_Data.hpp
     * @brief Declaration of Engine's Object's Object : Data
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system>
         */
        namespace Object {

            /**
             * @class Data
             * @brief Object's Object : Manage storing of mesh's attributes data
             */
            template <class T>
            class Data {
                protected:
                    std::vector<T> data;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Data();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the data to copy the content
                         */
                        Data(Data const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the data to move
                         */
                        Data(Data && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Data Deconstructor
                         */
                        ~Data();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the data to copy into this
                         * @return the reference of himself
                         */
                        Data& operator=(Data const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the data to move into this
                         * @return the reference of himself
                         */
                        Data& operator=(Data && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
