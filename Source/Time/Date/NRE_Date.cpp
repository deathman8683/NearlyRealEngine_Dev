
    #include "NRE_Date.hpp"

    namespace NRE {
        namespace Time {

            Date::Date() : Date(0, 0, 0) {
            }

            Date::Date(GLint const& h, GLint const& m, GLint const& s) : h(h), m(m), s(s) {
            }

            Date::Date(GLint const& time) {
                convertMs(time);
            }

            Date::Date(Date const& d) : h(d.getH()), m(d.getM()), s(d.getS()) {
            }

            Date::~Date() {
            }

            GLint const& Date::getH() const {
                return h;
            }

            GLint const& Date::getM() const {
                return m;
            }

            GLint const& Date::getS() const {
                return s;
            }

            void Date::setH(GLint const& v) {
                h = v;
            }

            void Date::setM(GLint const& v) {
                m = v;
            }

            void Date::setS(GLint const& v) {
                s = v;
            }

            void Date::convertMs(GLint const& time) {
                GLint tmpS, tmpM, tmpH;
                tmpS = time / 1000;
                tmpM = tmpS / 60;
                tmpS = tmpS - (tmpM * 60);
                tmpH = tmpM / 60;
                tmpM = tmpM - (tmpH * 60);
                setS(tmpS);
                setM(tmpM);
                setH(tmpH);
            }

        };
    };
