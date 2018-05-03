
    namespace NRE {
        namespace Support {

            Thread::Thread() {
            }

            template <class Function, class... Args>
            Thread::Thread(Function&& f, Args&&... args) : item(std::forward<Function>(f), std::forward<Args>(args)...) {
            }

            Thread::Thread(Thread && t) : item(std::move(t.item)) {
            }

            Thread::~Thread() {
            }

            void Thread::join() {
                item.join();
            }

            std::thread&& Thread::getItem() {
                return std::move(item);
            }

            Thread& Thread::operator=(Thread && t) {
                item = t.getItem();
                return *this;
            }

        };
    };
