
    #include "NRE_PackedVertex.hpp"

    namespace NRE {
        namespace World {

            PackedVertex::PackedVertex() : nCode(0), cCode(0) {
            }

            PackedVertex::PackedVertex(Maths::Point3D<GLint> const& p, Maths::Vector3D<GLbyte> const& n, Color::RGB const& c, size_t const& nCode, size_t const& cCode) : Maths::Point3D<GLint>(p), Maths::Vector3D<GLbyte>(n), Color::RGB(c), nCode(nCode), cCode(cCode) {
            }

            PackedVertex::PackedVertex(PackedVertex const& p) : Maths::Point3D<GLint>(p), Maths::Vector3D<GLbyte>(p), Color::RGB(p), nCode(p.getNCode()), cCode(p.getCCode()) {
            }

            PackedVertex::~PackedVertex() {
            }

            size_t const& PackedVertex::getNCode() const {
                return nCode;
            }

            size_t const& PackedVertex::getCCode() const {
                return cCode;
            }

            void PackedVertex::setNCode(size_t const& code) {
                nCode = code;
            }

            void PackedVertex::setCCode(size_t const& code) {
                cCode = code;
            }

            bool PackedVertex::operator==(PackedVertex const& p) const {
                return Maths::Point3D<GLint>(*this) == Maths::Point3D<GLint>(p) &&
                      getNCode() == p.getNCode() &&
                      getCCode() == p.getCCode();
            }

            bool PackedVertex::operator<(PackedVertex const& p) const {
                return Maths::Point3D<GLint>(*this) < Maths::Point3D<GLint>(p) &&
                      getNCode() < p.getNCode() &&
                      getCCode() < p.getCCode();
            }

            bool PackedVertex::operator>(PackedVertex const& p) const {
                return Maths::Point3D<GLint>(*this) > Maths::Point3D<GLint>(p) &&
                      getNCode() > p.getNCode() &&
                      getCCode() > p.getCCode();
            }

        };
    };
