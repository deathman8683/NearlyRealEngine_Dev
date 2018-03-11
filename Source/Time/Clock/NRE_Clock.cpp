
    #include "NRE_Clock.hpp"

    namespace NRE {
        namespace Time {

            Clock::Clock() {
            }

            Clock::Clock(Clock const& c) : AdvancedDate::AdvancedDate(c), Timestep::Timestep(c) {
            }

            Clock::~Clock() {
            }

            void Clock::updateTimestep(NREfloat const& minTimestep) {
                Timestep::update();
                if (getTimestep() <= minTimestep) {
                    SDL_Delay(minTimestep - getTimestep());
                    updateActualTime();
                }
            }

            void Clock::updateTime(bool const& convert) {
                AdvancedDate::update(getTimestep());
                if (convert) {
                    convertMs();
                }
            }

        };
    };
