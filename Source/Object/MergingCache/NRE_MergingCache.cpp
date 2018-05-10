
    #include "NRE_MergingCache.hpp"

    namespace NRE {
        namespace Object {

            bool* MergingCache::cache = 0;
            Maths::Vector4D<GLuint> MergingCache::size = Maths::Vector4D<GLuint>(16, 16, 128, 6);

            bool const& MergingCache::getVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face) {
                return getVoxelMergingFace(p.getX(), p.getY(), p.getZ(), face);
            }

            bool const& MergingCache::getVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face) {
                return cache[Array::get1DIndexFrom4D(x, y, z, face, size)];
            }

            void MergingCache::setVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face, bool const& state) {
                setVoxelMergingFace(p.getX(), p.getY(), p.getZ(), face, state);
            }

            void MergingCache::setVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face, bool const& state) {
                cache[Array::get1DIndexFrom4D(x, y, z, face, size)] = state;
            }

            void MergingCache::init() {
                cache = new bool[size.getX() * size.getY() * size.getZ() * size.getW()];
            }

            void MergingCache::free() {
                delete[] cache;
                cache = 0;
            }

            void MergingCache::reset() {
                std::fill(cache, cache + (size.getX() * size.getY() * size.getZ() * size.getW()), false);
            }

        };
    };
