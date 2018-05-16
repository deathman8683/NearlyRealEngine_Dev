
    #include "NRE_VoxelObject.hpp"

    namespace NRE {
        namespace Object {

            VoxelObject::VoxelObject() {
            }

            VoxelObject::VoxelObject(VoxelObject const& o) {
            }

            VoxelObject::VoxelObject(VoxelObject && o) {
            }

            VoxelObject::~VoxelObject() {
            }

            VoxelObject& VoxelObject::operator=(VoxelObject const& o) {
                return *this;
            }

            VoxelObject& VoxelObject::operator=(VoxelObject && o) {
                return *this;
            }

        };
    };
