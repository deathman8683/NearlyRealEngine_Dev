
    #include "NRE_UVData.hpp"

    namespace NRE {
        namespace Object {

            UVData::UVData() {
            }

            UVData::UVData(UVData const& d) : Data<GLfloat>::Data(d) {
            }

            UVData::UVData(UVData && d) : Data<GLfloat>::Data(d) {
            }

            UVData::~UVData() {
            }

            UVData& UVData::operator=(UVData const& d) {
                Data<GLfloat>::operator=(d);
                return *this;
            }

            UVData& UVData::operator=(UVData && d) {
                Data<GLfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
