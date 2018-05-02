
    #include "NRE_RGB.hpp"

    namespace NRE {
        namespace Color {

            GLubyte RGB::DEFAULT_R = 0;
            GLubyte RGB::DEFAULT_G = 0;
            GLubyte RGB::DEFAULT_B = 0;

            RGB::RGB() : RGB(DEFAULT_R, DEFAULT_G ,DEFAULT_B) {
            }

            RGB::RGB(GLubyte const& r, GLubyte const& g, GLubyte const& b) : Maths::Vector3D<GLubyte>::Vector3D(r, g, b) {
            }

            RGB::RGB(RGB const& color) : Maths::Vector3D<GLubyte>::Vector3D(color) {
            }

            RGB::RGB(RGB && color) : Maths::Vector3D<GLubyte>::Vector3D(std::move(color)) {
            }

            RGB::~RGB() {
            }

            RGB& RGB::operator=(RGB const& color) {
                Maths::Vector3D<GLubyte>::operator=(color);
                return *this;
            }

            RGB& RGB::operator=(RGB && color) {
                Maths::Vector3D<GLubyte>::operator=(std::move(color));
                return *this;
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

        };
    };
