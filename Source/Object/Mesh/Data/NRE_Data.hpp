
    /**
     * @file NRE_Data.hpp
     * @brief Declaration of Engine's Object's Object : Data
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "DataSet/NRE_DataSet.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system
         */
        namespace Object {

            /**
             * @class Data
             * @brief Object's Object : Manage storing of mesh's attributes data
             */
            template <class T>
            class Data : public DataSet {
                protected:
                    std::vector<T> data;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Data();

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the data to copy the content
                         */
                        Data(Data const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the data to move
                         */
                        Data(Data && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Data Deconstructor
                         */
                        virtual ~Data();

                    //## Getter ##//
                        T const& get(GLuint const& index) const;

                    //## Setter ##//

                    //## Methods ##//
                        void add(void* value, GLuint const& nbValue = 1) override;
                        size_t const size() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the data to copy into this
                         * @return the reference of himself
                         */
                        Data& operator=(Data const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the data to move into this
                         * @return the reference of himself
                         */
                        Data& operator=(Data && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            /**
             * Outstream operation for Data
             * @param stream the out stream to add the data d
             * @param d the data to add in the stream
             * @return the modified outstream
             */
            template <class T>
            inline std::ostream& operator<<(std::ostream &stream, Data<T> const& c) {
                stream << "(";
                for (GLuint i = 0; i < c.size() - 1; i = i + 1) {
                    stream << c.get(i) << ",";
                }
                stream << c.get(c.size() - 1) << ")";
                return stream;
            }

        };
    };

    #include "NRE_Data.tpp"
