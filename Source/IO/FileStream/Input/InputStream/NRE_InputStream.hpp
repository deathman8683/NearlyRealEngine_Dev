
    /**
     * @file NRE_InputStream.hpp
     * @brief Declaration of Engine's IO's Object : InputStream
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../File/NRE_File.hpp"

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
             * @class InputStream
             * @brief IO's Object : Base interface for Input related stream
             */
            class InputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        InputStream();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the input stream to copy the content
                         */
                        InputStream(InputStream const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the input stream to move
                         */
                        InputStream(InputStream && s);

                    //## Deconstructor ##//
                        /**
                         * InputStream Deconstructor
                         */
                        virtual ~InputStream();

                    //## Getter ##//
                        /**
                         * Stream getter
                         * @return the file's stream
                         */
                        virtual std::fstream& getStream() = 0;
                        /**
                         * Cursor position getter
                         * @return the stream cursor position
                         */
                        std::streampos const getPosition();

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Read into the passed data from the file stream
                         * @param object the data to store the read return
                         */
                        template <class T>
                        void read(T& object);
                        /**
                         * Read a file's line and store it into the given string
                         * @param line the string to store the readed line
                         * @return     tell if the read has been performed
                         */
                        bool const readLine(std::string &line);
                        /**
                         * Set the file cursor position to the begin + offset
                         * @param offset the file's offset
                         */
                        void seekBegin(size_t const& offset = 0);
                        /**
                         * Set the file cursor position to the end - offset
                         * @param offset the file's offset
                         */
                        void seekEnd(size_t const& offset = 0);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the input stream to copy into this
                         * @return the reference of himself
                         */
                        InputStream& operator=(InputStream const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the input stream to move into this
                         * @return the reference of himself
                         */
                        InputStream& operator=(InputStream && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
