
    /**
     * @file NRE_File.hpp
     * @brief Declaration of Engine's IO's Object : File
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <fstream>
    #include "../../Generic/NRE_Type.hpp"

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
             * @class File
             * @brief IO's Object : Manage a file path
             */
            class File {
                private:
                    std::string path;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        File();
                        File(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * Copy f into this
                         * @param f the file to copy the content
                         */
                        File(File const& f);

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the file to move
                         */
                        File(File && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * File Deconstructor
                         */
                        ~File();

                    //## Getter ##//
                        std::string const& getPath() const;

                    //## Setter ##//

                    //## Methods ##//
                        bool const exist() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of f into this
                         * @param f the file to copy into this
                         * @return the reference of himself
                         */
                        File& operator=(File const& f);
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the file to move into this
                         * @return the reference of himself
                         */
                        File& operator=(File && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for File
             * @param stream the out stream to add the file f
             * @param f the file to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, File const& f) {
                stream << "(" << f.getPath() << ")";
                return stream;
            }

        };
    };
