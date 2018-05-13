
    /**
     * @file NRE_MaterialData.hpp
     * @brief Declaration of Engine's Object's Object : MaterialData
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
             * @class MaterialData
             * @brief Object's Object : A specialized data object for material storing
             */
            class MaterialData : public Data<GLubyte> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        MaterialData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the material data to copy the content
                         */
                        MaterialData(MaterialData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the material data to move
                         */
                        MaterialData(MaterialData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * MaterialData Deconstructor
                         */
                        ~MaterialData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the material data to copy into this
                         * @return the reference of himself
                         */
                        MaterialData& operator=(MaterialData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the material data to move into this
                         * @return the reference of himself
                         */
                        MaterialData& operator=(MaterialData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
