
    /**
     * @file NRE_ColorData.hpp
     * @brief Declaration of Engine's Object's Object : ColorData
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
             * @class ColorData
             * @brief Object's Object : A specialized data object for color storing
             */
            class ColorData : public Data<GLfloat> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ColorData();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the color data to copy the content
                         */
                        ColorData(ColorData const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the color data to move
                         */
                        ColorData(ColorData && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ColorData Deconstructor
                         */
                        ~ColorData();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the color data to copy into this
                         * @return the reference of himself
                         */
                        ColorData& operator=(ColorData const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the color data to move into this
                         * @return the reference of himself
                         */
                        ColorData& operator=(ColorData && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
