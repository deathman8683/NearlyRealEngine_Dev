
    /**
     * @file NRE_AssimpException.hpp
     * @brief Declaration of Engine's Exception's Object : AssimpException
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ExceptionHandler.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Exception
         * @brief Engine's Exception Handler Module
         */
        namespace Exception {

            /**
             * @class AssimpException
             * @brief Exception's Object : An Assimp Exception
             */
            class AssimpException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        AssimpException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        AssimpException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        AssimpException(AssimpException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        AssimpException(AssimpException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * AssimpException Deconstructor
                         */
                        virtual ~AssimpException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        AssimpException& operator=(AssimpException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        AssimpException& operator=(AssimpException && e);
            };

        };
    };
