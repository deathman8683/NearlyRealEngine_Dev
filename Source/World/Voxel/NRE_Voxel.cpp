
    #include "NRE_Voxel.hpp"

    namespace NRE {
        namespace World {

            int Voxel::NB_VERTICES = 3 * 8;
            size_t Voxel::NB_INDEX = 36;

            Voxel::Voxel() : Voxel(VOID) {
            }

            Voxel::Voxel(GLubyte const& type) : type(type) {
            }

            Voxel::Voxel(Voxel const& vox) : type(vox.getType()) {
            }

            Voxel::~Voxel() {
            }

            GLubyte const& Voxel::getType() const {
                return type;
            }

            Color::RGB const Voxel::getColor() const {
                return VoxelTypes::getVoxelType(getType())->getColor();
            }

            void Voxel::setType(GLubyte const& type) {
                this->type = type;
            }

            size_t Voxel::getVertices(GLint* & vBuf, GLfloat* & cBuf, GLbyte* & nBuf, GLuint* & iBuf) {
                vBuf = new GLint[NB_VERTICES];
                    vBuf[0] = 0; vBuf[1] = 0; vBuf[2] = 0;
                    vBuf[3] = 0; vBuf[4] = 0; vBuf[5] = 1;
                    vBuf[6] = 0; vBuf[7] = 1; vBuf[8] = 0;
                    vBuf[9] = 0; vBuf[10] = 1; vBuf[11] = 1;
                    vBuf[12] = 1; vBuf[13] = 0; vBuf[14] = 0;
                    vBuf[15] = 1; vBuf[16] = 0; vBuf[17] = 1;
                    vBuf[18] = 1; vBuf[19] = 1; vBuf[20] = 1;
                    vBuf[21] = 1; vBuf[22] = 1; vBuf[23] = 0;

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

                iBuf = new GLuint[NB_INDEX];
                    iBuf[0] = 0;
                    iBuf[1] = 1;
                    iBuf[2] = 2;
                    iBuf[3] = 3;
                    iBuf[4] = 2;
                    iBuf[5] = 1;
                    iBuf[6] = 0;
                    iBuf[7] = 1;
                    iBuf[8] = 4;
                    iBuf[9] = 5;
                    iBuf[10] = 4;
                    iBuf[11] = 1;
                    iBuf[12] = 1;
                    iBuf[13] = 5;
                    iBuf[14] = 3;
                    iBuf[15] = 6;
                    iBuf[16] = 3;
                    iBuf[17] = 5;
                    iBuf[18] = 0;
                    iBuf[19] = 2;
                    iBuf[20] = 4;
                    iBuf[21] = 7;
                    iBuf[22] = 4;
                    iBuf[23] = 2;
                    iBuf[24] = 4;
                    iBuf[25] = 5;
                    iBuf[26] = 7;
                    iBuf[27] = 6;
                    iBuf[28] = 7;
                    iBuf[29] = 5;
                    iBuf[30] = 2;
                    iBuf[31] = 3;
                    iBuf[32] = 7;
                    iBuf[33] = 6;
                    iBuf[34] = 7;
                    iBuf[35] = 3;

                return NB_INDEX;
            }
        };
    };
