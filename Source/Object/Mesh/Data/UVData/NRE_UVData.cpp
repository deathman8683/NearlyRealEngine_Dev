
    #include "NRE_UVData.hpp"

    namespace NRE {
        namespace Object {

            UVData::UVData() {
            }

            UVData::UVData(UVData const& d) : Data<GLshort>::Data(d) {
            }

            UVData::UVData(UVData && d) : Data<GLshort>::Data(d) {
            }

            UVData::~UVData() {
            }

            UVData& UVData::operator=(UVData const& d) {
                Data<GLshort>::operator=(d);
                return *this;
            }

            UVData& UVData::operator=(UVData && d) {
                Data<GLshort>::operator=(std::move(d));
                return *this;
            }

        };
    };
