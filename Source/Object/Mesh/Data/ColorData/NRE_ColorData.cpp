
    #include "NRE_ColorData.hpp"

    namespace NRE {
        namespace Object {

            ColorData::ColorData() {
            }

            ColorData::ColorData(ColorData const& d) : Data<GLfloat>::Data(d) {
            }

            ColorData::ColorData(ColorData && d) : Data<GLfloat>::Data(d) {
            }

            ColorData::~ColorData() {
            }

            ColorData& ColorData::operator=(ColorData const& d) {
                Data<GLfloat>::operator=(d);
                return *this;
            }

            ColorData& ColorData::operator=(ColorData && d) {
                Data<GLfloat>::operator=(std::move(d));
                return *this;
            }

        };
    };
