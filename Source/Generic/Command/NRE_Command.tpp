
    namespace NRE {

        template <class Receiver>
        Command<Receiver>::Command() : Command(0, 0) {
        }

        template <class Receiver>
        Command<Receiver>::Command(Receiver* target, void(Receiver::* method)()) {
            this->target = target;
            action = method;
        }

        template <class Receiver>
        Command<Receiver>::~Command() {
        }

        template <class Receiver>
        void Command<Receiver>::execute() {
            (target->*action)();
        }

    };
