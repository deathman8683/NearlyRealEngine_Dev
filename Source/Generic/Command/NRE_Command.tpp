
    namespace NRE {

        template <class Receiver>
        Command<Receiver>::Command() : Command(0, 0) {
        }

        template <class Receiver>
        Command<Receiver>::Command(Receiver* target, void(Receiver::* method)()) : target(target), action(method) {
        }

        template <class Receiver>
        Command<Receiver>::Command(Command const& cmd) : target(cmd.target), action(cmd.action) {
        }

        template <class Receiver>
        Command<Receiver>::~Command() {
        }

        template <class Receiver>
        void Command<Receiver>::execute() {
            (target->*action)();
        }

        template <class Receiver>
        Command<Receiver>& Command<Receiver>::operator=(Command<Receiver> const& base) {
            target = base.target;
            action = base.action;
            return *this;
        }

        template <class Receiver>
        Command<Receiver>& Command<Receiver>::operator=(Command<Receiver> && base) {
            target = std::move(base.target);
            action = std::move(base.action);
            return *this;
        }

    };
