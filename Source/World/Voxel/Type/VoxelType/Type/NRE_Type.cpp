
    #include "NRE_Type.hpp"

    namespace NRE {
        namespace World {

            Void::Void() {
            }

            Void::~Void() {
            }

            Color::RGB const Void::getColor() const {
                return Color::RGB(255, 255, 255);
            }

            bool const Void::isSolid() const {
                return false;
            }

            Ocean::Ocean() {
            }

            Ocean::~Ocean() {
            }

            Color::RGB const Ocean::getColor() const {
                return Color::RGB(68, 68, 122);
            }

            bool const Ocean::isSolid() const {
                return true;
            }

            Beach::Beach() {
            }

            Beach::~Beach() {
            }

            Color::RGB const Beach::getColor() const {
                return Color::RGB(160, 144, 119);
            }

            bool const Beach::isSolid() const {
                return true;
            }

            Scorched::Scorched() {
            }

            Scorched::~Scorched() {
            }

            Color::RGB const Scorched::getColor() const {
                return Color::RGB(85, 85, 85);
            }

            bool const Scorched::isSolid() const {
                return true;
            }

            Bare::Bare() {
            }

            Bare::~Bare() {
            }

            Color::RGB const Bare::getColor() const {
                return Color::RGB(136, 136, 136);
            }

            bool const Bare::isSolid() const {
                return true;
            }

            Tundra::Tundra() {
            }

            Tundra::~Tundra() {
            }

            Color::RGB const Tundra::getColor() const {
                return Color::RGB(187, 187, 170);
            }

            bool const Tundra::isSolid() const {
                return true;
            }

            Snow::Snow() {
            }

            Snow::~Snow() {
            }

            Color::RGB const Snow::getColor() const {
                return Color::RGB(221, 221, 228);
            }

            bool const Snow::isSolid() const {
                return true;
            }

            TemperateDesert::TemperateDesert() {
            }

            TemperateDesert::~TemperateDesert() {
            }

            Color::RGB const TemperateDesert::getColor() const {
                return Color::RGB(201, 210, 155);
            }

            bool const TemperateDesert::isSolid() const {
                return true;
            }

            SubtropicalDesert::SubtropicalDesert() {
            }

            SubtropicalDesert::~SubtropicalDesert() {
            }

            Color::RGB const SubtropicalDesert::getColor() const {
                return Color::RGB(210, 185, 139);
            }

            bool const SubtropicalDesert::isSolid() const {
                return true;
            }

            Shrubland::Shrubland() {
            }

            Shrubland::~Shrubland() {
            }

            Color::RGB const Shrubland::getColor() const {
                return Color::RGB(136, 153, 119);
            }

            bool const Shrubland::isSolid() const {
                return true;
            }

            Taiga::Taiga() {
            }

            Taiga::~Taiga() {
            }

            Color::RGB const Taiga::getColor() const {
                return Color::RGB(153, 170, 119);
            }

            bool const Taiga::isSolid() const {
                return true;
            }

            Grassland::Grassland() {
            }

            Grassland::~Grassland() {
            }

            Color::RGB const Grassland::getColor() const {
                return Color::RGB(136, 170, 85);
            }

            bool const Grassland::isSolid() const {
                return true;
            }

            TemperateDeciduousForest::TemperateDeciduousForest() {
            }

            TemperateDeciduousForest::~TemperateDeciduousForest() {
            }

            Color::RGB const TemperateDeciduousForest::getColor() const {
                return Color::RGB(103, 148, 89);
            }

            bool const TemperateDeciduousForest::isSolid() const {
                return true;
            }

            TemperateRainForest::TemperateRainForest() {
            }

            TemperateRainForest::~TemperateRainForest() {
            }

            Color::RGB const TemperateRainForest::getColor() const {
                return Color::RGB(68, 136, 85);
            }

            bool const TemperateRainForest::isSolid() const {
                return true;
            }

            TropicalSeasonalForest::TropicalSeasonalForest() {
            }

            TropicalSeasonalForest::~TropicalSeasonalForest() {
            }

            Color::RGB const TropicalSeasonalForest::getColor() const {
                return Color::RGB(85, 153, 68);
            }

            bool const TropicalSeasonalForest::isSolid() const {
                return true;
            }

            TropicalRainForest::TropicalRainForest() {
            }

            TropicalRainForest::~TropicalRainForest() {
            }

            Color::RGB const TropicalRainForest::getColor() const {
                return Color::RGB(51, 119, 85);
            }

            bool const TropicalRainForest::isSolid() const {
                return true;
            }

        };
    };
