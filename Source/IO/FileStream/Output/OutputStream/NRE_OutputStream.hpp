
    /**
     * @file NRE_OutputStream.hpp
     * @brief Declaration of Engine's IO's Object : OutputStream
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
             * @class OutputStream
             * @brief IO's Object : Base interface for Output related stream
             */
            class OutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        OutputStream();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the output stream to copy the content
                         */
                        OutputStream(OutputStream const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the output stream to move
                         */
                        OutputStream(OutputStream && s);

                    //## Deconstructor ##//
                        /**
                         * OutputStream Deconstructor
                         */
                        virtual ~OutputStream();

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
                         * Write the passed data into the file stream
                         * @param object the data to write
                         */
                        template <class T>
                        void write(T const& object);
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
                         * @param s the output stream to copy into this
                         * @return the reference of himself
                         */
                        OutputStream& operator=(OutputStream const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the output stream to move into this
                         * @return the reference of himself
                         */
                        OutputStream& operator=(OutputStream && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
