
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(Object3D && o) : Object::Object(std::move(o)) {
            }

            Object3D::~Object3D() {
            }

            void Object3D::load(GLenum const& usage, IO::File const& file) {
                if (!file.exist()) {
                    throw (Exception::FileNotExistingException(file.getPath()));
                }
                Assimp::Importer importer;
                const aiScene* scene = importer.ReadFile(file.getPath(), aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

                if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE ||!scene->mRootNode) {
                    throw (Exception::AssimpException(importer.GetErrorString()));
                }

                processNode(scene->mRootNode, scene);
                allocateAndFill(usage);
            }

            void Object3D::processNode(aiNode *node, const aiScene *scene) {
                for (GLuint i = 0; i < node->mNumMeshes; i = i + 1) {
                    aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
                    meshes.push_back(processMesh(mesh, scene));
                }

                for (GLuint i = 0; i < node->mNumChildren; i = i + 1) {
                    processNode(node->mChildren[i], scene);
                }
            }

            Mesh3D* Object3D::processMesh(aiMesh *mesh, const aiScene *scene) {
                Mesh3D* nreMesh = new Mesh3D(GL_FLOAT);
                GLuint material = 15 + mesh->mMaterialIndex;

                for (GLuint i = 0; i < mesh->mNumVertices; i = i + 1) {
                    Maths::Vector3D<NREfloat> vector;
                    vector.setX(mesh->mVertices[i].x);
                    vector.setY(mesh->mVertices[i].y);
                    vector.setZ(mesh->mVertices[i].z);
                    nreMesh->add(0, vector.value(), 3);
                    vector.setX(mesh->mNormals[i].x);
                    vector.setY(mesh->mNormals[i].y);
                    vector.setZ(mesh->mNormals[i].z);
                    nreMesh->add(2, vector.value(), 3);
                    vector.setX(mesh->mTangents[i].x);
                    vector.setY(mesh->mTangents[i].y);
                    vector.setZ(mesh->mTangents[i].z);
                    nreMesh->add(3, vector.value(), 3);
                    nreMesh->add(1, &material);
                    Maths::Vector2D<NREfloat> uv;
                    if (mesh->mTextureCoords[0]) {
                        uv.setX(mesh->mTextureCoords[0][i].x);
                        uv.setY(mesh->mTextureCoords[0][i].y);
                    } else {
                        uv.setCoord(-1, -1);
                    }
                    nreMesh->add(4, uv.value(), 2);
                }

                for (GLuint i = 0; i < mesh->mNumFaces; i = i + 1) {
                    aiFace face = mesh->mFaces[i];
                    for (GLuint j = 0; j < face.mNumIndices; j = j + 1) {
                        nreMesh->add(5, &face.mIndices[j]);
                    }
                }

                return nreMesh;
            }

            void Object3D::processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type) {
                static_cast <Mesh3D*> (meshes[0])->processSphere(usage, radius, rings, sectors, type);
            }

            Object3D& Object3D::operator=(Object3D && o) {
                Object::operator=(std::move(o));
                return *this;
            }

        };
    };
