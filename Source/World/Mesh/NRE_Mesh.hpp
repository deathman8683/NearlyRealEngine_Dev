
    /**
     * @file NRE_Mesh.hpp
     * @brief Declaration of Engine's World's Object : Mesh
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include <vector>
    #include <unordered_map>

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's Voxel's Type's Module
         */
        namespace World {

            /**
             * @class Mesh
             * @brief World's Object : Manage object's rendering while creating their mesh with optimization
             */
            class Mesh {
                private:
                    std::vector<GLint> vData;
                    std::vector<GLfloat> cData;
                    std::vector<GLbyte> nData;
                    std::vector<GLuint> iData;
                    std::unordered_map<Voxel::PackedVertex<GLint>, size_t> map;

                public:
                    //## Constructor ##//
                    Mesh();

                    //## Copy-Constructor ##//
                    Mesh(Mesh const& mesh);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Mesh();

                    //## Getter ##//
                    std::vector<GLint> const& getVData() const;
                    std::vector<GLfloat> const& getCData() const;
                    std::vector<GLbyte> const& getNData() const;
                    std::vector<GLuint> const& getIData() const;
                    std::vector<GLint>* const& getVPointer() const;
                    std::vector<GLfloat>* const& getCPointer() const;
                    std::vector<GLbyte>* const& getNPointer() const;
                    std::vector<GLuint>* const& getIPointer() const;
                    std::unordered_map<Voxel::PackedVertex<GLint>, size_t> const& getMap() const;

                    //## Setter ##//
                    void setVData(std::vector<GLint> const& data);
                    void setCData(std::vector<GLfloat> const& data);
                    void setNData(std::vector<GLbyte> const& data);
                    void setIData(std::vector<GLuint> const& data);
                    void setMap(std::unordered_map<Voxel::PackedVertex<GLint>, size_t> const& map);

                    //## Methods ##//
                    void addVertex(Maths::Point3D<GLint> const& v);
                    void addColor(Color::RGB const& c);
                    void addNormal(Maths::Vector3D<GLbyte> const& n);
                    void addIndex(GLuint const& index);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
