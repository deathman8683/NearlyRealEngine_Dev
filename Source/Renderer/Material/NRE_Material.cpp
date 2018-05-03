
    #include "NRE_Material.hpp"

    namespace NRE {
        namespace Renderer {

            Material::Material() : Material(Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), 0.0, 0.0) {
            }

            Material::Material(Maths::Vector3D<NREfloat> const& albedo, NREfloat const& metallic, NREfloat const& roughness) : albedo(albedo), metallic(metallic), roughness(roughness) {
            }

            Material::Material(Material const& mat) : albedo(mat.getAlbedo()), metallic(mat.getMetallic()), roughness(mat.getRoughness()) {
            }

            Material::Material(Material && mat) : albedo(std::move(mat.getAlbedo())), metallic(std::move(mat.getMetallic())), roughness(std::move(mat.getRoughness())) {
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

            Material& Material::operator=(Material const& mat) {
                albedo = mat.getAlbedo();
                metallic = mat.getMetallic();
                roughness = mat.getRoughness();

                return *this;
            }

            Material& Material::operator=(Material && mat) {
                albedo = std::move(mat.albedo);
                metallic = std::move(mat.metallic);
                roughness = std::move(mat.roughness);

                return *this;
            }

        };
    };
