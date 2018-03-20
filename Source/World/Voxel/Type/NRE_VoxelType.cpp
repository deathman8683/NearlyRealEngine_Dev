
    #include "NRE_VoxelType.hpp"

    namespace NRE {
        namespace Voxel {

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
                return Color::RGB(5, 80, 5);
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

            Sand::Sand() {
            }

            Sand::Sand(Sand const& vox) : Voxel::Voxel(vox) {
            }

            Sand::~Sand() {
            }

            GLint const Sand::getType() const {
                return VoxelType::SAND;
            }

            Color::RGB const Sand::getColor() const {
                return Color::RGB(255, 221, 167);
            }

            Snow::Snow() {
            }

            Snow::Snow(Snow const& vox) : Voxel::Voxel(vox) {
            }

            Snow::~Snow() {
            }

            GLint const Snow::getType() const {
                return VoxelType::SNOW;
            }

            Color::RGB const Snow::getColor() const {
                return Color::RGB(213, 213, 213);
            }

            Dirt::Dirt() {
            }

            Dirt::Dirt(Dirt const& vox) : Voxel::Voxel(vox) {
            }

            Dirt::~Dirt() {
            }

            GLint const Dirt::getType() const {
                return VoxelType::DIRT;
            }

            Color::RGB const Dirt::getColor() const {
                return Color::RGB(92, 55, 3);
            }

            Water::Water() {
            }

            Water::Water(Water const& vox) : Voxel::Voxel(vox) {
            }

            Water::~Water() {
            }

            GLint const Water::getType() const {
                return VoxelType::WATER;
            }

            Color::RGB const Water::getColor() const {
                return Color::RGB(255, 255, 255);
            }

        };
    };
