
    #include "NRE_DataSet.hpp"

    namespace NRE {
        namespace Object {

            DataSet::DataSet() {
            }

            DataSet::DataSet(DataSet const& d) {
            }

            DataSet::DataSet(DataSet && d) {
            }

            DataSet::~DataSet() {
            }

            DataSet& DataSet::operator=(DataSet const& d) {
                return *this;
            }

            DataSet& DataSet::operator=(DataSet && d) {
                return *this;
            }

        };
    };
