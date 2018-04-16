
    #include "NRE_ShaderMap.hpp"

    namespace NRE {
        namespace Renderer {

            ShaderMap::ShaderMap() {
            }

            ShaderMap::ShaderMap(size_t const& n) : locations(n) {
            }

            ShaderMap::ShaderMap(ShaderMap const& map) : locations(map.size()) {
                locations = map.locations;
            }

            ShaderMap::ShaderMap(ShaderMap && map) : locations(map.size()) {
                locations = map.locations;
            }

            ShaderMap::~ShaderMap() {
                locations.erase(locations.begin(), locations.end());
            }

            GLint const& ShaderMap::getLocation(std::string const& key) const {
                return locations.at(key);
            }

            void ShaderMap::queryLocation(GLuint const& id, std::string const& key) {
                locations.emplace(key, glGetUniformLocation(id, key.c_str()));
            }

            size_t const ShaderMap::size() const {
                return locations.size();
            }

            ShaderMap& ShaderMap::operator=(ShaderMap const& map) {
                locations = map.locations;
                return *this;
            }

            ShaderMap& ShaderMap::operator=(ShaderMap && map) {
                locations = map.locations;
                return *this;
            }

        };
    };
