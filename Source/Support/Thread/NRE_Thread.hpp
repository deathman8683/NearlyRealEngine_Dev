
    /**
     * @file NRE_Thread.hpp
     * @brief Declaration of Engine's Support's Object : Thread
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <thread>
    #include "../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Support
         * @brief Engine's Application's Support Module
         */
        namespace Support {

            /**
             * @class Thread
             * @brief Support's Object : A simple application thread
             */
            class Thread {
                private:
                    std::thread item;

                public:
                    //## Constructor ##//
                    Thread();
                    template <class Function, class... Args>
                    Thread(Function&& f, Args&&... args);

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//

                    //## Getter ##//
                    std::thread&& getItem();

                    //## Setter ##//

                    //## Methods ##//
                    void join();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                    Thread& operator=(Thread&& t);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    #include "NRE_Thread.tpp"
