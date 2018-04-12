
    #include "NRE_Base2D.hpp"

    namespace NRE {
        namespace Maths {

            template <>
            bool const Base2D<NREfloat>::operator==(Base2D<NREfloat> const& base) const {
                return almostEqual(getX(), base.getX()) && almostEqual(getY(), base.getY());
            }

        };
    };
