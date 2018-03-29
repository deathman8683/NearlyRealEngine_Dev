
    #include "NRE_SSAO.hpp"

    namespace NRE {
        namespace Renderer {

            GLuint SSAO::KERNEL_SIZE = 32;
            GLuint SSAO::NOISE_SIZE = 4;

            SSAO::SSAO() : SSAO(1920.0 / 1080.0, 70.0) {
            }

            SSAO::SSAO(NREfloat const& ratio, NREfloat const& tanHalfFOV) : kernel(0), noise(0), ratio(ratio), tanHalfFOV(tanHalfFOV) {
               kernel = new Maths::Vector3D<NREfloat>[KERNEL_SIZE];
               noise = new GL::Texture2D(NOISE_SIZE, NOISE_SIZE, GL_RGBA, GL_RGBA32F, GL_FLOAT);
               generateKernel();
               generateNoise();
            }

            SSAO::SSAO(SSAO const& ao) : kernel(ao.getKernel()), noise(ao.getNoise()), ratio(ao.getRatio()), tanHalfFOV(ao.getTanHalfFOV()) {
            }

            SSAO::~SSAO() {
                delete[] kernel;
            }

            Maths::Vector3D<NREfloat>* const& SSAO::getKernel() const {
                return kernel;
            }

            GL::Texture2D* const& SSAO::getNoise() const {
                return noise;
            }

            NREfloat const& SSAO::getRatio() const {
                return ratio;
            }

            NREfloat const& SSAO::getTanHalfFOV() const {
                return tanHalfFOV;
            }

            void SSAO::setKernel(Maths::Vector3D<NREfloat>* const& kern) {
                kernel = kern;
            }

            void SSAO::setNoise(GL::Texture2D* const& tex) {
                noise = tex;
            }

            void SSAO::setRatio(NREfloat const& value) {
                ratio = value;
            }

            void SSAO::setTanHalfFOV(NREfloat const& value) {
                tanHalfFOV = value;
            }

            void SSAO::generateKernel() {
                std::uniform_real_distribution<NREfloat> rFloat(0.0, 1.0);
                std::default_random_engine generator;

                for (GLuint i = 0 ; i < KERNEL_SIZE ; i = i + 1) {
                    kernel[i].setCoord(
                        rFloat(generator) * 2.0 - 1.0,
                        rFloat(generator) * 2.0 - 1.0,
                        rFloat(generator)
                    );
                    kernel[i] = kernel[i] * rFloat(generator);
                    kernel[i].normalize();
                    NREfloat scale = static_cast <NREfloat> (i) / static_cast <NREfloat> (KERNEL_SIZE);
                    scale = lerp(0.1, 1.0, scale * scale);
                    kernel[i] = kernel[i] * scale;
                }
            }

            void SSAO::generateNoise() {
                std::uniform_real_distribution<NREfloat> rFloat(0.0, 1.0);
                std::default_random_engine generator;

                Maths::Vector3D<NREfloat> *ssaoNoise = new Maths::Vector3D<NREfloat>[NOISE_SIZE * NOISE_SIZE];
                for (GLuint i = 0; i < NOISE_SIZE * NOISE_SIZE; i = i + 1) {
                    ssaoNoise[i].setCoord(
                        rFloat(generator) * 2.0 - 1.0,
                        rFloat(generator) * 2.0 - 1.0,
                        0.0
                    );
                    ssaoNoise[i].normalize();
                }

                noise->update(0, 0, &ssaoNoise[0]);
                noise->bind();
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
                noise->unbind();
            }

            NREfloat SSAO::lerp(NREfloat const& a, NREfloat const& b, NREfloat const& f) const {
                return a + f * (b - a);
            }

        };
    };
