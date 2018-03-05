
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "Renderer/Shader/NRE_Shader.hpp"
    #include "World/Chunk/NRE_Chunk.hpp"

    using namespace NRE;

    int main(int argc, char **argv) {
        Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(800, 600));
        Camera::MoveableCamera camera("kBinder.cfg", "mBinder.cfg", Maths::Vector3D<NREfloat>(-3, -3, -3), Maths::Vector3D<NREfloat>(0, 0, 0), Maths::Vector2D<NREfloat>(0, 0), 0.01);

        World::Chunk test(true);

        test.constructMesh();

        Renderer::Shader shaderCouleur("Shaders/couleur3D.vert", "Shaders/couleur3D.frag", true);

        Maths::Matrix4x4<NREfloat> projection;
        Maths::Matrix4x4<NREfloat> modelview;

        projection.projection(70.0, 800.0 / 600.0, 0.1, 100.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        while(!camera.getQuit())
        {
            camera.update();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            modelview.setIdentity();
            camera.setView(modelview);

            test.render(shaderCouleur, modelview, projection);

            SDL_GL_SwapWindow(engineScene.getWindow().getItem());
        }

        camera.Keyboard::save("kBinder.cfg");
        camera.Mouse::save("mBinder.cfg");

        return 0;
    }
