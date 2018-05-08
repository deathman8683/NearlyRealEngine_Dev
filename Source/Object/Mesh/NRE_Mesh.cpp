
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace Object {

            Mesh::Mesh() {
            }

            Mesh::Mesh(Mesh const& m) : data(m.data) {
            }

            Mesh::Mesh(Mesh && m) : data(std::move(m.data)) {
            }

            Mesh::~Mesh() {
                for (DataSet* d : data) {
                    delete d;
                }
                data.erase(data.begin(), data.end());
            }

            void Mesh::push_back(DataSet* d) {
                data.push_back(d);
            }

            Mesh& Mesh::operator=(Mesh const& m) {
                data = m.data;
                return *this;
            }

            Mesh& Mesh::operator=(Mesh && m) {
                data = std::move(m.data);
                return *this;
            }

        };
    };
