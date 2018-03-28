
    #include "NRE_SSAO.hpp"

    namespace NRE {
        namespace Renderer {

            GLuint SSAO::KERNEL_SIZE = 32;

            SSAO::SSAO() : kernel(0) {
                kernel = new Maths::Vector3D<NREfloat>[KERNEL_SIZE];
                generateKernel();
            }

            SSAO::SSAO(SSAO const& ao) : kernel(ao.getKernel()) {
            }

            SSAO::~SSAO() {
                delete[] kernel;
            }

            Maths::Vector3D<NREfloat>* const& SSAO::getKernel() const {
                return kernel;
            }

            void SSAO::setKernel(Maths::Vector3D<NREfloat>* const& kern) {
                kernel = kern;
            }

            void SSAO::generateKernel() {
                for (GLuint i = 0 ; i < KERNEL_SIZE ; i = i + 1) {
                    NREfloat scale = i / static_cast <NREfloat> (KERNEL_SIZE);
                    kernel[i].setCoord(
                        2.0 * std::rand() / static_cast <NREfloat> (RAND_MAX) - 1.0,
                        2.0 * std::rand() / static_cast <NREfloat> (RAND_MAX) - 1.0,
                        2.0 * std::rand() / static_cast <NREfloat> (RAND_MAX) - 1.0
                    );
                    kernel[i] = kernel[i] * (0.1 + 0.9 * scale * scale);
                }
            }

        };
    };
