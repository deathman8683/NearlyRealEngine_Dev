
    #include "NRE_Color.hpp"

    namespace NRE {
        namespace Color {

            RGB::RGB(HSL const& color) : RGB(DEFAULT_R, DEFAULT_G, DEFAULT_B) {
                if (almostEqual(color.getS(), 0.0)) {
                    NREfloat value = std::round(color.getL() * 255.0);
                    setR(value);
                    setG(value);
                    setB(value);
                } else {
                    NREfloat tmpL;
                    if (color.getL() <= 0.5) {
                        tmpL = color.getL() * (1.0 + color.getS());
                    } else {
                        tmpL = color.getL() + color.getS() - color.getL() * color.getS();
                    }

                    NREfloat tmpS = 2 * color.getL() - tmpL;
                    NREfloat cH = color.getH() / 360.0;

                    NREfloat rPrime, gPrime, bPrime;

                    rPrime = cH + 0.333;
                    gPrime = cH;
                    bPrime = cH - 0.333;

                    if (rPrime < 0.0) {
                        rPrime = rPrime + 1.0;
                    }
                    if (rPrime >= 1.0) {
                        rPrime = rPrime - 1.0;
                    }
                    if (gPrime < 0.0) {
                        gPrime = gPrime + 1.0;
                    }
                    if (gPrime >= 1.0) {
                        gPrime = gPrime - 1.0;
                    }
                    if (bPrime < 0.0) {
                        bPrime = bPrime + 1.0;
                    }
                    if (bPrime >= 1.0) {
                        bPrime = bPrime - 1.0;
                    }

                    if (6 * rPrime < 1.0) {
                        rPrime = tmpS + (tmpL - tmpS) * 6 * rPrime;
                    } else if (2 * rPrime < 1.0) {
                        rPrime = tmpL;
                    } else if (3 * rPrime < 2.0) {
                        rPrime = tmpS + (tmpL - tmpS) * (0.666 - rPrime) * 6;
                    } else {
                        rPrime = tmpS;
                    }

                    if (6 * gPrime < 1.0) {
                        gPrime = tmpS + (tmpL - tmpS) * 6 * gPrime;
                    } else if (2 * gPrime < 1.0) {
                        gPrime = tmpL;
                    } else if (3 * gPrime < 2.0) {
                        gPrime = tmpS + (tmpL - tmpS) * (0.666 - gPrime) * 6;
                    } else {
                        gPrime = tmpS;
                    }

                    if (6 * bPrime < 1.0) {
                        bPrime = tmpS + (tmpL - tmpS) * 6 * bPrime;
                    } else if (2 * bPrime < 1.0) {
                        bPrime = tmpL;
                    } else if (3 * bPrime < 2.0) {
                        bPrime = tmpS + (tmpL - tmpS) * (0.666 - bPrime) * 6;
                    } else {
                        bPrime = tmpS;
                    }

                    setR(static_cast <GLubyte> (std::round(rPrime * 255.0)));
                    setG(static_cast <GLubyte> (std::round(gPrime * 255.0)));
                    setB(static_cast <GLubyte> (std::round(bPrime * 255.0)));
                }
            }

            RGBA::RGBA(HSLA const& color) : RGBA(RGB(color), static_cast <GLubyte> (color.getA() * 255)) {
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

            HSLA::HSLA(RGBA const& color) : HSL::HSL(RGB(color.getR(), color.getG(), color.getB())), a(static_cast <NREfloat> (color.getA()) / 255.0) {
            }

        };
    };
