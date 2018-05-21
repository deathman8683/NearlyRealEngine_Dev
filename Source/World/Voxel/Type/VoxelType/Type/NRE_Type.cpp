
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

            Renderer::Material const Void::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.1, "Void");
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

            Renderer::Material const Ocean::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.1, "Ocean");
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

            Renderer::Material const Beach::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.9, "Beach");
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

            Renderer::Material const Scorched::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.9, "Scorched");
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

            Renderer::Material const Bare::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Bare");
            }

            Tundra::Tundra() {
            }

            Tundra::~Tundra() {
            }

            Color::RGB const Tundra::getColor() const {
                return Color::RGB(187, 187, 187);
            }

            bool const Tundra::isSolid() const {
                return true;
            }

            Renderer::Material const Tundra::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Tundra");
            }

            Snow::Snow() {
            }

            Snow::~Snow() {
            }

            Color::RGB const Snow::getColor() const {
                return Color::RGB(221, 221, 221);
            }

            bool const Snow::isSolid() const {
                return true;
            }

            Renderer::Material const Snow::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Snow");
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

            Renderer::Material const TemperateDesert::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.9, "Temperate_Desert");
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

            Renderer::Material const SubtropicalDesert::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.9, "Subtropical_Desert");
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

            Renderer::Material const Shrubland::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Shrubland");
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

            Renderer::Material const Taiga::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Taiga");
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

            Renderer::Material const Grassland::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Grassland");
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

            Renderer::Material const TemperateDeciduousForest::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Temperate_Deciduous_Forest");
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

            Renderer::Material const TemperateRainForest::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Temperate_Rain_Forest");
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

            Renderer::Material const TropicalSeasonalForest::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Tropical_Seasonal_Forest");
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

            Renderer::Material const TropicalRainForest::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8, "Tropical_Rain_Forest");
            }

            Mat_1::Mat_1() {
            }

            Mat_1::~Mat_1() {
            }

            Color::RGB const Mat_1::getColor() const {
                return Color::RGB(102, 102, 102);
            }

            bool const Mat_1::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_1::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_1");
            }

            Mat_2::Mat_2() {
            }

            Mat_2::~Mat_2() {
            }

            Color::RGB const Mat_2::getColor() const {
                return Color::RGB(0, 0, 0);
            }

            bool const Mat_2::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_2::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_2");
            }

            Mat_3::Mat_3() {
            }

            Mat_3::~Mat_3() {
            }

            Color::RGB const Mat_3::getColor() const {
                return Color::RGB(204, 204, 204);
            }

            bool const Mat_3::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_3::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_3");
            }

            Mat_4::Mat_4() {
            }

            Mat_4::~Mat_4() {
            }

            Color::RGB const Mat_4::getColor() const {
                return Color::RGB(153, 122, 25);
            }

            bool const Mat_4::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_4::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_4");
            }

            Mat_5::Mat_5() {
            }

            Mat_5::~Mat_5() {
            }

            Color::RGB const Mat_5::getColor() const {
                return Color::RGB(0, 0, 0);
            }

            bool const Mat_5::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_5::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_5");
            }

            Mat_6::Mat_6() {
            }

            Mat_6::~Mat_6() {
            }

            Color::RGB const Mat_6::getColor() const {
                return Color::RGB(102, 25, 25);
            }

            bool const Mat_6::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_6::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_6");
            }

            Mat_7::Mat_7() {
            }

            Mat_7::~Mat_7() {
            }

            Color::RGB const Mat_7::getColor() const {
                return Color::RGB(51, 51, 51);
            }

            bool const Mat_7::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_7::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_7");
            }

            Mat_8::Mat_8() {
            }

            Mat_8::~Mat_8() {
            }

            Color::RGB const Mat_8::getColor() const {
                return Color::RGB(51, 51, 51);
            }

            bool const Mat_8::isSolid() const {
                return true;
            }

            Renderer::Material const Mat_8::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1, "Mat_8");
            }

        };
    };
