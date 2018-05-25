
    /**
     * @file NRE_FileStream.hpp
     * @brief Declaration of Engine's IO's Object : FileStream
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Exception/NRE_Exception.hpp"
    #include "Input/InputStream/NRE_InputStream.hpp"
    #include "Output/OutputStream/NRE_OutputStream.hpp"

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
                private:
                    std::fstream file;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FileStream() = delete;
                        FileStream(std::string const& path);

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
                        ~FileStream();

                    //## Getter ##//
                        virtual std::ios_base::openmode const getMode() const = 0;
                        bool const isOpen() const;

                    //## Setter ##//

                    //## Methods ##//
                        void open();
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
                    std::fstream& getStream();
            };

        };
    };
