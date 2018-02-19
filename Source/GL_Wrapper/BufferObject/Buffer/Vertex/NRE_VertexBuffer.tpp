
    namespace NRE {
        namespace GL {

            template <class T>
            VertexBuffer<T>::VertexBuffer(GLenum const& type, bool const& generate) : type(type) {
                if (generate) {
                    generateID();
                }
            }

            template <class T>
            VertexBuffer<T>::VertexBuffer(VertexBufferc const& buf) : Buffer::Buffer(buf), type(buf.getType()) {
            }

            template <class T>
            VertexBuffer<T>::~VertexBuffer() {
                deleteID();
            }

            template <class T>
            GLenum const& VertexBuffer<T>::getType() const {
                return type;
            }

            template <class T>
            void VertexBuffer<T>::setType(GLenum const& type) {
                this->type = type;
            }

            template <class T>
            void VertexBuffer<T>::generateID() {
                glGenBuffers(1, &id);
            }

            template <class T>
            void VertexBuffer<T>::deleteID() {
                glDeleteBuffers(1, &id);
            }

            template <class T>
            void VertexBuffer<T>::reload() {
                deleteID();
                generateID();
            }

            template <class T>
            void VertexBuffer<T>::allocate(unsigned int const& vertices, GLenum const& usage) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferData(GL_ARRAY_BUFFER, sizeof(T) * vertices * 3, NULL, usage);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

            template <class T>
            void VertexBuffer<T>::update(unsigned int const& vertices, GLvoid* const data) {
                glBindBuffer(GL_ARRAY_BUFFER, getID());
                glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(T) * vertices * 3, data);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
            }

        };
    };
