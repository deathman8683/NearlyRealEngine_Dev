
    #include "NRE_RGBA.hpp"

    namespace NRE {
        namespace Color {

            RGBA::RGBA() : a(DEFAULT_A) {
            }

            RGBA::RGBA(GLubyte const& r, GLubyte const& g, GLubyte const& b, GLubyte const& a) : RGB::RGB(r, g, b), a(a) {
            }

            RGBA::RGBA(RGB const& color, GLubyte const& a) : RGB::RGB(color), a(a) {
            }

            RGBA::RGBA(RGBA const& color) : RGB::RGB(color), a(color.getA()) {
            }

            RGBA::RGBA(HSLA const& color) : RGB::RGB(color), a(static_cast <GLubyte> (color.getA() * 255)) {
            }

            RGBA::~RGBA() {
            }

            GLubyte const& RGBA::getA() const {
                return a;
            }

            void RGBA::setA(GLubyte const& value) {
                a = value;
            }

            NREfloat RGBA::distance(RGBA const& c) const {
                return std::sqrt(distanceSquared(c));
            }

            NREfloat RGBA::distanceSquared(RGBA const& c) const {
                NREfloat aLenght = c.getA() - getA();
                return RGB::distanceSquared(c) + aLenght * aLenght;
            }

            RGBA& RGBA::operator+=(RGBA const& c) {
                RGB::operator+=(c);
                setA(static_cast <GLubyte> (static_cast <NREfloat> (getA()) * 0.5 + static_cast <NREfloat> (c.getA()) * 0.5));
            }

            RGBA& RGBA::operator-=(RGBA const& c) {
                RGB::operator-=(c);
                setA(static_cast <GLubyte> (static_cast <NREfloat> (getA()) * 0.5 - static_cast <NREfloat> (c.getA()) * 0.5));
            }

            RGBA RGBA::operator+(RGBA const& c) {
                RGBA tmp(*this);
                return tmp += c;
            }

            RGBA RGBA::operator-(RGBA const& c) {
                RGBA tmp(*this);
                return tmp -= c;
            }

            RGBA RGBA::operator-() {
                return RGBA(RGB::operator-(), 255 - getA());
            }

            bool RGBA::operator==(RGBA const& c) {
                return RGB::operator==(c) && getA() == c.getA();
            }

            bool RGBA::operator!=(RGBA const& c) {
                return !(*this == c);
            }

            bool RGBA::operator<(RGBA const& c) {
                return distanceSquared() < c.distanceSquared();
            }

            bool RGBA::operator>(RGBA const& c) {
                return distanceSquared() > c.distanceSquared();
            }

            bool RGBA::operator<=(RGBA const& c) {
                return distanceSquared() <= c.distanceSquared();
            }

            bool RGBA::operator>=(RGBA const& c) {
                return distanceSquared() >= c.distanceSquared();
            }

            inline std::ostream& operator<<(std::ostream &stream, RGBA const& c) {
                stream << "(" << static_cast <GLuint> (c.getR()) << "," << static_cast <GLuint> (c.getG()) << "," << static_cast <GLuint> (c.getB()) << "," << static_cast <GLuint> (c.getA()) << ")";
                return stream;
            }

        };
    };
