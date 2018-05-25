
    /**
     * @file NRE_IOFile.hpp
     * @brief Declaration of Engine's IO's Object : IOFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_FileStream.hpp"
    #include "../Input/InputStream/NRE_InputStream.hpp"
    #include "../Output/OutputStream/NRE_OutputStream.hpp"

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
             * @class IOFile
             * @brief IO's Object : Manage Input-Output file stream
             */
            class IOFile : public FileStream, public InputStream, public OutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IOFile() = delete;
                        IOFile(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy the content
                         */
                        IOFile(IOFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the IO file to move
                         */
                        IOFile(IOFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IOFile Deconstructor
                         */
                        virtual ~IOFile();

                    //## Getter ##//
                        virtual std::ios_base::openmode const getMode() const override;
                        virtual std::fstream& getStream() override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy into this
                         * @return the reference of himself
                         */
                        IOFile& operator=(IOFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the IO file to move into this
                         * @return the reference of himself
                         */
                        IOFile& operator=(IOFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
