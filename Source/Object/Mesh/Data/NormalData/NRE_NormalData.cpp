
    #include "NRE_NormalData.hpp"

    namespace NRE {
        namespace Object {

            NormalData::NormalData() {
            }

            NormalData::NormalData(NormalData const& d) : Data<NREfloat>::Data(d) {
            }

            NormalData::NormalData(NormalData && d) : Data<NREfloat>::Data(d) {
            }

            NormalData::~NormalData() {
            }

            NormalData& NormalData::operator=(NormalData const& d) {
                Data<NREfloat>::operator=(d);
                return *this;
            }

            NormalData& NormalData::operator=(NormalData && d) {
                Data<NREfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
