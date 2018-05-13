
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
                    std::vector<T> data;    /**< The data set values */

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
                        /**
                         * Value getter
                         * @param  index the data's index
                         * @return       the corresponding data
                         */
                        T const& getValue(GLuint const& index) const;
                        /**
                         * TypeSize getter
                         * @return the data set type size
                         */
                        size_t const getTypeSize() const override;
                        /**
                         * DataSize getter
                         * @return the data set size in bytes
                         */
                        size_t const getDataSize() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Size getter
                         * @return the set's size
                         */
                        size_t const size() const override;
                        /**
                         * Add a set of value in the set
                         * @param value   the pointer to the set of value
                         * @param nbValue the number of value to add
                         */
                        void add(const GLvoid* const value, GLuint const& nbValue = 1) override;
                        /**
                         * Return a pointer to the start of the data
                         * @return the data set's pointer
                         */
                        GLvoid* const value() override;
                        /**
                         * Clear the data set
                         */
                        void clear() override;

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
            inline std::ostream& operator<<(std::ostream &stream, Data<T> const& d) {
                stream << "(";
                for (GLuint i = 0; i < d.size() - 1; i = i + 1) {
                    stream << d.getValue(i) << ",";
                }
                stream << d.getValue(d.size() - 1) << ")";
                return stream;
            }

        };
    };

    #include "NRE_Data.tpp"
