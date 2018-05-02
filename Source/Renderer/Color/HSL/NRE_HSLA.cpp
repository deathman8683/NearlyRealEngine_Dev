
    #include "NRE_HSLA.hpp"

    namespace NRE {
        namespace Color {

            NREfloat HSLA::DEFAULT_A = 0;

            HSLA::HSLA() : a(DEFAULT_A) {
            }

            HSLA::HSLA(unsigned short int const& h, NREfloat const& s, NREfloat const& l, NREfloat const& a) : HSL::HSL(h, s, l), a(a) {
            }

            HSLA::HSLA(HSL const& color, NREfloat const& a) : HSL::HSL(color), a(a) {
            }

            HSLA::HSLA(HSLA const& color) : HSL::HSL(color), a(color.getA()) {
            }

            HSLA::HSLA(HSLA && color) : HSL::HSL(std::move(color)), a(std::move(color.getA())) {
            }

            HSLA::~HSLA() {
            }

            NREfloat const& HSLA::getA() const {
                return a;
            }

            void HSLA::setA(NREfloat const& value) {
                a = value;
            }

            HSLA& HSLA::operator=(HSLA const& color) {
                HSL::operator=(color);
                a = color.getA();
                return *this;
            }

            HSLA& HSLA::operator=(HSLA && color) {
                HSL::operator=(std::move(color));
                a = std::move(color.getA());
                return *this;
            }

            HSLA& HSLA::operator+=(HSLA const& c) {
                HSL::operator+=(c);
                setA(getA() * 0.5 + c.getA() * 0.5);
                return *this;
            }

            HSLA& HSLA::operator-=(HSLA const& c) {
                HSL::operator-=(c);
                setA(getA() * 0.5 - c.getA() * 0.5);
                return *this;
            }

            HSLA HSLA::operator+(HSLA const& c) {
                HSLA tmp(*this);
                return tmp += c;
            }

            HSLA HSLA::operator-(HSLA const& c) {
                HSLA tmp(*this);
                return tmp -= c;
            }

            HSLA HSLA::operator-() {
                return HSLA(HSL::operator-(), 1.0 - getA());
            }

        };
    };
