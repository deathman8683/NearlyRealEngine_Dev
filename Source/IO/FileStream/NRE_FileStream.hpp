
    /**
     * @file NRE_FileStream.hpp
     * @brief Declaration of Engine's IO's Object : FileStream
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../File/NRE_File.hpp"
    #include "../../Exception/NRE_Exception.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace IO
         * @brief Engine's IO's Module
         */
        namespace IO {

            /**
             * @class FileStream
             * @brief IO's Object : The base interface for Input, Output and IO file
             */
            class FileStream : public File {
                protected:
                    std::fstream file;  /**< The file stream */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FileStream() = delete;
                        /**
                         * Construct a file stream with a given file's path
                         * @param path the file's stream path
                         */
                        FileStream(File const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the file stream to copy the content
                         */
                        FileStream(FileStream const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the file stream to move
                         */
                        FileStream(FileStream && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * FileStream Deconstructor
                         */
                        virtual ~FileStream();

                    //## Getter ##//
                        /**
                         * Opening mode getter
                         * @return the file stream opening mode
                         */
                        virtual std::ios_base::openmode const getMode() const = 0;
                        /**
                         * Opening state getter
                         * @return the file's stream opening state
                         */
                        bool const isOpen() const;


                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Open the file stream with the file's path and file stream opening mode
                         */
                        void open();
                        /**
                         * Open the file stream but truncate all data inside the file
                         */
                        void openEmpty();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the file stream to copy into this
                         * @return the reference of himself
                         */
                        FileStream& operator=(FileStream const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the file stream to move into this
                         * @return the reference of himself
                         */
                        FileStream& operator=(FileStream && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
            };

        };
    };
