
    namespace NRE {
        namespace Object {

            template <class T>
            Data<T>::Data() {
            }

            template <class T>
            Data<T>::Data(Data const& d) : data(d.data) {
            }

            template <class T>
            Data<T>::Data(Data && d) : data(std::move(d.data)) {
            }

            template <class T>
            Data<T>::~Data() {
            }

            template <class T>
            Data<T>& Data<T>::operator=(Data const& d) {
                data = d.data;
                return *this;
            }

            template <class T>
            Data<T>& Data<T>::operator=(Data && d) {
                data = std::move(d.data);
                return *this;
            }

        };
    };
