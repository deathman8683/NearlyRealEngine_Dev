
    #include "NRE_HSL.hpp"

    namespace NRE {
        namespace Color {

            unsigned short int HSL::DEFAULT_H = 0;
            NREfloat HSL::DEFAULT_S = 0;
            NREfloat HSL::DEFAULT_L = 0;

            HSL::HSL() : h(DEFAULT_H), s(DEFAULT_S), l(DEFAULT_L) {
            }

            HSL::HSL(unsigned short int const& h, NREfloat const& s, NREfloat const& l) : h(h), s(s), l(l) {
            }

            HSL::HSL(HSL const& color) : h(color.getH()), s(color.getS()), l(color.getL()) {
            }

            HSL::HSL(RGB const& color) : h(DEFAULT_H), s(DEFAULT_S), l(DEFAULT_L)  {
                NREfloat rPrime = static_cast <NREfloat> (color.getR()) / 255.0;
                NREfloat gPrime = static_cast <NREfloat> (color.getG()) / 255.0;
                NREfloat bPrime = static_cast <NREfloat> (color.getB()) / 255.0;
                NREfloat cMax = std::max({rPrime, gPrime, bPrime});
                NREfloat cMin = std::min({rPrime, gPrime, bPrime});
                NREfloat delta = cMax - cMin;

                if (delta == 0) {
                    setH(0);
                }
                if (cMax == rPrime) {
                    setH(60 * ((static_cast <unsigned short int> ((gPrime - bPrime) / delta)) % 6));
                }
                if (cMax == gPrime) {
                    setH(60 * ((static_cast <unsigned short int> ((bPrime - rPrime) / delta)) + 2));
                }
                if (cMax == bPrime) {
                    setH(60 * ((static_cast <unsigned short int> ((rPrime - gPrime) / delta)) + 4));
                }

                setL((cMax + cMin) / 2);

                if (delta == 0) {
                    setS(0);
                } else {
                    setS(delta / (1 - std::abs(2 * lightness - 1)));
                }

                setH(hue);
            }

            HSL::~HSL() {
            }

            unsigned short int const& HSL::getH() const {
                return h;
            }

            NREfloat const& HSL::getS() const {
                return s;
            }

            NREfloat const& HSL::getL() const {
                return l;
            }

            void HSL::setH(unsigned short int const& value) {
                h = value;
            }

            void HSL::setS(NREfloat const& value) {
                s = value;
            }

            void HSL::setL(NREfloat const& value) {
                l = value;
            }

            HSL& HSL::operator+=(HSL const& c) {
                *this = HSL(RGB(*this) + RGB(c));
                return *this;
            }

            HSL& HSL::operator-=(HSL const& c) {
                *this = HSL(RGB(*this) - RGB(c));
                return *this;
            }

            HSL HSL::operator+(HSL const& c) {
                HSL tmp(*this);
                return tmp += c;
            }

            HSL HSL::operator-(HSL const& c) {
                HSL tmp(*this);
                return tmp -= c;
            }

            HSL HSL::operator-() {
                return -RGB(*this);
            }

            inline std::ostream& operator<<(std::ostream &stream, HSL const& c) {
                stream << "(" << c.getH() << "," << c.getS() << "," << c.getL() << ")";
                return stream;
            }

        };
    };
