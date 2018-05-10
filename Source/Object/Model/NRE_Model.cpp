
    #include "NRE_Model.hpp"

    namespace NRE {
        namespace Object {

            Model::Model() {
            }

            Model::Model(Model const& m) : voxels(m.voxels), size(m.size) {
            }

            Model::Model(Model && m) : voxels(std::move(m.voxels)), size(std::move(m.size)) {
            }

            Model::~Model() {
            }

            World::Voxel const& Model::getVoxel(Maths::Point3D<GLuint> const& p) const {
                return getVoxel(p.getX(), p.getY(), p.getZ());
            }

            World::Voxel const& Model::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return voxels[Array::get1DIndexFrom3D(x, y, z, size)];
            }

            World::Voxel const& Model::getVoxel(GLuint const& index) const {
                return voxels[index];
            }

            Maths::Vector3D<GLuint> const& Model::getSize() const {
                return size;
            }

            Model& Model::operator=(Model const& m) {
                voxels = m.voxels;
                size = m.size;
                return *this;
            }

            Model& Model::operator=(Model && m) {
                voxels = std::move(m.voxels);
                size = std::move(m.size);
                return *this;
            }

        };
    };
