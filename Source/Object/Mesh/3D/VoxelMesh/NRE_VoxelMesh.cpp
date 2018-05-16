
    #include "NRE_<Class>.hpp"

    namespace NRE {
        namespace Object {

            <Class>::<Class>() {
            }

            <Class>::<Class>(<Class> const& <Var>) {
            }

            <Class>::<Class>(<Class> && <Var>) {
            }

            <Class>::~<Class>() {
            }

            <Class>& <Class>::operator=(<Class> const& <Var>) {
                return *this;
            }

            <Class>& <Class>::operator=(<Class> && <Var>) {
                return *this;
            }

        };
    };
