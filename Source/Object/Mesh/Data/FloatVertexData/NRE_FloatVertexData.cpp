
    #include "NRE_FloatVertexData.hpp"

    namespace NRE {
        namespace Object {

            FloatVertexData::FloatVertexData() {
            }

            FloatVertexData::FloatVertexData(FloatVertexData const& d) : Data<NREfloat>::Data(d) {
            }

            FloatVertexData::FloatVertexData(FloatVertexData && d) : Data<NREfloat>::Data(d) {
            }

            FloatVertexData::~FloatVertexData() {
            }

            FloatVertexData& FloatVertexData::operator=(FloatVertexData const& d) {
                Data<NREfloat>::operator=(d);
                return *this;
            }

            FloatVertexData& FloatVertexData::operator=(FloatVertexData && d) {
                Data<NREfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
