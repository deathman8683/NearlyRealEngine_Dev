
    #include "NRE_IndexData.hpp"

    namespace NRE {
        namespace Object {

            IndexData::IndexData() {
            }

            IndexData::IndexData(IndexData const& d) : Data<GLuint>::Data(d) {
            }

            IndexData::IndexData(IndexData && d) : Data<GLuint>::Data(d) {
            }

            IndexData::~IndexData() {
            }

            IndexData& IndexData::operator=(IndexData const& d) {
                Data<GLuint>::operator=(d);
                return *this;
            }

            IndexData& IndexData::operator=(IndexData && d) {
                Data<GLuint>::operator=(std::move(d));
                return *this;
            }

        };
    };
