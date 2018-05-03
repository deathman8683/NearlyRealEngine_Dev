
    #include "NRE_Timestep.hpp"

    namespace NRE {
        namespace Time {

            Timestep::Timestep() : actualTime(0), lastTime(0) {
            }

            Timestep::Timestep(Timestep const& t) : actualTime(t.getActualTime()), lastTime(t.getLastTime()) {
            }

            Timestep::Timestep(Timestep && t) : actualTime(std::move(t.getActualTime())), lastTime(std::move(t.getLastTime())) {
            }

            Timestep::~Timestep() {
            }

            NREfloat const& Timestep::getActualTime() const {
                return actualTime;
            }

            NREfloat const& Timestep::getLastTime() const {
                return lastTime;
            }

            NREfloat const Timestep::getTimestep() const {
                return actualTime - lastTime;
            }

            void Timestep::setActualTime(NREfloat const& t) {
                actualTime = t;
            }

            void Timestep::setLastTime(NREfloat const& t) {
                lastTime = t;
            }

            void Timestep::updateLastTime() {
                setLastTime(getActualTime());
            }

            void Timestep::updateActualTime() {
                setActualTime(SDL_GetTicks());
            }

            void Timestep::update() {
                updateLastTime();
                updateActualTime();
            }

            Timestep& Timestep::operator=(Timestep const& t) {
                actualTime = t.actualTime;
                lastTime = t.lastTime;
                return *this;
            }

            Timestep& Timestep::operator=(Timestep && t) {
                actualTime = std::move(t.actualTime);
                lastTime = std::move(t.lastTime);
                return *this;
            }

        };
    };
