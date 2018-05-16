
    #include "NRE_VoxelObject.hpp"

    namespace NRE {
        namespace Object {

            VoxelObject::VoxelObject() {
            }

            VoxelObject::VoxelObject(VoxelObject && o) : Object3D(std::move(o)) {
            }

            VoxelObject::~VoxelObject() {
                voxelSets.erase(voxelSets.begin(), voxelSets.end());
            }

            VoxelSet const& VoxelObject::getVoxelSet(GLuint const& index) const {
                return voxelSets[index];
            }

            void VoxelObject::setLeft(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setLeft(&s);
            }

            void VoxelObject::setRight(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setRight(&s);
            }

            void VoxelObject::setFront(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setFront(&s);
            }

            void VoxelObject::setBack(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setBack(&s);
            }

            void VoxelObject::setUp(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setUp(&s);
            }

            void VoxelObject::setBottom(GLuint const& index, VoxelSet const& s) {
                static_cast <VoxelMesh*> (meshes[index])->setBottom(&s);
            }

            void VoxelObject::save(std::string const& path) const {
                for (VoxelSet s : voxelSets) {
                    s.save(path);
                }
            }
            void VoxelObject::load(std::string const& path) {
                for (VoxelSet s : voxelSets) {
                    s.load(path);
                }
            }

            void VoxelObject::process(GLenum const& usage, Maths::Point2D<GLint> const& coord) {
                for (Mesh* m : meshes) {
                    static_cast <VoxelMesh*> (m)->process(usage, coord);
                }
            }

            void VoxelObject::loadVoxels(GLuint const& index, GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLubyte const& type) {
                voxelSets[index].loadVoxels(x, y, z, nb, type);
            }

            void VoxelObject::push_back(Maths::Vector3D<GLuint> const& size) {
                voxelSets.emplace(voxelSets.end(), size);
                Object::push_back(new VoxelMesh(&voxelSets[voxelSets.size() - 1]));
            }

            VoxelObject& VoxelObject::operator=(VoxelObject && o) {
                Object3D::operator=(std::move(o));
                return *this;
            }

        };
    };
