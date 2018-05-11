
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(Maths::Vector3D<GLuint> size) : model(size) {
                buffer = new GL::IBO(true);
                buffer->push_back(new GL::MaterialBuffer(true));
                buffer->push_back(new GL::NormalBuffer(true));

                mesh = new Mesh3D(&model, 0, 0, 0, 0, 0, 0);

                access(GL_INT);
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

            void Object3D::process(GLenum const& usage, Maths::Point2D<GLint> const& coord) {
                static_cast <Mesh3D*> (mesh)->process(*(static_cast<GL::IBO*> (buffer)), usage, coord);
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
