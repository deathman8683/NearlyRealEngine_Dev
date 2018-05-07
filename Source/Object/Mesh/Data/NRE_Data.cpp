
    #include "NRE_Data.hpp"

    namespace NRE {
        namespace Object {

            template <class T>
            Data<T>::Data() {
            }

            template <class T>
            Data<T>::Data(Data const& d) {
            }

            template <class T>
            Data<T>::Data(Data && d) {
            }

            template <class T>
            Data<T>::~Data() {
            }

            template <class T>
            Data& Data<T>::operator=(Data const& d) {
                return *this;
            }

            template <class T>
            Data& Data<T>::operator=(Data && d) {
                return *this;
            }

        };
    };
