
    #include "Support/Scene/NRE_Scene.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"
    
    using namespace NRE;
    using namespace Maths;

    int main(int argc, char **argv) {
        /*try {
            Support::Scene engineScene("NRE 0.1 - Dev version", Maths::Vector2D<int>(1280, 720));
            Camera::MoveableCamera camera(70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100));

            World::World engineWorld(Maths::Vector2D<GLuint>(10, 10), Maths::Vector2D<GLint>(0, 0));

            Renderer::Shader skyBoxShader("Shaders/SkyBox.vert", "Shaders/SkyBox.frag", true);
            Renderer::Shader gBufferPass("Shaders/GBufferPass.vert", "Shaders/GBufferPass.frag", true);
            Renderer::Shader ssaoPass("Shaders/SSAOPass.vert", "Shaders/SSAOPass.frag", true);
            Renderer::Shader pbrShader("Shaders/PBRShader.vert", "Shaders/PBRShader.frag", true);
            Renderer::Shader captureShader("Shaders/CaptureShader.vert", "Shaders/CaptureShader.frag", true);
            Renderer::Shader irradianceShader("Shaders/IrradianceShader.vert", "Shaders/IrradianceShader.frag", true);
            Renderer::Shader prefilterShader("Shaders/PrefilterShader.vert", "Shaders/PrefilterShader.frag", true);
            Renderer::Shader brdfShader("Shaders/BRDFShader.vert", "Shaders/BRDFShader.frag", true);

            std::vector<Light::Light*> engineLight;
            //Light::DirectionnalLight engineLight1(Maths::Point3D<NREfloat>(0, 250, 300),Maths::Vector3D<NREfloat>(1.0, 1.0, 1.0), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0), 0.1);
            Light::PointLight engineLight2(Maths::Point3D<NREfloat>(29.7,  28.0, 29.0), Maths::Vector3D<NREfloat>(400.0, 0.0, 0.0));
            Light::PointLight engineLight3(Maths::Point3D<NREfloat>(71.6,  41.7, 29.0), Maths::Vector3D<NREfloat>(0.0, 400.0, 0.0));
            Light::PointLight engineLight4(Maths::Point3D<NREfloat>(60.5, -44.8, 29.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 400.0));
            Light::PointLight engineLight5(Maths::Point3D<NREfloat>(50.0, -4.8,  29.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            //engineLight.push_back(&engineLight1);
            engineLight.push_back(&engineLight2);
            engineLight.push_back(&engineLight3);
            engineLight.push_back(&engineLight4);
            engineLight.push_back(&engineLight5);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, rotation;

            Time::Clock engineClock;

            Renderer::EnvironmentMap engineSkybox("Data/SkyBox/Space_HD.hdr", captureShader, irradianceShader, prefilterShader, brdfShader);

            camera.computeProjectionMatrix(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            NREfloat skyboxAngleX = 0.0;
            int colorAngle = 0, nbFrames = 0;

            glViewport(0, 0, 1280.0, 720.0);

            camera.Keyboard::getKey(SDL_SCANCODE_E).setSwitch(true);

            while(!camera.getQuit())
            {
                engineClock.updateActualTime();
                nbFrames = nbFrames + 1;

                if (engineClock.getActualTime() - engineClock.getLastTime() >= 1000.0) {
                    std::cout << 1000.0 / nbFrames << "ms / frame" << std::endl;
                    nbFrames = 0;
                    engineClock.setLastTime(engineClock.getLastTime() + 1000.0);
                }

                //std::cout << camera.getEye() << std::endl;

                camera.update();

                colorAngle = colorAngle + 1;
                colorAngle = colorAngle % 360;

                skyboxAngleX += 0.01;
                if (skyboxAngleX >= 360) {
                    skyboxAngleX = 0.0;
                }
                rotation.setIdentity();

                Color::HSL color(colorAngle, 1.0, 0.5);
                Color::RGB colorRGB(color);
                Maths::Vector3D<NREfloat> tmpColor((static_cast <NREfloat> (colorRGB.getR() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getG() / 255.0)) * 4000.0,
                                                   (static_cast <NREfloat> (colorRGB.getB() / 255.0)) * 4000.0);
                engineLight5.setIntensities(tmpColor);

                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                modelview.setIdentity();
                camera.setView(modelview);

                engineDeferredRenderer.startGBufferPass();
                    engineWorld.render(gBufferPass, modelview, projection, &camera);
                    Maths::Matrix4x4<NREfloat> tmp(modelview);
                    modelview = modelview * rotation;
                    engineSkybox.render(skyBoxShader, projection, modelview);
                    modelview = tmp;
                engineDeferredRenderer.endGBufferPass();

                invProjection = projection;
                invProjection.inverse();
                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.SSAOPass(ssaoPass, projection, invProjection);

                Camera::Key& it2 = camera.Keyboard::getKey(SDL_SCANCODE_F);
                if (it2.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(1, 0));
                }
                Camera::Key& it3 = camera.Keyboard::getKey(SDL_SCANCODE_G);
                if (it3.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(0, -1));
                }
                Camera::Key& it4 = camera.Keyboard::getKey(SDL_SCANCODE_H);
                if (it4.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(-1, 0));
                }
                Camera::Key& it5 = camera.Keyboard::getKey(SDL_SCANCODE_T);
                if (it5.isActive()) {
                    engineWorld.shiftChunks(Maths::Vector2D<GLint>(0, 1));
                }

                engineDeferredRenderer.render(pbrShader, invModelview, invProjection, rotation, camera, engineLight, engineSkybox);

                engineWorld.update(2);

                SDL_GL_SwapWindow(engineScene.getWindow().getItem());
            }
        }
        catch (Exception::ExceptionHandler const& e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }

        World::VoxelTypes::free();
        */
        Base2D<int> base(5);
        Point2D<int> tmp0, tmp1(1, 1), tmp2(3), tmp3(Base2D<int>(4)), tmp4(base), tmp5(tmp0), tmp6(Point2D<int>(7));

        std::cout << base << std::endl;
        std::cout << tmp0 << std::endl;
        std::cout << tmp1 << std::endl;
        std::cout << tmp2 << std::endl;
        std::cout << tmp3 << std::endl;
        std::cout << tmp4 << std::endl;
        std::cout << tmp5 << std::endl;
        std::cout << tmp6 << std::endl;

        return 0;
    }
