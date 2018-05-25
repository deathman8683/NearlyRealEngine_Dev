
    /**
     * @file NRE_OutputFile.hpp
     * @brief Declaration of Engine's IO's Object : OutputFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../NRE_FileStream.hpp"
    #include "../OutputStream/NRE_OutputStream.hpp"

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
             * @class OutputFile
             * @brief IO's Object : Manage Output file stream
             */
            class OutputFile : public FileStream, public OutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        OutputFile() = delete;
                        /**
                         * Construct an output file stream with a given file's path
                         * @param path the file's stream path
                         */
                        OutputFile(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the Output file to copy the content
                         */
                        OutputFile(OutputFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the Output file to move
                         */
                        OutputFile(OutputFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * OutputFile Deconstructor
                         */
                        virtual ~OutputFile();

                    //## Getter ##//
                        /**
                         * Opening mode getter
                         * @return the output file stream opening mode
                         */
                        virtual std::ios_base::openmode const getMode() const override;
                        /**
                         * Stream getter
                         * @return the output file's stream
                         */
                        virtual std::fstream& getStream() override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the Output file to copy into this
                         * @return the reference of himself
                         */
                        OutputFile& operator=(OutputFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the Output file to move into this
                         * @return the reference of himself
                         */
                        OutputFile& operator=(OutputFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
