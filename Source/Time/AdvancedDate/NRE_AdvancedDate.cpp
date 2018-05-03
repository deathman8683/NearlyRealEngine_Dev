
    #include "NRE_AdvancedDate.hpp"

    namespace NRE {
        namespace Time {

            AdvancedDate::AdvancedDate() : ms(0) {
            }

            AdvancedDate::AdvancedDate(AdvancedDate const& t) : Date::Date(t), ms(t.getMs()) {
            }

            AdvancedDate::AdvancedDate(AdvancedDate && t) : Date::Date(std::move(t)), ms(std::move(t.getMs())) {
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

            AdvancedDate& AdvancedDate::operator=(AdvancedDate const& t) {
                Date::operator=(t);
                ms = t.ms;
                return *this;
            }

            AdvancedDate& AdvancedDate::operator=(AdvancedDate && t) {
                Date::operator=(std::move(t));
                ms = std::move(t.ms);
                return *this;
            }

        };
    };
