
    #include "NRE_Type.hpp"

    namespace NRE {
        namespace World {

            Void::Void() {
            }

            Void::~Void() {
            }

            bool const Void::isSolid() const {
                return false;
            }

            Renderer::Material const Void::getMaterial() const {
                return Renderer::Material("Void");
            }

            Ocean::Ocean() {
            }

            Ocean::~Ocean() {
            }

            bool const Ocean::isSolid() const {
                return true;
            }

            Renderer::Material const Ocean::getMaterial() const {
                return Renderer::Material("Ocean");
            }

            Beach::Beach() {
            }

            Beach::~Beach() {
            }

            bool const Beach::isSolid() const {
                return true;
            }

            Renderer::Material const Beach::getMaterial() const {
                return Renderer::Material("Beach");
            }

            Scorched::Scorched() {
            }

            Scorched::~Scorched() {
            }

            bool const Scorched::isSolid() const {
                return true;
            }

            Renderer::Material const Scorched::getMaterial() const {
                return Renderer::Material("Scorched");
            }

            Bare::Bare() {
            }

            Bare::~Bare() {
            }

            bool const Bare::isSolid() const {
                return true;
            }

            Renderer::Material const Bare::getMaterial() const {
                return Renderer::Material("Bare");
            }

            Tundra::Tundra() {
            }

            Tundra::~Tundra() {
            }

            bool const Tundra::isSolid() const {
                return true;
            }

            Renderer::Material const Tundra::getMaterial() const {
                return Renderer::Material("Tundra");
            }

            Snow::Snow() {
            }

            Snow::~Snow() {
            }

            bool const Snow::isSolid() const {
                return true;
            }

            Renderer::Material const Snow::getMaterial() const {
                return Renderer::Material("Snow");
            }

            TemperateDesert::TemperateDesert() {
            }

            TemperateDesert::~TemperateDesert() {
            }

            bool const TemperateDesert::isSolid() const {
                return true;
            }

            Renderer::Material const TemperateDesert::getMaterial() const {
                return Renderer::Material("Temperate_Desert");
            }

            SubtropicalDesert::SubtropicalDesert() {
            }

            SubtropicalDesert::~SubtropicalDesert() {
            }

            bool const SubtropicalDesert::isSolid() const {
                return true;
            }

            Renderer::Material const SubtropicalDesert::getMaterial() const {
                return Renderer::Material("Subtropical_Desert");
            }

            Shrubland::Shrubland() {
            }

            Shrubland::~Shrubland() {
            }

            bool const Shrubland::isSolid() const {
                return true;
            }

            Renderer::Material const Shrubland::getMaterial() const {
                return Renderer::Material("Shrubland");
            }

            Taiga::Taiga() {
            }

            Taiga::~Taiga() {
            }

            bool const Taiga::isSolid() const {
                return true;
            }

            Renderer::Material const Taiga::getMaterial() const {
                return Renderer::Material("Taiga");
            }

            Grassland::Grassland() {
            }

            Grassland::~Grassland() {
            }

            bool const Grassland::isSolid() const {
                return true;
            }

            Renderer::Material const Grassland::getMaterial() const {
                return Renderer::Material("Grassland");
            }

            TemperateDeciduousForest::TemperateDeciduousForest() {
            }

            TemperateDeciduousForest::~TemperateDeciduousForest() {
            }

            bool const TemperateDeciduousForest::isSolid() const {
                return true;
            }

            Renderer::Material const TemperateDeciduousForest::getMaterial() const {
                return Renderer::Material("Temperate_Deciduous_Forest");
            }

            TemperateRainForest::TemperateRainForest() {
            }

            TemperateRainForest::~TemperateRainForest() {
            }

            bool const TemperateRainForest::isSolid() const {
                return true;
            }

            Renderer::Material const TemperateRainForest::getMaterial() const {
                return Renderer::Material("Temperate_Rain_Forest");
            }

            TropicalSeasonalForest::TropicalSeasonalForest() {
            }

            TropicalSeasonalForest::~TropicalSeasonalForest() {
            }

            bool const TropicalSeasonalForest::isSolid() const {
                return true;
            }

            Renderer::Material const TropicalSeasonalForest::getMaterial() const {
                return Renderer::Material("Tropical_Seasonal_Forest");
            }

            TropicalRainForest::TropicalRainForest() {
            }

            TropicalRainForest::~TropicalRainForest() {
            }

            bool const TropicalRainForest::isSolid() const {
                return true;
            }

            Renderer::Material const TropicalRainForest::getMaterial() const {
                return Renderer::Material("Tropical_Rain_Forest");
            }

            Mat_1::Mat_1() {
            }

            Mat_1::~Mat_1() {
            }

            bool const Mat_1::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_1::getMaterial() const {
                return Renderer::Material("Mat_1");
            }

            Mat_2::Mat_2() {
            }

            Mat_2::~Mat_2() {
            }

            bool const Mat_2::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_2::getMaterial() const {
                return Renderer::Material("Mat_2");
            }

            Mat_3::Mat_3() {
            }

            Mat_3::~Mat_3() {
            }

            bool const Mat_3::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_3::getMaterial() const {
                return Renderer::Material("Mat_3");
            }

            Mat_4::Mat_4() {
            }

            Mat_4::~Mat_4() {
            }

            bool const Mat_4::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_4::getMaterial() const {
                return Renderer::Material("Mat_4");
            }

            Mat_5::Mat_5() {
            }

            Mat_5::~Mat_5() {
            }

            bool const Mat_5::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_5::getMaterial() const {
                return Renderer::Material("Mat_5");
            }

            Mat_6::Mat_6() {
            }

            Mat_6::~Mat_6() {
            }

            bool const Mat_6::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_6::getMaterial() const {
                return Renderer::Material("Mat_6");
            }

            Mat_7::Mat_7() {
            }

            Mat_7::~Mat_7() {
            }

            bool const Mat_7::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_7::getMaterial() const {
                return Renderer::Material("Mat_7");
            }

            Mat_8::Mat_8() {
            }

            Mat_8::~Mat_8() {
            }

            bool const Mat_8::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_8::getMaterial() const {
                return Renderer::Material("Mat_8");
            }

        };
    };
