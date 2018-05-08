
    /**
     * @file NRE_DataSet.hpp
     * @brief Declaration of Engine's Object's Object : DataSet
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Generic/NRE_Type.hpp"

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
             * @class DataSet
             * @brief Object's Object : An interface to manage template specialization of data in mesh
             */
            class DataSet {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        DataSet();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the data set to copy the content
                         */
                        DataSet(DataSet const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the data set to move
                         */
                        DataSet(DataSet && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * DataSet Deconstructor
                         */
                        virtual ~DataSet();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        virtual void add(void* value, GLuint const& nbValue = 1) = 0;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the data set to copy into this
                         * @return the reference of himself
                         */
                        DataSet& operator=(DataSet const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the data set to move into this
                         * @return the reference of himself
                         */
                        DataSet& operator=(DataSet && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
