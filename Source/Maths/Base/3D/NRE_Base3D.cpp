
    #include "NRE_Base3D.hpp"

    namespace NRE {
        namespace Maths {

            template <>
            bool const Base3D<NREfloat>::operator==(Base3D<NREfloat> const& base) const {
                return almostEqual(getX(), base.getX()) && almostEqual(getY(), base.getY()) && almostEqual(getZ(), base.getZ());
            }

        };
    };
