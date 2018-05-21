
    #include "NRE_Material.hpp"

    namespace NRE {
        namespace Renderer {

            Material::Material() : Material(Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), 0.0, 0.0, "") {
            }

            Material::Material(Maths::Vector3D<NREfloat> const& albedo, NREfloat const& metallic, NREfloat const& roughness, std::string const& path) : albedo(albedo), metallic(metallic), roughness(roughness), albedoTex(0) {
                albedoTex = new GL::Texture2D("Data/Material/" + path + "/" + path + "_Albedo.png", false);
            }

            Material::Material(Material const& mat) : albedo(mat.getAlbedo()), metallic(mat.getMetallic()), roughness(mat.getRoughness()), albedoTex(mat.albedoTex) {
            }

            Material::Material(Material && mat) : albedo(std::move(mat.getAlbedo())), metallic(std::move(mat.getMetallic())), roughness(std::move(mat.getRoughness())), albedoTex(std::move(mat.albedoTex)) {
            }

            Material::~Material() {
            }

            Maths::Vector3D<NREfloat> const& Material::getAlbedo() const {
                return albedo;
            }

            NREfloat const& Material::getMetallic() const {
                return metallic;
            }

            NREfloat const& Material::getRoughness() const {
                return roughness;
            }

            GL::Texture2D const& Material::getAlbedoTexture() const {
                return *albedoTex;
            }

            NREfloat* const Material::getMetallicValue() {
                return &metallic;
            }

            NREfloat* const Material::getRoughnessValue() {
                return &roughness;
            }

            void Material::setAlbedo(Maths::Vector3D<NREfloat> const& albedo) {
                this->albedo = albedo;
            }

            void Material::setMetallic(NREfloat const& value) {
                metallic = value;
            }

            void Material::setRoughness(NREfloat const& value) {
                roughness = value;
            }

            void Material::freeTextures() {
                delete albedoTex;
                albedoTex = 0;
            }

            Material& Material::operator=(Material const& mat) {
                albedo = mat.getAlbedo();
                metallic = mat.getMetallic();
                roughness = mat.getRoughness();
                albedoTex = mat.albedoTex;
                return *this;
            }

            Material& Material::operator=(Material && mat) {
                albedo = std::move(mat.albedo);
                metallic = std::move(mat.metallic);
                roughness = std::move(mat.roughness);
                albedoTex = std::move(mat.albedoTex);
                return *this;
            }

        };
    };
