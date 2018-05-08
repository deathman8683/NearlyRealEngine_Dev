
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
            T const& Data<T>::getValue(GLuint const& index) const {
                return data.at(index);
            }

            template <class T>
            void Data<T>::add(GLvoid* value, GLuint const& nbValue) {
                T* v = static_cast <T*> (value);
                for (GLuint i = 0; i < nbValue; i = i + 1) {
                    data.push_back(v[i]);
                }
            }

            template <class T>
            size_t const Data<T>::size() const {
                return data.size();
            }

            template <class T>
            size_t const Data<T>::getTypeSize() const {
                return sizeof(T);
            }

            template <class T>
            size_t const Data<T>::getDataSize() const {
                return size() * getTypeSize();
            }

            template <class T>
            GLvoid* const Data<T>::value() {
                return &data[0];
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
