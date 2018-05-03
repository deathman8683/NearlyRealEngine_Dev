
    #include "NRE_SSAO.hpp"

    namespace NRE {
        namespace Renderer {

            GLuint SSAO::KERNEL_SIZE = 16;
            GLuint SSAO::NOISE_SIZE = 4;

            SSAO::SSAO() : kernel(0), noise(0) {
               kernel = new Maths::Vector3D<NREfloat>[KERNEL_SIZE];
               noise = new GL::Texture2D(NOISE_SIZE, NOISE_SIZE, GL_RGBA, GL_RGBA32F, GL_FLOAT);
               generateKernel();
               generateNoise();
            }

            SSAO::SSAO(SSAO && ssao) : kernel(std::move(ssao.kernel)), noise(std::move(ssao.noise)), ratio(std::move(ssao.ratio)), tanHalfFOV(std::move(ssao.tanHalfFOV)) {
            }

            SSAO::~SSAO() {
                delete[] kernel;
                delete noise;
            }

            Maths::Vector3D<NREfloat>* const& SSAO::getKernel() const {
                return kernel;
            }

            GL::Texture2D* const& SSAO::getNoise() const {
                return noise;
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
                    scale = Maths::lerp(0.1, 1.0, scale * scale);
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

            SSAO& SSAO::operator=(SSAO && ssao) {
                kernel = std::move(ssao.kernel);
                noise = std::move(ssao.noise);
                ratio = std::move(ssao.ratio);
                tanHalfFOV = std::move(ssao.tanHalfFOV);
                return *this;
            }

        };
    };
