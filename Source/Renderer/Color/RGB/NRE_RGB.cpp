
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
                return std::sqrt(distanceSquared(c));
            }

            NREfloat RGB::distanceSquared(RGB const& c) const {
                NREfloat rLenght = c.getR() - getR();
                NREfloat gLenght = c.getG() - getG();
                NREfloat bLenght = c.getB() - getB();
                return rLenght * rLenght + gLenght * gLenght + bLenght * bLenght;
            }

            RGB& RGB::operator+=(RGB const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 + static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 + static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 + static_cast <NREfloat> (c.getB()) * 0.5));
                return *this;
            }

            RGB& RGB::operator-=(RGB const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 - static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 - static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 - static_cast <NREfloat> (c.getB()) * 0.5));
                return *this;
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

        };
    };
