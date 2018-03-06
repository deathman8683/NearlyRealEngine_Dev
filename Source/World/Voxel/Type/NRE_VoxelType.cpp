
    #include "NRE_VoxelType.hpp"

    namespace NRE {
        namespace Voxel {

            Grass::Grass() {
            }

            Grass::Grass(Grass const& vox) : Voxel::Voxel(vox) {
            }

            Grass::~Grass() {
            }

            GLint const Grass::getType() const {
                return VoxelType::GRASS;
            }

            Color::RGB const Grass::getColor() const {
                return Color::RGB(12, 147, 47);
            }

            Stone::Stone() {
            }

            Stone::Stone(Stone const& vox) : Voxel::Voxel(vox) {
            }

            Stone::~Stone() {
            }

            GLint const Stone::getType() const {
                return VoxelType::STONE;
            }

            Color::RGB const Stone::getColor() const {
                return Color::RGB(55, 55, 55);
            }

            Void::Void() {
            }

            Void::Void(Void const& vox) : Voxel::Voxel(vox) {
            }

            Void::~Void() {
            }

            GLint const Void::getType() const {
                return VoxelType::VOID;
            }

            Color::RGB const Void::getColor() const {
                return Color::RGB(255, 255, 255);
            }

        };
    };
