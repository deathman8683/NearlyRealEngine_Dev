
    #include "NRE_Voxel.hpp"

    namespace NRE {
        namespace World {

            bool Voxel::DEFAULT_STATE = true;
            int Voxel::NB_VERTICES = 3 * 36;

            Voxel::Voxel() : active(DEFAULT_STATE) {
            }

            Voxel::Voxel(bool const& state) : active(state) {
            }

            Voxel::Voxel(Voxel const& vox) : active(vox.isActive()) {
            }

            Voxel::~Voxel() {
            }

            bool const& Voxel::isActive() const {
                return active;
            }

            void Voxel::setActive(bool const& state) {
                active = state;
            }

            void Voxel::getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf) {
                vBuf = new GLint[NB_VERTICES];
                    vBuf[0] = 0; vBuf[1] = 0; vBuf[2] = 0;
                    vBuf[3] = 0; vBuf[4] = 0; vBuf[5] = 1;
                    vBuf[6] = 0; vBuf[7] = 1; vBuf[8] = 0;

                    vBuf[9] = 0; vBuf[10] = 1; vBuf[11] = 1;
                    vBuf[12] = 0; vBuf[13] = 1; vBuf[14] = 0;
                    vBuf[15] = 0; vBuf[16] = 0; vBuf[17] = 1;

                    vBuf[18] = 0; vBuf[19] = 0; vBuf[20] = 0;
                    vBuf[21] = 0; vBuf[22] = 0; vBuf[23] = 1;
                    vBuf[24] = 1; vBuf[25] = 0; vBuf[26] = 0;

                    vBuf[27] = 1; vBuf[28] = 0; vBuf[29] = 1;
                    vBuf[30] = 1; vBuf[31] = 0; vBuf[32] = 0;
                    vBuf[33] = 0; vBuf[34] = 0; vBuf[35] = 1;

                    vBuf[36] = 0; vBuf[37] = 0; vBuf[38] = 1;
                    vBuf[39] = 1; vBuf[40] = 0; vBuf[41] = 1;
                    vBuf[42] = 0; vBuf[43] = 1; vBuf[44] = 1;

                    vBuf[45] = 1; vBuf[46] = 1; vBuf[47] = 1;
                    vBuf[48] = 0; vBuf[49] = 1; vBuf[50] = 1;
                    vBuf[51] = 1; vBuf[52] = 0; vBuf[53] = 1;

                    vBuf[54] = 0; vBuf[55] = 0; vBuf[56] = 0;
                    vBuf[57] = 0; vBuf[58] = 1; vBuf[59] = 0;
                    vBuf[60] = 1; vBuf[61] = 0; vBuf[62] = 0;

                    vBuf[63] = 1; vBuf[64] = 1; vBuf[65] = 0;
                    vBuf[66] = 1; vBuf[67] = 0; vBuf[68] = 0;
                    vBuf[69] = 0; vBuf[70] = 1; vBuf[71] = 0;

                    vBuf[72] = 1; vBuf[73] = 0; vBuf[74] = 0;
                    vBuf[75] = 1; vBuf[76] = 0; vBuf[77] = 1;
                    vBuf[78] = 1; vBuf[79] = 1; vBuf[80] = 0;

                    vBuf[81] = 1; vBuf[82] = 1; vBuf[83] = 1;
                    vBuf[84] = 1; vBuf[85] = 1; vBuf[86] = 0;
                    vBuf[87] = 1; vBuf[88] = 0; vBuf[89] = 1;

                    vBuf[90] = 0; vBuf[91] = 1; vBuf[92] = 0;
                    vBuf[93] = 0; vBuf[94] = 1; vBuf[95] = 1;
                    vBuf[96] = 1; vBuf[97] = 1; vBuf[98] = 0;

                    vBuf[99] = 1; vBuf[100] = 1; vBuf[101] = 1;
                    vBuf[102] = 1; vBuf[103] = 1; vBuf[104] = 0;
                    vBuf[105] = 0; vBuf[106] = 1; vBuf[107] = 1;

                cBuf = new GLfloat[NB_VERTICES];
                    Color::RGB voxColor = getColor();
                    for (int i = 0; i < NB_VERTICES; i = i + 3) {
                        cBuf[i] = voxColor.getR() / 255.0;
                        cBuf[i + 1] = voxColor.getG() / 255.0;
                        cBuf[i + 2] = voxColor.getB() / 255.0;
                    }

                nBuf = new GLbyte[NB_VERTICES];
                    for (int i = 0; i < NB_VERTICES; i = i + 3) {
                        nBuf[i] = 1;
                        nBuf[i + 1] = 0;
                        nBuf[i + 2] = 0;
                    }
            }

        };
    };
