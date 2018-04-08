
    #include "NRE_Region.hpp"

    namespace NRE {
        namespace World {

            Region::Region() : path("") {
            }

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

            Region::Region(Region const& reg) : path(reg.getPath()), chunk(reg.getChunk()) {
            }

            Region::~Region() {
            }

            std::string const& Region::getPath() const {
                return path;
            }

            std::queue<std::pair<Maths::Point2D<GLint>, Chunk*>> const& Region::getChunk() const {
                return chunk;
            }

            void Region::setPath(std::string const& path) {
                this->path = path;
            }

            void Region::setChunk(std::queue<std::pair<Maths::Point2D<GLint>, Chunk*>> const& chunk) {
                this->chunk = chunk;
            }

            bool Region::isEmpty() const {
                return chunk.empty();
            }

            void Region::save() {
                std::fstream chunkFile;
                chunkFile.open(path, std::ios::in | std::ios::out | std::ios::binary);
                if (!chunkFile.is_open()) {
                    createTable(chunkFile);
                }
                size_t limit = getChunk().size();
                for (GLuint i = 0; i < limit; i = i + 1) {
                    Maths::Point2D<GLint> tmp = chunk.front().second->getCoord();
                    chunk.front().second->setCoord(chunk.front().first);
                    chunk.front().second->save(chunkFile);
                    chunk.front().second->setCoord(tmp);
                    chunk.pop();
                }
                chunkFile.close();
            }

            void Region::load(World* w) {
                std::fstream chunkFile;
                chunkFile.open(path, std::ios::in | std::ios::out | std::ios::binary);
                if (!chunkFile.is_open()) {
                    createTable(chunkFile);
                }
                size_t limit = getChunk().size();
                for (GLuint i = 0; i < limit; i = i + 1) {
                    chunk.front().second->load(chunkFile, w);
                    chunk.pop();
                }
                chunkFile.close();
            }

            void Region::createTable(std::fstream &chunkFile) {
                chunkFile.open(path, std::ios::trunc | std::ios::out | std::ios::binary);
                std::stringstream table;
                GLuint offset = 0, size = 0;
                for (GLuint x = 0; x < 16; x = x + 1) {
                    for (GLuint y = 0; y < 16; y = y + 1) {
                        table.write(reinterpret_cast<char*> (&offset), 3);
                        table.write(reinterpret_cast<char*> (&size), 1);
                    }
                }
                chunkFile << table.rdbuf();
            }

            void Region::add(Chunk *chunk) {
                add(chunk, chunk->getCoord());
            }

            void Region::add(Chunk *chunk, Maths::Point2D<GLint> const& coord) {
                this->chunk.push(std::pair<Maths::Point2D<GLint>, Chunk*>(coord, chunk));
            }

        };
    };
