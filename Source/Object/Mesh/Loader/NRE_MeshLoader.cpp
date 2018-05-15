
    #include "NRE_MeshLoader.hpp"

    namespace NRE {
        namespace Object {

            MeshLoader::MeshLoader() : target(0) {
            }

            MeshLoader::MeshLoader(Mesh3D* mesh, std::string const& path) : target(mesh) {
                load(path);
            }

            MeshLoader::MeshLoader(MeshLoader const& ml) : target(ml.target) {
            }

            MeshLoader::MeshLoader(MeshLoader && ml) : target(std::move(ml.target)) {
            }

            MeshLoader::~MeshLoader() {
            }

            void MeshLoader::load(std::string const& path) {
                std::fstream meshFile;
                meshFile.open(path, std::ios::in);
                if (!meshFile.is_open()) {
                    throw (Exception::IOException("Mesh File could not be open : " + path));
                }
                while (!meshFile.eof()) {
                    std::string tmp;
                    std::getline(meshFile, tmp);

                    GLint n = tmp.find_first_of(" ");
                    std::string firstWord = tmp.substr(0, n);
                    if (firstWord.compare("v") == 0) {
                        std::stringstream v(tmp.substr(n + 1));
                        NREfloat x, y, z;
                        v >> x >> y >> z;
                        Maths::Point3D<NREfloat> vertex(x, y, z);
                        target->add(0, vertex.value(), 3);
                    } else if (firstWord.compare("vn") == 0) {
                        std::stringstream vn(tmp.substr(n + 1));
                        NREfloat x, y, z;
                        vn >> x >> y >> z;
                        Maths::Vector3D<NREfloat> normal(x, y, z);
                        target->add(2, normal.value(), 3);
                    } else if (firstWord.compare("f") == 0) {
                        std::stringstream f(tmp.substr(n + 1));
                        std::string indexLine;
                        std::vector<GLuint> idx;
                        GLuint cpt = 0;
                        while (std::getline(f, indexLine, ' ')) {
                        std::stringstream index(indexLine);
                            GLuint id;
                            index >> id;
                            id = id - 1;
                            idx.push_back(id);
                            cpt = cpt + 1;
                        }
                        //std::sort(idx.begin(), idx.end());
                        if (cpt == 4) {
                            target->add(3, &idx[3]);
                            target->add(3, &idx[1]);
                            target->add(3, &idx[0]);
                            target->add(3, &idx[1]);
                            target->add(3, &idx[3]);
                            target->add(3, &idx[2]);
                        } else {
                            target->add(3, &idx[0]);
                            target->add(3, &idx[1]);
                            target->add(3, &idx[2]);
                        }
                    } else {
                        //std::cout << tmp << std::endl;
                    }
                }

                GLubyte material = 16;
                for (GLuint i = 0; i < target->getDataSet(0)->size() / 3; i = i + 1) {
                    target->add(1, &material);
                }
            }

            MeshLoader& MeshLoader::operator=(MeshLoader const& ml) {
                target = ml.target;
                return *this;
            }

            MeshLoader& MeshLoader::operator=(MeshLoader && ml) {
                target = std::move(ml.target);
                return *this;
            }

        };
    };
