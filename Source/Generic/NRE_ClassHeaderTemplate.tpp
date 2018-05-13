
    /**
     * @file NRE_<Class>.hpp
     * @brief Declaration of Engine's <Module>'s Object : <Class>
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "<Path>/Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace <Module>
         * @brief <Module_Desc>
         */
        namespace <Module> {

            /**
             * @class <Class>
             * @brief <Module>'s Object : <Class_Desc>
             */
            class <Class> {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        <Class>();

                    //## Copy-Constructor ##//
                        /**
                         * Copy <Var> into this
                         * @param <Var> the <class> to copy the content
                         */
                        <Class>(<Class> const& <Var>);

                    //## Move-Constructor ##//
                        /**
                         * Move <Var> into this, leaving <Var> empty
                         * @param <Var> the <class> to move
                         */
                        <Class>(<Class> && <Var>);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * <Class> Deconstructor
                         */
                        ~<Class>();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of <Var> into this
                         * @param <Var> the <class> to copy into this
                         * @return the reference of himself
                         */
                        <Class>& operator=(<Class> const& <Var>);
                        /**
                         * Move assigment of <Var> into this, leaving <Var> empty
                         * @param <Var> the <class> to move into this
                         * @return the reference of himself
                         */
                        <Class>& operator=(<Class> && <Var>);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
