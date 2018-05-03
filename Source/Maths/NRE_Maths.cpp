
    #include "NRE_Maths.hpp"


    namespace NRE {
        namespace Maths {

            NREfloat const toRad(NREfloat const& x) {
                return x * NRE::Global::PI / 180.0;
            }

            NREfloat const toDeg(NREfloat const& x) {
                return x * 180.0 / NRE::Global::PI;
            }

            bool const almostEqual(NREfloat const& a, NREfloat const& b) {
                return std::abs(a - b) < NRE::Global::EPSILON;
            }

            NREfloat const lerp(NREfloat const& a, NREfloat const& b, NREfloat const& f) {
                return a + f * (b - a);
            }
            
        };
    };
