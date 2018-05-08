
    #include "NRE_MaterialData.hpp"

    namespace NRE {
        namespace Object {

            MaterialData::MaterialData() {
            }

            MaterialData::MaterialData(MaterialData const& d) : Data<GLubyte>::Data(d) {
            }

            MaterialData::MaterialData(MaterialData && d) : Data<GLubyte>::Data(d) {
            }

            MaterialData::~MaterialData() {
            }

            MaterialData& MaterialData::operator=(MaterialData const& d) {
                Data<GLubyte>::operator=(d);
                return *this;
            }

            MaterialData& MaterialData::operator=(MaterialData && d) {
                Data<GLubyte>::operator=(std::move(d));
                return *this;
            }

        };
    };
