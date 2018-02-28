
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

            }

            RGBA RGBA::operator+(RGBA const& c) {

            }

            RGBA RGBA::operator-(RGBA const& c) {

            }

            RGBA RGBA::operator-() {

            }

            bool RGBA::operator==(RGBA const& c) {

            }

            bool RGBA::operator!=(RGBA const& c) {

            }

            bool RGBA::operator<(RGBA const& c) {

            }

            bool RGBA::operator>(RGBA const& c) {

            }

            bool RGBA::operator<=(RGBA const& c) {

            }

            bool RGBA::operator>=(RGBA const& c) {

            }

            inline std::ostream& operator<<(std::ostream &stream, RGBA const& c);

        };
    };
