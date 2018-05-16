
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(GLenum const& type, Maths::Vector3D<GLuint> size) : model(size) {
                mesh = new Mesh3D(type, &model, 0, 0, 0, 0, 0, 0);
            }

            Object3D::Object3D(Object3D && o) : Object::Object(std::move(o)), model(std::move(o.model)) {
            }

            Object3D::~Object3D() {
            }

            Model const& Object3D::getModel() const {
                return model;
            }

            void Object3D::setLeft(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setLeft(&(o.model));
            }

            void Object3D::setRight(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setRight(&(o.model));
            }

            void Object3D::setFront(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setFront(&(o.model));
            }

            void Object3D::setBack(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setBack(&(o.model));
            }

            void Object3D::setUp(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setUp(&(o.model));
            }

            void Object3D::setBottom(Object3D const& o) {
                static_cast <Mesh3D*> (mesh)->setBottom(&(o.model));
            }

            void Object3D::save(std::string const& path) const {
                model.save(path);
            }
            void Object3D::load(std::string const& path) {
                model.load(path);
            }

            void Object3D::loadOBJ(std::string const& path) {
                MeshLoader loader(static_cast <Mesh3D*> (mesh), path);
                mesh->allocateAndFill(GL_STATIC_DRAW);
            }

            void Object3D::process(GLenum const& usage, Maths::Point2D<GLint> const& coord) {
                static_cast <Mesh3D*> (mesh)->process(usage, coord);
            }

            void Object3D::processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type) {
                static_cast <Mesh3D*> (mesh)->processSphere(usage, radius, rings, sectors, type);
            }

            void Object3D::loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLubyte const& type) {
                model.loadVoxels(x, y, z, nb, type);
            }

            Object3D& Object3D::operator=(Object3D && o) {
                Object::operator=(std::move(o));
                model = std::move(o.model);
                return *this;
            }

        };
    };
