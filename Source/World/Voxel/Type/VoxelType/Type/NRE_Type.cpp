
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
                                                                    0.0, 0.1);
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
                                                                    0.0, 0.1);
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
                                                                    0.0, 0.9);
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
                                                                    0.0, 0.9);
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
                                                                    0.0, 0.8);
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

            Renderer::Material const Tundra::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8);
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

            Renderer::Material const Snow::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.9);
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
                                                                    0.0, 0.9);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
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
                                                                    0.0, 0.8);
            }

            Gold::Gold() {
            }

            Gold::~Gold() {
            }

            Color::RGB const Gold::getColor() const {
                return Color::RGB(255, 181, 74);
            }

            bool const Gold::isSolid() const {
                return true;
            }

            Renderer::Material const Gold::getMaterial() const {
                return Renderer::Material(Maths::Vector3D<NREfloat>(std::pow(static_cast <NREfloat> (getColor().getR()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getG()) / 255.0, 2.2),
                                                                    std::pow(static_cast <NREfloat> (getColor().getB()) / 255.0, 2.2)),
                                                                    0.9, 0.1);
            }

        };
    };
