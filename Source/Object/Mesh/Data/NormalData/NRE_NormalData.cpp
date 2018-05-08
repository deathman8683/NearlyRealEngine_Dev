
    #include "NRE_NormalData.hpp"

    namespace NRE {
        namespace Object {

            NormalData::NormalData() {
            }

            NormalData::NormalData(NormalData const& d) : Data<GLbyte>::Data(d) {
            }

            NormalData::NormalData(NormalData && d) : Data<GLbyte>::Data(d) {
            }

            NormalData::~NormalData() {
            }

            NormalData& NormalData::operator=(NormalData const& d) {
                Data<GLbyte>::operator=(d);
                return *this;
            }

            NormalData& NormalData::operator=(NormalData && d) {
                Data<GLbyte>::operator=(std::move(d));
                return *this;
            }

        };
    };
