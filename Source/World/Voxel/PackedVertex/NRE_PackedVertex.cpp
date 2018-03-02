
    #include "NRE_PackedVertex.hpp"

    namespace NRE {
        namespace Voxel {

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

            void PackedVertex::setNCode(size_t const& code) const {
                nCode = code;
            }

            void PackedVertex::setCCode(size_t const& code) const {
                cCode = code;
            }

            bool PackedVertex::operator<(PackedVertex const& p) {
                return Maths::Point3D<GLint>(*this) < Maths::Point3D<GLint>(p) &&
                      getNCode() < p.getNCode() &&
                      getCCode() < p.getCCode();
            }

            bool PackedVertex::operator>(PackedVertex const& p) {
                return Maths::Point3D<GLint>(*this) > Maths::Point3D<GLint>(p) &&
                      getNCode() > p.getNCode() &&
                      getCCode() > p.getCCode();
            }

            namespace std {

                size_t hash<PackedVertex>::operator()(PackedVertex const& p) const
                {
                    size_t h1 = p.Maths::Point3D<GLint>::getX();
                    size_t h2 = p.Maths::Point3D<GLint>::getY();
                    size_t h3 = p.Maths::Point3D<GLint>::getZ();

                    size_t hV = h3 * 100'000'000 + h2 * 1'000'000 + h1 * 10'000 + p.getNCode() * 1'000 + p.getCCode();
                    return hV;
                }

            };

        };
    };
