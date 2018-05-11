
    #include "NRE_VoxelPoint.hpp"

    namespace NRE {
        namespace World {

            VoxelPoint::VoxelPoint() {
            }

            VoxelPoint::VoxelPoint(Maths::Point3D<GLint> const& p) {
                compute(p);
            }

            VoxelPoint::VoxelPoint(VoxelPoint const& p) : coord(p.coord), chunk(p.chunk) {
            }

            VoxelPoint::VoxelPoint(VoxelPoint && p) : coord(std::move(p.coord)), chunk(std::move(p.chunk)) {
            }

            VoxelPoint::~VoxelPoint() {
            }

            Maths::Point3D<GLuint> const& VoxelPoint::getCoord() const {
                return coord;
            }

            Maths::Point2D<GLint> const& VoxelPoint::getChunkCoord() const {
                return chunk;
            }

            void VoxelPoint::compute(Maths::Point3D<GLint> const& p) {
                Maths::Point3D<GLint> trunc;

                trunc.setX(static_cast <GLint> (std::floor(p.getX())));
                trunc.setY(static_cast <GLint> (std::floor(p.getY())));
                trunc.setZ(static_cast <GLint> (std::floor(p.getZ())));
                if (trunc.getX() < 0) {
                    chunk.setX(((trunc.getX() + 1) / static_cast <GLint> (Chunk::SIZE_X)));
                } else {
                    chunk.setX((trunc.getX() / static_cast <GLint> (Chunk::SIZE_X)));
                }
                if (trunc.getY() < 0) {
                    chunk.setY(((trunc.getY() + 1) / static_cast <GLint> (Chunk::SIZE_Y)));
                } else {
                    chunk.setY((trunc.getY() / static_cast <GLint> (Chunk::SIZE_Y)));
                }
                if (p.getX() < 0) {
                    chunk.setX(chunk.getX() - 1);
                }
                if (p.getY() < 0) {
                    chunk.setY(chunk.getY() - 1);
                }

                coord.setX(trunc.getX() - (chunk.getX() * static_cast <GLint> (Chunk::SIZE_X)));
                coord.setY(trunc.getY() - (chunk.getY() * static_cast <GLint> (Chunk::SIZE_Y)));
                coord.setZ(trunc.getZ());
            }

            VoxelPoint& VoxelPoint::operator=(VoxelPoint const& p) {
                coord = p.coord;
                chunk = p.chunk;
                return *this;
            }

            VoxelPoint& VoxelPoint::operator=(VoxelPoint && p) {
                coord = std::move(p.coord);
                chunk = std::move(p.chunk);
                return *this;
            }

        };
    };
