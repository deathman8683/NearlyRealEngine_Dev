
    #include "NRE_RGB.hpp"

    namespace NRE {
        namespace Color {

            GLubyte RGB::DEFAULT_R = 0;
            GLubyte RGB::DEFAULT_G = 0;
            GLubyte RGB::DEFAULT_B = 0;

            RGB::RGB() : r(DEFAULT_R), g(DEFAULT_G), b(DEFAULT_B) {
            }

            RGB::RGB(GLubyte const& r, GLubyte const& g, GLubyte const& b) : r(r), g(g), b(b) {
            }

            RGB::RGB(RGB const& color) : r(color.getR()), g(color.getG()), b(color.getB()) {
            }

            RGB::RGB(HSL const& color) {
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

            RGB::~RGB() {
            }

            GLubyte const& RGB::getR() const {
                return r;
            }

            GLubyte const& RGB::getG() const {
                return g;
            }

            GLubyte const& RGB::getB() const {
                return b;
            }

            void RGB::setR(GLubyte const& value) {
                r = value;
            }

            void RGB::setG(GLubyte const& value) {
                g = value;
            }

            void RGB::setB(GLubyte const& value) {
                b = value;
            }

            NREfloat RGB::distance(RGB const& c) const {
                return std::sqrt()
            }

            NREfloat RGB::distanceSquared(RGB const& c) const {
                NREfloat rLenght = c.getR() - getR();
                NREfloat gLenght = c.getG() - getG();
                NREflaot bLenght = c.getB() - getB();
                return rLenght * rLenght + gLenght * gLenght + bLenght * bLenght;
            }

            RGB& RGB::operator+=(RGB const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 + static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 + static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 + static_cast <NREfloat> (c.getB()) * 0.5));
            }

            RGB& RGB::operator-=(RGB const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 - static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 - static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 - static_cast <NREfloat> (c.getB()) * 0.5));
            }

            RGB RGB::operator+(RGB const& c) {
                RGB tmp(*this);
                return tmp += c;
            }

            RGB RGB::operator-(RGB const& c) {
                RGB tmp(*this);
                return tmp -= c;
            }

            RGB RGB::operator-() {
                return RGB(255 - getR(), 255 - getG(), 255 - getB());
            }

            bool RGB::operator==(RGB const& c) {
                return getR() == c.getR() && getG() == c.getG() && getB() == c.getB();
            }

            bool RGB::operator!=(RGB const& c) {
                return !(*this == c);
            }

            bool RGB::operator<(RGB const& c) {
                return distanceSquared() < c.distanceSquared();
            }

            bool RGB::operator>(RGB const& c) {
                return distanceSquared() > c.distanceSquared();
            }

            bool RGB::operator<=(RGB const& c) {
                return distanceSquared() <= c.distanceSquared();
            }

            bool RGB::operator>=(RGB const& c) {
                return distanceSquared() >= c.distanceSquared();
            }

            inline std::ostream& operator<<(std::ostream &stream, RGB const& c) {
                stream << "(" << static_cast <GLuint> (c.getR()) << "," << static_cast <GLuint> (c.getG()) << "," << static_cast <GLuint> (c.getB()) << ")";
                return stream;
            }

        };
    };
