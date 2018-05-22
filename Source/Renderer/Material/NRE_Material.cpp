
    #include "NRE_Material.hpp"

    namespace NRE {
        namespace Renderer {

            Material::Material() : Material(0.0, 0.0, "") {
            }

            Material::Material(NREfloat const& metallic, NREfloat const& roughness, std::string const& path) : metallic(metallic), roughness(roughness), albedo(0), normal(0) {
                albedo = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Albedo.png", false);
                normal = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Normal.png", false);
            }

            Material::Material(Material const& mat) : metallic(mat.getMetallic()), roughness(mat.getRoughness()), albedo(mat.albedo), normal(mat.normal) {
            }

            Material::Material(Material && mat) : metallic(std::move(mat.getMetallic())), roughness(std::move(mat.getRoughness())), albedo(std::move(mat.albedo)), normal(std::move(mat.normal)) {
            }

            Material::~Material() {
            }

            NREfloat const& Material::getMetallic() const {
                return metallic;
            }

            NREfloat const& Material::getRoughness() const {
                return roughness;
            }

            GL::Texture2D const& Material::getAlbedo() const {
                return *albedo;
            }

            GL::Texture2D const& Material::getNormal() const {
                return *normal;
            }

            NREfloat* const Material::getMetallicValue() {
                return &metallic;
            }

            NREfloat* const Material::getRoughnessValue() {
                return &roughness;
            }

            void Material::setMetallic(NREfloat const& value) {
                metallic = value;
            }

            void Material::setRoughness(NREfloat const& value) {
                roughness = value;
            }

            void Material::freeTextures() {
                delete albedo;
                delete normal;
                albedo = 0;
                normal = 0;
            }

            Material& Material::operator=(Material const& mat) {
                metallic = mat.getMetallic();
                roughness = mat.getRoughness();
                albedo = mat.albedo;
                normal = mat.normal;
                return *this;
            }

            Material& Material::operator=(Material && mat) {
                metallic = std::move(mat.metallic);
                roughness = std::move(mat.roughness);
                albedo = std::move(mat.albedo);
                normal = std::move(mat.normal);
                return *this;
            }

        };
    };
