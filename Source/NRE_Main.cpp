
    #include "Support/Stage/NRE_Stage.hpp"
    #include "Camera/NRE_MoveableCamera.hpp"
    #include "World/NRE_World.hpp"
    #include "Time/Clock/NRE_Clock.hpp"
    #include "Renderer/DeferredRenderer/NRE_DeferredRenderer.hpp"

    using namespace NRE;
    using namespace Maths;

    int main(int argc, char **argv) {
        try {
            Support::Stage engineStage("NRE 0.1 - Dev version", Maths::Vector2D<int>(1280, 720));
            Camera::MoveableCamera camera(70.0, 1280.0 / 720.0, Maths::Vector2D<NREfloat>(0.1, 2000.0), Maths::Vector3D<NREfloat>(0, 1, 100), Maths::Vector3D<NREfloat>(0, 0, 100));

            World::World engineWorld(Maths::Vector2D<GLuint>(5, 5), Maths::Vector2D<GLint>(0, 0));

            std::vector<Light::Light*> engineLight;
            Light::DirectionnalLight engineLight1(Maths::Point3D<NREfloat>(0, 0, 300),Maths::Vector3D<NREfloat>(0.06, 0.16, 0.5), Maths::Vector3D<NREfloat>(0.0, 0.0, -1.0));
            Light::PointLight engineLight2(Maths::Point3D<NREfloat>(29.7,  28.0, 29.0), Maths::Vector3D<NREfloat>(400.0, 0.0, 0.0));
            Light::PointLight engineLight3(Maths::Point3D<NREfloat>(71.6,  41.7, 29.0), Maths::Vector3D<NREfloat>(0.0, 400.0, 0.0));
            Light::PointLight engineLight4(Maths::Point3D<NREfloat>(60.5, -44.8, 29.0), Maths::Vector3D<NREfloat>(0.0, 0.0, 400.0));
            Light::PointLight engineLight5(Maths::Point3D<NREfloat>(50.0, -4.8,  29.0), Maths::Vector3D<NREfloat>(4000.0, 4000.0, 4000.0));
            engineLight.push_back(&engineLight1);
            engineLight.push_back(&engineLight2);
            engineLight.push_back(&engineLight3);
            engineLight.push_back(&engineLight4);
            engineLight.push_back(&engineLight5);

            Maths::Matrix4x4<NREfloat> projection, modelview, invProjection, invModelview, rotation;

            Time::Clock engineClock;

            Renderer::EnvironmentMap engineSkybox("Data/SkyBox/Space_HD.hdr");

            camera.computeProjectionMatrix(projection);

            Renderer::EngineShader::sendProjection(projection);

            Renderer::DeferredRenderer engineDeferredRenderer(Maths::Vector2D<NREfloat>(1280.0, 720.0));

            NREfloat skyboxAngleX = 0.0;
            int colorAngle = 0, nbFrames = 0;

            glViewport(0, 0, 1280.0, 720.0);

            camera.Keyboard::getKey(SDL_SCANCODE_E).setSwitch(true);
            //camera.Keyboard::getKey(SDL_SCANCODE_F).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksLeft));
            //camera.Keyboard::getKey(SDL_SCANCODE_H).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksRight));
            //camera.Keyboard::getKey(SDL_SCANCODE_G).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksBack));
            //camera.Keyboard::getKey(SDL_SCANCODE_T).setAction(new Command<World::World>(&engineWorld, World::World::shiftChunksFront));

            GL::IBO* oTIBO = new GL::IBO(true);
            oTIBO->push_back(new GL::MaterialBuffer(true));
            oTIBO->push_back(new GL::NormalBuffer(true));

            Object::Mesh* oTMesh = new Object::Mesh();
            oTMesh->push_back(new Object::MaterialData());
            oTMesh->push_back(new Object::NormalData());
            oTMesh->push_back(new Object::IndexData());

            Object::Object3D oT1(Maths::Vector3D<GLuint>(5, 9, 6));
            GLuint x = 0, y = 0, z = 0;

            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 3, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 25, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 3, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 10, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 3, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 25, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 3, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 10, World::VOID);
            oT1.loadVoxels(x, y, z, 35, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 10, World::VOID);
            oT1.loadVoxels(x, y, z, 35, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 35, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 35, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.loadVoxels(x, y, z, 3, World::SCORCHED);
            oT1.loadVoxels(x, y, z, 1, World::VOID);
            oT1.process(GL_STATIC_DRAW, Maths::Point2D<GLint>(0, 0));

            while(!camera.getQuit())
            {
                engineClock.updateActualTime();
                nbFrames = nbFrames + 1;

                if (engineClock.getActualTime() - engineClock.getLastTime() >= 1000.0) {
                    std::cout << 1000.0 / nbFrames << "ms / frame" << std::endl;
                    nbFrames = 0;
                    engineClock.setLastTime(engineClock.getLastTime() + 1000.0);
                }
                //engineClock.updateTimestep(1000.0 / 60.0);

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

                rotation.rotate(-skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                engineLight1.setPosition(rotation * Maths::Vector3D<NREfloat>(0, 0, 300));

                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));
                rotation.rotate(skyboxAngleX, Maths::Vector3D<NREfloat>(0.0, 1.0, 0.0));

                modelview.setIdentity();
                camera.setView(modelview);

                engineDeferredRenderer.startGBufferPass();
                    engineWorld.render(modelview, projection, &camera);
                    Renderer::EngineShader::getShader("GBuffer")->bind();
                        Renderer::EngineShader::getShader("GBuffer")->useMat4("modelview", 1, &modelview);
                        Renderer::EngineShader::getShader("GBuffer")->useMat4("projection", 1, &projection);
                        //oT1.draw();
                    Renderer::EngineShader::getShader("GBuffer")->unbind();
                    Maths::Matrix4x4<NREfloat> tmp(modelview);
                    modelview = modelview * rotation;
                    engineSkybox.render( projection, modelview);
                    modelview = tmp;
                engineDeferredRenderer.endGBufferPass();

                invProjection = projection;
                invProjection.inverse();
                invModelview = modelview;
                invModelview.inverse();

                engineDeferredRenderer.SSAOPass(projection, invProjection);

                engineDeferredRenderer.render(invModelview, invProjection, rotation, camera, engineLight, engineSkybox);

                engineWorld.update(1);

                engineStage.updateScreen();
            }
        }
        catch (Exception::ExceptionHandler const& e) {
            std::cout << e.what() << std::endl;
        }
        catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }

        return 0;
    }
