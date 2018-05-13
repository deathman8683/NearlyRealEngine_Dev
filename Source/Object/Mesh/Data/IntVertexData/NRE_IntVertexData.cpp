
    #include "NRE_IntVertexData.hpp"

    namespace NRE {
        namespace Object {

            IntVertexData::IntVertexData() {
            }

            IntVertexData::IntVertexData(IntVertexData const& d) : Data<GLint>::Data(d) {
            }

            IntVertexData::IntVertexData(IntVertexData && d) : Data<GLint>::Data(d) {
            }

            IntVertexData::~IntVertexData() {
            }

            IntVertexData& IntVertexData::operator=(IntVertexData const& d) {
                Data<GLint>::operator=(d);
                return *this;
            }

            IntVertexData& IntVertexData::operator=(IntVertexData && d) {
                Data<GLint>::operator=(std::move(d));
                return *this;
            }

        };
    };
