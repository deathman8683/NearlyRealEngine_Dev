
    /**
     * @file NRE_FileNotExistingException.hpp
     * @brief Declaration of Engine's Exception's Object : FileNotExistingException
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_IOException.hpp"

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
             * @class FileNotExistingException
             * @brief Exception's Object : A special IO exception to tell that a file is not existing
             */
            class FileNotExistingException : public IOException {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FileNotExistingException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        FileNotExistingException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        FileNotExistingException(FileNotExistingException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        FileNotExistingException(FileNotExistingException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * FileNotExistingException Deconstructor
                         */
                        virtual ~FileNotExistingException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        FileNotExistingException& operator=(FileNotExistingException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        FileNotExistingException& operator=(FileNotExistingException && e);
            };

        };
    };
