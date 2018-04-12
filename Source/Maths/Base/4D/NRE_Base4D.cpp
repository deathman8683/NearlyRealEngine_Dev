
    #include "NRE_Base4D.hpp"

    namespace NRE {
        namespace Maths {

            template <>
            bool const Base4D<NREfloat>::operator==(Base4D<NREfloat> const& base) const {
                return almostEqual(getX(), base.getX()) && almostEqual(getY(), base.getY()) && almostEqual(getZ(), base.getZ()) && almostEqual(getW(), base.getW());
            }

        };
    };
