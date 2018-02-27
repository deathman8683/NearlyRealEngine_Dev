
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
                    cBuf[0] = 0; cBuf[1] = 0; cBuf[2] = 0;
                    cBuf[3] = 0; cBuf[4] = 0; cBuf[5] = 1;
                    cBuf[6] = 0; cBuf[7] = 1; cBuf[8] = 0;

                    cBuf[9] = 0; cBuf[10] = 1; cBuf[11] = 1;
                    cBuf[12] = 0; cBuf[13] = 1; cBuf[14] = 0;
                    cBuf[15] = 0; cBuf[16] = 0; cBuf[17] = 1;

                    cBuf[18] = 0; cBuf[19] = 0; cBuf[20] = 0;
                    cBuf[21] = 0; cBuf[22] = 0; cBuf[23] = 1;
                    cBuf[24] = 1; cBuf[25] = 0; cBuf[26] = 0;

                    cBuf[27] = 1; cBuf[28] = 0; cBuf[29] = 1;
                    cBuf[30] = 1; cBuf[31] = 0; cBuf[32] = 0;
                    cBuf[33] = 0; cBuf[34] = 0; cBuf[35] = 1;

                    cBuf[36] = 0; cBuf[37] = 0; cBuf[38] = 1;
                    cBuf[39] = 1; cBuf[40] = 0; cBuf[41] = 1;
                    cBuf[42] = 0; cBuf[43] = 1; cBuf[44] = 1;

                    cBuf[45] = 1; cBuf[46] = 1; cBuf[47] = 1;
                    cBuf[48] = 0; cBuf[49] = 1; cBuf[50] = 1;
                    cBuf[51] = 1; cBuf[52] = 0; cBuf[53] = 1;

                    cBuf[54] = 0; cBuf[55] = 0; cBuf[56] = 0;
                    cBuf[57] = 0; cBuf[58] = 1; cBuf[59] = 0;
                    cBuf[60] = 1; cBuf[61] = 0; cBuf[62] = 0;

                    cBuf[63] = 1; cBuf[64] = 1; cBuf[65] = 0;
                    cBuf[66] = 1; cBuf[67] = 0; cBuf[68] = 0;
                    cBuf[69] = 0; cBuf[70] = 1; cBuf[71] = 0;

                    cBuf[72] = 1; cBuf[73] = 0; cBuf[74] = 0;
                    cBuf[75] = 1; cBuf[76] = 0; cBuf[77] = 1;
                    cBuf[78] = 1; cBuf[79] = 1; cBuf[80] = 0;

                    cBuf[81] = 1; cBuf[82] = 1; cBuf[83] = 1;
                    cBuf[84] = 1; cBuf[85] = 1; cBuf[86] = 0;
                    cBuf[87] = 1; cBuf[88] = 0; cBuf[89] = 1;

                    cBuf[90] = 0; cBuf[91] = 1; cBuf[92] = 0;
                    cBuf[93] = 0; cBuf[94] = 1; cBuf[95] = 1;
                    cBuf[96] = 1; cBuf[97] = 1; cBuf[98] = 0;

                    cBuf[99] = 1; cBuf[100] = 1; cBuf[101] = 1;
                    cBuf[102] = 1; cBuf[103] = 1; cBuf[104] = 0;
                    cBuf[105] = 0; cBuf[106] = 1; cBuf[107] = 1;

                nBuf = new GLbyte[NB_VERTICES];
                    nBuf[0] = 1; nBuf[1] = 0; nBuf[2] = 0;
                    nBuf[3] = 1; nBuf[4] = 0; nBuf[5] = 0;
                    nBuf[6] = 1; nBuf[7] = 0; nBuf[8] = 0;

                    nBuf[9] = 1; nBuf[10] = 0; nBuf[11] = 0;
                    nBuf[12] = 1; nBuf[13] = 0; nBuf[14] = 0;
                    nBuf[15] = 1; nBuf[16] = 0; nBuf[17] = 0;

                    nBuf[18] = 1; nBuf[19] = 0; nBuf[20] = 0;
                    nBuf[21] = 1; nBuf[22] = 0; nBuf[23] = 0;
                    nBuf[24] = 1; nBuf[25] = 0; nBuf[26] = 0;

                    nBuf[27] = 1; nBuf[28] = 0; nBuf[29] = 0;
                    nBuf[30] = 1; nBuf[31] = 0; nBuf[32] = 0;
                    nBuf[33] = 1; nBuf[34] = 0; nBuf[35] = 0;

                    nBuf[36] = 1; nBuf[37] = 0; nBuf[38] = 0;
                    nBuf[39] = 1; nBuf[40] = 0; nBuf[41] = 0;
                    nBuf[42] = 1; nBuf[43] = 0; nBuf[44] = 0;

                    nBuf[45] = 1; nBuf[46] = 0; nBuf[47] = 0;
                    nBuf[48] = 1; nBuf[49] = 0; nBuf[50] = 0;
                    nBuf[51] = 1; nBuf[52] = 0; nBuf[53] = 0;

                    nBuf[54] = 1; nBuf[55] = 0; nBuf[56] = 0;
                    nBuf[57] = 1; nBuf[58] = 0; nBuf[59] = 0;
                    nBuf[60] = 1; nBuf[61] = 0; nBuf[62] = 0;

                    nBuf[63] = 1; nBuf[64] = 0; nBuf[65] = 0;
                    nBuf[66] = 1; nBuf[67] = 0; nBuf[68] = 0;
                    nBuf[69] = 1; nBuf[70] = 0; nBuf[71] = 0;

                    nBuf[72] = 1; nBuf[73] = 0; nBuf[74] = 0;
                    nBuf[75] = 1; nBuf[76] = 0; nBuf[77] = 0;
                    nBuf[78] = 1; nBuf[79] = 0; nBuf[80] = 0;

                    nBuf[81] = 1; nBuf[82] = 0; nBuf[83] = 0;
                    nBuf[84] = 1; nBuf[85] = 0; nBuf[86] = 0;
                    nBuf[87] = 1; nBuf[88] = 0; nBuf[89] = 0;

                    nBuf[90] = 1; nBuf[91] = 0; nBuf[92] = 0;
                    nBuf[93] = 1; nBuf[94] = 0; nBuf[95] = 0;
                    nBuf[96] = 1; nBuf[97] = 0; nBuf[98] = 0;

                    nBuf[99] = 1; nBuf[100] = 0; nBuf[101] = 0;
                    nBuf[102] = 1; nBuf[103] = 0; nBuf[104] = 0;
                    nBuf[105] = 1; nBuf[106] = 0; nBuf[107] = 0;
            }

            std::ostream& operator<<(std::ostream &stream, Voxel const& vox) {
                stream << "(" << vox.getType() << ")";
                return stream;
            }

        };
    };
