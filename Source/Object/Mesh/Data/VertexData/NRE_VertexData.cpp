
    #include "NRE_VertexData.hpp"

    namespace NRE {
        namespace Object {

            VertexData::VertexData() {
            }

            VertexData::VertexData(VertexData const& d) : Data<GLint>::Data(d) {
            }

            VertexData::VertexData(VertexData && d) : Data<GLint>::Data(d) {
            }

            VertexData::~VertexData() {
            }

            VertexData& VertexData::operator=(VertexData const& d) {
                Data<GLint>::operator=(d);
                return *this;
            }

            VertexData& VertexData::operator=(VertexData && d) {
                Data<GLint>::operator=(std::move(d));
                return *this;
            }

        };
    };
