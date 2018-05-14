
    #include "NRE_UVData.hpp"

    namespace NRE {
        namespace Object {

            UVData::UVData() {
            }

            UVData::UVData(UVData const& d) : Data<NREfloat>::Data(d) {
            }

            UVData::UVData(UVData && d) : Data<NREfloat>::Data(d) {
            }

            UVData::~UVData() {
            }

            UVData& UVData::operator=(UVData const& d) {
                Data<NREfloat>::operator=(d);
                return *this;
            }

            UVData& UVData::operator=(UVData && d) {
                Data<NREfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
