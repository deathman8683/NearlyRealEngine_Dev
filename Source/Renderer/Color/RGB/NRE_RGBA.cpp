
    #include "NRE_RGBA.hpp"

    namespace NRE {
        namespace Color {

            GLubyte RGBA::DEFAULT_R = 0;
            GLubyte RGBA::DEFAULT_G = 0;
            GLubyte RGBA::DEFAULT_B = 0;
            GLubyte RGBA::DEFAULT_A = 0;

            RGBA::RGBA() : RGBA(DEFAULT_R, DEFAULT_G, DEFAULT_B, DEFAULT_A) {
            }

            RGBA::RGBA(GLubyte const& r, GLubyte const& g, GLubyte const& b, GLubyte const& a) : Maths::Vector4D<GLubyte>::Vector4D(r, g, b, a) {
            }

            RGBA::RGBA(RGB const& color, GLubyte const& a) : Maths::Vector4D<GLubyte>::Vector4D(color, a) {
            }

            RGBA::RGBA(RGBA const& color) : Maths::Vector4D<GLubyte>::Vector4D(color) {
            }

            RGBA::RGBA(RGBA && color) : Maths::Vector4D<GLubyte>::Vector4D(std::move(color)) {
            }

            RGBA::~RGBA() {
            }

            RGBA& RGBA::operator=(RGBA const& color) {
                Maths::Vector4D<GLubyte>::operator=(color);
                return *this;
            }

            RGBA& RGBA::operator=(RGBA && color) {
                Maths::Vector4D<GLubyte>::operator=(std::move(color));
                return *this;
            }

            RGBA& RGBA::operator+=(RGBA const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 + static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 + static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 + static_cast <NREfloat> (c.getB()) * 0.5));
                setA(static_cast <GLubyte> (static_cast <NREfloat> (getA()) * 0.5 + static_cast <NREfloat> (c.getA()) * 0.5));
                return *this;
            }

            RGBA& RGBA::operator-=(RGBA const& c) {
                setR(static_cast <GLubyte> (static_cast <NREfloat> (getR()) * 0.5 - static_cast <NREfloat> (c.getR()) * 0.5));
                setG(static_cast <GLubyte> (static_cast <NREfloat> (getG()) * 0.5 - static_cast <NREfloat> (c.getG()) * 0.5));
                setB(static_cast <GLubyte> (static_cast <NREfloat> (getB()) * 0.5 - static_cast <NREfloat> (c.getB()) * 0.5));
                setA(static_cast <GLubyte> (static_cast <NREfloat> (getA()) * 0.5 - static_cast <NREfloat> (c.getA()) * 0.5));
                return *this;
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
                return RGBA(255 - getR(), 255 - getG(), 255 - getB(), 255 - getA());
            }

        };
    };
