
    #include "NRE_TangentData.hpp"

    namespace NRE {
        namespace Object {

            TangentData::TangentData() {
            }

            TangentData::TangentData(TangentData const& d) : Data<NREfloat>::Data(d) {
            }

            TangentData::TangentData(TangentData && d) : Data<NREfloat>::Data(d) {
            }

            TangentData::~TangentData() {
            }

            TangentData& TangentData::operator=(TangentData const& d) {
                Data<NREfloat>::operator=(d);
                return *this;
            }

            TangentData& TangentData::operator=(TangentData && d) {
                Data<NREfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
