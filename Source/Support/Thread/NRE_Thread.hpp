
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
                    std::thread item;   /**< The wrapped thread */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Thread() = delete;
                        /**
                         * Construct a new thread from the function to use and the function's arguments
                         * @param f    the thread's function
                         * @param args the function's arguments
                         */
                        template <class Function, class... Args>
                        Thread(Function&& f, Args&&... args);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param t the thread to copy the content
                         */
                        Thread(Thread const& t) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move t into this, leaving t empty
                         * @param t the thread to move
                         */
                        Thread(Thread && t);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Thread Deconstructor
                         */
                        ~Thread();

                    //## Getter ##//
                        /**
                         * Wrapped Item getter
                         * @return the wrapped item
                         */
                        std::thread&& getItem();

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Join the current thread to the main program
                         */
                        void join();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param t the thread to copy into this
                         * @return the reference of himself
                         */
                        Thread& operator=(Thread const& t) = delete;
                        /**
                         * Move assigment of t into this, leaving t empty
                         * @param t the thread to move into this
                         * @return the reference of himself
                         */
                        Thread& operator=(Thread && t);

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
