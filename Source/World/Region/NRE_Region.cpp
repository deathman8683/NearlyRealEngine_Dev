
    #include "NRE_Region.hpp"

    namespace NRE {
        namespace World {

            Region::Region(std::string const& path) : path(path) {
            }

            Region::Region(Chunk *chunk) {
                std::ostringstream xStr, yStr;
                if (chunk->getCoord().getX() < 0) {
                    xStr << (chunk->getCoord().getX() / 16) -1;
                } else {
                    xStr << (chunk->getCoord().getX() / 16);
                }
                if (chunk->getCoord().getY() < 0) {
                    yStr << (chunk->getCoord().getY() / 16) -1;
                } else {
                    yStr << (chunk->getCoord().getY() / 16);
                }
                path = "Data/Region/r." + xStr.str() + "." + yStr.str() + ".dat";
                this->chunk.push(std::pair<Maths::Point2D<GLint>, Chunk*>(chunk->getCoord(), chunk));
            }

            Region::Region(Region const& reg) : path(reg.getPath()), chunk(reg.chunk) {
            }

            Region::Region(Region && reg) : path(std::move(reg.getPath())), chunk(std::move(reg.chunk)) {
            }

            Region::~Region() {
            }

            std::string const& Region::getPath() const {
                return path;
            }

            bool Region::isEmpty() const {
                return chunk.empty();
            }

            void Region::save() {
                IO::IOFile chunkFile(path);
                if (!chunkFile.exist()) {
                    createTable();
                }
                chunkFile.open(std::ios::in | std::ios::out | std::ios::binary);
                size_t limit = chunk.size();
                for (GLuint i = 0; i < limit; i = i + 1) {
                    Maths::Point2D<GLint> tmp = chunk.front().second->getCoord();
                    chunk.front().second->setCoord(chunk.front().first);
                    chunk.front().second->save(chunkFile.getStream());
                    chunk.front().second->setCoord(tmp);
                    chunk.pop();
                }
            }

            void Region::load(World* w) {
                IO::IOFile chunkFile(path);
                if (!chunkFile.exist()) {
                    createTable();
                }
                chunkFile.open(std::ios::in | std::ios::out | std::ios::binary);
                size_t limit = chunk.size();
                for (GLuint i = 0; i < limit; i = i + 1) {
                    chunk.front().second->load(chunkFile.getStream(), w);
                    chunk.pop();
                }
            }

            void Region::createTable() {
                IO::IOFile chunkFile(path);
                chunkFile.open(std::ios::out | std::ios::binary, true);
                std::stringstream table;
                GLuint offset = 0, size = 0;
                for (GLuint x = 0; x < 16; x = x + 1) {
                    for (GLuint y = 0; y < 16; y = y + 1) {
                        table.write(reinterpret_cast<char*> (&offset), 3);
                        table.write(reinterpret_cast<char*> (&size), 1);
                    }
                }
                chunkFile.write(table);
            }

            void Region::add(Chunk *chunk) {
                add(chunk, chunk->getCoord());
            }

            void Region::add(Chunk *chunk, Maths::Point2D<GLint> const& coord) {
                this->chunk.push(std::pair<Maths::Point2D<GLint>, Chunk*>(coord, chunk));
            }

            Region& Region::operator=(Region const& reg) {
                path = reg.path;
                chunk = reg.chunk;
                return *this;
            }

            Region& Region::operator=(Region && reg) {
                path = std::move(reg.path);
                chunk = std::move(reg.chunk);
                return *this;
            }

        };
    };
