
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

            Ocean::Ocean() {
            }

            Ocean::Ocean(Ocean const& vox) : Voxel::Voxel(vox) {
            }

            Ocean::~Ocean() {
            }

            GLint const Ocean::getType() const {
                return VoxelType::OCEAN;
            }

            Color::RGB const Ocean::getColor() const {
                return Color::RGB(68, 68, 122);
            }

            Beach::Beach() {
            }

            Beach::Beach(Beach const& vox) : Voxel::Voxel(vox) {
            }

            Beach::~Beach() {
            }

            GLint const Beach::getType() const {
                return VoxelType::BEACH;
            }

            Color::RGB const Beach::getColor() const {
                return Color::RGB(160, 144, 119);
            }

            Scorched::Scorched() {
            }

            Scorched::Scorched(Scorched const& vox) : Voxel::Voxel(vox) {
            }

            Scorched::~Scorched() {
            }

            GLint const Scorched::getType() const {
                return VoxelType::SCORCHED;
            }

            Color::RGB const Scorched::getColor() const {
                return Color::RGB(85, 85, 85);
            }

            Bare::Bare() {
            }

            Bare::Bare(Bare const& vox) : Voxel::Voxel(vox) {
            }

            Bare::~Bare() {
            }

            GLint const Bare::getType() const {
                return VoxelType::BARE;
            }

            Color::RGB const Bare::getColor() const {
                return Color::RGB(136, 136, 136);
            }

            Tundra::Tundra() {
            }

            Tundra::Tundra(Tundra const& vox) : Voxel::Voxel(vox) {
            }

            Tundra::~Tundra() {
            }

            GLint const Tundra::getType() const {
                return VoxelType::TUNDRA;
            }

            Color::RGB const Tundra::getColor() const {
                return Color::RGB(187, 187, 170);
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
                return Color::RGB(221, 221, 228);
            }

            TemperateDesert::TemperateDesert() {
            }

            TemperateDesert::TemperateDesert(TemperateDesert const& vox) : Voxel::Voxel(vox) {
            }

            TemperateDesert::~TemperateDesert() {
            }

            GLint const TemperateDesert::getType() const {
                return VoxelType::TEMPERATE_DESERT;
            }

            Color::RGB const TemperateDesert::getColor() const {
                return Color::RGB(201, 210, 155);
            }

            SubtropicalDesert::SubtropicalDesert() {
            }

            SubtropicalDesert::SubtropicalDesert(SubtropicalDesert const& vox) : Voxel::Voxel(vox) {
            }

            SubtropicalDesert::~SubtropicalDesert() {
            }

            GLint const SubtropicalDesert::getType() const {
                return VoxelType::SUBTROPICAL_DESERT;
            }

            Color::RGB const SubtropicalDesert::getColor() const {
                return Color::RGB(210, 185, 139);
            }

            Shrubland::Shrubland() {
            }

            Shrubland::Shrubland(Shrubland const& vox) : Voxel::Voxel(vox) {
            }

            Shrubland::~Shrubland() {
            }

            GLint const Shrubland::getType() const {
                return VoxelType::SHRUBLAND;
            }

            Color::RGB const Shrubland::getColor() const {
                return Color::RGB(136, 153, 119);
            }

            Taiga::Taiga() {
            }

            Taiga::Taiga(Taiga const& vox) : Voxel::Voxel(vox) {
            }

            Taiga::~Taiga() {
            }

            GLint const Taiga::getType() const {
                return VoxelType::TAIGA;
            }

            Color::RGB const Taiga::getColor() const {
                return Color::RGB(153, 170, 119);
            }

            Grassland::Grassland() {
            }

            Grassland::Grassland(Grassland const& vox) : Voxel::Voxel(vox) {
            }

            Grassland::~Grassland() {
            }

            GLint const Grassland::getType() const {
                return VoxelType::GRASSLAND;
            }

            Color::RGB const Grassland::getColor() const {
                return Color::RGB(136, 170, 85);
            }

            TemperateDeciduousForest::TemperateDeciduousForest() {
            }

            TemperateDeciduousForest::TemperateDeciduousForest(TemperateDeciduousForest const& vox) : Voxel::Voxel(vox) {
            }

            TemperateDeciduousForest::~TemperateDeciduousForest() {
            }

            GLint const TemperateDeciduousForest::getType() const {
                return VoxelType::TEMPERATE_DECIDUOUS_FOREST;
            }

            Color::RGB const TemperateDeciduousForest::getColor() const {
                return Color::RGB(103, 148, 89);
            }

            TemperateRainForest::TemperateRainForest() {
            }

            TemperateRainForest::TemperateRainForest(TemperateRainForest const& vox) : Voxel::Voxel(vox) {
            }

            TemperateRainForest::~TemperateRainForest() {
            }

            GLint const TemperateRainForest::getType() const {
                return VoxelType::TEMPERATE_RAIN_FOREST;
            }

            Color::RGB const TemperateRainForest::getColor() const {
                return Color::RGB(68, 136, 85);
            }

            TropicalSeasonalForest::TropicalSeasonalForest() {
            }

            TropicalSeasonalForest::TropicalSeasonalForest(TropicalSeasonalForest const& vox) : Voxel::Voxel(vox) {
            }

            TropicalSeasonalForest::~TropicalSeasonalForest() {
            }

            GLint const TropicalSeasonalForest::getType() const {
                return VoxelType::TROPICAL_SEASONAL_FOREST;
            }

            Color::RGB const TropicalSeasonalForest::getColor() const {
                return Color::RGB(85, 153, 68);
            }

            TropicalRainForest::TropicalRainForest() {
            }

            TropicalRainForest::TropicalRainForest(TropicalRainForest const& vox) : Voxel::Voxel(vox) {
            }

            TropicalRainForest::~TropicalRainForest() {
            }

            GLint const TropicalRainForest::getType() const {
                return VoxelType::TROPICAL_RAIN_FOREST;
            }

            Color::RGB const TropicalRainForest::getColor() const {
                return Color::RGB(51, 119, 85);
            }

            Tree::Tree() {
            }

            Tree::Tree(Tree const& vox) : Voxel::Voxel(vox) {
            }

            Tree::~Tree() {
            }

            GLint const Tree::getType() const {
                return VoxelType::TREE;
            }

            Color::RGB const Tree::getColor() const {
                return Color::RGB(65, 18, 1);
            }

        };
    };
