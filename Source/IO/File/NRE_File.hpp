
    /**
     * @file NRE_File.hpp
     * @brief Declaration of Engine's IO's Object : File
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
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
                protected:
                    std::string path;   /**< The file's path */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        File();
                        /**
                         * Construct a File with the given path
                         * @param path the file's path
                         */
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
                        /**
                         * Path's getter
                         * @return the file's path
                         */
                        std::string const& getPath() const;

                    //## Setter ##//
                        /**
                         * Path's setter
                         * @param path the new file's path
                         */
                        void setPath(std::string const& path);

                    //## Methods ##//
                        /**
                         * Test if the file's path exist
                         * @return [description]
                         */
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
                stream << f.getPath();
                return stream;
            }

        };
    };
