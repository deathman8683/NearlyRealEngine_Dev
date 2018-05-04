
    #include "NRE_Mouse.hpp"

    namespace NRE {
        namespace Camera {

            unsigned int Mouse::NUM_BUTTONS = SDL_BUTTON_X2 + 1;
            NREfloat Mouse::DEFAULT_SENSITIVITY = 0.1;

            Mouse::Mouse() : KeyBinder::KeyBinder(NUM_BUTTONS), sensitivity(DEFAULT_SENSITIVITY) {
            }

            Mouse::Mouse(Maths::Point2D<unsigned short int> const& click, Maths::Point2D<unsigned short int> const& cursor, NREfloat const& sensitivity) : KeyBinder::KeyBinder(NUM_BUTTONS), click(click), cursor(cursor), sensitivity(sensitivity) {
            }

            Mouse::Mouse(Mouse const& m) : KeyBinder::KeyBinder(m), click(m.getClick()), cursor(m.getCursor()), sensitivity(m.getSensitivity()) {
            }

            Mouse::Mouse(Mouse && m) : KeyBinder::KeyBinder(std::move(m)), click(std::move(m.getClick())), cursor(std::move(m.getCursor())), sensitivity(std::move(m.getSensitivity())) {
            }

            Mouse::~Mouse() {
            }

            Maths::Point2D<unsigned short int> const& Mouse::getClick() const {
                return click;
            }

            Maths::Point2D<unsigned short int> const& Mouse::getCursor() const {
                return cursor;
            }

            NREfloat const& Mouse::getSensitivity() const {
                return sensitivity;
            }

            void Mouse::setClick(Maths::Point2D<unsigned short int> const& p) {
                click = p;
            }

            void Mouse::setCursor(Maths::Point2D<unsigned short int> const& p) {
                cursor = p;
            }

            void Mouse::setSensitivity(NREfloat const& s) {
                sensitivity = s;
            }

            Mouse& Mouse::operator=(Mouse const& m) {
                KeyBinder::operator=(m);
                click = m.click;
                cursor = m.cursor;
                sensitivity = m.sensitivity;
                return *this;
            }

            Mouse& Mouse::operator=(Mouse && m) {
                KeyBinder::operator=(std::move(m));
                click = std::move(m.click);
                cursor = std::move(m.cursor);
                sensitivity = std::move(m.sensitivity);
                return *this;
            }

        };
    };
