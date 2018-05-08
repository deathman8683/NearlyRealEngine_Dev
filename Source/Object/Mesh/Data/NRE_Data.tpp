
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
            T const& Data<T>::get(GLuint const& index) const {
                return data.at(index);
            }

            template <class T>
            void Data<T>::add(void* value, GLuint const& nbValue) {
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
            const T* const Data<T>::value() const {
                return &data[0];
            }

            template <class T>
            void Data<T>::update(const GL::AttributeBuffer* const& buffer, GLintptr const& offset) const {
                buffer->update(offset, size(), value());
            }

            template <class T>
            void Data<T>::allocateAndFill(const GL::AttributeBuffer* const& buffer, GLenum const& usage) const {
                buffer->allocateAndFill(size(), usage, value());
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
