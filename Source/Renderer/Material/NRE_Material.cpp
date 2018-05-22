
    #include "NRE_Material.hpp"

    namespace NRE {
        namespace Renderer {

            Material::Material() : Material("") {
            }

            Material::Material(std::string const& path) : albedo(0), normal(0), roughness(0), metallic(0) {
                albedo = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Albedo.png", false);
                normal = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Normal.png", false);
                roughness = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Roughness.png", false);
                metallic = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Metallic.png", false);
            }

            Material::Material(Material const& mat) : albedo(mat.albedo), normal(mat.normal), roughness(mat.roughness), metallic(mat.metallic) {
            }

            Material::Material(Material && mat) : albedo(std::move(mat.albedo)), normal(std::move(mat.normal)), roughness(std::move(mat.roughness)), metallic(std::move(mat.metallic)) {
            }

            Material::~Material() {
            }

            GL::Texture2D const& Material::getAlbedo() const {
                return *albedo;
            }

            GL::Texture2D const& Material::getNormal() const {
                return *normal;
            }

            GL::Texture2D const& Material::getRoughness() const {
                return *roughness;
            }

            GL::Texture2D const& Material::getMetallic() const {
                return *metallic;
            }

            void Material::freeTextures() {
                delete albedo;
                delete normal;
                delete roughness;
                delete metallic;
                albedo = 0;
                normal = 0;
                roughness = 0;
                metallic = 0;
            }

            Material& Material::operator=(Material const& mat) {
                albedo = mat.albedo;
                normal = mat.normal;
                roughness = mat.roughness;
                metallic = mat.metallic;
                return *this;
            }

            Material& Material::operator=(Material && mat) {
                albedo = std::move(mat.albedo);
                normal = std::move(mat.normal);
                roughness = std::move(mat.roughness);
                metallic = std::move(mat.metallic);
                return *this;
            }

        };
    };
