
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

            Ocean::Ocean() {
            }

            Ocean::~Ocean() {
            }

            Color::RGB const Ocean::getColor() const {
                return Color::RGB(68, 68, 122);
            }

            Beach::Beach() {
            }

            Beach::~Beach() {
            }

            Color::RGB const Beach::getColor() const {
                return Color::RGB(160, 144, 119);
            }

            Scorched::Scorched() {
            }

            Scorched::~Scorched() {
            }

            Color::RGB const Scorched::getColor() const {
                return Color::RGB(85, 85, 85);
            }

            Bare::Bare() {
            }

            Bare::~Bare() {
            }

            Color::RGB const Bare::getColor() const {
                return Color::RGB(136, 136, 136);
            }

            Tundra::Tundra() {
            }

            Tundra::~Tundra() {
            }

            Color::RGB const Tundra::getColor() const {
                return Color::RGB(187, 187, 170);
            }

            Snow::Snow() {
            }

            Snow::~Snow() {
            }

            Color::RGB const Snow::getColor() const {
                return Color::RGB(221, 221, 228);
            }

            TemperateDesert::TemperateDesert() {
            }

            TemperateDesert::~TemperateDesert() {
            }

            Color::RGB const TemperateDesert::getColor() const {
                return Color::RGB(201, 210, 155);
            }

            SubtropicalDesert::SubtropicalDesert() {
            }

            SubtropicalDesert::~SubtropicalDesert() {
            }

            Color::RGB const SubtropicalDesert::getColor() const {
                return Color::RGB(210, 185, 139);
            }

            Shrubland::Shrubland() {
            }

            Shrubland::~Shrubland() {
            }

            Color::RGB const Shrubland::getColor() const {
                return Color::RGB(136, 153, 119);
            }

            Taiga::Taiga() {
            }

            Taiga::~Taiga() {
            }

            Color::RGB const Taiga::getColor() const {
                return Color::RGB(153, 170, 119);
            }

            Grassland::Grassland() {
            }

            Grassland::~Grassland() {
            }

            Color::RGB const Grassland::getColor() const {
                return Color::RGB(136, 170, 85);
            }

            TemperateDeciduousForest::TemperateDeciduousForest() {
            }

            TemperateDeciduousForest::~TemperateDeciduousForest() {
            }

            Color::RGB const TemperateDeciduousForest::getColor() const {
                return Color::RGB(103, 148, 89);
            }

            TemperateRainForest::TemperateRainForest() {
            }

            TemperateRainForest::~TemperateRainForest() {
            }

            Color::RGB const TemperateRainForest::getColor() const {
                return Color::RGB(68, 136, 85);
            }

            TropicalSeasonalForest::TropicalSeasonalForest() {
            }

            TropicalSeasonalForest::~TropicalSeasonalForest() {
            }

            Color::RGB const TropicalSeasonalForest::getColor() const {
                return Color::RGB(85, 153, 68);
            }

            TropicalRainForest::TropicalRainForest() {
            }

            TropicalRainForest::~TropicalRainForest() {
            }

            Color::RGB const TropicalRainForest::getColor() const {
                return Color::RGB(51, 119, 85);
            }

        };
    };
