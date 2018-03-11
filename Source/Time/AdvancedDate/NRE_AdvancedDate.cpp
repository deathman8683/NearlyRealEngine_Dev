
    #include "NRE_AdvancedDate.hpp"

    namespace NRE {
        namespace Time {

            AdvancedDate::AdvancedDate() : ms(0) {
            }

            AdvancedDate::AdvancedDate(AdvancedDate const& t) : Date::Date(t), ms(t.getMs()) {
            }

            AdvancedDate::~AdvancedDate() {
            }

            GLint const& AdvancedDate::getMs() const {
                return ms;
            }

            void AdvancedDate::setMs(GLint const& t) {
                ms = t;
            }

            void AdvancedDate::update(GLint const& increment) {
                setMs(getMs() + increment);
            }

            void AdvancedDate::convertMs() {
                Date::convertMs(getMs());
            }

        };
    };
