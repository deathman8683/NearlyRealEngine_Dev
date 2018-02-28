
    #include "NRE_Color.hpp"

    namespace NRE {
        namespace Color {

            RGB::RGB(HSL const& color) : r(DEFAULT_R), g(DEFAULT_G), b(DEFAULT_B) {
                NREfloat c = (1 - std::abs(2 * color.getL() - 1 * color.getS()));
                NREfloat x = c * (1 - std::abs((color.getH() / 60) % 2 - 1));
                NREfloat m = color.getL() - c / 2;

                NREfloat rPrime, gPrime, bPrime;

                if (color.getH() >= 0 && color.getH() < 60) {
                    rPrime = c;
                    gPrime = x;
                    bPrime = 0;
                } else if (color.getH() >= 60 && color.getH() < 120) {
                    rPrime = x;
                    gPrime = c;
                    bPrime = 0;
                } else if (color.getH() >= 120 && color.getH() < 180) {
                    rPrime = 0;
                    gPrime = c;
                    bPrime = x;
                } else if (color.getH() >= 180 && color.getH() < 240) {
                    rPrime = 0;
                    gPrime = c;
                    bPrime = c;
                } else if (color.getH() >= 240 && color.getH() < 300) {
                    rPrime = x;
                    gPrime = 0;
                    bPrime = c;
                } else {
                    rPrime = c;
                    gPrime = 0;
                    bPrime = x;
                }

                setR(static_cast <GLubyte>((rPrime + m) * 255));
                setG(static_cast <GLubyte>((gPrime + m) * 255));
                setB(static_cast <GLubyte>((bPrime + m) * 255));
            }

            RGBA::RGBA(HSLA const& color) : RGB::RGB(color), a(static_cast <GLubyte> (color.getA() * 255)) {
            }

            HSL::HSL(RGB const& color) : h(DEFAULT_H), s(DEFAULT_S), l(DEFAULT_L)  {
                NREfloat rPrime = static_cast <NREfloat> (color.getR()) / 255.0;
                NREfloat gPrime = static_cast <NREfloat> (color.getG()) / 255.0;
                NREfloat bPrime = static_cast <NREfloat> (color.getB()) / 255.0;
                NREfloat cMax = std::max(std::max(rPrime, gPrime), bPrime);
                NREfloat cMin = std::min(std::min(rPrime, gPrime), bPrime);
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
                    setS(delta / (1 - std::abs(2 * getL() - 1)));
                }
            }

            HSL& HSL::operator+=(HSL const& c) {
                *this = HSL(RGB(*this) + RGB(c));
                return *this;
            }

            HSL& HSL::operator-=(HSL const& c) {
                *this = HSL(RGB(*this) - RGB(c));
                return *this;
            }

            HSL HSL::operator-() {
                return -RGB(*this);
            }

            HSLA::HSLA(RGBA const& color) : HSL::HSL(color), a(static_cast <NREfloat> (color.getA()) / 255.0) {
            }

        };
    };
