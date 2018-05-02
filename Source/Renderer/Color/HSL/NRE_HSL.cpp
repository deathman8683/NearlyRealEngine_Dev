
    #include "NRE_HSL.hpp"

    namespace NRE {
        namespace Color {

            unsigned short int HSL::DEFAULT_H = 0;
            NREfloat HSL::DEFAULT_S = 0;
            NREfloat HSL::DEFAULT_L = 0;

            HSL::HSL() : HSL(DEFAULT_H, DEFAULT_S, DEFAULT_L) {
            }

            HSL::HSL(unsigned short int const& h, NREfloat const& s, NREfloat const& l) : h(h), s(s), l(l) {
            }

            HSL::HSL(HSL const& color) : h(color.getH()), s(color.getS()), l(color.getL()) {
            }

            HSL::HSL(HSL && color) : h(std::move(color.getH())), s(std::move(color.getS())), l(std::move(color.getL())) {
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

            HSL& HSL::operator=(HSL const& color) {
                h = color.getH();
                s = color.getS();
                l = color.getL();
                return *this;
            }

            HSL& HSL::operator=(HSL && color) {
                h = std::move(color.getH());
                s = std::move(color.getS());
                l = std::move(color.getL());
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

        };
    };
